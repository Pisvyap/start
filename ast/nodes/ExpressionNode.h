#pragma once

#include "Nodes.h"

class ExpressionNode : public ASTNode {
public:
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
