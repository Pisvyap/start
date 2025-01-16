#pragma once
#include <support/CPPUtils.h>

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
                + std::to_string(value->type.type)
                + "' to variable '" + name + "'(type " + std::to_string(var->type.type) + ")");

        if (var->type.is_array) {
            var->type.array_size = value->type.array_size;
        }
    }

    llvm::Value *Codegen() override;

    void generate_bytecode() override {
        // Сначала вызываем генерацию от value (ожидая, что результат будет наверху стека)
        value->generate_bytecode();

        // И сохраняем в переменную
        bc::bytecode.emplace_back(bc::OP::STORE_VAR, this->name);
    }
};