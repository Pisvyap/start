#pragma once

#include <memory>
#include <vector>
#include <string>

class ASTNode {
    public:
      virtual ~ASTNode() = default;
};

using ASTNodePtr = std::shared_ptr<ASTNode>;

class ProgramNode : public ASTNode {
public:
    std::vector<ASTNodePtr> declarations;
};

class FunctionNode : public ASTNode {
public:
    std::string name;
    std::vector<std::pair<std::string, ASTNodePtr>> parameters; // pair<name, parameter>
    std::string returnType;
    ASTNodePtr body;
};

class CodeBlockNode : public ASTNode {
public:
    std::vector<ASTNodePtr> statements;
};

class StatementNode : public ASTNode {};

class VariableDeclarationNode : public ASTNode {
public:
    std::string name;
    std::string type;
    ASTNodePtr initializer;
};

class AssignmentNode : public ASTNode {
public:
    std::string name;
    std::string type;
    ASTNodePtr value;
};

class ExpressionNode : public ASTNode {};

class BinaryOperationNode : public ASTNode {
public:
    enum BinaryOperationType {
        Add, Sub, Mul, Div, Mod
    };
    BinaryOperationType operation;
    ASTNodePtr left;
    ASTNodePtr right;
};

