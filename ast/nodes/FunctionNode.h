#pragma once

#include "../ASTNode.h"
#include "Nodes.h"

class FunctionNode : public ASTNode<FunctionNode> {
public:
    std::string name;
    // TODO replace with ParameterNode
    std::vector<ParameterNode::Ptr> parameters; // pair<name, parameter>
    std::string returnType;
    CodeBlockNode::Ptr body;
};
