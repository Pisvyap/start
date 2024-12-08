#pragma once
#include "ExpressionNode.h"

class LiteralNode : public ExpressionNode {
public:
    enum VariableType {
        INT, BOOL
    };
    VariableType type;
    void print(const int indent) override {
        std::cout << (type == VariableType::INT ? "INT" : "BOOL");
    }
};