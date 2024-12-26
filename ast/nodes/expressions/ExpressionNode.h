#pragma once

#include "../../ASTNode.h"

class ExpressionNode : public ASTNode {
public:
    Type type;

    explicit ExpressionNode(const Type& type) : type(type) { }

    ExpressionNode() : type(Type(INT, 0)) { }

    explicit ExpressionNode(const std::string& type) : type(map_type(type)) { }

    void print(const int indent) override {
        std::cout << "EXPR";
    }

    llvm::Value *Codegen() override { return nullptr; }
};
