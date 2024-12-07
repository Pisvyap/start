#pragma once

#include "Nodes.h"

class ParameterNode : public ASTNode {
public:
  std::string name;
  std::string type;
};