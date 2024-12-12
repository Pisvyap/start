#pragma once

#include "StatementNode.h"

class VariableDeclarationNode : public StatementNode {
public:
    std::string name;
    std::string type;
    Ptr<ExpressionNode> initializer;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "VarDecl: " << type << ' ' << name << " := "; initializer->print(indent); std::cout << "\n";
    }
};