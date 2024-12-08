#pragma once

#include "../../ASTNode.h"

class ExpressionNode : public ASTNode {
public:
    void print(const int indent) override {
        std::cout << "EXPR";
    }
};

class AssignmentNode : public ASTNode {
public:
    std::string name;
    std::string type;
    Ptr<ASTNode> value; // TODO replace with concrete type?
};

class BinaryOperationNode : public ASTNode {
public:
    enum BinaryOperationType {
        Add, Sub, Mul, Div, Mod
    };
    BinaryOperationType operation;
    Ptr<ExpressionNode> left;
    Ptr<ExpressionNode> right;
};
