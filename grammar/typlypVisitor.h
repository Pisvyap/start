
// Generated from C:/Users/ladyp/CLionProjects/tyaplyap/grammar/typlyp.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "typlypParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by typlypParser.
 */
class  typlypVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by typlypParser.
   */
    virtual std::any visitProgram(typlypParser::ProgramContext *context) = 0;

    virtual std::any visitFunctionDecl(typlypParser::FunctionDeclContext *context) = 0;

    virtual std::any visitExternalDecl(typlypParser::ExternalDeclContext *context) = 0;

    virtual std::any visitParamList(typlypParser::ParamListContext *context) = 0;

    virtual std::any visitParam(typlypParser::ParamContext *context) = 0;

    virtual std::any visitBlock(typlypParser::BlockContext *context) = 0;

    virtual std::any visitStatement(typlypParser::StatementContext *context) = 0;

    virtual std::any visitVarDecl(typlypParser::VarDeclContext *context) = 0;

    virtual std::any visitAssignment(typlypParser::AssignmentContext *context) = 0;

    virtual std::any visitArrayAssignment(typlypParser::ArrayAssignmentContext *context) = 0;

    virtual std::any visitReturnStatement(typlypParser::ReturnStatementContext *context) = 0;

    virtual std::any visitIfStatement(typlypParser::IfStatementContext *context) = 0;

    virtual std::any visitWhileStatement(typlypParser::WhileStatementContext *context) = 0;

    virtual std::any visitForStatement(typlypParser::ForStatementContext *context) = 0;

    virtual std::any visitForInit(typlypParser::ForInitContext *context) = 0;

    virtual std::any visitForUpdate(typlypParser::ForUpdateContext *context) = 0;

    virtual std::any visitExpr(typlypParser::ExprContext *context) = 0;

    virtual std::any visitArgList(typlypParser::ArgListContext *context) = 0;

    virtual std::any visitExprList(typlypParser::ExprListContext *context) = 0;

    virtual std::any visitType(typlypParser::TypeContext *context) = 0;


};

