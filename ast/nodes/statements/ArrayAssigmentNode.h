#pragma once
#include "StatementNode.h"

class ArrayAssigmentNode : public StatementNode {
public:
    std::string name;
    Ptr<ExpressionNode> index;
    Ptr<ExpressionNode> value;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << name << "[";
        index->print(indent);
        std::cout << "] := ";
        value->print(indent);
        std::cout << '\n';
    }

    void semantic_check(SemanticTable& table) override {
        index->semantic_check(table);
        value->semantic_check(table);

        // Проверка на наличие массива
        Symbol* arr = table.lookup(name);
        if (arr == nullptr || arr->isFunction || !arr->type.is_array)
            throw std::runtime_error("Array '" + name + "' was not declared");

        // Проверка индекса
        // TODO проверка, не вышли ли за пределы??
        if (index->type != INT)
            throw std::runtime_error("Only 'chislo' indices supported");

        // Проверка на правильность типов
        if (arr->type.type != value->type.type)
            throw std::runtime_error("Type mismatch in array assignment");
    }

    void generate_bytecode() override {
        index->generate_bytecode();

        value->generate_bytecode();

        bc::bytecode.emplace_back(bc::LOAD_PTR, name);

        bc::bytecode.emplace_back(bc::STORE_IN_ARRAY);
    }

    llvm::Value *Codegen() override;
};