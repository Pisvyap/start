#pragma once
#include "StatementNode.h"

class PrintStatementNode : public StatementNode {
public:
    Ptr<ExpressionNode> expression;

    void print(const int indent) override {
        std::cout << "PRINTING "; expression->print(indent); std::cout << std::endl;
    }

    void semantic_check(SemanticTable& table) override {
        expression->semantic_check(table);
    }

    llvm::Value *Codegen() override;

    void generate_bytecode() override {
        expression->generate_bytecode();

        bc::bytecode.emplace_back(bc::OP::VIVEDY);
    }
};
