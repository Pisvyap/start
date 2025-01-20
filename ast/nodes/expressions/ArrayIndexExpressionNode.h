#pragma once
#include "ExpressionNode.h"

class ArrayIndexExpressionNode : public ExpressionNode {
public:
    std::string name;
    Ptr<ExpressionNode> index;
    void print(const int indent) override {
        std::cout << name << '['; index->print(indent); std::cout << ']';
    }

    void semantic_check(SemanticTable& table) override {
        // Проверка существования массива
        Symbol* arr = table.lookup(name);
        if (arr == nullptr || arr->isFunction || !arr->type.is_array)
            throw std::runtime_error("Array '" + name + "' was not declared");

        // Проверка правильности индекса
        index->semantic_check(table);
        if (index->type.type != INT)
            throw std::runtime_error("Arrays support only 'chislo' indices");
        // TODO проверка что не вышли за пределы? и другие проверки (отрицательные числа)

        if (arr->type.type == INT) {
            this->type = Type(INT);
        } else {
            this->type = Type(BOOL);
        }
    }

    void generate_bytecode() override {
        index->generate_bytecode();

        bc::bytecode.emplace_back(bc::GRUZY_UKAZATEL, name);

        bc::bytecode.emplace_back(bc::GRUZY_IZ_SGRUDY);
    }

    llvm::Value *Codegen() override;
};