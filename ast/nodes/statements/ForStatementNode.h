#pragma once
#include "StatementNode.h"
#include "VariableDecalrationNode.h"
#include "../CodeBlockNode.h"

class ForStatementNode : public StatementNode {
public:
    Ptr<VariableDeclarationNode> init;
    Ptr<ExpressionNode> condition;
    Ptr<AssigmentStatementNode> step;
    Ptr<CodeBlockNode> body;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "FOR BEGIN\n";
        init->print(indent + 1);
        ASTNode::print(indent + 1);
        condition->print(indent); std::cout << '\n';;
        step->print(indent + 1);
        body->print(indent + 1);
    }

    void semantic_check(SemanticTable& table) override {
        // Заходим внутрь цикла
        table.enterScope();
        init->semantic_check(table);
        condition->semantic_check(table);
        step->semantic_check(table);
        body->semantic_check(table);
        table.leaveScope();
    }

    llvm::Value *Codegen() override;

    void generate_bytecode() override {
        // Генерируем инициализацию
        // TODO Возможно стоит как то помечать, что это начало цикла FOR?
        init->generate_bytecode();

        int for_start = bc::LABEL_COUNT;
        int for_end = bc::LABEL_COUNT + 1;
        bc::LABEL_COUNT += 2;

        // Метка на проверку условий
        bc::bytecode.emplace_back(bc::OP::LABEL, llvm::APInt(128, for_start));
        condition->generate_bytecode();

        // Переход к концу цикла если не выполняется условие
        bc::bytecode.emplace_back(bc::OP::JUMP_IF_FALSE, llvm::APInt(128, for_end));

        // Генерация тела цикла
        body->generate_bytecode();

        // выполнение update и переход к проверке условия
        step->generate_bytecode();
        bc::bytecode.emplace_back(bc::OP::JUMP, llvm::APInt(128, for_start));

        // Метка выхода из цикла
        bc::bytecode.emplace_back(bc::OP::LABEL, llvm::APInt(128, for_end));
    }
};
