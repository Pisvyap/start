#pragma once

#include <vector>

#include "../ASTNode.h"
#include "../TreeWriter.h"
#include "Nodes.h"

class ProgramNode final : ASTNode {
public:
    std::vector<Ptr<ExternalFunctionNode>> externalFunctions;
    std::vector<Ptr<FunctionNode>> functions;
    std::vector<Ptr<StatementNode>> statements;
};
