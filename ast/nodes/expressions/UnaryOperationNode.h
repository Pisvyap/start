#pragma once

#include "ExpressionNode.h"
#include "../../ASTNode.h"


class UnaryOperationNode : public ExpressionNode {
public:
    enum UnaryOperationType {
        NOT
    };
    UnaryOperationType operation;
    Ptr<ExpressionNode> expression;
    void print(const int indent) override {
        std::cout << operation << ' '; expression->print(indent);
    }
};
