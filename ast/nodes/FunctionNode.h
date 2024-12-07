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
    void print(const int indent) override {
        ASTNode::print(indent);
        printf("Function %s -> %s\n", name.c_str(), returnType.c_str());
        for (auto& param: parameters)
            param->print(indent + 1);
        body->print(indent + 1);
    }
};
