#pragma once
#include "StatementNode.h"
#include "../CodeBlockNode.h"

class ForStatementNode : public StatementNode {
public:
    Ptr<StatementNode> init; // TODO по хорошему наверное надо отдельную ноду для этого (как в грамматике)
    Ptr<ExpressionNode> condition;
    Ptr<StatementNode> step;
    Ptr<CodeBlockNode> body;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "FOR BEGIN\n";
        init->print(indent + 1);
        ASTNode::print(indent + 1);
        condition->print(indent); std::cout << '\n';;
        step->print(indent + 1);
        body->print(indent + 1);
    }
    virtual Value *Codegen();
};
