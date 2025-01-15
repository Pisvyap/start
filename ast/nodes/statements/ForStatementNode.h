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
};
