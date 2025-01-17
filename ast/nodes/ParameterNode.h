#pragma once

#include "../ASTNode.h"

class ParameterNode : public ASTNode {
public:
    std::string name;
    Type type;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "Parameter[name=" << name << ";type=" << to_string(type) << ']' << std::endl;
    }

    void generate_bytecode() override{
        // Тут нормально что пусто
        // TODO если понадобится все-таки в функциях - то доделаем
    }

    llvm::Value *Codegen() override;
};