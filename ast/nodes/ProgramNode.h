#pragma once
#include "../ASTNode.h"
#include "Nodes.h"

class ProgramNode : ASTNode<ProgramNode> {
public:
    std::vector<FunctionNode::Ptr> functions;
    std::vector<StatementNode::Ptr> statements;
};
