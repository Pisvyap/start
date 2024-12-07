#pragma once

#include <vector>
#include "../ASTNode.h"
#include "Nodes.h"

class ExternalFunctionNode : public ASTNode {
public:
     std::string name;
     std::vector<Ptr<ParameterNode>> parameters;
     std::string returnType;
};