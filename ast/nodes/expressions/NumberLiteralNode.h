#pragma once
#include <bemapiset.h>

#include "LiteralNode.h"

// TODO use 128bit integers
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