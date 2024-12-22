#pragma once

#include "../ASTNode.h"

class ParameterNode : public ASTNode {
public:
    std::string name;
    TypeStruct type;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "Parameter[name=" << name << ";type=" << type.type << ']' << std::endl;
    }
    virtual llvm::Value *Codegen();
};