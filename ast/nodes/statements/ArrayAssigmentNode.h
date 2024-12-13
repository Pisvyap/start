#pragma once
#include "StatementNode.h"

class ArrayAssigmentNode : public StatementNode {
public:
    std::string arrayName;
    Ptr<ExpressionNode> index;
    Ptr<ExpressionNode> value;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << arrayName << "[";
        index->print(indent);
        std::cout << "] := ";
        value->print(indent);
        std::cout << '\n';
    }
};