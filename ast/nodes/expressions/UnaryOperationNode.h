#pragma once

#include "ExpressionNode.h"
#include "../../ASTNode.h"


class UnaryOperationNode : public ExpressionNode {
public:
    enum UnaryOperationType {
        NOT
    };

    UnaryOperationType operation;
    Ptr<ExpressionNode> expression;

    void print(const int indent) override {
        std::cout << operation << ' '; expression->print(indent);
    }

    void semantic_check(SemanticTable& table) override {
        expression->semantic_check(table);
        if (expression->type != BOOL)
            throw std::runtime_error("NOT operation requires 'logika' value");

        this->type = BOOL;
    }

    llvm::Value *Codegen() override;

    void generate_bytecode() override {
        // Вызываем генерацию от expression (ожидая результат наверху)
        expression->generate_bytecode();

        // выполняем операцию
        switch (operation) {
            case NOT:
                bc::bytecode.emplace_back(bc::OP::NOT);
                return;
            default:
                throw std::runtime_error("AST and Bytecode unary operators mismatch");
        }
    }
};
