#pragma once

#include <vector>
#include "../ASTNode.h"
#include "Nodes.h"

class ExternalFunctionNode : public ASTNode {
public:
     std::string name;
     std::vector<Ptr<ParameterNode>> parameters;
     std::string returnType;
     void print(const int indent) override {
          ASTNode::print(indent);
          printf("ExternalFunction: %s -> %s\n", name.c_str(), returnType.c_str());
          for (auto& param : parameters)
               param->print(indent+1);
     }
};