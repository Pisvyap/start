#pragma once
#include "LiteralNode.h"

class BoolLiteralNode : public LiteralNode {
public:
    bool value;

    BoolLiteralNode(const std::string& value) {
        this->value = (value == "da");
        this->type = Type(BOOL);

        this->bool_value = this->value;
        this->int_value = this->value ? 1 : 0;
    }
    void print(const int indent) override {
        std::cout << (value ? "TRUE" : "FALSE");
    }

    void generate_bytecode() override {
        bc::bytecode.emplace_back(bc::OP::GRUZY_POSTOYANNUYU, llvm::APInt(1, this->int_value));
    }

    llvm::Value *Codegen() override;
};