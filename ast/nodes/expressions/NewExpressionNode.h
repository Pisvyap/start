#pragma once
#include "ExpressionNode.h"

class NewExpressionNode : public ExpressionNode {
public:
    Ptr<ExpressionNode> expression;
    void print(const int indent) override {
        std::cout << "new " << to_string(type);
    }

    void semantic_check(SemanticTable& table) override {
        expression->semantic_check(table);
        if (expression->type.type != INT)
            throw std::runtime_error("Array creation requires 'chislo' expression");
        try {
            auto number = dynamic_cast<LiteralNode*>(expression.get());
            if (number != nullptr) {
                type.array_size = number->int_value;
            }
        } catch (const std::exception& e) { }
    }

    llvm::Value *Codegen() override;
};