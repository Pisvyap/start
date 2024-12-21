#pragma once
#include "StatementNode.h"

class AssigmentStatementNode : public StatementNode {
public:
    std::string name;
    Ptr<ExpressionNode> value;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << name << " := "; value->print(indent); std::cout << std::endl;
    }

    void semantic_check(SemanticTable& table) override {
        Symbol* var = table.lookup(name);
        if (var == nullptr)
            throw std::runtime_error("Variable '" + name + "' not found");

        if (var->isFunction)
            throw std::runtime_error("Cannot assign to function '" + name + "'");

        // Сначала нужно вызвать semantic_check у ExpressionNode, потому что иногда (например в случае Identifier)
        // Он проставляет значение поля type
        value->semantic_check(table);

        if (var->type != value->type)
            throw std::runtime_error("Type mismatch. Can't assign "
                + std::to_string(value->type)
                + "' to variable '" + name + "'(type " + std::to_string(var->type) + ")");
    }
};