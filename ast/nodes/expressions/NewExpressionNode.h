#pragma once
#include "ExpressionNode.h"

class NewExpressionNode : public ExpressionNode {
public:
    Ptr<ExpressionNode> expression;
    void print(const int indent) override {
        std::cout << "new " << type << " of size "; expression->print(indent);
    }

    void semantic_check(SemanticTable& table) override {
        expression->semantic_check(table);
        if (expression->type != INT)
            throw std::runtime_error("Array creation requires 'chislo' expression");
    }
    virtual llvm::Value *Codegen();
};