#pragma once
#include "LiteralNode.h"

class BoolLiteralNode : public LiteralNode {
public:
    bool value;
    BoolLiteralNode() {
        type = VariableType::BOOL;
    }
    void print(const int indent) override {
        std::cout << (value ? "TRUE" : "FALSE");
    }
};