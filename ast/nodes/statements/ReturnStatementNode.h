#pragma once

#include "StatementNode.h"
#include "../ExpressionNode.h"

class ReturnStatementNode : public StatementNode {
public:
    Ptr<ExpressionNode> expression;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "RETURN" << std::endl;
        expression->print(indent + 1);
    }
};