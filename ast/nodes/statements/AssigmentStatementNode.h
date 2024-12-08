#pragma once
#include "StatementNode.h"

class AssigmentStatementNode : public StatementNode {
public:
    std::string name;
    Ptr<ExpressionNode> value;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << name << " = "; value->print(indent); std::cout << std::endl;
    }
};