#pragma once
#include "LiteralNode.h"

class BoolLiteralNode : public LiteralNode {
public:
    bool value;

    BoolLiteralNode(const std::string& value) {
        this->value = (value == "pravda");
        this->type = Type(BOOL);

        this->bool_value = this->value;
        this->int_value = this->value ? 1 : 0;
    }
    void print(const int indent) override {
        std::cout << (value ? "TRUE" : "FALSE");
    }

    void generate_bytecode() override {
        // Пока что булевые переменные через 0 или 1, хз норм ли будет дальше так
        bc::bytecode.emplace_back(bc::OP::LOAD_CONST, this->int_value);
    }

    llvm::Value *Codegen() override;
};