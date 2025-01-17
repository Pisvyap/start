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
        // Для начала выполняем условие
        condition->generate_bytecode();

        // В случае false переход.
        bc::bytecode.emplace_back(bc::OP::JUMP_IF_FALSE, bc::LABEL_COUNT);

        // Теперь тело true и переход к выходу из if
        thenBlock->generate_bytecode();
        bc::bytecode.emplace_back(bc::OP::JUMP, bc::LABEL_COUNT + 1);

        // Генерируем метку для false (И увеличиваем счетчик меток)
        bc::bytecode.emplace_back(bc::OP::LABEL, bc::LABEL_COUNT++);

        // Теперь тело false
        elseBlock->generate_bytecode();

        // Метка выхода из if
        bc::bytecode.emplace_back(bc::OP::LABEL, bc::LABEL_COUNT++);
    }
};
