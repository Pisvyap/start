#pragma once

#include <vector>

#include "../ASTNode.h"
#include "ExternalFunctionNode.h"
#include "FunctionNode.h"
#include "StatementNode.h"

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
    }
};
