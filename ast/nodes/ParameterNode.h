#pragma once

#include "Nodes.h"

class ParameterNode : public ASTNode<ParameterNode> {
public:
  std::string name;
  std::string type;

};