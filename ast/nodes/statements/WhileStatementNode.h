#pragma once
#include "../CodeBlockNode.h"
#include "StatementNode.h"

class WhileStatementNode : public StatementNode {
public:
    Ptr<ExpressionNode> condition;
    Ptr<CodeBlockNode> body;
    void print(const int indent) override {
        ASTNode::print(indent);
        std::cout << "WHILE ";
        condition->print(indent);
        std::cout << std::endl;
        body->print(indent + 1);
    }

    void semantic_check(SemanticTable& table) override {
        condition->semantic_check(table);
        if (condition->type != BOOL)
            throw std::runtime_error("Expected 'logika' in while condition");

        table.enterScope();
        body->semantic_check(table);
        table.leaveScope();
    }

    llvm::Value *Codegen() override;

    void generate_bytecode() override {
        int while_start = bc::LABEL_COUNT;
        int while_end = bc::LABEL_COUNT + 1;
        bc::LABEL_COUNT += 2;

        bc::bytecode.emplace_back(bc::OP::LABEL, llvm::APInt(128, while_start));
        condition->generate_bytecode();

        bc::bytecode.emplace_back(bc::OP::JUMP_IF_FALSE, llvm::APInt(128, while_end));

        body->generate_bytecode();
        bc::bytecode.emplace_back(bc::OP::JUMP, llvm::APInt(128, while_start));

        bc::bytecode.emplace_back(bc::OP::LABEL, llvm::APInt(128, while_end));
    }
};