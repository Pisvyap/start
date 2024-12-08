#pragma once

#include "StatementNode.h"
#include "../CodeBlockNode.h"
#include "../ExpressionNode.h"

class IfStatementNode : public StatementNode {
public:
    Ptr<ExpressionNode> condition;
    Ptr<CodeBlockNode> thenBlock;
    Ptr<CodeBlockNode> elseBlock;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "IF" << std::endl;
        condition->print(indent);
        ASTNode::print(indent);
        std::cout << "THEN" << std::endl;
        thenBlock->print(indent + 1);
        ASTNode::print(indent);
        std::cout << "ELSE" << std::endl;
        elseBlock->print(indent + 1);
    }
};
