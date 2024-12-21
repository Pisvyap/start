#pragma once
#include "StatementNode.h"
#include "../expressions/ExpressionNode.h"

class ExpressionStatementNode : public StatementNode {
public:
    Ptr<ExpressionNode> expression;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "ExpressionStatement ";
        expression->print(indent + 1);
    }

    void semantic_check(SemanticTable& table) override {
        expression->semantic_check(table);
    }
};
