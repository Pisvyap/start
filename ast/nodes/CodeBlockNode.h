#pragma once

#include <vector>
#include "statements/StatementNode.h"

class CodeBlockNode : public ASTNode {
public:
    std::vector<Ptr<StatementNode>> statements;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "CodeBlockStart" << std::endl;
        for (auto& stmt : statements)
            stmt->print(indent + 1);
    }

    void semantic_check(SemanticTable& table) override {
        for (const auto& stmt : statements) {
            stmt->semantic_check(table);
        }
    }

    llvm::Value *Codegen() override;

    void generate_bytecode() override {
        for (const auto& stmt : statements)
            stmt->generate_bytecode();
    }
};