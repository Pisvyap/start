#pragma once

#include "../ASTNode.h"
#include "Nodes.h"

class StatementNode : public ASTNode<StatementNode> {
};

class VariableDeclarationNode : public StatementNode {
public:
    std::string name;
    std::string type;
    ExpressionNode::Ptr initializer;
};