#pragma once
#include "ExpressionNode.h"

// Это когда указываем число или true/false
class LiteralNode : public ExpressionNode {
public:
    int int_value;
    bool bool_value;

    void print(const int indent) override {
        std::cout << type.type;
    }

    llvm::Value *Codegen() override { return nullptr; }
};