#pragma once

#include "ASTNode.h"
#include "nodes/CodeBlockNode.h"
#include "nodes/expressions/ExpressionNode.h"
#include "nodes/FunctionNode.h"
#include "nodes/statements/StatementNode.h"
#include "nodes/ProgramNode.h"
#include "nodes/statements/IfStatementNode.h"
#include "nodes/ParameterNode.h"
#include "nodes/statements/ReturnStatementNode.h"

#include "../grammar/typlypBaseVisitor.h"
#include "nodes/expressions/ArrayIndexExpressionNode.h"
#include "nodes/expressions/BinaryOperationNode.h"
#include "nodes/expressions/BoolLiteralNode.h"
#include "nodes/expressions/FunctionCallExpressionNode.h"
#include "nodes/expressions/IdentifierNode.h"
#include "nodes/expressions/NewExpressionNode.h"
#include "nodes/expressions/NumberLiteralNode.h"
#include "nodes/statements/ArrayAssigmentNode.h"
#include "nodes/statements/AssigmentStatementNode.h"
#include "nodes/statements/ExpressionStatementNode.h"
#include "nodes/statements/ForStatementNode.h"
#include "nodes/statements/PrintStatementNode.h"
#include "nodes/statements/VariableDecalrationNode.h"
#include "nodes/statements/WhileStatementNode.h"

template<typename Node>
Ptr<Node> acast(std::any any) {
    return std::any_cast<Ptr<Node>>(any);
}

class ASTBuilder : public typlypBaseVisitor {
public:
    std::any visitProgram(typlypParser::ProgramContext *context) override {
        auto programNode = std::make_shared<ProgramNode>();

        for (auto& func : context->functionDecl()) {
            programNode->functions.push_back(std::any_cast<Ptr<FunctionNode>>(visitFunctionDecl(func)));
        }

        for (auto& statement : context->statement()) {
            programNode->statements.push_back(std::any_cast<Ptr<StatementNode>>(visitStatement(statement)));
        }

        return programNode;
    }

    std::any visitFunctionDecl(typlypParser::FunctionDeclContext* context) override {
        auto functionNode = std::make_shared<FunctionNode>();

        functionNode->name = context->ID()->getText();
        functionNode->returnType = map_type(context->type()->getText());

        if (context->paramList())
            for (auto param : context->paramList()->param())
                functionNode->parameters.push_back(std::any_cast<Ptr<ParameterNode>>(visitParam(param)));

        functionNode->body = std::any_cast<Ptr<CodeBlockNode>>(visitBlock(context->block()));

        return functionNode;
    }

    std::any visitParam(typlypParser::ParamContext* context) override {
        auto paramNode = std::make_shared<ParameterNode>();
        paramNode->name = context->ID()->getText();
        paramNode->type = map_type(context->type()->getText());

        return paramNode;
    }

    std::any visitBlock(typlypParser::BlockContext* context) override {
        auto blockNode = std::make_shared<CodeBlockNode>();
        for (auto& statement : context->statement()) {
            blockNode->statements.push_back(std::any_cast<Ptr<StatementNode>>(visitStatement(statement)));
        }

        return blockNode;
    }

    std::any visitStatement(typlypParser::StatementContext *context) override {
        if (context->varDecl())
            return std::any_cast<Ptr<StatementNode>>(visitVarDecl(context->varDecl()));

        if (context->ifStatement())
            return std::any_cast<Ptr<StatementNode>>(visitIfStatement(context->ifStatement()));

        if (context->returnStatement())
            return std::any_cast<Ptr<StatementNode>>(visitReturnStatement(context->returnStatement()));

        if (context->whileStatement())
            return std::any_cast<Ptr<StatementNode>>(visitWhileStatement(context->whileStatement()));

        if (context->assignment())
            return std::any_cast<Ptr<StatementNode>>(visitAssignment(context->assignment()));

        if (context->arrayAssignment())
            return std::any_cast<Ptr<StatementNode>>(visitArrayAssignment(context->arrayAssignment()));

        if (context->forStatement())
            return std::any_cast<Ptr<StatementNode>>(visitForStatement(context->forStatement()));

        if (context->printStatement())
            return std::any_cast<Ptr<StatementNode>>(visitPrintStatement(context->printStatement()));

        // Если ничего конкретного, то это statement в виде `expr;`
        auto node = std::make_shared<ExpressionStatementNode>();
        node->expression = std::any_cast<Ptr<ExpressionNode>>(visitExpr(context->expr()));
        return static_cast<Ptr<StatementNode>>(node);
    }

    std::any visitPrintStatement(typlypParser::PrintStatementContext* context) override {
        auto node = std::make_shared<PrintStatementNode>();

        node->expression = std::any_cast<Ptr<ExpressionNode>>(visitExpr(context->expr()));

        return static_cast<Ptr<StatementNode>>(node);
    }

    std::any visitForStatement(typlypParser::ForStatementContext* context) override {
        auto node = std::make_shared<ForStatementNode>();

        node->init = std::any_cast<Ptr<StatementNode>>(visitForInit(context->forInit()));
        node->condition = std::any_cast<Ptr<ExpressionNode>>(visitExpr(context->expr()));
        node->step = std::any_cast<Ptr<StatementNode>>(visitForUpdate(context->forUpdate()));
        node->body = std::any_cast<Ptr<CodeBlockNode>>(visitBlock(context->block()));

        return static_cast<Ptr<StatementNode>>(node);;
    }

    std::any visitForUpdate(typlypParser::ForUpdateContext* context) override {
        return std::any_cast<Ptr<StatementNode>>(visitAssignment(context->assignment()));
    }

    std::any visitForInit(typlypParser::ForInitContext* context) override {
        if (context->varDecl())
            return std::any_cast<Ptr<StatementNode>>(visitVarDecl(context->varDecl()));
        else
            return std::any_cast<Ptr<StatementNode>>(visitAssignment(context->assignment()));
    }

    std::any visitArrayAssignment(typlypParser::ArrayAssignmentContext* context) override {
        auto node = std::make_shared<ArrayAssigmentNode>();

        node->name = context->ID()->getText();
        node->index = std::any_cast<Ptr<ExpressionNode>>(visitExpr(context->expr()[0]));
        node->value = std::any_cast<Ptr<ExpressionNode>>(visitExpr(context->expr()[1]));

        return static_cast<Ptr<StatementNode>>(node);
    }

    std::any visitAssignment(typlypParser::AssignmentContext* context) override {
        auto node = std::make_shared<AssigmentStatementNode>();

        node->name = context->ID()->getText();
        node->value = std::any_cast<Ptr<ExpressionNode>>(visitExpr(context->expr()));

        return static_cast<Ptr<StatementNode>>(node);
    }

    std::any visitWhileStatement(typlypParser::WhileStatementContext* context) override {
        auto node = std::make_shared<WhileStatementNode>();

        node->condition = std::any_cast<Ptr<ExpressionNode>>(visitExpr(context->expr()));
        node->body = std::any_cast<Ptr<CodeBlockNode>>(visitBlock(context->block()));

        return static_cast<Ptr<StatementNode>>(node);
    }

    std::any visitReturnStatement(typlypParser::ReturnStatementContext* context) override {
        auto returnNode = std::make_shared<ReturnStatementNode>();
        returnNode->expression = std::any_cast<Ptr<ExpressionNode>>(visitExpr(context->expr()));

        return static_cast<Ptr<StatementNode>>(returnNode);
    }

    std::any visitIfStatement(typlypParser::IfStatementContext* context) override {
        auto ifNode = std::make_shared<IfStatementNode>();

        ifNode->condition = std::any_cast<Ptr<ExpressionNode>>(visitExpr(context->expr()));
        ifNode->thenBlock = std::any_cast<Ptr<CodeBlockNode>>(visitBlock(context->block(0)));
        if (context->block().size() > 1)
            ifNode->elseBlock = std::any_cast<Ptr<CodeBlockNode>>(visitBlock(context->block(1)));

        return static_cast<Ptr<StatementNode>>(ifNode);
    }

    std::any visitVarDecl(typlypParser::VarDeclContext* context) override {
        auto varDeclNode = std::make_shared<VariableDeclarationNode>();

        varDeclNode->name = context->ID()->getText();
        varDeclNode->type = map_type(context->type()->getText());
        varDeclNode->initializer = std::any_cast<Ptr<ExpressionNode>>(visitExpr(context->expr()));

        return static_cast<Ptr<StatementNode>>(varDeclNode);
    }

    std::any visitExpr(typlypParser::ExprContext* context) override {
        if (context->ID() && context->LPAREN() && context->RPAREN()) {
            auto node = std::make_shared<FunctionCallExpressionNode>();
            node->name = context->ID()->getText();
            if (context->argList())
                for (auto arg : context->argList()->expr())
                    node->arguments.push_back(std::any_cast<Ptr<ExpressionNode>>(visitExpr(arg)));

            return static_cast<Ptr<ExpressionNode>>(node);
        }

        if (context->expr().size() == 2) {
            auto node = std::make_shared<BinaryOperationNode>();

            node->left = acast<ExpressionNode>(visitExpr(context->expr()[0]));
            node->right = acast<ExpressionNode>(visitExpr(context->expr()[1]));

            if (context->PLUS()) node->operation = BinaryOperationNode::Add;
            else if (context->MINUS()) node->operation = BinaryOperationNode::Sub;
            else if (context->MULT()) node->operation = BinaryOperationNode::Mul;
            else if (context->DIV()) node->operation = BinaryOperationNode::Div;
            else if (context->MOD()) node->operation = BinaryOperationNode::Mod;
            else if (context->EQ()) node->operation = BinaryOperationNode::EQ;
            else if (context->NEQ()) node->operation = BinaryOperationNode::NE;
            else if (context->GT()) node->operation = BinaryOperationNode::GT;
            else if (context->GE()) node->operation = BinaryOperationNode::GE;
            else if (context->LT()) node->operation = BinaryOperationNode::LT;
            else if (context->LE()) node->operation = BinaryOperationNode::LE;

            return static_cast<Ptr<ExpressionNode>>(node);
        }

        if (context->INT()) {
            auto node = std::make_shared<NumberLiteralNode>(context->INT()->getText());
            return static_cast<Ptr<ExpressionNode>>(node);
        }

        if (context->BOOL()) {
            auto node = std::make_shared<BoolLiteralNode>(context->BOOL()->getText());
            return static_cast<Ptr<ExpressionNode>>(node);
        }

        if (context->ID() && context->expr().empty()) {
            auto node = std::make_shared<IdentifierNode>();
            node->name = context->ID()->getText();
            return static_cast<Ptr<ExpressionNode>>(node);
        }

        // chislo[1]
        if (context->ID() && context->LBRACKET() && context->RBRACKET() && context->expr().size() == 1) {
            auto node = std::make_shared<ArrayIndexExpressionNode>();
            node->name = context->ID()->getText();
            node->index = std::any_cast<Ptr<ExpressionNode>>(visitExpr(context->expr()[0]));
            return static_cast<Ptr<ExpressionNode>>(node);
        }

        // chislo<1>
        if (context->scalarType()) {
            auto node = std::make_shared<NewExpressionNode>();
            node->type = map_type(context->scalarType()->getText(), true);
            node->expression = std::any_cast<Ptr<ExpressionNode>>(visitExpr(context->expr()[0]));
            return static_cast<Ptr<ExpressionNode>>(node);
        }

        // (expr)
        if (context->LPAREN() && context->RPAREN()) {
            return visitExpr(context->expr()[0]);
        }

        return std::make_shared<ExpressionNode>();
    }
};
