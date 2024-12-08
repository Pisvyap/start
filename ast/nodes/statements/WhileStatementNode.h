#pragma once
#include "../CodeBlockNode.h"
#include "StatementNode.h"

class WhileStatementNode : public StatementNode {
public:
    Ptr<ExpressionNode> condition;
    Ptr<CodeBlockNode> body;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "WHILE ";
        condition->print(indent);
        std::cout << std::endl;
        body->print(indent + 1);
    }
};