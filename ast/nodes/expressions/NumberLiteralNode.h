#pragma once
#include <bemapiset.h>

#include "LiteralNode.h"

class NumberLiteralNode : public LiteralNode {
public:
    int value;
    NumberLiteralNode() {
        type = VariableType::INT;
    }
    void print(const int indent) override {
        std::cout << value;
    }
};