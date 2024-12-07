#pragma once

#include <vector>

class CodeBlockNode : public ASTNode {
public:
    std::vector<Ptr<StatementNode>> statements;
};