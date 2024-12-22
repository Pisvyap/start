#pragma once

#include <map>
#include <vector>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include "nodes/expressions/NumberLiteralNode.h"
#include "nodes/expressions/BinaryOperationNode.h"
#include "nodes/expressions/BoolLiteralNode.h"
#include "nodes/expressions/UnaryOperationNode.h"
#include "nodes/expressions/IdentifierNode.h"
#include "nodes/expressions/ArrayIndexExpressionNode.h"
#include "nodes/expressions/NewExpressionNode.h"
#include "nodes/expressions/FunctionCallExpressionNode.h"
#include "nodes/statements/ArrayAssigmentNode.h"
#include "nodes/statements/AssigmentStatementNode.h"
#include "nodes/statements/ExpressionStatementNode.h"
#include "nodes/statements/ForStatementNode.h"
#include "nodes/statements/IfStatementNode.h"
#include "nodes/statements/ReturnStatementNode.h"
#include "nodes/statements/VariableDecalrationNode.h"
#include "nodes/statements/WhileStatementNode.h"
#include "nodes/CodeBlockNode.h"
#include "nodes/ExternalFunctionNode.h"
#include "nodes/FunctionNode.h"
#include "nodes/ParameterNode.h"
#include "nodes/ProgramNode.h"


using namespace llvm;

// Value *ErrorV(const char *Str) { Error(Str); return 0; } // Обработчик ошибок (у нас вообще он будет???)
// static LLVMContext context;
// static llvm::Module *TheModule; //LLVM-конструкция, содержит все функции/глобалы в куске кода
// static IRBuilder<> Builder(context); //вспомогательный объект, помогает генерировать инструкции LLVM
// static std::map<std::string, llvm::AllocaInst*> NamedValues; //таблица символов

// Ноды EXPRESSIONS

Value *NumberLiteralNode::Codegen() {
    // ConstantInt* constVal = ConstantInt::get(
    //     context,
    //     llvm::APInt(128, value, true)
    // );
    //
    // return constVal;
    return nullptr;
}

Value *BoolLiteralNode::Codegen() {
    // llvm::ConstantInt* constVal = llvm::ConstantInt::get(
    //     context,
    //     llvm::APInt(1, value, true)
    // );
    //
    // return constVal;
    return nullptr;
}

Value* BinaryOperationNode::Codegen() {
    // Value* L = left->Codegen();
    // Value* R = right->Codegen();
    // if (!L || !R)
    //     return nullptr;
    // switch (operation) {
    //     case BinaryOperationType::Add:
    //         return Builder.CreateAdd(L, R, "addtmp");
    //     case BinaryOperationType::Sub:
    //         return Builder.CreateSub(L, R, "subtmp");
    //     case BinaryOperationType::Mul:
    //         return Builder.CreateMul(L, R, "multmp");
    //     case BinaryOperationType::Div:
    //         return Builder.CreateSDiv(L, R, "divtmp");
    //     case BinaryOperationType::Mod:
    //         return Builder.CreateSRem(L, R, "modtmp");
    //     case BinaryOperationType::LT:
    //         return Builder.CreateICmpSLT(L, R, "lttmp");
    //     case BinaryOperationType::LE:
    //         return Builder.CreateICmpSLE(L, R, "letmp");
    //     case BinaryOperationType::GT:
    //         return Builder.CreateICmpSGT(L, R, "gttmp");
    //     case BinaryOperationType::GE:
    //         return Builder.CreateICmpSGE(L, R, "getmp");
    //     case BinaryOperationType::EQ:
    //         return Builder.CreateICmpEQ(L, R, "eqtmp");
    //     case BinaryOperationType::NE:
    //         return Builder.CreateICmpNE(L, R, "netmp");
    // }
    return nullptr;
}

Value* UnaryOperationNode::Codegen() {
    // switch (operation) {
    //     case NOT: {
    //         llvm::Value* result = llvm::BinaryOperator::CreateNot(expression->Codegen(), "not_result");
    //         return result;
    //     }
    //     default:
    //         return nullptr;
    // }
    return nullptr;
}

Value* IdentifierNode::Codegen() {
    // auto it = NamedValues.find(name);
    // if (it != NamedValues.end()) {
    //
    //     return Builder.CreateLoad(
    //         it->second->getAllocatedType(),
    //         it->second,
    //         name.c_str());
    // }
    return nullptr;
}

Value* ArrayIndexExpressionNode::Codegen() {
    // llvm::Value* idxPtr = index->Codegen();
    // auto it = NamedValues.find(name);
    // if (it != NamedValues.end()) {
    //     llvm::Value* arrayPtr = it->second;
    //     llvm::Value* idx128 = Builder.CreateSExt(idxPtr, llvm::Type::getInt128Ty(context), "index128");
    //     llvm::Type* elementType = arrayPtr->getType()->getArrayElementType();
    //
    //     llvm::Value* elementPtr = Builder.CreateGEP(elementType, arrayPtr,
    //         { llvm::ConstantInt::get(llvm::Type::getInt64Ty(context), 0), idx128 }, "elementptr");
    //
    //     llvm::Value* loadedValue = Builder.CreateLoad(elementType, elementPtr, "loadedval");
    //
    //     return loadedValue;
    // }

    return nullptr;
}

Value* NewExpressionNode::Codegen() {
    return nullptr;
    // llvm::Value* sizeExpr = expression->Codegen();
    // llvm::Type* sizeType = llvm::Type::getInt32Ty(context);
    // llvm::Value* size32 = Builder.CreateZExtOrTrunc(sizeExpr, sizeType);
    // llvm::Function* mallocFn = llvm::cast<llvm::Function>(
    //         context.GpModule->getOrInsertFunction(
    //                 "malloc",
    //                 llvm::FunctionType::get(
    //                         llvm::PointerType::getUnqual(
    //                                 llvm::Type::getInt8Ty(context)),
    //                                 {sizeType},
    //                                 false)));
    // llvm::Value* allocatedMemory = Builder.CreateCall(mallocFn, {size32});
    // llvm::Type* ptrType = llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(context));
    // llvm::Value* castedPtr = Builder.CreateBitCast(allocatedMemory, ptrType);
    // return castedPtr;
}

Value* FunctionCallExpressionNode::Codegen() {
    // auto it = NamedValues.find(name);
    // llvm::Function* func = it->second->getFunction();
    // std::vector<llvm::Value*> argv;
    // for (auto arg : arguments) {
    //     llvm::Value* argV = arg->Codegen();
    //     argv.push_back(argV);
    // }
    // llvm::Value* res = Builder.CreateCall(func, argv); //Как я понял void у нас нет, поэтому пока так
    // return res;
    return nullptr;
}

// Ноды STATEMENTS

Value* ArrayAssigmentNode::Codegen() {
    // llvm::Value* idxPtr = index->Codegen();
    // llvm::Value* valPtr = value->Codegen();
    // auto it = NamedValues.find(name);
    // llvm::Value* arrayPtr = it->second;
    // llvm::Type* elementType = arrayPtr->getType()->getArrayElementType();
    // llvm::Value* idx64 = Builder.CreateSExt(idxPtr, llvm::Type::getInt64Ty(context), "index64");
    // llvm::Value* elementPtr = Builder.CreateGEP(elementType,
    //         arrayPtr,
    //         {llvm::ConstantInt::get(llvm::Type::getInt64Ty(context),0),
    //          idx64},
    //          "elementptr");
    // Builder.CreateStore(valPtr, elementPtr);
    return nullptr;
}

Value* AssigmentStatementNode::Codegen() {
    // llvm::Value* valPtr = value->Codegen();
    // auto it = NamedValues.find(name);
    // if (it == NamedValues.end()) {
    //     return nullptr;
    // }
    // llvm::Value* varPtr = it->second;
    // Builder.CreateStore(valPtr, varPtr);
    return nullptr;
}

Value* ExpressionStatementNode::Codegen() {
    // llvm::BasicBlock* currentBlock = Builder.GetInsertBlock();
    // if (!currentBlock) {
    //     llvm::errs() << "Error: No insertion point set in the builder\n";
    //     return nullptr;
    // }
    //
    // llvm::Value* exprValue = expression->Codegen();
    // if (!exprValue) {
    //     llvm::errs() << "Error: failed to generate code for expression\n";
    //     return nullptr;
    // }
    //
    // return exprValue;
    return nullptr;
}

Value* ForStatementNode::Codegen() { //Очень надо будет чекать
    // BasicBlock *initBB = BasicBlock::Create(context, "for.init");
    // Builder.CreateBr(initBB);
    // Builder.SetInsertPoint(initBB);
    // init->Codegen();
    // Function *TheFunction = Builder.GetInsertBlock()->getParent();
    // BasicBlock *condBB = BasicBlock::Create(context, "for.cond", TheFunction);
    // BasicBlock *bodyBB = BasicBlock::Create(context, "for.body", TheFunction);
    // BasicBlock *stepBB = BasicBlock::Create(context, "for.step", TheFunction);
    // BasicBlock *afterBB = BasicBlock::Create(context, "for.after", TheFunction);
    //
    // Builder.CreateBr(condBB);
    // Value *condVal = condition->Codegen();
    // Builder.CreateCondBr(condVal, bodyBB, afterBB);
    // Builder.SetInsertPoint(bodyBB);
    // body->Codegen();
    //
    // Builder.CreateBr(stepBB);
    // Builder.SetInsertPoint(stepBB);
    // step->Codegen();
    // Builder.CreateBr(condBB);
    // Builder.SetInsertPoint(afterBB);
    // return ConstantInt::get(llvm::Type::getInt32Ty(context), 0);
    return nullptr;
}

Value* IfStatementNode::Codegen() { //Очень надо будет чекать
    // llvm::Value* condVal = condition->Codegen();
    // if (!condVal) {
    //     llvm::errs() << "Error: failed to generate condition for if statement\n";
    //     return nullptr;
    // }
    //
    // condVal = Builder.CreateICmpNE(
    //     condVal,
    //     llvm::ConstantInt::get(condVal->getType(), 0),
    //     "ifcond"
    // );
    //
    // llvm::Function* TheFunction = Builder.GetInsertBlock()->getParent();
    //
    // llvm::BasicBlock* thenBB = llvm::BasicBlock::Create(context, "if.then", TheFunction);
    // llvm::BasicBlock* elseBB = llvm::BasicBlock::Create(context, "if.else");
    // llvm::BasicBlock* mergeBB = llvm::BasicBlock::Create(context, "if.merge");
    //
    // Builder.CreateCondBr(condVal, thenBB, elseBB);
    //
    // Builder.SetInsertPoint(thenBB);
    // if (thenBlock) {
    //     if (!thenBlock->Codegen()) {
    //         llvm::errs() << "Error: failed to generate code for then block\n";
    //         return nullptr;
    //     }
    // }
    // Builder.CreateBr(mergeBB);
    //
    // elseBB->insertInto(TheFunction);
    // Builder.SetInsertPoint(elseBB);
    // if (elseBlock) {
    //     if (!elseBlock->Codegen()) {
    //         llvm::errs() << "Error: failed to generate code for else block\n";
    //         return nullptr;
    //     }
    // }
    // Builder.CreateBr(mergeBB);
    //
    // mergeBB->insertInto(TheFunction);
    // Builder.SetInsertPoint(mergeBB);
    //
    // return llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 0);
    return nullptr;
}

Value* ReturnStatementNode::Codegen() {
    // Value* retVal = expression ? expression->Codegen() : nullptr;
    // Builder.CreateRet(retVal);
    return nullptr;
}

Value* VariableDeclarationNode::Codegen() {
    // Type* varType = Type::getTypeByName(type, context);
    // Value* initVal = initializer ? initializer->Codegen() : nullptr;
    // initVal = Constant::getNullValue(varType);
    // AllocaInst* alloc = Builder.CreateAlloca(varType, nullptr, name.c_str());
    // Builder.CreateStore(initVal, alloc);
    // NamedValues[name] = alloc;
    return nullptr;
}

Value* WhileStatementNode::Codegen()  { //Очень надо будет чекать
    // Function *TheFunction = Builder.GetInsertBlock()->getParent();
    // BasicBlock *condBB = BasicBlock::Create(context, "while.cond", TheFunction);
    // BasicBlock *bodyBB = BasicBlock::Create(context, "while.body", TheFunction);
    // BasicBlock *afterBB = BasicBlock::Create(context, "while.after", TheFunction);
    //
    // Builder.CreateBr(condBB);
    // Builder.SetInsertPoint(condBB);
    // Value *condVal = condition->Codegen();
    //
    // Builder.CreateCondBr(condVal, bodyBB, afterBB);
    // Builder.SetInsertPoint(bodyBB);
    // body->Codegen();
    // Builder.CreateBr(condBB);
    // Builder.SetInsertPoint(afterBB);
    //
    // return ConstantInt::get(llvm::Type::getInt32Ty(context), 0);
    return nullptr;
}

// Ноды остальные

Value *CodeBlockNode::Codegen() {
    // for (auto &statement : statements) {
    //     Value* result = statement->Codegen();
    // }
    return nullptr;
}

llvm::Value *ExternalFunctionNode::Codegen() { //Доделать, пока хз как точно
}

llvm::Value *FunctionNode::Codegen() { //Доделать, пока хз как точно

}

llvm::Value *ParameterNode::Codegen() { //Доделать, пока хз как точно
}


llvm::Value *ProgramNode::Codegen() {
    // for (auto &extFunc : externalFunctions) {
    //     extFunc->Codegen();
    // }
    // for (auto &func : functions) {
    //     func->Codegen();
    // }
    // for (auto &stmt : statements) {
    //     stmt->Codegen();
    // }
    return nullptr;
}