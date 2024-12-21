#pragma once

#include <vector>
#include "../ASTNode.h"
#include "ParameterNode.h"

class ExternalFunctionNode : public ASTNode {
public:
     std::string name;
     std::vector<Ptr<ParameterNode>> parameters;
     Type returnType;
     void print(const int indent) override {
          ASTNode::print(indent);
          printf("ExternalFunction: %s -> %s\n", name.c_str(), returnType);
          for (auto& param : parameters)
               param->print(indent+1);
     }

     void semantic_check(SemanticTable& table) override {
          // Добавляем функцию в текущий скоуп
          Symbol func(returnType, true);
          for (auto& param : parameters) {
               func.paramTypes.push_back(param->type);
          }
          table.addSymbol(name, func);
     }
    virtual Value *Codegen();
};