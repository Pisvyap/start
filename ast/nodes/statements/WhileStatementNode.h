#pragma once
#include "../CodeBlockNode.h"
#include "StatementNode.h"

class WhileStatementNode : public StatementNode {
public:
    Ptr<ExpressionNode> condition;
    Ptr<CodeBlockNode> body;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "WHILE ";
        condition->print(indent);
        std::cout << std::endl;
        body->print(indent + 1);
    }

    void semantic_check(SemanticTable& table) override {
        condition->semantic_check(table);
        if (condition->type != BOOL)
            throw std::runtime_error("Expected 'logika' in while condition");

        table.enterScope();
        body->semantic_check(table);
        table.leaveScope();
    }

    llvm::Value *Codegen() override;

    void generate_bytecode() override {
        int while_start = bc::LABEL_COUNT;
        int while_end = bc::LABEL_COUNT + 1;
        bc::LABEL_COUNT += 2;

        // Метка на условие и проверка его
        bc::bytecode.emplace_back(bc::OP::LABEL, while_start);
        condition->generate_bytecode();

        // Переход в случае невыполнения условия
        bc::bytecode.emplace_back(bc::OP::JUMP_IF_FALSE, while_end);

        // Обработка тела цикла (и возврат к проверке условия)
        body->generate_bytecode();
        bc::bytecode.emplace_back(bc::OP::JUMP, while_start);

        // Метка конца цикла
        bc::bytecode.emplace_back(bc::OP::LABEL, while_end);
    }
};