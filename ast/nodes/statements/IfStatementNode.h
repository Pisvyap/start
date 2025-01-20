#pragma once

#include "StatementNode.h"
#include "../CodeBlockNode.h"
#include "../expressions/ExpressionNode.h"

class IfStatementNode : public StatementNode {
public:
    Ptr<ExpressionNode> condition;
    Ptr<CodeBlockNode> thenBlock;
    Ptr<CodeBlockNode> elseBlock;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "IF "; condition->print(indent); std::cout << std::endl;

        ASTNode::print(indent);
        std::cout << "THEN" << std::endl;
        thenBlock->print(indent + 1);

        if (elseBlock != nullptr) {
            ASTNode::print(indent);
            std::cout << "ELSE" << std::endl;
            elseBlock->print(indent + 1);
        }
    }

    void semantic_check(SemanticTable& table) override {
        condition->semantic_check(table);
        if (condition->type != BOOL)
            throw std::runtime_error("Type mismatch. Expected 'logika' int IF statement");

        // Обрабатываем THEN ветку
        table.enterScope();
        thenBlock->semantic_check(table);
        table.leaveScope();

        // Обрабатываем ELSE ветку
        if (elseBlock != nullptr) {
            table.enterScope();
            elseBlock->semantic_check(table);
            table.leaveScope();
        }
    }

    llvm::Value *Codegen() override;

    void generate_bytecode() override {
        condition->generate_bytecode();

        int false_label = bc::LABEL_COUNT;
        int end_label = bc::LABEL_COUNT + 1;
        bc::LABEL_COUNT += 2;

        bc::bytecode.emplace_back(bc::OP::JUMP_IF_FALSE, llvm::APInt(128, false_label));

        thenBlock->generate_bytecode();
        bc::bytecode.emplace_back(bc::OP::JUMP, llvm::APInt(128, end_label));

        bc::bytecode.emplace_back(bc::OP::LABEL, llvm::APInt(128, false_label));

        if (elseBlock != nullptr) {
            elseBlock->generate_bytecode();
        }

        bc::bytecode.emplace_back(bc::OP::LABEL, llvm::APInt(128, end_label));
    }
};
