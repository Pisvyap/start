#pragma once

#include <vector>

#include "../ASTNode.h"
#include "ParameterNode.h"

class FunctionNode : public ASTNode {
public:
    std::string name;
    std::vector<Ptr<ParameterNode>> parameters; // pair<name, parameter>
    Type returnType;
    Ptr<CodeBlockNode> body;
    void print(const int indent) override {
        ASTNode::print(indent);
        printf("Function %s -> %s\n", name.c_str(), to_string(returnType).c_str());
        for (auto& param: parameters)
            param->print(indent + 1);
        body->print(indent + 1);
    }

    void semantic_check(SemanticTable& table) override {
        // Проверка имени на занятость
        if (table.lookup(name)) {
            throw std::runtime_error("Identifier '" + name + "' already exists in this scope");
        }

        // Добавляем функцию в текущий скоуп
        Symbol func(returnType, true);
        for (auto& param : parameters) {
            func.paramTypes.push_back(param->type);
        }
        table.addSymbol(name, func);

        // Проверяем тело функции и заполняем в новый скоуп
        table.enterScope();
        Symbol function_return(returnType, true);
        table.addSymbol("return", function_return);
        for (auto& parameter : parameters) {
            Symbol param(parameter->type, false);
            table.addSymbol(parameter->name, param);
        }
        body->semantic_check(table);
        table.leaveScope();
    }

    void generate_bytecode() override {
        bc::bytecode.emplace_back(bc::OP::MISSIYA_NACHALO, name);

        for (auto& param : parameters) {
            if (param->type.is_array) {
                bc::bytecode.emplace_back(bc::OP::HRANY_UKAZATEL, param->name);
            } else if (param->type.type == ScalarType::INT) {
                bc::bytecode.emplace_back(bc::OP::HRANY_PEREMENNUYU, param->name);
            } else if (param->type.type == ScalarType::BOOL) {
                bc::bytecode.emplace_back(bc::OP::HRANY_PEREMENNUYU, param->name);
            }
        }

        body->generate_bytecode();

        bc::bytecode.emplace_back(bc::OP::MISSIYA_KONEC);
    }

    llvm::Value *Codegen() override;
};
