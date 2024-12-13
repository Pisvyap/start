#pragma once
#include "ExpressionNode.h"

class NewExpression : public ExpressionNode {
public:
    std::string type;
    Ptr<ExpressionNode> expression;
    void print(const int indent) override {
        std::cout << "new " << type << " of size "; expression->print(indent);
    }
};