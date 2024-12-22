#pragma once
#include "ExpressionNode.h"

class IdentifierNode : public ExpressionNode {
public:
    std::string name;
    void print(const int indent) override {
        std::cout << name;
    }

    void semantic_check(SemanticTable& table) override {
        Symbol* decl = table.lookup(name);
        if (decl == nullptr)
            throw std::runtime_error("Identifier '" + name + "' does not exist");

        this->type = decl->type;
    }

    llvm::Value *Codegen() override;
};