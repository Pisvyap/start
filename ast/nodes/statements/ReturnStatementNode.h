#pragma once

#include "StatementNode.h"
#include "../expressions/ExpressionNode.h"

class ReturnStatementNode : public StatementNode {
public:
    Ptr<ExpressionNode> expression;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "RETURN "; expression->print(indent); std::cout << "\n";
    }

    void semantic_check(SemanticTable& table) override {
        expression->semantic_check(table);

        const auto function = table.lookup("return");
        if (function == nullptr)
            throw std::runtime_error("Return statement outside function");

        if (function->type != expression->type)
            throw std::runtime_error("Function return type mismatch. [Expected: "
                + to_string(function->type) + "; got: " + to_string(expression->type) + ']');
    }

    void generate_bytecode() override {
        expression->generate_bytecode();

        bc::bytecode.emplace_back(bc::OP::VERNUT);
    }

    llvm::Value *Codegen() override;
};