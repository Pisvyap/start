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
#include "llvm/ExecutionEngine/Orc/LLJIT.h"

#include "utils/utils.h"

using namespace llvm;

constexpr Logger logger;
auto context = std::make_unique<LLVMContext>();
auto module = std::make_unique<Module>("MyModule", *context); // LLVM-конструкция, содержит все функции/глобалы в куске кода
IRBuilder Builder(*context);                          // вспомогательный объект, помогает генерировать инструкции LLVM
std::map<std::string, AllocaInst*> NamedValues;         // таблица символов
std::map<std::string, Function*> Functions;

// Ноды EXPRESSIONS

Value* NumberLiteralNode::Codegen() {
    ConstantInt* constVal = ConstantInt::get(
        *context,
        APInt(128, value, true)
    );

    return constVal;
}

Value* BoolLiteralNode::Codegen() {
    ConstantInt* constVal = ConstantInt::get(
        *context,
        APInt(1, value, true)
    );

    return constVal;
}

Value* BinaryOperationNode::Codegen() {
    Value* L = left->Codegen();
    Value* R = right->Codegen();

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

llvm::Value* ArrayIndexExpressionNode::Codegen() {
    // Проверяем, существует ли массив с таким именем
    AllocaInst* arrayAlloc = NamedValues[name];
    if (!arrayAlloc)
        throw CodegenException("Array '" + name + "' was not declared");

    // Генерация кода для индекса
    llvm::Value* indexValue = index->Codegen();
    if (!indexValue->getType()->isIntegerTy())
        throw CodegenException("Array index must be of integer type");

    // Приведение индекса к `i32`, если он не соответствует
    llvm::Type* indexType = llvm::Type::getInt32Ty(*context);
    if (indexValue->getType() != indexType) {
        indexValue = Builder.CreateIntCast(indexValue, indexType, true, "indexCast");
    }

    // Получение указателя на элемент массива
    llvm::Value* elementPtr = Builder.CreateGEP(
            arrayAlloc->getAllocatedType(), // Тип массива
            arrayAlloc,                     // Указатель на массив
            {Builder.getInt32(0), indexValue}, // Индекс
            name + "_element_ptr"           // Имя (опционально)
    );

    // Получение типа элемента массива
    llvm::Type* elementType = arrayAlloc->getAllocatedType()->getArrayElementType();

    // Загрузка значения элемента массива
    llvm::Value* elementValue = Builder.CreateLoad(
            elementType, // Тип элемента массива
            elementPtr,  // Указатель
            name + "_element_value" // Имя для отладочной информации
    );

    return elementValue; // Возвращаем значение элемента
}



Value* NewExpressionNode::Codegen() {
    // Генерируем код для выражения, которое задает размер массива
    Value* sizeExpr = expression->Codegen();
    llvm::Type* sizeType = llvm::Type::getInt128Ty(*context);
    Value* size128 = Builder.CreateZExtOrTrunc(sizeExpr, sizeType);

    auto* constantSize = llvm::dyn_cast<ConstantInt>(size128);
    if (!constantSize) {
        throw CodegenException("Array size must be a constant value for stack allocation.");
    }

    uint64_t arraySize = constantSize->getZExtValue();
    llvm::Type* elementType;

    // Определяем тип элемента массива
    if (type.type == BOOL) {
        elementType = llvm::Type::getInt1Ty(*context);
    } else if (type.type == INT) {
        elementType = llvm::Type::getInt128Ty(*context); // chislo
    } else {
        throw CodegenException("Unsupported array type in NewExpressionNode.");
    }

    llvm::ArrayType* arrayType = llvm::ArrayType::get(elementType, arraySize);
    AllocaInst* alloc = Builder.CreateAlloca(arrayType, nullptr, "array_alloc");
    alloc->setAlignment(Align(16));

    return alloc;
}



Value* FunctionCallExpressionNode::Codegen() {
    auto it = Functions.find(name);

    if (it == Functions.end())
        throw CodegenException("Function not found: " + name);

    Function* func = it->second;
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
llvm::Value* ArrayAssigmentNode::Codegen() {
    // Проверяем, существует ли массив с таким именем
    AllocaInst* arrayAlloc = NamedValues[name];
    if (!arrayAlloc)
        throw CodegenException("Array '" + name + "' was not declared");

    // Генерация кода для вычисления индекса
    llvm::Value* indexValue = index->Codegen();
    if (!indexValue->getType()->isIntegerTy())
        throw CodegenException("Array index must be of integer type");

    // Приведение индекса к необходимому типу, если требуется
    llvm::Type* indexType = llvm::Type::getInt32Ty(*context);
    if (indexValue->getType() != indexType) {
        indexValue = Builder.CreateIntCast(indexValue, indexType, true, "indexCast");
    }

    // Получение указателя на элемент массива
    llvm::Value* elementPtr = Builder.CreateGEP(
            arrayAlloc->getAllocatedType(), // Тип массива
            arrayAlloc,                     // Указатель на массив
            {Builder.getInt32(0), indexValue}, // Индекс
            name + "_element_ptr"           // Имя (опционально)
    );

    // Генерация кода для значения, которое будет записано
    llvm::Value* valueToStore = value->Codegen();

    // Проверка типа: должны быть совместимы типы элемента массива и значения
    llvm::Type* elementType = arrayAlloc->getAllocatedType()->getArrayElementType();
    if (valueToStore->getType() != elementType) {
        throw CodegenException("Type mismatch: cannot assign value to array element");
    }

    // Создаем инструкцию записи (store)
    Builder.CreateStore(valueToStore, elementPtr);

    return valueToStore;
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
    // Очень надо будет чекать
    // TODO в этом блоке аллокация - она кидает ошибку т.к. инструкция alloc может быть только в начальной функции, но не в условных блоках
    // TODO пока что так костыльно работает, если все-таки будет вылетать ошибка из-за этого - переделаем
    // BasicBlock* initBB = BasicBlock::Create(*context, "for.init");
    // Builder.CreateBr(initBB);
    // Builder.SetInsertPoint(initBB);

    init->Codegen();
    Function* TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock* condBB = BasicBlock::Create(*context, "for.cond", TheFunction);
    BasicBlock* bodyBB = BasicBlock::Create(*context, "for.body", TheFunction);
    BasicBlock* stepBB = BasicBlock::Create(*context, "for.step", TheFunction);
    BasicBlock* afterBB = BasicBlock::Create(*context, "for.after", TheFunction);

    Builder.CreateBr(condBB);
    Builder.SetInsertPoint(condBB);
    Value* condVal = condition->Codegen();
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

    BasicBlock* thenBB = BasicBlock::Create(*context, "if.then", TheFunction);
    BasicBlock* elseBB = BasicBlock::Create(*context, "if.else");
    BasicBlock* mergeBB = BasicBlock::Create(*context, "if.merge");

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

    Value* initVal = nullptr;

    if (initializer) {
        initVal = initializer->Codegen();

        // Если это массив, инициализатор уже содержит правильный alloca
        if (type.is_array && llvm::isa<AllocaInst>(initVal)) {
            NamedValues[name] = llvm::cast<AllocaInst>(initVal);
            return initVal;
        }
    }

    // Если инициализатор отсутствует, создаем новую alloca
    if (!initVal) {
        initVal = Constant::getNullValue(varType);
    }
    // TODO Делаем аллокацию без првоерки ее места(можно только в начале функции).
    // TODO Сделать переключение на начало функции -> аллоцировать память -> вернуться к блоку с которым работали
    AllocaInst* alloc = Builder.CreateAlloca(varType, nullptr, name);
    alloc->setAlignment(Align(16));
    Builder.CreateStore(initVal, alloc);

    NamedValues[name] = alloc;
    return alloc;
}


Value* WhileStatementNode::Codegen() {
    //Очень надо будет чекать
    Function* TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock* condBB = BasicBlock::Create(*context, "while.cond", TheFunction);
    BasicBlock* bodyBB = BasicBlock::Create(*context, "while.body", TheFunction);
    BasicBlock* afterBB = BasicBlock::Create(*context, "while.after", TheFunction);

    Builder.CreateBr(condBB);
    Builder.SetInsertPoint(condBB);
    Value* condVal = condition->Codegen();
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

Value* PrintStatementNode::Codegen() {
    Function* printfFunc = module->getFunction("printf");
    if (!printfFunc) {

        FunctionType* printfType = FunctionType::get(
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


    Value* value = expression->Codegen();
    if (!value) {
        throw CodegenException("Codegen for expression in PrintStatementNode failed");
    }


    llvm::Type* valueType = value->getType();

    if (valueType->isIntegerTy(128)) {

        Value* lowPart = Builder.CreateTrunc(value, llvm::Type::getInt64Ty(*context), "lowPart");
        Value* highPart = Builder.CreateLShr(value, llvm::ConstantInt::get(valueType, 64));
        highPart = Builder.CreateTrunc(highPart, llvm::Type::getInt64Ty(*context), "highPart");

        Constant* singlePartFormatConst = ConstantDataArray::getString(*context, "%llu\n");
        auto singlePartFormatVar = new GlobalVariable(
            *module,
            singlePartFormatConst->getType(),
            true,
            GlobalValue::PrivateLinkage,
            singlePartFormatConst,
            ".strSinglePart"
        );

        Constant* dualPartFormatConst = ConstantDataArray::getString(*context, "%llu%llu\n");
        auto* dualPartFormatVar = new GlobalVariable(
            *module,
            dualPartFormatConst->getType(),
            true,
            GlobalValue::PrivateLinkage,
            dualPartFormatConst,
            ".strDualPart"
        );

        Value* singlePartFormatPtr = Builder.CreateInBoundsGEP(
            singlePartFormatVar->getValueType(),
            singlePartFormatVar,
            { ConstantInt::get(llvm::Type::getInt32Ty(*context), 0),
              ConstantInt::get(llvm::Type::getInt32Ty(*context), 0) }
        );

        Value* dualPartFormatPtr = Builder.CreateInBoundsGEP(
            dualPartFormatVar->getValueType(),
            dualPartFormatVar,
            { ConstantInt::get(llvm::Type::getInt32Ty(*context), 0),
              ConstantInt::get(llvm::Type::getInt32Ty(*context), 0) }
        );

        Value* isHighZero = Builder.CreateICmpEQ(highPart, ConstantInt::get(llvm::Type::getInt64Ty(*context), 0));

        Function* parentFunction = Builder.GetInsertBlock()->getParent();
        BasicBlock* printLowPartBlock = BasicBlock::Create(*context, "printLowPart", parentFunction);
        BasicBlock* printDualPartBlock = BasicBlock::Create(*context, "printDualPart", parentFunction);
        BasicBlock* afterPrintBlock = BasicBlock::Create(*context, "afterPrint", parentFunction);

        Builder.CreateCondBr(isHighZero, printLowPartBlock, printDualPartBlock);

        Builder.SetInsertPoint(printLowPartBlock);
        Builder.CreateCall(printfFunc, { singlePartFormatPtr, lowPart });
        Builder.CreateBr(afterPrintBlock);

        Builder.SetInsertPoint(printDualPartBlock);
        Builder.CreateCall(printfFunc, { dualPartFormatPtr, highPart, lowPart });
        Builder.CreateBr(afterPrintBlock);

        Builder.SetInsertPoint(afterPrintBlock);
    }
    else if (valueType->isIntegerTy()) {
        Value* formatStrPtr = nullptr;

        Constant* formatStrConst = ConstantDataArray::getString(*context, "%d\n");
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
            { ConstantInt::get(llvm::Type::getInt32Ty(*context), 0),
              ConstantInt::get(llvm::Type::getInt32Ty(*context), 0) }
        );

        Builder.CreateCall(printfFunc, { formatStrPtr, value });
    } else {
        throw std::runtime_error("Unsupported type for PrintStatementNode");
    }

    return nullptr;
}


// Ноды остальные
Value* CodeBlockNode::Codegen() {
    for (auto& statement: statements)
        statement->Codegen();

    return llvm::Constant::getNullValue(llvm::Type::getInt32Ty(*context));
}

Value* FunctionNode::Codegen() {
    llvm::Type* llvmReturnType = nullptr;

    if (returnType.is_array)
        throw CodegenException("Error. Functions cannot return arrays");

    if (returnType.type == INT)
        llvmReturnType = llvm::Type::getInt128Ty(*context);
    else if (returnType.type == BOOL) {
        llvmReturnType = llvm::Type::getInt1Ty(*context);
    } else {
        throw CodegenException("Unknown return type: " + to_string(returnType.type));
    }

    // Определяем типы параметров
    std::vector<llvm::Type*> paramTypes;
    for (const auto& param : parameters) {
        llvm::Type* paramType = nullptr;
        if (param->type.is_array && param->type.type == INT) {
            paramType = PointerType::get(llvm::Type::getInt128Ty(*context), 0);
        } else if (param->type.is_array && param->type.type == BOOL) {
            paramType = PointerType::get(llvm::Type::getInt1Ty(*context), 0);
        } else if (param->type.type == INT)
            paramType = llvm::Type::getInt128Ty(*context);
        else if (param->type.type == BOOL) {
            paramType = llvm::Type::getInt1Ty(*context);
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

    Functions[name] = function;

    // Сохраняем текущую точку вставки
    llvm::BasicBlock* originalInsertBlock = Builder.GetInsertBlock();

    // Переходим в тело функции
    BasicBlock* entryBlock = BasicBlock::Create(*context, "entry", function);
    Builder.SetInsertPoint(entryBlock);

    // Устанавливаем имена параметров и добавляем их в таблицу переменных
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
            Builder.CreateRet(ConstantInt::get(*context, llvm::APInt(128, 0)));
        } else {
            Builder.CreateRet(ConstantInt::get(*context, llvm::APInt(1, 0)));
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
    for (auto& func: functions) {
        func->Codegen();
    }
    for (auto& stmt: statements) {
        stmt->Codegen();
    }

    return Constant::getNullValue(llvm::Type::getInt32Ty(*context));
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
    try {
        Ptr<ProgramNode> ast;
        ASTBuilder builder;
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
    FunctionType* funcType = FunctionType::get(llvm::Type::getVoidTy(*context), false);
    Function* mainFunc = Function::Create(funcType, Function::ExternalLinkage, "main", module.get());
    BasicBlock* entry = BasicBlock::Create(*context, "entry", mainFunc);

    Builder.SetInsertPoint(entry);

    return mainFunc;
}

std::unique_ptr<orc::LLJIT> createJIT() {
    Expected<std::unique_ptr<orc::LLJIT>> jit = orc::LLJITBuilder().create();
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
void optimize(){
    PassBuilder passBuilder;

    ModuleAnalysisManager mam;
    passBuilder.registerModuleAnalyses(mam);

    ModulePassManager modulePassManager;

    // Удаление глобального dead code и удаление лишних аргументов в функции
    modulePassManager.addPass(GlobalDCEPass());
    modulePassManager.addPass(DeadArgumentEliminationPass());

    modulePassManager.run(*module, mam);
}

int main() {
    const std::string input = readFile("test.typlyp");

    auto AST = build_ast(input);

    create_main_function();

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
        module->print(llvm::outs(), nullptr);
        logger.error("Error. Module verification failed.");
        return 1;
    }
    logger.info("module verification successful.");

    std::error_code EC;
    raw_fd_ostream outFile("output.ll", EC, sys::fs::OF_None);
//    if (EC) {
//        logger.error("Could not open output file: ", EC.message());
//        return 1;
//    }

    module->print(outFile, nullptr);
    outFile.close();
    logger.info("LLVM IR written to output.ll");

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
