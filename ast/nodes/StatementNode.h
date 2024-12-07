#pragma once

#include "../ASTNode.h"
#include "Nodes.h"

class StatementNode : public ASTNode {};

class VariableDeclarationNode : public StatementNode {
public:
    std::string name;
    std::string type;
    Ptr<ExpressionNode> initializer;
    void print(const int indent) override {
        ASTNode::print(indent);
        printf("Variable Declaration: %s %s\n", type.c_str(), name.c_str());
        // initializer->print(indent + 1);
    }
};