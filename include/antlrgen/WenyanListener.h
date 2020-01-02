
// Generated from Wenyan.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "WenyanParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by WenyanParser.
 */
class  WenyanListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(WenyanParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(WenyanParser::ProgramContext *ctx) = 0;

  virtual void enterBlock(WenyanParser::BlockContext *ctx) = 0;
  virtual void exitBlock(WenyanParser::BlockContext *ctx) = 0;

  virtual void enterStatement(WenyanParser::StatementContext *ctx) = 0;
  virtual void exitStatement(WenyanParser::StatementContext *ctx) = 0;

  virtual void enterExpression(WenyanParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(WenyanParser::ExpressionContext *ctx) = 0;

  virtual void enterAssignStatement(WenyanParser::AssignStatementContext *ctx) = 0;
  virtual void exitAssignStatement(WenyanParser::AssignStatementContext *ctx) = 0;

  virtual void enterIfStatement(WenyanParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(WenyanParser::IfStatementContext *ctx) = 0;

  virtual void enterIfStartState(WenyanParser::IfStartStateContext *ctx) = 0;
  virtual void exitIfStartState(WenyanParser::IfStartStateContext *ctx) = 0;

  virtual void enterIfThenState(WenyanParser::IfThenStateContext *ctx) = 0;
  virtual void exitIfThenState(WenyanParser::IfThenStateContext *ctx) = 0;

  virtual void enterIfElseState(WenyanParser::IfElseStateContext *ctx) = 0;
  virtual void exitIfElseState(WenyanParser::IfElseStateContext *ctx) = 0;

  virtual void enterForStatement(WenyanParser::ForStatementContext *ctx) = 0;
  virtual void exitForStatement(WenyanParser::ForStatementContext *ctx) = 0;

  virtual void enterVariable(WenyanParser::VariableContext *ctx) = 0;
  virtual void exitVariable(WenyanParser::VariableContext *ctx) = 0;

  virtual void enterApplyStatement(WenyanParser::ApplyStatementContext *ctx) = 0;
  virtual void exitApplyStatement(WenyanParser::ApplyStatementContext *ctx) = 0;

  virtual void enterApplyFunction(WenyanParser::ApplyFunctionContext *ctx) = 0;
  virtual void exitApplyFunction(WenyanParser::ApplyFunctionContext *ctx) = 0;

  virtual void enterFuncVars(WenyanParser::FuncVarsContext *ctx) = 0;
  virtual void exitFuncVars(WenyanParser::FuncVarsContext *ctx) = 0;

  virtual void enterDeclarefunction(WenyanParser::DeclarefunctionContext *ctx) = 0;
  virtual void exitDeclarefunction(WenyanParser::DeclarefunctionContext *ctx) = 0;

  virtual void enterVariables(WenyanParser::VariablesContext *ctx) = 0;
  virtual void exitVariables(WenyanParser::VariablesContext *ctx) = 0;

  virtual void enterDeclareNumber(WenyanParser::DeclareNumberContext *ctx) = 0;
  virtual void exitDeclareNumber(WenyanParser::DeclareNumberContext *ctx) = 0;

  virtual void enterNumber(WenyanParser::NumberContext *ctx) = 0;
  virtual void exitNumber(WenyanParser::NumberContext *ctx) = 0;

  virtual void enterNumberInteger(WenyanParser::NumberIntegerContext *ctx) = 0;
  virtual void exitNumberInteger(WenyanParser::NumberIntegerContext *ctx) = 0;

  virtual void enterNumberIntegerCN(WenyanParser::NumberIntegerCNContext *ctx) = 0;
  virtual void exitNumberIntegerCN(WenyanParser::NumberIntegerCNContext *ctx) = 0;

  virtual void enterNumberFloat(WenyanParser::NumberFloatContext *ctx) = 0;
  virtual void exitNumberFloat(WenyanParser::NumberFloatContext *ctx) = 0;

  virtual void enterNumberFloatCN(WenyanParser::NumberFloatCNContext *ctx) = 0;
  virtual void exitNumberFloatCN(WenyanParser::NumberFloatCNContext *ctx) = 0;


};

