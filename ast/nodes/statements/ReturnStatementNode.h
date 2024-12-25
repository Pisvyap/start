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
        expression->semantic_check(table); // TODO Проверять возвращаемый тип с типом функции
    }

    llvm::Value *Codegen() override;
};