#pragma once
#include "ExpressionNode.h"

class IdentifierNode : public ExpressionNode {
public:
    std::string name;
    void print(const int indent) override {
        std::cout << name;
    }
};