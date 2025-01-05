
// Generated from C:/Users/ladyp/CLionProjects/tyaplyap/grammar/typlyp.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "typlypVisitor.h"


/**
 * This class provides an empty implementation of typlypVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  typlypBaseVisitor : public typlypVisitor {
public:

  virtual std::any visitProgram(typlypParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDecl(typlypParser::FunctionDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExternalDecl(typlypParser::ExternalDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParamList(typlypParser::ParamListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam(typlypParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(typlypParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(typlypParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(typlypParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(typlypParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayAssignment(typlypParser::ArrayAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStatement(typlypParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStatement(typlypParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStatement(typlypParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStatement(typlypParser::ForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForInit(typlypParser::ForInitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForUpdate(typlypParser::ForUpdateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(typlypParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgList(typlypParser::ArgListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprList(typlypParser::ExprListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(typlypParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVoidType(typlypParser::VoidTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScalarType(typlypParser::ScalarTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayType(typlypParser::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }


};

