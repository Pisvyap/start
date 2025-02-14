#pragma once
#include "ExpressionNode.h"

class IdentifierNode : public ExpressionNode {
public:
    std::string name;
    bool is_function;

    void print(const int indent) override {
        std::cout << name;
    }

    void semantic_check(SemanticTable& table) override {
        Symbol* decl = table.lookup(name);
        if (decl == nullptr)
            throw std::runtime_error("Identifier '" + name + "' does not exist");

        this->type = decl->type;
        this->is_function = decl->isFunction;
    }

    void generate_bytecode() override {
        if (is_function)
            bc::bytecode.emplace_back(bc::OP::ZOVY, this->name);
        else
            bc::bytecode.emplace_back(bc::OP::GRUZY_PEREMENNUYU, this->name);
    }

    llvm::Value *Codegen() override;
};