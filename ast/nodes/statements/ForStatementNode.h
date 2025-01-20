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
        // TODO Возможно стоит как то помечать, что это начало цикла FOR?
        init->generate_bytecode();

        int for_start = bc::LABEL_COUNT;
        int for_end = bc::LABEL_COUNT + 1;
        bc::LABEL_COUNT += 2;

        bc::bytecode.emplace_back(bc::OP::METKA, llvm::APInt(128, for_start));
        condition->generate_bytecode();

        bc::bytecode.emplace_back(bc::OP::PRIGAY_ESLI_NEPRAVDA, llvm::APInt(128, for_end));

        body->generate_bytecode();

        step->generate_bytecode();
        bc::bytecode.emplace_back(bc::OP::PRIGAY, llvm::APInt(128, for_start));

        bc::bytecode.emplace_back(bc::OP::METKA, llvm::APInt(128, for_end));
    }
};
