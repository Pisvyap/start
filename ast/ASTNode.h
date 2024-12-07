#pragma once

#include <memory>
#include <vector>
#include <string>


template<typename T = void>
class ASTNode {
public:
    virtual ~ASTNode() = default;

    using Ptr = std::shared_ptr<T>;
};

template<>
class ASTNode<void> {
    public:
    virtual ~ASTNode() = default;

    using Ptr = std::shared_ptr<ASTNode>;
};

class StatementNode : public ASTNode<StatementNode> {};

class ExpressionNode : public ASTNode<ExpressionNode> {};

class VariableDeclarationNode : public ASTNode<VariableDeclarationNode> {
public:
    std::string name;
    std::string type;
    ExpressionNode::Ptr initializer;
};

class AssignmentNode : public ASTNode<AssignmentNode> {
public:
    std::string name;
    std::string type;
    ASTNode::Ptr value; // TODO replace with concrete type?
};

class BinaryOperationNode : public ASTNode<BinaryOperationNode> {
public:
    enum BinaryOperationType {
        Add, Sub, Mul, Div, Mod
    };
    BinaryOperationType operation;
    ExpressionNode::Ptr left;
    ExpressionNode::Ptr right;
};

