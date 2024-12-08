#pragma once

#include "../../ASTNode.h"

class ExpressionNode : public ASTNode {
public:
    void print(const int indent) override {
        std::cout << "EXPR";
    }
};
