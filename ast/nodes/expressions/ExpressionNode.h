#pragma once

#include "../../ASTNode.h"

class ExpressionNode : public ASTNode {
public:
    TypeStruct type;

    explicit ExpressionNode(const TypeStruct& type) : type(type) { }

    ExpressionNode() : type(TypeStruct(INT, 0)) { }

    explicit ExpressionNode(const std::string& type) : type(map_type(type)) { }

    void print(const int indent) override {
        std::cout << "EXPR";
    }

    llvm::Value *Codegen() override { return nullptr; }
};
