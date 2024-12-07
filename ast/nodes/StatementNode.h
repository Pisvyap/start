#pragma once

#include "../ASTNode.h"
#include "Nodes.h"

class StatementNode : public ASTNode {
};

class VariableDeclarationNode : public StatementNode {
public:
    std::string name;
    std::string type;
    Ptr<ExpressionNode> initializer;
};