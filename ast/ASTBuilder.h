#pragma once

#include "ASTNode.h"
#include "nodes/Nodes.h"

#include "../grammar/typlypBaseVisitor.h"

class ASTBuilder : public typlypBaseVisitor {
public:
    std::any visitProgram(typlypParser::ProgramContext *context) override {
        auto programNode = std::make_shared<ProgramNode>();

        std::cout << "Start reading external functions" << std::endl;
        for (auto& func : context->externalDecl()) {
            programNode->externalFunctions.push_back(std::any_cast<Ptr<ExternalFunctionNode>>(visitExternalDecl(func)));
        }
        std::cout << "End reading external functions" << std::endl;

        std::cout << "Start reading function decls" << std::endl;
        for (auto& func : context->functionDecl()) {
            programNode->functions.push_back(std::any_cast<Ptr<FunctionNode>>(visitFunctionDecl(func)));
        }
        std::cout << "End reading function decls" << std::endl;

        std::cout << "Start reading statements" << std::endl;
        for (auto& statement : context->statement()) {
            programNode->statements.push_back(std::any_cast<Ptr<StatementNode>>(visitStatement(statement)));
        }

        std::cout << "End reading statements" << std::endl;

        return programNode;
    }

    std::any visitExternalDecl(typlypParser::ExternalDeclContext* context) override {
        auto node = std::make_shared<ExternalFunctionNode>();
        std::cout << "  VisitExternal" << std::endl;

        node->name = context->ID()->getText();
        node->returnType = context->type()->getText();
        std::cout << "  " << node->name << ' ' << node->returnType <<  std::endl;
        if (context->paramList()) {
            for (auto& param : context->paramList()->param()) {
                node->parameters.push_back(std::any_cast<Ptr<ParameterNode>>(visitParam(param)));
            }
        }

        return node;
    }

    std::any visitFunctionDecl(typlypParser::FunctionDeclContext* context) override {
        auto functionNode = std::make_shared<FunctionNode>();
        std::cout << "  VisitFunctionDecl" << std::endl;

        functionNode->name = context->ID()->getText();
        functionNode->returnType = context->type()->getText();
        std::cout << "  " << functionNode->name << ' ' << functionNode->returnType << std::endl;

        if (context->paramList()) {
            for (auto param : context->paramList()->param()) {
                functionNode->parameters.push_back(std::any_cast<Ptr<ParameterNode>>(visitParam(param)));
            }
        }

        functionNode->body = std::any_cast<Ptr<CodeBlockNode>>(visitBlock(context->block()));

        return functionNode;
    }

    std::any visitParam(typlypParser::ParamContext* context) override {
        std::cout << "          VisitParam" << std::endl;
        auto paramNode = std::make_shared<ParameterNode>();
        paramNode->name = context->ID()->getText();
        paramNode->type = context->type()->getText();
        std::cout << "          " << paramNode->name << ' ' << paramNode->type << std::endl;

        return paramNode;
    }

    std::any visitBlock(typlypParser::BlockContext* context) override {
        auto blockNode = std::make_shared<CodeBlockNode>();

        std::cout << "      VisitBlock" << std::endl;
        for (auto& statement : context->statement()) {
            blockNode->statements.push_back(std::any_cast<Ptr<StatementNode>>(visitStatement(statement)));
        }

        return blockNode;
    }

    std::any visitStatement(typlypParser::StatementContext *context) override {
        std::cout << "          VisitStatement" << std::endl;
        if (context->varDecl()) {
            return std::any_cast<Ptr<StatementNode>>(visitVarDecl(context->varDecl()));
        }
        return nullptr;
    }

    std::any visitVarDecl(typlypParser::VarDeclContext* context) override {
        auto varDeclNode = std::make_shared<VariableDeclarationNode>();
        std::cout << "              VisitVarDecl" << std::endl;

        varDeclNode->name = context->ID()->getText();
        varDeclNode->type = context->type()->getText();
        varDeclNode->initializer = std::any_cast<Ptr<ExpressionNode>>(visitExpr(context->expr()));

        std::cout << "              " << varDeclNode->name << ' ' << varDeclNode->type << std::endl;

        return static_cast<Ptr<StatementNode>>(varDeclNode);
    }

    std::any visitExpr(typlypParser::ExprContext* context) override {
        auto exprNode = std::make_shared<ExpressionNode>();
        std::cout << "                  In visitExpr" << std::endl;
        std::cout << "                  " << context->children[0]->getText() << std::endl;
        return exprNode;
    }
};
