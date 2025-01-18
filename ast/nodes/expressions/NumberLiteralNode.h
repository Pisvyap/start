#pragma once

#include "LiteralNode.h"

class NumberLiteralNode : public LiteralNode {
public:
    uint64_t value; //А че тут 64?

    NumberLiteralNode(const std::string& value) {
        this->value = std::stoi(value);
        this->type = Type(INT);

        this->int_value = this->value;
        this->bool_value = this->value != 0;
    }
    void print(const int indent) override {
        std::cout << value;
    }

    void generate_bytecode() override {
        bc::bytecode.emplace_back(bc::LOAD_CONST, llvm::APInt(128, this->value));
    }

    llvm::Value *Codegen() override;
};