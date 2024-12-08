#pragma once

#include "ASTNode.h"
#include "nodes/CodeBlockNode.h"
#include "nodes/ExpressionNode.h"
#include "nodes/FunctionNode.h"
#include "nodes/statements/StatementNode.h"
#include "nodes/ExternalFunctionNode.h"
#include "nodes/ProgramNode.h"
#include "nodes/statements/IfStatementNode.h"
#include "nodes/ParameterNode.h"
#include "nodes/statements/ReturnStatementNode.h"

#include "../grammar/typlypBaseVisitor.h"
#include "nodes/statements/WhileStatementNode.h"

class ASTBuilder : public typlypBaseVisitor {
public:
    std::any visitProgram(typlypParser::ProgramContext *context) override {
        auto programNode = std::make_shared<ProgramNode>();

        for (auto& func : context->externalDecl()) {
            programNode->externalFunctions.push_back(std::any_cast<Ptr<ExternalFunctionNode>>(visitExternalDecl(func)));
        }

        for (auto& func : context->functionDecl()) {
            programNode->functions.push_back(std::any_cast<Ptr<FunctionNode>>(visitFunctionDecl(func)));
        }

        for (auto& statement : context->statement()) {
            programNode->statements.push_back(std::any_cast<Ptr<StatementNode>>(visitStatement(statement)));
        }

        return programNode;
    }

    std::any visitExternalDecl(typlypParser::ExternalDeclContext* context) override {
        auto node = std::make_shared<ExternalFunctionNode>();

        node->name = context->ID()->getText();
        node->returnType = context->type()->getText();
        if (context->paramList()) {
            for (auto& param : context->paramList()->param()) {
                node->parameters.push_back(std::any_cast<Ptr<ParameterNode>>(visitParam(param)));
            }
        }

        return node;
    }

    std::any visitFunctionDecl(typlypParser::FunctionDeclContext* context) override {
        auto functionNode = std::make_shared<FunctionNode>();

        functionNode->name = context->ID()->getText();
        functionNode->returnType = context->type()->getText();

        if (context->paramList()) {
            for (auto param : context->paramList()->param()) {
                functionNode->parameters.push_back(std::any_cast<Ptr<ParameterNode>>(visitParam(param)));
            }
        }

        functionNode->body = std::any_cast<Ptr<CodeBlockNode>>(visitBlock(context->block()));

        return functionNode;
    }

    std::any visitParam(typlypParser::ParamContext* context) override {
        auto paramNode = std::make_shared<ParameterNode>();
        paramNode->name = context->ID()->getText();
        paramNode->type = context->type()->getText();

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

        return std::make_shared<StatementNode>();
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
        varDeclNode->type = context->type()->getText();
        varDeclNode->initializer = std::any_cast<Ptr<ExpressionNode>>(visitExpr(context->expr()));

        return static_cast<Ptr<StatementNode>>(varDeclNode);
    }

    std::any visitExpr(typlypParser::ExprContext* context) override {
        auto exprNode = std::make_shared<ExpressionNode>();
        return exprNode;
    }
};
