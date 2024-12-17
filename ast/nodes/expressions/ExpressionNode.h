#pragma once

#include "../../ASTNode.h"

class ExpressionNode : public ASTNode {
public:
    Type type;

    explicit ExpressionNode(const Type type) : type(type) { }

    ExpressionNode() : type(INT) { }

    explicit ExpressionNode(const std::string& type) {
        this->type = map_type(type);
    }

    void print(const int indent) override {
        std::cout << "EXPR";
    }
};
