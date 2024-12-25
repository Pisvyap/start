#pragma once

#include "StatementNode.h"

class VariableDeclarationNode : public StatementNode {
public:
    std::string name;
    Type type;
    Ptr<ExpressionNode> initializer;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "VarDecl: " << to_string(type) << ' ' << name << " := "; initializer->print(indent); std::cout << "\n";
    }

    void semantic_check(SemanticTable& table) override {
        // Проверка имени на занятость
        if (table.lookup(name))
            throw std::runtime_error("Identifier '" + name + "' already declared in this scope");

        initializer->semantic_check(table);
        if (initializer->type != type) {
            throw std::runtime_error("Type mismatch in variable declaration: " + name
                + ". Expected " + to_string(type) + ", Got " + to_string(initializer->type));
        }

        // Добавление переменной в скоуп
        Symbol var(type, false);
        table.addSymbol(name, var);
    }

    llvm::Value *Codegen() override;
};