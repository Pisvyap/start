#pragma once
#include "ExpressionNode.h"

class ArrayIndexExpression : public ExpressionNode {
public:
    std::string arrayName;
    Ptr<ExpressionNode> index;
    void print(const int indent) override {
        std::cout << arrayName << '['; index->print(indent); std::cout << ']';
    }
};