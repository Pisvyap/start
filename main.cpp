#include <iostream>

#include <typlypParser.h>

#include "antlr4-runtime.h"
#include "ast/ASTBuilder.h"
#include "ast/ASTNode.h"
#include "grammar/typlypLexer.h"

#include "vm/VirtualMachine.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/raw_ostream.h"
#include "ast/nodes/expressions/UnaryOperationNode.h"
#include "llvm/ExecutionEngine/Orc/LLJIT.h"
#include <gc/gc.h>

#include "utils/utils.h"

using namespace llvm;

auto context = std::make_unique<LLVMContext>();
auto module = std::make_unique<Module>("MyModule", *context);
IRBuilder Builder(*context);
std::map<std::string, AllocaInst *> NamedValues;
std::map<std::string, Value *> Arrays;
std::map<std::string, Function *> Functions;

// Ноды EXPRESSIONS
Value *NumberLiteralNode::Codegen() {
    ConstantInt *constVal = ConstantInt::get(
            *context,
            APInt(128, value, true)
    );

    return constVal;
}

Value *BoolLiteralNode::Codegen() {
    ConstantInt *constVal = ConstantInt::get(
            *context,
            APInt(1, value, true)
    );

    return constVal;
}

Value *BinaryOperationNode::Codegen() {
    Value *L = left->Codegen();
    Value *R = right->Codegen();

    switch (operation) {
        case Add:
            return Builder.CreateAdd(L, R, "addtmp");
        case Sub:
            return Builder.CreateSub(L, R, "subtmp");
        case Mul:
            return Builder.CreateMul(L, R, "multmp");
        case Div:
            return Builder.CreateSDiv(L, R, "divtmp");
        case Mod:
            return Builder.CreateSRem(L, R, "modtmp");
        case LT:
            return Builder.CreateICmpSLT(L, R, "lttmp");
        case LE:
            return Builder.CreateICmpSLE(L, R, "letmp");
        case GT:
            return Builder.CreateICmpSGT(L, R, "gttmp");
        case GE:
            return Builder.CreateICmpSGE(L, R, "getmp");
        case EQ:
            return Builder.CreateICmpEQ(L, R, "eqtmp");
        case NE:
            return Builder.CreateICmpNE(L, R, "netmp");
        default:
            throw CodegenException("Unsupported operation in BinaryOperationNode::Codegen");
    }
}

Value *UnaryOperationNode::Codegen() {
    switch (operation) {
        case NOT: {
            Value *result = Builder.CreateNot(expression->Codegen(), "not_result");
            return result;
        }
        default:
            throw CodegenException("Unsupported operation in UnaryOperationNode::Codegen");
    }
}

Value *IdentifierNode::Codegen() {
    if (NamedValues.find(name) != NamedValues.end()) {
        auto it = NamedValues.find(name);
        return Builder.CreateLoad(
                it->second->getAllocatedType(),
                it->second,
                name.c_str());
    } else if (Arrays.find(name) != Arrays.end()) {
        auto it = Arrays.find(name);
        return it->second;
    } else {
        throw CodegenException("Identifier not found: " + name);
    }
}

Value *ArrayIndexExpressionNode::Codegen() {
    Value *arrayValue = Arrays[name];
    if (!arrayValue)
        throw CodegenException("Array '" + name + "' was not declared");

    Value *indexValue = index->Codegen();
    if (!indexValue->getType()->isIntegerTy())
        throw CodegenException("Array index must be of integer type");

    llvm::Type *indexType = llvm::Type::getInt128Ty(*context);
    if (indexValue->getType() != indexType) {
        indexValue = Builder.CreateIntCast(indexValue, indexType, true, "indexCast");
    }

    auto *arrayPointerType = llvm::dyn_cast<PointerType>(arrayValue->getType());
    if (!arrayPointerType)
        throw CodegenException("Variable '" + name + "' is not a pointer");
    llvm::Type *elementType;
    if (type.type == BOOL) {
        elementType = llvm::Type::getInt1Ty(*context);
    } else if (type.type == INT) {
        elementType = llvm::Type::getInt128Ty(*context);
    } else {
        throw CodegenException("Unsupported array type in NewExpressionNode.");
    }

    Value *elementPtr = Builder.CreateGEP(
            elementType,
            arrayValue,
            indexValue,
            name + "_element_ptr"
    );

    Value *elementValue = Builder.CreateLoad(
            elementType,
            elementPtr,
            name + "_element_value"
    );

    return elementValue;
}

Value *NewExpressionNode::Codegen() {
    Value *sizeExpr = expression->Codegen();
    llvm::Type *sizeType = llvm::Type::getInt128Ty(*context);
    Value *size128 = Builder.CreateZExtOrTrunc(sizeExpr, sizeType);

    auto *constantSize = llvm::dyn_cast<ConstantInt>(size128);
    if (!constantSize) {
        throw CodegenException("Array size must be a constant value for stack allocation.");
    }

    uint64_t arraySize = constantSize->getZExtValue();
    llvm::Type *elementType;

    if (type.type == BOOL) {
        elementType = llvm::Type::getInt8Ty(*context); // Используем i8 вместо i1
    } else if (type.type == INT) {
        elementType = llvm::Type::getInt128Ty(*context);
    } else {
        throw CodegenException("Unsupported array type in NewExpressionNode.");
    }

    uint64_t elementSize = (type.type == BOOL) ? 1 : (elementType->getPrimitiveSizeInBits() / 8);

    void *allocatedArray = GC_MALLOC(arraySize * elementSize);
    if (!allocatedArray) {
        throw CodegenException("Failed to allocate memory for array.");
    }

    return Builder.CreatePointerCast(
            ConstantInt::get(llvm::Type::getInt64Ty(*context), reinterpret_cast<uint64_t>(allocatedArray)),
            PointerType::getUnqual(elementType)
    );
}

Value *FunctionCallExpressionNode::Codegen() {
    auto it = Functions.find(name);

    if (it == Functions.end())
        throw CodegenException("Function not found: " + name);

    Function *func = it->second;
    std::vector<Value *> argv;

    for (const auto &arg: arguments) {
        Value *argV = arg->Codegen();

        argv.push_back(argV);
    }

    Value *res = Builder.CreateCall(func, argv);
    return res;
}

// Ноды STATEMENTS
Value *ArrayAssigmentNode::Codegen() {
    Value *arrayValue = Arrays[name];
    if (!arrayValue)
        throw CodegenException("Array '" + name + "' was not declared");

    auto *arrayPointerType = llvm::dyn_cast<PointerType>(arrayValue->getType());
    if (!arrayPointerType)
        throw CodegenException("Variable '" + name + "' is not a pointer");

    Value *valueToStore = value->Codegen();

    llvm::Type *elementType = valueToStore->getType();

    Value *indexValue = index->Codegen();
    if (!indexValue->getType()->isIntegerTy())
        throw CodegenException("Array index must be of integer type");

    llvm::Type *indexType = llvm::Type::getInt128Ty(*context);
    if (indexValue->getType() != indexType) {
        indexValue = Builder.CreateIntCast(indexValue, indexType, true, "indexCast");
    }

    Value *elementPtr = Builder.CreateGEP(
            elementType,
            arrayValue,
            indexValue,
            name + "_element_ptr"
    );

    Builder.CreateStore(valueToStore, elementPtr);

    return valueToStore;
}

Value *AssigmentStatementNode::Codegen() {
    Value *valPtr = value->Codegen();
    if (NamedValues.find(name) != NamedValues.end()) {
        auto it = NamedValues.find(name);
        Value *varPtr = it->second;
        Builder.CreateStore(valPtr, varPtr);
        return nullptr;
    } else if (Arrays.find(name) != Arrays.end()) {
        auto it = Arrays.find(name);
        Value *varPtr = it->second;
        Builder.CreateStore(valPtr, varPtr);
        return nullptr;
    } else {
        throw CodegenException("Variable not found: " + name);
    }
}

Value *ExpressionStatementNode::Codegen() {
    BasicBlock *currentBlock = Builder.GetInsertBlock();

    if (!currentBlock)
        throw CodegenException("No insertion point set in the builder");

    Value *exprValue = expression->Codegen();

    if (!exprValue)
        throw CodegenException("Failed to generate code for expression");

    return exprValue;
}

Value *ForStatementNode::Codegen() {

    init->Codegen();
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *condBB = BasicBlock::Create(*context, "for.cond", TheFunction);
    BasicBlock *bodyBB = BasicBlock::Create(*context, "for.body", TheFunction);
    BasicBlock *stepBB = BasicBlock::Create(*context, "for.step", TheFunction);
    BasicBlock *afterBB = BasicBlock::Create(*context, "for.after", TheFunction);

    Builder.CreateBr(condBB);
    Builder.SetInsertPoint(condBB);
    Value *condVal = condition->Codegen();
    Builder.CreateCondBr(condVal, bodyBB, afterBB);

    Builder.SetInsertPoint(bodyBB);
    body->Codegen();
    Builder.CreateBr(stepBB);

    Builder.SetInsertPoint(stepBB);
    step->Codegen();
    Builder.CreateBr(condBB);

    Builder.SetInsertPoint(afterBB);
    return ConstantInt::get(llvm::Type::getInt128Ty(*context), 0);
}

Value *IfStatementNode::Codegen() {
    Value *condVal = condition->Codegen();
    if (!condVal)
        throw CodegenException("Failed to generate condition for if statement");

    condVal = Builder.CreateICmpNE(
            condVal,
            ConstantInt::get(condVal->getType(), 0),
            "ifcond"
    );

    Function *TheFunction = Builder.GetInsertBlock()->getParent();

    BasicBlock *thenBB = BasicBlock::Create(*context, "if.then", TheFunction);
    BasicBlock *elseBB = BasicBlock::Create(*context, "if.else");
    BasicBlock *mergeBB = BasicBlock::Create(*context, "if.merge");

    Builder.CreateCondBr(condVal, thenBB, elseBB);

    Builder.SetInsertPoint(thenBB);

    if (thenBlock)
        thenBlock->Codegen();

    Builder.CreateBr(mergeBB);

    elseBB->insertInto(TheFunction);
    Builder.SetInsertPoint(elseBB);

    if (elseBlock)
        elseBlock->Codegen();
    Builder.CreateBr(mergeBB);

    mergeBB->insertInto(TheFunction);
    Builder.SetInsertPoint(mergeBB);

    return ConstantInt::get(llvm::Type::getInt128Ty(*context), 0);
}

Value *ReturnStatementNode::Codegen() {
    Value *retVal = expression ? expression->Codegen() : nullptr;
    if (retVal == nullptr) {
        throw CodegenException("Return statement not found");
    }

    Builder.CreateRet(retVal);
    return retVal;
}

Value *VariableDeclarationNode::Codegen() {
    llvm::Type *varType;

    if (type.type == INT) {
        if (type.is_array) {
            varType = PointerType::getUnqual(llvm::Type::getInt128Ty(*context));
        } else {
            varType = llvm::Type::getInt128Ty(*context);
        }
    } else if (type.type == BOOL) {
        if (type.is_array) {
            varType = PointerType::getUnqual(llvm::Type::getInt1Ty(*context));
        } else {
            varType = llvm::Type::getInt1Ty(*context);
        }
    } else {
        throw CodegenException("Unknown type: " + to_string(type.type));
    }

    Value *initVal = nullptr;

    if (initializer) {
        initVal = initializer->Codegen();

        if (type.is_array && initVal->getType()->isPointerTy()) {
            Arrays[name] = initVal;
            return initVal;
        }
    }

    if (!initVal) {
        if (type.is_array) {
            throw CodegenException("Array must be explicitly initialized");
        } else {
            initVal = Constant::getNullValue(varType);
        }
    }

    if (type.is_array) {
        auto *arrayType = llvm::dyn_cast<ArrayType>(varType->getArrayElementType());
        if (!arrayType) {
            throw CodegenException("Failed to deduce array type for allocation");
        }

        void *allocatedArray = GC_MALLOC(arrayType->getElementType()->getPrimitiveSizeInBits() / 8);
        if (!allocatedArray) {
            throw CodegenException("Failed to allocate memory for array.");
        }

        Arrays[name] = Builder.CreatePointerCast(
                ConstantInt::get(llvm::Type::getInt64Ty(*context), reinterpret_cast<uint64_t>(allocatedArray)),
                varType, name + "_ptr"
        );
        return Arrays[name];
    } else {
        AllocaInst *alloc = Builder.CreateAlloca(varType, nullptr, name);
        alloc->setAlignment(Align(16));
        Builder.CreateStore(initVal, alloc);
        NamedValues[name] = alloc;
        return alloc;
    }
}


Value *WhileStatementNode::Codegen() {
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *condBB = BasicBlock::Create(*context, "while.cond", TheFunction);
    BasicBlock *bodyBB = BasicBlock::Create(*context, "while.body", TheFunction);
    BasicBlock *afterBB = BasicBlock::Create(*context, "while.after", TheFunction);

    Builder.CreateBr(condBB);
    Builder.SetInsertPoint(condBB);
    Value *condVal = condition->Codegen();
    if (!condVal)
        throw CodegenException("Failed to generate condition for while statement");

    Builder.CreateCondBr(condVal, bodyBB, afterBB);
    Builder.SetInsertPoint(bodyBB);
    body->Codegen();
    if (!body)
        throw CodegenException("Failed to generate while statement");

    Builder.CreateBr(condBB);
    Builder.SetInsertPoint(afterBB);

    return ConstantInt::get(llvm::Type::getInt128Ty(*context), 0);
}

Value *PrintStatementNode::Codegen() {
    Function *printfFunc = module->getFunction("printf");
    if (!printfFunc) {
        FunctionType *printfType = FunctionType::get(
                IntegerType::getInt128Ty(*context),
                PointerType::getUnqual(llvm::Type::getInt8Ty(*context)),
                true
        );
        printfFunc = Function::Create(
                printfType,
                Function::ExternalLinkage,
                "printf",
                *module
        );
    }


    Value *value = expression->Codegen();
    if (!value) {
        throw CodegenException("Codegen for expression in PrintStatementNode failed");
    }


    llvm::Type *valueType = value->getType();

    if (valueType->isIntegerTy(128)) {
        Value *lowPart = Builder.CreateTrunc(value, llvm::Type::getInt64Ty(*context), "lowPart");
        Value *highPart = Builder.CreateLShr(value, llvm::ConstantInt::get(valueType, 64));
        highPart = Builder.CreateTrunc(highPart, llvm::Type::getInt64Ty(*context), "highPart");

        Constant *singlePartFormatConst = ConstantDataArray::getString(*context, "%llu\n");
        auto singlePartFormatVar = new GlobalVariable(
                *module,
                singlePartFormatConst->getType(),
                true,
                GlobalValue::PrivateLinkage,
                singlePartFormatConst,
                ".strSinglePart"
        );

        Constant *dualPartFormatConst = ConstantDataArray::getString(*context, "%llu%llu\n");
        auto *dualPartFormatVar = new GlobalVariable(
                *module,
                dualPartFormatConst->getType(),
                true,
                GlobalValue::PrivateLinkage,
                dualPartFormatConst,
                ".strDualPart"
        );

        Value *singlePartFormatPtr = Builder.CreateInBoundsGEP(
                singlePartFormatVar->getValueType(),
                singlePartFormatVar,
                {
                        ConstantInt::get(llvm::Type::getInt32Ty(*context), 0),
                        ConstantInt::get(llvm::Type::getInt32Ty(*context), 0)
                }
        );

        Value *dualPartFormatPtr = Builder.CreateInBoundsGEP(
                dualPartFormatVar->getValueType(),
                dualPartFormatVar,
                {
                        ConstantInt::get(llvm::Type::getInt32Ty(*context), 0),
                        ConstantInt::get(llvm::Type::getInt32Ty(*context), 0)
                }
        );

        Value *isHighZero = Builder.CreateICmpEQ(highPart, ConstantInt::get(llvm::Type::getInt64Ty(*context), 0));

        Function *parentFunction = Builder.GetInsertBlock()->getParent();
        BasicBlock *printLowPartBlock = BasicBlock::Create(*context, "printLowPart", parentFunction);
        BasicBlock *printDualPartBlock = BasicBlock::Create(*context, "printDualPart", parentFunction);
        BasicBlock *afterPrintBlock = BasicBlock::Create(*context, "afterPrint", parentFunction);

        Builder.CreateCondBr(isHighZero, printLowPartBlock, printDualPartBlock);

        Builder.SetInsertPoint(printLowPartBlock);
        Builder.CreateCall(printfFunc, {singlePartFormatPtr, lowPart});
        Builder.CreateBr(afterPrintBlock);

        Builder.SetInsertPoint(printDualPartBlock);
        Builder.CreateCall(printfFunc, {dualPartFormatPtr, highPart, lowPart});
        Builder.CreateBr(afterPrintBlock);

        Builder.SetInsertPoint(afterPrintBlock);
    } else if (valueType->isIntegerTy(1)) {
        Constant *trueStrConst = ConstantDataArray::getString(*context, "pravda\n");
        auto trueStrVar = new GlobalVariable(
                *module,
                trueStrConst->getType(),
                true,
                GlobalValue::PrivateLinkage,
                trueStrConst,
                ".strTrue"
        );

        Constant *falseStrConst = ConstantDataArray::getString(*context, "lozh\n");
        auto falseStrVar = new GlobalVariable(
                *module,
                falseStrConst->getType(),
                true,
                GlobalValue::PrivateLinkage,
                falseStrConst,
                ".strFalse"
        );

        Value *trueStrPtr = Builder.CreateInBoundsGEP(
                trueStrVar->getValueType(),
                trueStrVar,
                {
                        ConstantInt::get(llvm::Type::getInt32Ty(*context), 0),
                        ConstantInt::get(llvm::Type::getInt32Ty(*context), 0)
                }
        );

        Value *falseStrPtr = Builder.CreateInBoundsGEP(
                falseStrVar->getValueType(),
                falseStrVar,
                {
                        ConstantInt::get(llvm::Type::getInt32Ty(*context), 0),
                        ConstantInt::get(llvm::Type::getInt32Ty(*context), 0)
                }
        );

        Value *condition = Builder.CreateICmpEQ(value, ConstantInt::get(llvm::Type::getInt1Ty(*context), 1));
        Value *selectedStr = Builder.CreateSelect(condition, trueStrPtr, falseStrPtr);

        Builder.CreateCall(printfFunc, {selectedStr});
    } else if (valueType->isIntegerTy()) {
        Value *formatStrPtr;

        Constant *formatStrConst = ConstantDataArray::getString(*context, "%d\n");
        auto formatStrVar = new GlobalVariable(
                *module,
                formatStrConst->getType(),
                true,
                GlobalValue::PrivateLinkage,
                formatStrConst,
                ".str"
        );
        formatStrPtr = Builder.CreateInBoundsGEP(
                formatStrVar->getValueType(),
                formatStrVar,
                {
                        ConstantInt::get(llvm::Type::getInt32Ty(*context), 0),
                        ConstantInt::get(llvm::Type::getInt32Ty(*context), 0)
                }
        );

        Builder.CreateCall(printfFunc, {formatStrPtr, value});
    } else {
        throw std::runtime_error("Unsupported type for PrintStatementNode");
    }

    return nullptr;
}


// Ноды остальные
Value *CodeBlockNode::Codegen() {
    for (auto &statement: statements)
        statement->Codegen();

    return Constant::getNullValue(llvm::Type::getInt32Ty(*context));
}

Value *FunctionNode::Codegen() {
    llvm::Type *llvmReturnType;

    if (returnType.is_array)
        throw CodegenException("Error. Functions cannot return arrays");

    if (returnType.type == INT)
        llvmReturnType = llvm::Type::getInt128Ty(*context);
    else if (returnType.type == BOOL) {
        llvmReturnType = llvm::Type::getInt1Ty(*context);
    } else {
        throw CodegenException("Unknown return type: " + to_string(returnType.type));
    }

    std::vector<llvm::Type *> paramTypes;
    for (const auto &param: parameters) {
        llvm::Type *paramType;
        if (param->type.is_array && param->type.type == INT) {
            paramType = PointerType::get(ArrayType::getInt128Ty(*context), 0);
        } else if (param->type.is_array && param->type.type == BOOL) {
            paramType = PointerType::get(ArrayType::getInt1Ty(*context), 0);
        } else if (param->type.type == INT)
            paramType = llvm::Type::getInt128Ty(*context);
        else if (param->type.type == BOOL) {
            paramType = llvm::Type::getInt1Ty(*context);
        } else {
            throw CodegenException("Unknown parameter type: " + to_string(param->type.type));
        }
        paramTypes.push_back(paramType);
    }

    FunctionType *funcType = FunctionType::get(llvmReturnType, paramTypes, false);

    Function *function = Function::Create(
            funcType,
            Function::InternalLinkage,
            name,
            module.get()
    );

    Functions[name] = function;

    BasicBlock *originalInsertBlock = Builder.GetInsertBlock();

    BasicBlock *entryBlock = BasicBlock::Create(*context, "entry", function);
    Builder.SetInsertPoint(entryBlock);

    auto paramIt = function->arg_begin();
    for (const auto &param: parameters) {
        Argument &llvmArg = *paramIt++;
        llvmArg.setName(param->name);
        IRBuilder<> tempBuilder(&function->getEntryBlock(), function->getEntryBlock().begin());

        if (param->type.is_array) {
            llvm::Type *elementType = nullptr;
            if (param->type.type == INT) {
                elementType = llvm::Type::getInt128Ty(*context);
            } else if (param->type.type == BOOL) {
                elementType = llvm::Type::getInt1Ty(*context);
            }
            llvm::Type *pointerType = PointerType::get(elementType, 0);
            Value *castedPtr = Builder.CreateBitCast(&llvmArg, pointerType, param->name + "_ptr");

            Arrays[param->name] = castedPtr;
        } else {
            AllocaInst *alloca = tempBuilder.CreateAlloca(llvmArg.getType(), nullptr, param->name);
            alloca->setAlignment(Align(16));
            Builder.CreateStore(&llvmArg, alloca);
            NamedValues[param->name] = alloca;
        }
    }

    Value *bodyValue = body->Codegen();
    if (!bodyValue) {
        throw CodegenException("Error while generating function body");
    }

    if (function->doesNotReturn()) {
        if (returnType.type == INT) {
            Builder.CreateRet(ConstantInt::get(*context, llvm::APInt(128, 0)));
        } else {
            Builder.CreateRet(ConstantInt::get(*context, llvm::APInt(1, 0)));
        }
    }

    if (verifyFunction(*function, &errs())) {
        throw CodegenException("Error: Function " + name + " contains errors!");
    }

    Builder.SetInsertPoint(originalInsertBlock);

    return function;
}

Value *ParameterNode::Codegen() {
    Value *paramValue;
    if (type.is_array) {
        paramValue = Arrays[name];
        if (type.array_size <= 0)
            throw CodegenException("Error: array " + name + " has invalid size: " + to_string(type.array_size));

        return paramValue;
    }

    paramValue = NamedValues[name];
    if (type.type == INT or type.type == BOOL) {
        return paramValue;
    }

    throw CodegenException("Unknown parameter type: " + to_string(type.type));
}


Value *ProgramNode::Codegen() {
    for (auto &func: functions) {
        func->Codegen();
    }
    for (auto &stmt: statements) {
        stmt->Codegen();
    }

    return Constant::getNullValue(llvm::Type::getInt32Ty(*context));
}


Ptr<ProgramNode> build_ast(const std::string &code) {
    antlr4::ANTLRInputStream inputStream(code);
    auto lexer = typlypLexer(&inputStream);
    antlr4::CommonTokenStream tokenStream(&lexer);
    auto parser = typlypParser(&tokenStream);

    auto tree = parser.program();

    try {
        Ptr<ProgramNode> ast;
        ASTBuilder builder;
        auto ast_any = builder.visitProgram(tree);
        ast = std::any_cast<Ptr<ProgramNode> >(ast_any);
        // ast->print(0);

        SemanticTable table;
        ast->semantic_check(table);

        return ast;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return nullptr;
    }
}

Function *create_main_function() {
    FunctionType *funcType = FunctionType::get(llvm::Type::getVoidTy(*context), false);
    Function *mainFunc = Function::Create(funcType, Function::ExternalLinkage, "main", module.get());
    BasicBlock *entry = BasicBlock::Create(*context, "entry", mainFunc);

    Builder.SetInsertPoint(entry);

    return mainFunc;
}

std::unique_ptr<orc::LLJIT> createJIT() {
    Expected<std::unique_ptr<orc::LLJIT> > jit = orc::LLJITBuilder().create();
    if (!jit) {
        errs() << "Failed to create JIT: " << toString(jit.takeError()) << "\n";
        return nullptr;
    }

    return std::move(*jit);
}

#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Transforms/IPO/GlobalDCE.h"
#include "llvm/Transforms/IPO/DeadArgumentElimination.h"

void optimize() {
    PassBuilder passBuilder;

    ModuleAnalysisManager mam;
    passBuilder.registerModuleAnalyses(mam);

    ModulePassManager modulePassManager;

    modulePassManager.addPass(GlobalDCEPass());
    modulePassManager.addPass(DeadArgumentEliminationPass());

    modulePassManager.run(*module, mam);
}

// Здесь будет пока что только свертка констант
void bytecode_optimize(){
    bool flag;
    do {
        auto array_size = bc::bytecode.size();
        flag = false;
        for (int i = 0; i < array_size; i++){
            if (bc::bytecode[i].op == bc::OP::DOBAV) {
                if (bc::bytecode[i-1].op == bc::OP::GRUZY_POSTOYANNUYU && bc::bytecode[i-2].op == bc::OP::GRUZY_POSTOYANNUYU) {
                    bc::bytecode[i-2].op = bc::OP::GRUZY_POSTOYANNUYU;
                    bc::bytecode[i-2].operand = bc::bytecode[i-2].operand + bc::bytecode[i-1].operand;
                    bc::bytecode.erase(bc::bytecode.begin() + i - 1, bc:: bytecode.cbegin() + i + 1);
                    i -=2;
                    array_size-=2;
                    flag = true;
                }
            }
            if (bc::bytecode[i].op == bc::OP::VICHTY) {
                if (bc::bytecode[i-1].op == bc::OP::GRUZY_POSTOYANNUYU && bc::bytecode[i-2].op == bc::OP::GRUZY_POSTOYANNUYU) {
                    bc::bytecode[i-2].op = bc::OP::GRUZY_POSTOYANNUYU;
                    bc::bytecode[i-2].operand = bc::bytecode[i-1].operand -bc::bytecode[i-2].operand;
                    bc::bytecode.erase(bc::bytecode.begin() + i - 1, bc:: bytecode.cbegin() + i + 1);
                    i -=2;
                    array_size-=2;
                    flag = true;
                }
            }
            if (bc::bytecode[i].op == bc::OP::UMNOZH) {
                if (bc::bytecode[i-1].op == bc::OP::GRUZY_POSTOYANNUYU && bc::bytecode[i-2].op == bc::OP::GRUZY_POSTOYANNUYU) {
                    bc::bytecode[i-2].op = bc::OP::GRUZY_POSTOYANNUYU;
                    bc::bytecode[i-2].operand = bc::bytecode[i-2].operand * bc::bytecode[i-1].operand;
                    bc::bytecode.erase(bc::bytecode.begin() + i - 1, bc:: bytecode.cbegin() + i + 1);
                    i -=2;
                    array_size-=2;
                    flag = true;
                }
            }
            if (bc::bytecode[i].op == bc::OP::DELY) {
                if (bc::bytecode[i-1].op == bc::OP::GRUZY_POSTOYANNUYU && bc::bytecode[i-2].op == bc::OP::GRUZY_POSTOYANNUYU) {
                    bc::bytecode[i-2].op = bc::OP::GRUZY_POSTOYANNUYU;
                    bc::bytecode[i-2].operand = bc::bytecode[i-1].operand.sdiv(bc::bytecode[i-2].operand);
                    bc::bytecode.erase(bc::bytecode.begin() + i - 1, bc:: bytecode.cbegin() + i + 1);
                    i -=2;
                    array_size-=2;
                    flag = true;
                }
            }
        }
    } while (flag);
}

int main(int argc, char *argv[]) {
    GC_INIT()

    const auto input_file = read_file_name(argc, argv);
    const auto interpreter_or_compile = interpret_or_compile(argc, argv);

    const auto input = read_file(input_file);

    auto AST = build_ast(input);
    if (AST == nullptr) {
        Logger::error("Error. AST build failure.");
        return 1;
    }

    if (interpreter_or_compile == "-I"){
        AST->generate_bytecode();
        //bc::print_bytecode();
        //std::cout << "---ABOBA---" << std::endl;
        bytecode_optimize();
        // bc::print_bytecode();
        auto* virtualMachine = new vm::VirtualMachine();
        virtualMachine->execute(bc::bytecode);
        return 0;
    }
    else if (interpreter_or_compile == "-C"){
        create_main_function();

        try {
            module->setDataLayout("e-m:w-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128");
            AST->Codegen();
        } catch (const CodegenException &e) {
            Logger::error(e.what());
            module->print(outs(), nullptr);
            return 1;
        }

        Builder.CreateRetVoid();

        if (verifyModule(*module, &errs())) {
            module->print(llvm::outs(), nullptr);
            Logger::error("Error. Module verification failed.");
            return 1;
        }

        // Оптимизации
        //module->print(outs(), nullptr);
        optimize();
        //module->print(errs(), nullptr);

        InitializeNativeTarget();
        InitializeNativeTargetAsmPrinter();
        InitializeNativeTargetAsmParser();

        auto jitOrError = createJIT();

        auto jit = std::move(jitOrError);

        orc::ThreadSafeModule tsm(std::move(module), std::move(context));

        if (auto err = jit->addIRModule(std::move(tsm))) {
            errs() << "Failed to add module to JIT: " << toString(std::move(err)) << "\n";
            return 1;
        }

        auto symbolOrError = jit->lookup("main");
        if (!symbolOrError) {
            errs() << "Failed to find symbol '" << "main" << "': " << toString(symbolOrError.takeError()) << "\n";
            return 1;
        }

        const auto functionPointer = symbolOrError->getValue();
        const auto function = reinterpret_cast<int (*)()>(functionPointer);

        function();

        return 0;
    }
    else {
        throw UnknownExecutionTypeException("Unknown execution type flag");
    }
}
