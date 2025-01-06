#include <iostream>
#include <typlypParser.h>
#include <llvm/Target/TargetMachine.h>

#include "antlr4-runtime.h"
#include "ast/ASTBuilder.h"
#include "ast/ASTNode.h"
#include "grammar/typlypLexer.h"

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/FileSystem.h"
#include "ast/nodes/expressions/UnaryOperationNode.h"

#include "utils/utils.h"

using namespace llvm;

constexpr Logger logger;
LLVMContext context;
auto module = std::make_unique<Module>("MyModule", context); // LLVM-конструкция, содержит все функции/глобалы в куске кода
IRBuilder Builder(context);                          // вспомогательный объект, помогает генерировать инструкции LLVM
std::map<std::string, AllocaInst*> NamedValues;         // таблица символов

// Ноды EXPRESSIONS

Value* NumberLiteralNode::Codegen() {
    ConstantInt* constVal = ConstantInt::get(
        context,
        APInt(128, value, true)
    );

    return constVal;
}

Value* BoolLiteralNode::Codegen() {
    ConstantInt* constVal = ConstantInt::get(
        context,
        APInt(1, value, true)
    );

    return constVal;
}

Value* BinaryOperationNode::Codegen() {
    Value* L = left->Codegen();
    Value* R = right->Codegen();

    // по идее когда все на исключениях, эта проверка не нужна
    // if (!L || !R)
        // return nullptr;

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

Value* UnaryOperationNode::Codegen() {
    switch (operation) {
        case NOT: {
            Value* result = Builder.CreateNot(expression->Codegen(), "not_result");
            return result;
        }
        default:
            throw CodegenException("Unsupported operation in UnaryOperationNode::Codegen");
    }
}

Value* IdentifierNode::Codegen() {
    auto it = NamedValues.find(name);
    if (it == NamedValues.end())
        throw CodegenException("Identifier not found: " + name);

    return Builder.CreateLoad(
        it->second->getAllocatedType(),
        it->second,
        name.c_str());
}

Value* ArrayIndexExpressionNode::Codegen() {
    Value* idxPtr = index->Codegen();

    auto it = NamedValues.find(name);
    if (it == NamedValues.end())
        throw CodegenException("Array not found: " + name);

    Value* arrayPtr = it->second;
    Value* idx128 = Builder.CreateSExt(idxPtr, llvm::Type::getInt128Ty(context), "index128");
    llvm::Type* elementType = arrayPtr->getType()->getArrayElementType();

    Value* elementPtr = Builder.CreateGEP(elementType, arrayPtr,
                                                {
                                                    ConstantInt::get(llvm::Type::getInt64Ty(context), 0),
                                                    idx128
                                                }, "elementptr");

    Value* loadedValue = Builder.CreateLoad(elementType, elementPtr, "loadedval");

    return loadedValue;
}

Value* NewExpressionNode::Codegen() {
    Value* sizeExpr = expression->Codegen();
    llvm::Type* sizeType = llvm::Type::getInt128Ty(context);
    Value* size128 = Builder.CreateZExtOrTrunc(sizeExpr, sizeType);

    auto* mallocFn = llvm::cast<Function>(
        module->getOrInsertFunction(
            "malloc",
            FunctionType::get(
                PointerType::getUnqual(llvm::Type::getInt8Ty(context)),
                {sizeType},
                false)
        ).getCallee()
    );

    Value* allocatedMemory = Builder.CreateCall(mallocFn, {size128});
    llvm::Type* ptrType = PointerType::getUnqual(llvm::Type::getInt8Ty(context));
    Value* castedPtr = Builder.CreateBitCast(allocatedMemory, ptrType);
    return castedPtr;
}

Value* FunctionCallExpressionNode::Codegen() {
    auto it = NamedValues.find(name);
    if (it == NamedValues.end())
        throw CodegenException("Function not found: " + name);

    Function* func = it->second->getFunction();
    std::vector<Value*> argv;
    for (const auto& arg: arguments) {
        Value* argV = arg->Codegen();
        argv.push_back(argV);
    }
    // TODO void появился, надо переделать
    Value* res = Builder.CreateCall(func, argv); //Как я понял void у нас нет, поэтому пока так
    return res;
}

// Ноды STATEMENTS
Value* ArrayAssigmentNode::Codegen() {
    Value* idxPtr = index->Codegen();
    Value* valPtr = value->Codegen();
    auto it = NamedValues.find(name);

    if (it == NamedValues.end())
        throw CodegenException("Array not found: " + name);

    Value* arrayPtr = it->second;
    llvm::Type* elementType = arrayPtr->getType()->getArrayElementType();
    Value* idx64 = Builder.CreateSExt(idxPtr, llvm::Type::getInt64Ty(context), "index64");
    Value* elementPtr = Builder.CreateGEP(elementType,
                                                arrayPtr,
                                                {
                                                    llvm::ConstantInt::get(llvm::Type::getInt64Ty(context), 0),
                                                    idx64
                                                },
                                                "elementptr");
    Builder.CreateStore(valPtr, elementPtr);
    return elementPtr;
}

Value* AssigmentStatementNode::Codegen() {
    Value* valPtr = value->Codegen();

    auto it = NamedValues.find(name);
    if (it == NamedValues.end())
        throw CodegenException("Variable not found: " + name);

    Value* varPtr = it->second;
    Builder.CreateStore(valPtr, varPtr);
    return nullptr;
}

Value* ExpressionStatementNode::Codegen() {
    BasicBlock* currentBlock = Builder.GetInsertBlock();

    if (!currentBlock)
        throw CodegenException("No insertion point set in the builder");

    Value* exprValue = expression->Codegen();

    if (!exprValue)
        throw CodegenException("Failed to generate code for expression");

    return exprValue;
}

Value* ForStatementNode::Codegen() {
    //Очень надо будет чекать
    BasicBlock* initBB = BasicBlock::Create(context, "for.init");
    Builder.CreateBr(initBB);
    Builder.SetInsertPoint(initBB);
    init->Codegen();
    Function* TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock* condBB = BasicBlock::Create(context, "for.cond", TheFunction);
    BasicBlock* bodyBB = BasicBlock::Create(context, "for.body", TheFunction);
    BasicBlock* stepBB = BasicBlock::Create(context, "for.step", TheFunction);
    BasicBlock* afterBB = BasicBlock::Create(context, "for.after", TheFunction);

    Builder.CreateBr(condBB);
    Value* condVal = condition->Codegen();
    Builder.CreateCondBr(condVal, bodyBB, afterBB);
    Builder.SetInsertPoint(bodyBB);
    body->Codegen();

    Builder.CreateBr(stepBB);
    Builder.SetInsertPoint(stepBB);
    step->Codegen();
    Builder.CreateBr(condBB);
    Builder.SetInsertPoint(afterBB);
    return ConstantInt::get(llvm::Type::getInt128Ty(context), 0);
}

Value* IfStatementNode::Codegen() {
    //Очень надо будет чекать
    Value* condVal = condition->Codegen();
    if (!condVal)
        throw CodegenException("Failed to generate condition for if statement");

    condVal = Builder.CreateICmpNE(
        condVal,
        ConstantInt::get(condVal->getType(), 0),
        "ifcond"
    );

    Function* TheFunction = Builder.GetInsertBlock()->getParent();

    BasicBlock* thenBB = BasicBlock::Create(context, "if.then", TheFunction);
    BasicBlock* elseBB = BasicBlock::Create(context, "if.else");
    BasicBlock* mergeBB = BasicBlock::Create(context, "if.merge");

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

    return ConstantInt::get(llvm::Type::getInt128Ty(context), 0);
}

Value* ReturnStatementNode::Codegen() {
    Value* retVal = expression ? expression->Codegen() : nullptr;
    if (retVal == nullptr) {
        throw CodegenException("Return statement not found");
    }

    Builder.CreateRet(retVal);
    return retVal;
}

Value* VariableDeclarationNode::Codegen() {
    llvm::Type* varType;
    if (type.type == INT) {
        if (type.is_array)
            varType = ArrayType::get(llvm::Type::getInt128Ty(context), type.array_size);
        else
            varType = llvm::Type::getInt128Ty(context);
    } else if (type.type == BOOL) {
        if (type.is_array)
            varType = ArrayType::get(llvm::Type::getInt1Ty(context), type.array_size);
        else
            varType = llvm::Type::getInt1Ty(context);
    } else {
        throw CodegenException("Unknown type: " + to_string(type.type));
    }

    Value* initVal = initializer ? initializer->Codegen() : Constant::getNullValue(varType);
    AllocaInst* alloc = Builder.CreateAlloca(varType, nullptr, name);
    Builder.CreateStore(initVal, alloc);
    NamedValues[name] = alloc;
    return alloc;
}

Value* WhileStatementNode::Codegen() {
    //Очень надо будет чекать
    Function* TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock* condBB = BasicBlock::Create(context, "while.cond", TheFunction);
    BasicBlock* bodyBB = BasicBlock::Create(context, "while.body", TheFunction);
    BasicBlock* afterBB = BasicBlock::Create(context, "while.after", TheFunction);

    Builder.CreateBr(condBB);
    Builder.SetInsertPoint(condBB);
    Value* condVal = condition->Codegen();

    Builder.CreateCondBr(condVal, bodyBB, afterBB);
    Builder.SetInsertPoint(bodyBB);
    body->Codegen();
    Builder.CreateBr(condBB);
    Builder.SetInsertPoint(afterBB);

    return ConstantInt::get(llvm::Type::getInt128Ty(context), 0);
}

// Ноды остальные
Value* CodeBlockNode::Codegen() {
    for (auto& statement: statements)
        statement->Codegen();

    return llvm::Constant::getNullValue(llvm::Type::getInt32Ty(context));
}

Value* ExternalFunctionNode::Codegen() {
    llvm::Type* llvmReturnType = nullptr;
    if (returnType.is_array) {
        if (returnType.type == INT) {
            llvmReturnType = PointerType::get(llvm::Type::getInt128Ty(context), 0);
        } else if (returnType.type == BOOL) {
            llvmReturnType = PointerType::get(llvm::Type::getInt1Ty(context), 0);
        }
    } else {
        llvmReturnType = returnType.type == INT
                             ? llvm::Type::getInt128Ty(context)
                             : llvm::Type::getInt1Ty(context);
    }

    // Определяем типы параметров
    std::vector<llvm::Type*> paramTypes;
    for (const auto& param: parameters) {
        llvm::Type* paramType = nullptr;
        if (param->type.is_array) {
            paramType = PointerType::get(
                param->type.type == INT and param->type.is_array
                    ? llvm::Type::getInt128Ty(context)
                    : llvm::Type::getInt1Ty(context),
                0);
        } else {
            paramType = param->type.type == INT
                            ? llvm::Type::getInt128Ty(context)
                            : llvm::Type::getInt1Ty(context);
        }
        paramTypes.push_back(paramType);
    }

    // Создаем тип функции
    FunctionType* funcType = FunctionType::get(llvmReturnType, paramTypes, false);

    // Объявляем внешнюю функцию
    Function* function = Function::Create(
        funcType,
        Function::ExternalLinkage, // External linkage означает, что функция определена вне текущего модуля
        name,
        module.get()
    );

    return function;
}

Value* FunctionNode::Codegen() {
    llvm::Type* llvmReturnType = nullptr;

    if (returnType.is_array)
        throw CodegenException("Error. Functions cannot return arrays");

    if (returnType.type == INT)
        llvmReturnType = llvm::Type::getInt128Ty(context);
    else if (returnType.type == BOOL) {
        llvmReturnType = llvm::Type::getInt1Ty(context);
    } else {
        throw CodegenException("Unknown return type: " + to_string(returnType.type));
    }

    // Определяем типы параметров
    std::vector<llvm::Type*> paramTypes;
    for (const auto& param : parameters) {
        llvm::Type* paramType = nullptr;
        if (param->type.is_array && param->type.type == INT) {
            paramType = PointerType::get(llvm::Type::getInt128Ty(context), 0);
        } else if (param->type.is_array && param->type.type == BOOL) {
            paramType = PointerType::get(llvm::Type::getInt1Ty(context), 0);
        } else if (param->type.type == INT)
            paramType = llvm::Type::getInt128Ty(context);
        else if (param->type.type == BOOL) {
            paramType = llvm::Type::getInt1Ty(context);
        } else {
            throw CodegenException("Unknown parameter type: " + to_string(param->type.type));
        }
        paramTypes.push_back(paramType);
    }

    // Создаем тип функции
    FunctionType* funcType = FunctionType::get(llvmReturnType, paramTypes, false);

    // Создаем функцию в модуле
    Function* function = Function::Create(
        funcType,
        Function::InternalLinkage, // ExternalLinkage, если функция вызывается извне
        name,
        module.get()
    );

    // Сохраняем текущую точку вставки
    llvm::BasicBlock* originalInsertBlock = Builder.GetInsertBlock();

    // Переходим в тело функции
    BasicBlock* entryBlock = BasicBlock::Create(context, "entry", function);
    Builder.SetInsertPoint(entryBlock);

    // Устанавливаем имена параметров и добавляем их в таблицу переменных
    NamedValues.clear();
    auto paramIt = function->arg_begin();
    for (const auto& param : parameters) {
        Argument& llvmArg = *paramIt++;
        llvmArg.setName(param->name);
        IRBuilder<> tempBuilder(&function->getEntryBlock(), function->getEntryBlock().begin());
        AllocaInst* alloca = tempBuilder.CreateAlloca(llvmArg.getType(), nullptr, param->name);
        Builder.CreateStore(&llvmArg, alloca);
        NamedValues[param->name] = alloca;
    }

    // Генерируем код для тела функции
    Value* bodyValue = body->Codegen();
    if (!bodyValue) {
        throw CodegenException("Error while generating function body");
    }

    // Если тело не заканчивается возвратом, добавляем возврат значения по умолчанию
    if (function->doesNotReturn()) {
        if (returnType.type == INT) {
            Builder.CreateRet(ConstantInt::get(context, llvm::APInt(128, 0)));
        } else {
            Builder.CreateRet(ConstantInt::get(context, llvm::APInt(1, 0)));
        }
    }

    // Проверяем корректность функции
    if (verifyFunction(*function, &llvm::errs())) {
        throw CodegenException("Error: Function " + name + " contains errors!");
    }

    // Восстанавливаем точку вставки
    Builder.SetInsertPoint(originalInsertBlock);

    return function;
}
Value* ParameterNode::Codegen() {
    Value* paramValue = NamedValues[name];
    if (type.is_array) {
        if (type.array_size <= 0)
            throw CodegenException("Error: array " + name + " has invalid size: " + to_string(type.array_size));

        return paramValue;
    }

    if (type.type == INT or type.type == BOOL) {
        return paramValue;
    }

    throw CodegenException("Unknown parameter type: " + to_string(type.type));
}


Value* ProgramNode::Codegen() {
    for (auto& extFunc: externalFunctions) {
        extFunc->Codegen();
    }
    for (auto& func: functions) {
        func->Codegen();
    }
    for (auto& stmt: statements) {
        stmt->Codegen();
    }

    return llvm::Constant::getNullValue(llvm::Type::getInt32Ty(context));
}


Ptr<ProgramNode> build_ast(const std::string& code) {
    // Создание ANTLR потока
    antlr4::ANTLRInputStream inputStream(code);
    auto lexer = typlypLexer(&inputStream);
    antlr4::CommonTokenStream tokenStream(&lexer);
    auto parser = typlypParser(&tokenStream);

    // Дерево разбора
    auto tree = parser.program();

    // Строим AST
    ASTBuilder builder;
    Ptr<ProgramNode> ast;
    try {
        auto ast_any = builder.visitProgram(tree);
        ast = std::any_cast<Ptr<ProgramNode> >(ast_any);
        ast->print(0);

        SemanticTable table;
        ast->semantic_check(table);

        return ast;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return nullptr;
    }
}

Function* create_main_function() {
    FunctionType* funcType = FunctionType::get(llvm::Type::getVoidTy(context), false);
    Function* mainFunc = Function::Create(funcType, Function::ExternalLinkage, "main", module.get());
    BasicBlock* entry = BasicBlock::Create(context, "entry", mainFunc);

    Builder.SetInsertPoint(entry);

    return mainFunc;
}

int main() {
    logger.info("Hello, World!");
    const std::string input = readFile("test.typlyp");

    auto AST = build_ast(input);

    Function* mainFunc = create_main_function();

    if (AST == nullptr) {
        logger.error("Error. AST build failure.");
        return 1;
    }

    try {
        AST->Codegen();
    } catch (const CodegenException& e) {
        logger.error(e.what());
        module->print(llvm::outs(), nullptr);
        return 1;
    }

    Builder.CreateRetVoid();

    if (verifyModule(*module, &errs())) {
        logger.error("Error. Module verification failed.");
        return 1;
    }
    logger.info("module verification successful.");

    // Сохранение IR в файл
    std::error_code EC;
    raw_fd_ostream outFile("output.ll", EC, llvm::sys::fs::OF_None);
    if (EC) {
        logger.error("Could not open output file: ", EC.message());
        return 1;
    }

    module->print(outFile, nullptr);
    outFile.close();
    logger.info("LLVM IR written to output.ll");

    return 0;

    // JIT-исполнение
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();
    InitializeNativeTargetAsmParser();

    std::string errorStr;
    ExecutionEngine* engine = EngineBuilder(std::move(module))
            .setErrorStr(&errorStr)
            .setOptLevel(CodeGenOptLevel::Default)
            .setEngineKind(EngineKind::JIT)
            .create();

    if (!engine) {
        logger.error("Failed to create ExecutionEngine: ", errorStr);
        return 1;
    }

    // Выполнение main
    auto mainFuncEng = engine->FindFunctionNamed("main");
    if (!mainFunc) {
        logger.error("Failed to find main function in ExecutionEngine");
        return 1;
    }

    auto mainEngPtr = (int (*)()) engine->getPointerToFunction(mainFuncEng);
    int result = mainEngPtr();
    logger.info("Program exited with code: ", result);

    return 0;
}
