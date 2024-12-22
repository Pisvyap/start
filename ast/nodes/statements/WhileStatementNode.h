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
};