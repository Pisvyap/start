#pragma once

#include "Nodes.h"

class ExpressionNode : public ASTNode<ExpressionNode> {};

class AssignmentNode : public ASTNode<AssignmentNode> {
public:
    std::string name;
    std::string type;
    ASTNode::Ptr value; // TODO replace with concrete type?
};

class BinaryOperationNode : public ASTNode<BinaryOperationNode> {
public:
    enum BinaryOperationType {
        Add, Sub, Mul, Div, Mod
    };
    BinaryOperationType operation;
    ExpressionNode::Ptr left;
    ExpressionNode::Ptr right;
};
