#pragma once

class CodeBlockNode : public ASTNode<CodeBlockNode> {
public:
    std::vector<StatementNode::Ptr> statements;
};