#pragma once

#include <vector>

#include "../ASTNode.h"
#include "ExternalFunctionNode.h"
#include "FunctionNode.h"
#include "statements/StatementNode.h"

class ProgramNode final : ASTNode {
public:
    std::vector<Ptr<ExternalFunctionNode>> externalFunctions;
    std::vector<Ptr<FunctionNode>> functions;
    std::vector<Ptr<StatementNode>> statements;
    void print(const int indent) override {
        ASTNode::print(indent);
        for (auto& ext : externalFunctions)
            ext->print(indent);
        ASTNode::print(indent);
        for (auto& func : functions)
            func->print(indent);
        ASTNode::print(indent);
        for (auto& stmt : statements)
            stmt->print(indent);
        std::cout << std::endl;
    }
    void semantic_check(SemanticTable& table) override {
        for (const auto& ext : externalFunctions)
            ext->semantic_check(table);

        for (const auto& func : functions)
            func->semantic_check(table);

        for (const auto& stmt : statements)
            stmt->semantic_check(table);
    }
    virtual llvm::Value *Codegen();
};
