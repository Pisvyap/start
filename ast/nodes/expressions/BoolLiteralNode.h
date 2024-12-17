#pragma once
#include "LiteralNode.h"

class BoolLiteralNode : public LiteralNode {
public:
    bool value;

    BoolLiteralNode(const std::string& value) {
        this->value = value == "pravda";
        this->type = BOOL;

        this->bool_value = this->value;
        this->int_value = this->value ? 1 : 0;
    }
    void print(const int indent) override {
        std::cout << (value ? "TRUE" : "FALSE");
    }
};