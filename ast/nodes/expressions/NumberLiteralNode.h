#pragma once

#include "LiteralNode.h"

// TODO use 128bit integers
class NumberLiteralNode : public LiteralNode {
public:
    int value;

    NumberLiteralNode(const std::string& value) {
        this->value = std::stoi(value);
        this->type = Type(INT);

        this->int_value = this->value;
        this->bool_value = this->value != 0;
    }
    void print(const int indent) override {
        std::cout << value;
    }

    llvm::Value *Codegen() override;
};