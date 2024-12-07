#pragma once

#include <vector>

#include "../ASTNode.h"
#include "Nodes.h"

class FunctionNode : public ASTNode {
public:
    std::string name;
    std::vector<Ptr<ParameterNode>> parameters; // pair<name, parameter>
    std::string returnType;
    Ptr<CodeBlockNode> body;
};
