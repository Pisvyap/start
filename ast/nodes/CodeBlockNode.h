#pragma once

#include <vector>

class CodeBlockNode : public ASTNode {
public:
    std::vector<Ptr<StatementNode>> statements;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "CodeBlockStart" << std::endl;
        for (auto& stmt : statements)
            stmt->print(indent + 1);
    }
};