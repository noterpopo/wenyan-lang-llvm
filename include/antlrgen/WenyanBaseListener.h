
// Generated from Wenyan.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "WenyanListener.h"


/**
 * This class provides an empty implementation of WenyanListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  WenyanBaseListener : public WenyanListener {
public:

  virtual void enterProgram(WenyanParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(WenyanParser::ProgramContext * /*ctx*/) override { }

  virtual void enterBlock(WenyanParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(WenyanParser::BlockContext * /*ctx*/) override { }

  virtual void enterStatement(WenyanParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(WenyanParser::StatementContext * /*ctx*/) override { }

  virtual void enterExpression(WenyanParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(WenyanParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterIfStatement(WenyanParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(WenyanParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterForStatement(WenyanParser::ForStatementContext * /*ctx*/) override { }
  virtual void exitForStatement(WenyanParser::ForStatementContext * /*ctx*/) override { }

  virtual void enterAssignStatement(WenyanParser::AssignStatementContext * /*ctx*/) override { }
  virtual void exitAssignStatement(WenyanParser::AssignStatementContext * /*ctx*/) override { }

  virtual void enterVariable(WenyanParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(WenyanParser::VariableContext * /*ctx*/) override { }

  virtual void enterApplyStatement(WenyanParser::ApplyStatementContext * /*ctx*/) override { }
  virtual void exitApplyStatement(WenyanParser::ApplyStatementContext * /*ctx*/) override { }

  virtual void enterApplyFunction(WenyanParser::ApplyFunctionContext * /*ctx*/) override { }
  virtual void exitApplyFunction(WenyanParser::ApplyFunctionContext * /*ctx*/) override { }

  virtual void enterDeclarefunction(WenyanParser::DeclarefunctionContext * /*ctx*/) override { }
  virtual void exitDeclarefunction(WenyanParser::DeclarefunctionContext * /*ctx*/) override { }

  virtual void enterVariables(WenyanParser::VariablesContext * /*ctx*/) override { }
  virtual void exitVariables(WenyanParser::VariablesContext * /*ctx*/) override { }

  virtual void enterDeclareNumber(WenyanParser::DeclareNumberContext * /*ctx*/) override { }
  virtual void exitDeclareNumber(WenyanParser::DeclareNumberContext * /*ctx*/) override { }

  virtual void enterNumber(WenyanParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(WenyanParser::NumberContext * /*ctx*/) override { }

  virtual void enterNumberInteger(WenyanParser::NumberIntegerContext * /*ctx*/) override { }
  virtual void exitNumberInteger(WenyanParser::NumberIntegerContext * /*ctx*/) override { }

  virtual void enterNumberIntegerCN(WenyanParser::NumberIntegerCNContext * /*ctx*/) override { }
  virtual void exitNumberIntegerCN(WenyanParser::NumberIntegerCNContext * /*ctx*/) override { }

  virtual void enterNumberFloat(WenyanParser::NumberFloatContext * /*ctx*/) override { }
  virtual void exitNumberFloat(WenyanParser::NumberFloatContext * /*ctx*/) override { }

  virtual void enterNumberFloatCN(WenyanParser::NumberFloatCNContext * /*ctx*/) override { }
  virtual void exitNumberFloatCN(WenyanParser::NumberFloatCNContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

