#pragma once

#include "ASTNode.h"
#include "nodes/Nodes.h"

#include "../grammar/typlypBaseVisitor.h"

class ASTBuilder : public typlypBaseVisitor {
public:
    std::any visitProgram(typlypParser::ProgramContext *context) override {
        auto programNode = std::make_shared<ProgramNode>();

        std::cout << "Start reading function decls" << std::endl;
        for (auto& func : context->functionDecl()) {
            programNode->functions.push_back(std::any_cast<FunctionNode::Ptr>(visitFunctionDecl(func)));
        }
        std::cout << "End reading function decls" << std::endl;

        std::cout << "Start reading statements" << std::endl;
        for (auto& statement : context->statement()) {
            programNode->statements.push_back(std::any_cast<StatementNode::Ptr>(visitStatement(statement)));
        }
        std::cout << "End reading statements" << std::endl;

        return programNode;
    }

    std::any visitFunctionDecl(typlypParser::FunctionDeclContext* context) override {
        auto functionNode = std::make_shared<FunctionNode>();
        std::cout << "  In visitFunctionDecl" << std::endl;

        functionNode->name = context->ID()->getText();
        functionNode->returnType = context->type()->getText();
        std::cout << "  " << context->ID()->getText() << std::endl;
        std::cout << "  " << context->type()->getText() << std::endl;

        std::cout << "  Start reading parameters " << std::endl;
        if (context->paramList()) {
            for (auto param : context->paramList()->param()) {
                functionNode->parameters.push_back(std::any_cast<ParameterNode::Ptr>(visitParam(param)));
            }
        }
        std::cout << "  Read all parameters" << std::endl;

        functionNode->body = std::any_cast<CodeBlockNode::Ptr>(visitBlock(context->block()));

        return functionNode;
    }

    std::any visitParam(typlypParser::ParamContext* context) override {
        std::cout << "          In visitParam" << std::endl;
        auto paramNode = std::make_shared<ParameterNode>();
        paramNode->name = context->ID()->getText();
        paramNode->type = context->type()->getText();
        std::cout << "          " << context->ID()->getText() << std::endl;
        std::cout << "          " << context->type()->getText() << std::endl;

        return paramNode;
    }

    std::any visitBlock(typlypParser::BlockContext* context) override {
        auto blockNode = std::make_shared<CodeBlockNode>();

        std::cout << "      In visitBlock" << std::endl;
        for (auto& statement : context->statement()) {
            blockNode->statements.push_back(std::any_cast<StatementNode::Ptr>(visitStatement(statement)));
        }

        return blockNode;
    }

    std::any visitStatement(typlypParser::StatementContext *context) override {
        std::cout << "          In visitStatement" << std::endl;
        if (context->varDecl()) {
            return std::any_cast<StatementNode::Ptr>(visitVarDecl(context->varDecl()));
        }
        return nullptr;
    }

    std::any visitVarDecl(typlypParser::VarDeclContext* context) override {
        auto varDeclNode = std::make_shared<VariableDeclarationNode>();
        std::cout << "              In visitVarDecl" << std::endl;

        varDeclNode->name = context->ID()->getText();
        varDeclNode->type = context->type()->getText();
        varDeclNode->initializer = std::any_cast<ExpressionNode::Ptr>(visitExpr(context->expr()));

        std::cout << "              End visitVarDecl" << std::endl;

        return static_cast<StatementNode::Ptr>(varDeclNode);
    }

    std::any visitExpr(typlypParser::ExprContext* context) override {
        auto exprNode = std::make_shared<ExpressionNode>();
        std::cout << "                  In visitExpr" << std::endl;
        std::cout << "                  " << context->children[0]->getText() << std::endl;
        return exprNode;
    }
};
