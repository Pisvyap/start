
// Generated from C:/Users/ladyp/CLionProjects/tyaplyap/grammar/typlyp.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "typlypParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by typlypParser.
 */
class  typlypListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(typlypParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(typlypParser::ProgramContext *ctx) = 0;

  virtual void enterFunctionDecl(typlypParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(typlypParser::FunctionDeclContext *ctx) = 0;

  virtual void enterParamList(typlypParser::ParamListContext *ctx) = 0;
  virtual void exitParamList(typlypParser::ParamListContext *ctx) = 0;

  virtual void enterParam(typlypParser::ParamContext *ctx) = 0;
  virtual void exitParam(typlypParser::ParamContext *ctx) = 0;

  virtual void enterBlock(typlypParser::BlockContext *ctx) = 0;
  virtual void exitBlock(typlypParser::BlockContext *ctx) = 0;

  virtual void enterStatement(typlypParser::StatementContext *ctx) = 0;
  virtual void exitStatement(typlypParser::StatementContext *ctx) = 0;

  virtual void enterVarDecl(typlypParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(typlypParser::VarDeclContext *ctx) = 0;

  virtual void enterAssignment(typlypParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(typlypParser::AssignmentContext *ctx) = 0;

  virtual void enterArrayAssignment(typlypParser::ArrayAssignmentContext *ctx) = 0;
  virtual void exitArrayAssignment(typlypParser::ArrayAssignmentContext *ctx) = 0;

  virtual void enterReturnStatement(typlypParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(typlypParser::ReturnStatementContext *ctx) = 0;

  virtual void enterIfStatement(typlypParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(typlypParser::IfStatementContext *ctx) = 0;

  virtual void enterWhileStatement(typlypParser::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(typlypParser::WhileStatementContext *ctx) = 0;

  virtual void enterForStatement(typlypParser::ForStatementContext *ctx) = 0;
  virtual void exitForStatement(typlypParser::ForStatementContext *ctx) = 0;

  virtual void enterPrintStatement(typlypParser::PrintStatementContext *ctx) = 0;
  virtual void exitPrintStatement(typlypParser::PrintStatementContext *ctx) = 0;

  virtual void enterExpr(typlypParser::ExprContext *ctx) = 0;
  virtual void exitExpr(typlypParser::ExprContext *ctx) = 0;

  virtual void enterArgList(typlypParser::ArgListContext *ctx) = 0;
  virtual void exitArgList(typlypParser::ArgListContext *ctx) = 0;

  virtual void enterType(typlypParser::TypeContext *ctx) = 0;
  virtual void exitType(typlypParser::TypeContext *ctx) = 0;

  virtual void enterVoidType(typlypParser::VoidTypeContext *ctx) = 0;
  virtual void exitVoidType(typlypParser::VoidTypeContext *ctx) = 0;

  virtual void enterScalarType(typlypParser::ScalarTypeContext *ctx) = 0;
  virtual void exitScalarType(typlypParser::ScalarTypeContext *ctx) = 0;

  virtual void enterArrayType(typlypParser::ArrayTypeContext *ctx) = 0;
  virtual void exitArrayType(typlypParser::ArrayTypeContext *ctx) = 0;


};

