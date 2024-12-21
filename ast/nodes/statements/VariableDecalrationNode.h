#pragma once

#include "StatementNode.h"

class VariableDeclarationNode : public StatementNode {
public:
    std::string name;
    Type type;
    Ptr<ExpressionNode> initializer;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "VarDecl: " << type << ' ' << name << " := "; initializer->print(indent); std::cout << "\n";
    }

    void semantic_check(SemanticTable& table) override {
        // Проверка имени на занятость
        if (table.lookup(name))
            throw std::runtime_error("Identifier '" + name + "' already declared in this scope");

        // Добавление переменной в скоуп
        Symbol var(type, false);
        table.addSymbol(name, var);
    }
};