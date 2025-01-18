#pragma once
#include <vector>

#include "ExpressionNode.h"

class FunctionCallExpressionNode final : public ExpressionNode {
public:
    std::string name;
    std::vector<Ptr<ExpressionNode>> arguments;
    void print(const int indent) override {
        std::cout << "FunctionCall " << name << "(";
        for (int i = 0; i < arguments.size(); i++) {
            arguments[i]->print(indent);
            std::cout << ", ";
        }

        std::cout << ")";
    }

    void semantic_check(SemanticTable& table) override {
        // Проверка на наличие функции
        Symbol* func = table.lookup(name);
        if (func == nullptr || !func->isFunction)
            throw std::runtime_error("Function '" + name + "' was not declared");

        // Проверка аргументов
        if (func->paramTypes.size() != arguments.size())
            throw std::runtime_error(
                "Parameter number mismatch (expected " + std::to_string(arguments.size())
                    + " given " + std::to_string(func->paramTypes.size()));

        for (int i = 0; i < func->paramTypes.size(); i++) {
            arguments.at(i)->semantic_check(table);
            if (arguments.at(i)->type != func->paramTypes.at(i))
                throw std::runtime_error("Function '" + name + "' argument mismatch (" + std::to_string(i) + ")");
        }

        // Сохраняемый возвращаемый тип
        this->type = func->type;
    }

    llvm::Value *Codegen() override;

    void generate_bytecode() override {
        // Аргументы функции загружаются с конца. (Чтобы при чтении стека сверху вниз был верный порядок)
        // Хз, может быть и в обычном порядке тоже норм. Пока неясно
        for (auto it = arguments.rbegin(); it != arguments.rend(); ++it)
            (*it)->generate_bytecode();

        // Вызываем функцию
        bc::bytecode.emplace_back(bc::OP::CALL, this->name, llvm::APInt(128, arguments.size()));
    }
};