
// Generated from C:/Users/ladyp/CLionProjects/tyaplyap/grammar/typlyp.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "typlypListener.h"


/**
 * This class provides an empty implementation of typlypListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  typlypBaseListener : public typlypListener {
public:

  virtual void enterProgram(typlypParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(typlypParser::ProgramContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(typlypParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(typlypParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterExternalDecl(typlypParser::ExternalDeclContext * /*ctx*/) override { }
  virtual void exitExternalDecl(typlypParser::ExternalDeclContext * /*ctx*/) override { }

  virtual void enterParamList(typlypParser::ParamListContext * /*ctx*/) override { }
  virtual void exitParamList(typlypParser::ParamListContext * /*ctx*/) override { }

  virtual void enterParam(typlypParser::ParamContext * /*ctx*/) override { }
  virtual void exitParam(typlypParser::ParamContext * /*ctx*/) override { }

  virtual void enterBlock(typlypParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(typlypParser::BlockContext * /*ctx*/) override { }

  virtual void enterStatement(typlypParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(typlypParser::StatementContext * /*ctx*/) override { }

  virtual void enterVarDecl(typlypParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(typlypParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterAssignment(typlypParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(typlypParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterArrayAssignment(typlypParser::ArrayAssignmentContext * /*ctx*/) override { }
  virtual void exitArrayAssignment(typlypParser::ArrayAssignmentContext * /*ctx*/) override { }

  virtual void enterReturnStatement(typlypParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(typlypParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(typlypParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(typlypParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterWhileStatement(typlypParser::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(typlypParser::WhileStatementContext * /*ctx*/) override { }

  virtual void enterForStatement(typlypParser::ForStatementContext * /*ctx*/) override { }
  virtual void exitForStatement(typlypParser::ForStatementContext * /*ctx*/) override { }

  virtual void enterPrintStatement(typlypParser::PrintStatementContext * /*ctx*/) override { }
  virtual void exitPrintStatement(typlypParser::PrintStatementContext * /*ctx*/) override { }

  virtual void enterExpr(typlypParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(typlypParser::ExprContext * /*ctx*/) override { }

  virtual void enterArgList(typlypParser::ArgListContext * /*ctx*/) override { }
  virtual void exitArgList(typlypParser::ArgListContext * /*ctx*/) override { }

  virtual void enterExprList(typlypParser::ExprListContext * /*ctx*/) override { }
  virtual void exitExprList(typlypParser::ExprListContext * /*ctx*/) override { }

  virtual void enterType(typlypParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(typlypParser::TypeContext * /*ctx*/) override { }

  virtual void enterVoidType(typlypParser::VoidTypeContext * /*ctx*/) override { }
  virtual void exitVoidType(typlypParser::VoidTypeContext * /*ctx*/) override { }

  virtual void enterScalarType(typlypParser::ScalarTypeContext * /*ctx*/) override { }
  virtual void exitScalarType(typlypParser::ScalarTypeContext * /*ctx*/) override { }

  virtual void enterArrayType(typlypParser::ArrayTypeContext * /*ctx*/) override { }
  virtual void exitArrayType(typlypParser::ArrayTypeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

