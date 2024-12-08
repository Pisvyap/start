#pragma once
#include "../CodeBlockNode.h"
#include "StatementNode.h"

class WhileStatementNode : public StatementNode {
public:
    Ptr<ExpressionNode> condition;
    Ptr<CodeBlockNode> body;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "WHILE" << std::endl;
        condition->print(indent);
        body->print(indent + 1);
    }
};