#include <iostream>
#include <fstream>
#include <iterator>
#include <typlypParser.h>

#include "antlr4-runtime.h"
#include "ast/ASTBuilder.h"
#include "ast/ASTNode.h"
#include "grammar/typlypLexer.h"

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/MCJIT.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/FileSystem.h"
#include "ast/nodes/expressions/UnaryOperationNode.h"

std::string readFile(const std::string& fileName) {
    const std::string path = "../scratches/" + fileName;

    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "File " << path << " does not exist" << std::endl;
        return std::string();
    }

    std::string contents(std::istreambuf_iterator<char>{file}, {});
    file.close();

    return contents;
}

using namespace llvm;

static LLVMContext context;
static llvm::Module* module = new llvm::Module("MyModule", context); //LLVM-конструкция, содержит все функции/глобалы в куске кода
static IRBuilder<> Builder(context); //вспомогательный объект, помогает генерировать инструкции LLVM
static std::map<std::string, llvm::AllocaInst*> NamedValues; //таблица символов

// Ноды EXPRESSIONS

Value *NumberLiteralNode::Codegen() {
    ConstantInt* constVal = ConstantInt::get(
            context,
            llvm::APInt(128, value, true)
    );

    return constVal;
}

Value *BoolLiteralNode::Codegen() {
    llvm::ConstantInt* constVal = llvm::ConstantInt::get(
            context,
            llvm::APInt(1, value, true)
    );

    return constVal;
}

Value* BinaryOperationNode::Codegen() {
    Value* L = left->Codegen();
    Value* R = right->Codegen();
    if (!L || !R)
        return nullptr;
    switch (operation) {
        case BinaryOperationType::Add:
            return Builder.CreateAdd(L, R, "addtmp");
        case BinaryOperationType::Sub:
            return Builder.CreateSub(L, R, "subtmp");
        case BinaryOperationType::Mul:
            return Builder.CreateMul(L, R, "multmp");
        case BinaryOperationType::Div:
            return Builder.CreateSDiv(L, R, "divtmp");
        case BinaryOperationType::Mod:
            return Builder.CreateSRem(L, R, "modtmp");
        case BinaryOperationType::LT:
            return Builder.CreateICmpSLT(L, R, "lttmp");
        case BinaryOperationType::LE:
            return Builder.CreateICmpSLE(L, R, "letmp");
        case BinaryOperationType::GT:
            return Builder.CreateICmpSGT(L, R, "gttmp");
        case BinaryOperationType::GE:
            return Builder.CreateICmpSGE(L, R, "getmp");
        case BinaryOperationType::EQ:
            return Builder.CreateICmpEQ(L, R, "eqtmp");
        case BinaryOperationType::NE:
            return Builder.CreateICmpNE(L, R, "netmp");
    }
}

Value* UnaryOperationNode::Codegen() {
    switch (operation) {
        case NOT: {
            llvm::Value* result = Builder.CreateNot(expression->Codegen(), "not_result");
            return result;
        }
        default:
            return nullptr;
    }
}

Value* IdentifierNode::Codegen() {
    auto it = NamedValues.find(name);
    if (it != NamedValues.end()) {

        return Builder.CreateLoad(
                it->second->getAllocatedType(),
                it->second,
                name.c_str());
    }
    return nullptr;
}

Value* ArrayIndexExpressionNode::Codegen() {
    llvm::Value* idxPtr = index->Codegen();
    auto it = NamedValues.find(name);
    if (it != NamedValues.end()) {
        llvm::Value* arrayPtr = it->second;
        llvm::Value* idx128 = Builder.CreateSExt(idxPtr, llvm::Type::getInt128Ty(context), "index128");
        llvm::Type* elementType = arrayPtr->getType()->getArrayElementType();

        llvm::Value* elementPtr = Builder.CreateGEP(elementType, arrayPtr,
                                                    { llvm::ConstantInt::get(llvm::Type::getInt64Ty(context), 0), idx128 }, "elementptr");

        llvm::Value* loadedValue = Builder.CreateLoad(elementType, elementPtr, "loadedval");

        return loadedValue;
    }
    return nullptr;
}

Value* NewExpressionNode::Codegen() {
    llvm::Value* sizeExpr = expression->Codegen();
    llvm::Type* sizeType = llvm::Type::getInt128Ty(context);
    llvm::Value* size128 = Builder.CreateZExtOrTrunc(sizeExpr, sizeType);


    auto* mallocFn = llvm::cast<llvm::Function>(
            module->getOrInsertFunction(
                    "malloc",
                    llvm::FunctionType::get(
                            llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(context)),
                            {sizeType},
                            false)
            ).getCallee()
    );

    llvm::Value* allocatedMemory = Builder.CreateCall(mallocFn, {size128});
    llvm::Type* ptrType = llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(context));
    llvm::Value* castedPtr = Builder.CreateBitCast(allocatedMemory, ptrType);
    return castedPtr;
}

Value* FunctionCallExpressionNode::Codegen() {
    auto it = NamedValues.find(name);
    llvm::Function* func = it->second->getFunction();
    std::vector<llvm::Value*> argv;
    for (const auto& arg : arguments) {
        llvm::Value* argV = arg->Codegen();
        argv.push_back(argV);
    }
    llvm::Value* res = Builder.CreateCall(func, argv); //Как я понял void у нас нет, поэтому пока так
    return res;
}

// Ноды STATEMENTS

Value* ArrayAssigmentNode::Codegen() {
    llvm::Value* idxPtr = index->Codegen();
    llvm::Value* valPtr = value->Codegen();
    auto it = NamedValues.find(name);
    llvm::Value* arrayPtr = it->second;
    llvm::Type* elementType = arrayPtr->getType()->getArrayElementType();
    llvm::Value* idx64 = Builder.CreateSExt(idxPtr, llvm::Type::getInt64Ty(context), "index64");
    llvm::Value* elementPtr = Builder.CreateGEP(elementType,
                                                arrayPtr,
                                                {llvm::ConstantInt::get(llvm::Type::getInt64Ty(context),0),
                                                 idx64},
                                                "elementptr");
    Builder.CreateStore(valPtr, elementPtr);
    return nullptr;
}

Value* AssigmentStatementNode::Codegen() {
    llvm::Value* valPtr = value->Codegen();
    auto it = NamedValues.find(name);
    if (it == NamedValues.end()) {
        return nullptr;
    }
    llvm::Value* varPtr = it->second;
    Builder.CreateStore(valPtr, varPtr);
    return nullptr;
}

Value* ExpressionStatementNode::Codegen() {
    llvm::BasicBlock* currentBlock = Builder.GetInsertBlock();
    if (!currentBlock) {
        llvm::errs() << "Error: No insertion point set in the builder\n";
        return nullptr;
    }

    llvm::Value* exprValue = expression->Codegen();
    if (!exprValue) {
        llvm::errs() << "Error: failed to generate code for expression\n";
        return nullptr;
    }

    return exprValue;
}

Value* ForStatementNode::Codegen() { //Очень надо будет чекать
    BasicBlock *initBB = BasicBlock::Create(context, "for.init");
    Builder.CreateBr(initBB);
    Builder.SetInsertPoint(initBB);
    init->Codegen();
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *condBB = BasicBlock::Create(context, "for.cond", TheFunction);
    BasicBlock *bodyBB = BasicBlock::Create(context, "for.body", TheFunction);
    BasicBlock *stepBB = BasicBlock::Create(context, "for.step", TheFunction);
    BasicBlock *afterBB = BasicBlock::Create(context, "for.after", TheFunction);

    Builder.CreateBr(condBB);
    Value *condVal = condition->Codegen();
    Builder.CreateCondBr(condVal, bodyBB, afterBB);
    Builder.SetInsertPoint(bodyBB);
    body->Codegen();

    Builder.CreateBr(stepBB);
    Builder.SetInsertPoint(stepBB);
    step->Codegen();
    Builder.CreateBr(condBB);
    Builder.SetInsertPoint(afterBB);
    return ConstantInt::get(llvm::Type::getInt32Ty(context), 0);
}

Value* IfStatementNode::Codegen() { //Очень надо будет чекать
    llvm::Value* condVal = condition->Codegen();
    if (!condVal) {
        llvm::errs() << "Error: failed to generate condition for if statement\n";
        return nullptr;
    }

    condVal = Builder.CreateICmpNE(
            condVal,
            llvm::ConstantInt::get(condVal->getType(), 0),
            "ifcond"
    );

    llvm::Function* TheFunction = Builder.GetInsertBlock()->getParent();

    llvm::BasicBlock* thenBB = llvm::BasicBlock::Create(context, "if.then", TheFunction);
    llvm::BasicBlock* elseBB = llvm::BasicBlock::Create(context, "if.else");
    llvm::BasicBlock* mergeBB = llvm::BasicBlock::Create(context, "if.merge");

    Builder.CreateCondBr(condVal, thenBB, elseBB);

    Builder.SetInsertPoint(thenBB);
    if (thenBlock) {
        if (!thenBlock->Codegen()) {
            llvm::errs() << "Error: failed to generate code for then block\n";
            return nullptr;
        }
    }
    Builder.CreateBr(mergeBB);

    elseBB->insertInto(TheFunction);
    Builder.SetInsertPoint(elseBB);
    if (elseBlock) {
        if (!elseBlock->Codegen()) {
            llvm::errs() << "Error: failed to generate code for else block\n";
            return nullptr;
        }
    }
    Builder.CreateBr(mergeBB);

    mergeBB->insertInto(TheFunction);
    Builder.SetInsertPoint(mergeBB);

    return llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 0);
}

Value* ReturnStatementNode::Codegen() {
    Value* retVal = expression ? expression->Codegen() : nullptr;
    Builder.CreateRet(retVal);
    return nullptr;
}

Value* VariableDeclarationNode::Codegen() {
    llvm::Type* varType;
    if (type.type == INT)
        varType = llvm::Type::getInt128Ty(context);
    else if(type.type == BOOL)
        varType = llvm::Type::getInt1Ty(context);
    else if (type.type == INT_ARRAY)
        varType = llvm::ArrayType::get(llvm::Type::getInt128Ty(context), type.array_size);
    else if (type.type == BOOL_ARRAY)
        varType = llvm::ArrayType::get(llvm::Type::getInt1Ty(context), type.array_size);
    else {
        llvm::errs() << "Unknown type: " << type.type << "\n";
        return nullptr;
    }
    Value* initVal = initializer ? initializer->Codegen() : Constant::getNullValue(varType);
    AllocaInst* alloc = Builder.CreateAlloca(varType, nullptr, name);
    Builder.CreateStore(initVal, alloc);
    NamedValues[name] = alloc;
    return nullptr;
}

Value* WhileStatementNode::Codegen()  { //Очень надо будет чекать
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *condBB = BasicBlock::Create(context, "while.cond", TheFunction);
    BasicBlock *bodyBB = BasicBlock::Create(context, "while.body", TheFunction);
    BasicBlock *afterBB = BasicBlock::Create(context, "while.after", TheFunction);

    Builder.CreateBr(condBB);
    Builder.SetInsertPoint(condBB);
    Value *condVal = condition->Codegen();

    Builder.CreateCondBr(condVal, bodyBB, afterBB);
    Builder.SetInsertPoint(bodyBB);
    body->Codegen();
    Builder.CreateBr(condBB);
    Builder.SetInsertPoint(afterBB);

    return ConstantInt::get(llvm::Type::getInt32Ty(context), 0);
}

// Ноды остальные

Value *CodeBlockNode::Codegen() {
    for (auto &statement : statements) {
        Value* result = statement->Codegen();
    }
    return nullptr;
}

llvm::Value *ExternalFunctionNode::Codegen() {
    llvm::Type *llvmReturnType = nullptr;
    if (returnType.is_array()) {
        if (returnType.type == INT_ARRAY) {
            llvmReturnType = llvm::PointerType::get(llvm::Type::getInt32Ty(context), 0);
        } else if (returnType.type == BOOL_ARRAY) {
            llvmReturnType = llvm::PointerType::get(llvm::Type::getInt1Ty(context), 0);
        }
    } else {
        llvmReturnType = (returnType.type == INT)
                         ? llvm::Type::getInt32Ty(context)
                         : llvm::Type::getInt1Ty(context);
    }

    // Определяем типы параметров
    std::vector<llvm::Type *> paramTypes;
    for (const auto &param : parameters) {
        llvm::Type *paramType = nullptr;
        if (param->type.is_array()) {
            paramType = llvm::PointerType::get(
                    (param->type.type == INT_ARRAY ? llvm::Type::getInt32Ty(context)
                                                   : llvm::Type::getInt1Ty(context)),
                    0);
        } else {
            paramType = (param->type.type == INT)
                        ? llvm::Type::getInt32Ty(context)
                        : llvm::Type::getInt1Ty(context);
        }
        paramTypes.push_back(paramType);
    }

    // Создаем тип функции
    llvm::FunctionType *funcType = llvm::FunctionType::get(llvmReturnType, paramTypes, false);

    // Объявляем внешнюю функцию
    llvm::Function *function = llvm::Function::Create(
            funcType,
            llvm::Function::ExternalLinkage, // External linkage означает, что функция определена вне текущего модуля
            name,
            module
    );

    return function;
}

llvm::Value *FunctionNode::Codegen() {
    llvm::Type *llvmReturnType = nullptr;
    switch (returnType.type) {
        case INT:
            llvmReturnType = llvm::Type::getInt32Ty(context);
            break;
        case BOOL:
            llvmReturnType = llvm::Type::getInt1Ty(context);
            break;
        case INT_ARRAY:
        case BOOL_ARRAY:
            std::cerr << "Ошибка: функции не могут возвращать массивы" << std::endl;
            return nullptr;
        default:
            std::cerr << "Неизвестный тип возвращаемого значения: " << returnType.type << std::endl;
            return nullptr;
    }

    // Определяем типы параметров
    std::vector<llvm::Type *> paramTypes;
    for (const auto &param : parameters) {
        llvm::Type *paramType = nullptr;
        switch (param->type.type) {
            case INT:
                paramType = llvm::Type::getInt32Ty(context);
                break;
            case BOOL:
                paramType = llvm::Type::getInt1Ty(context);
                break;
            case INT_ARRAY:
                paramType = llvm::PointerType::get(llvm::Type::getInt32Ty(context), 0);
                break;
            case BOOL_ARRAY:
                paramType = llvm::PointerType::get(llvm::Type::getInt1Ty(context), 0);
                break;
            default:
                std::cerr << "Неизвестный тип параметра: " << param->type.type << std::endl;
                return nullptr;
        }
        paramTypes.push_back(paramType);
    }

    // Создаем тип функции
    llvm::FunctionType *funcType = llvm::FunctionType::get(llvmReturnType, paramTypes, false);

    // Создаем функцию в модуле
    llvm::Function *function = llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        name,
        module
    );

    // Переходим в тело функции
    llvm::BasicBlock *entryBlock = llvm::BasicBlock::Create(context, "entry", function);
    Builder.SetInsertPoint(entryBlock);

    // Устанавливаем имена параметров и добавляем их в таблицу переменных
    NamedValues.clear(); // Сбрасываем текущую таблицу переменных
    auto paramIt = function->arg_begin();
    for (const auto &param : parameters) {
        llvm::Argument &llvmArg = *paramIt++;
        llvmArg.setName(param->name);
        llvm::IRBuilder<> tempBuilder(&function->getEntryBlock(), function->getEntryBlock().begin());
        llvm::AllocaInst *alloca = tempBuilder.CreateAlloca(llvmArg.getType(), nullptr, param->name);
        Builder.CreateStore(&llvmArg, alloca);
        NamedValues[param->name] = alloca;
    }

    // Генерируем код для тела функции
    llvm::Value *bodyValue = body->Codegen();
    if (!bodyValue) {
        std::cerr << "Ошибка генерации кода для тела функции " << name << std::endl;
        function->eraseFromParent();
        return nullptr;
    }

    // Если тело не заканчивается возвратом, добавляем возврат значения по умолчанию
    if (returnType.type == INT) {
        Builder.CreateRet(llvm::ConstantInt::get(context, llvm::APInt(32, 0)));
    } else if (returnType.type == BOOL) {
        Builder.CreateRet(llvm::ConstantInt::get(context, llvm::APInt(1, 0)));
    }

//    // Проверяем корректность функции
//    if (llvm::verifyFunction(*function, &llvm::errs())) {
//        std::cerr << "Ошибка: в функции " << name << " обнаружены ошибки!" << std::endl;
//        function->eraseFromParent();
//        return nullptr;
//    }

    return function;
}

llvm::Value *ParameterNode::Codegen() {
    llvm::Value *paramValue = NamedValues[name];
    switch (type.type) {
        case INT:
        case BOOL:
            return paramValue;
        case INT_ARRAY:
        case BOOL_ARRAY:
            if (type.array_size <= 0) {
                std::cerr << "Ошибка: массив " << name << " имеет некорректный размер: "
                          << type.array_size << std::endl; // Или че у нас там за костыль с <-1>?
                return nullptr;
            }
            return paramValue;

        default:
            std::cerr << "Неизвестный тип параметра: " << static_cast<int>(type.type) << std::endl;
            return nullptr;
    }
}


llvm::Value *ProgramNode::Codegen() {
    for (auto &extFunc: externalFunctions) {
        extFunc->Codegen();
    }
    for (auto &func: functions) {
        func->Codegen();
    }
    for (auto &stmt: statements) {
        stmt->Codegen();
    }
    return nullptr;
}


int main() {
    const std::string input = readFile("test.typlyp");

    // Создание ANTLR потока
    antlr4::ANTLRInputStream inputStream(input);
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
        ast = std::any_cast<Ptr<ProgramNode>>(ast_any);
        ast->print(0);

        SemanticTable table;
        ast->semantic_check(table);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // 6. Генерация LLVM IR с помощью Codegen каждой ноды
    try {
        llvm::FunctionType *mainType = llvm::FunctionType::get(llvm::Type::getInt32Ty(context), false);
        llvm::Function *mainFunc = llvm::Function::Create(mainType, llvm::Function::ExternalLinkage, "main", module);

        llvm::BasicBlock *entry = llvm::BasicBlock::Create(context, "entry", mainFunc);
        Builder.SetInsertPoint(entry);

        // Генерация кода для AST
        llvm::Value *result = ast->Codegen();

        // Возврат результата из main
        Builder.CreateRet(result);

    } catch (const std::exception& e) {
        std::cerr << "Error during Codegen: " << e.what() << std::endl;
        return 1;
    }

    // 7. Сохранение IR в файл
    std::error_code EC;
    llvm::raw_fd_ostream outFile("output.ll", EC, llvm::sys::fs::OF_None);
    if (EC) {
        std::cerr << "Could not open output file: " << EC.message() << std::endl;
        return 1;
    }
    module->print(outFile, nullptr);
    outFile.close();
    std::cout << "LLVM IR written to output.ll" << std::endl;

    // 8. JIT-исполнение
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();

    std::string errorStr;
    llvm::ExecutionEngine *engine = llvm::EngineBuilder(static_cast<std::unique_ptr<Module>>(module))
            .setErrorStr(&errorStr)
            .setOptLevel(llvm::CodeGenOptLevel::Default)
            .create();

    if (!engine) {
        std::cerr << "Failed to create ExecutionEngine: " << errorStr << std::endl;
        return 1;
    }

    // Выполнение main
    auto mainFunc = engine->FindFunctionNamed("main");
    if (!mainFunc) {
        std::cerr << "No main function found in generated code" << std::endl;
        return 1;
    }

    auto mainPtr = (int (*)())engine->getPointerToFunction(mainFunc);
    int result = mainPtr();
    std::cout << "Program exited with code: " << result << std::endl;

    return 0;
}
