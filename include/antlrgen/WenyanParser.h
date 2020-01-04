
// Generated from Wenyan.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"

using namespace llvm;


class  WenyanParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, OP = 2, YI3 = 3, Return = 4, XiZhi = 5, ShiYi = 6, If = 7, 
    EndDeclare = 8, Else = 9, ForStart = 10, ForStart2 = 11, ForEnd = 12, 
    Variable = 13, Left = 14, Right = 15, Left4 = 16, Right4 = 17, Apply = 18, 
    At = 19, The = 20, End = 21, FunctionStart = 22, FunctionEnd = 23, VarPref = 24, 
    VariableStart = 25, DeclareMethod = 26, ThisIs = 27, Is = 28, Said = 29, 
    MethodOf = 30, EndStatment = 31, IHave = 32, NameAs = 33, ValueIs = 34, 
    DeclareDigit = 35, IntegerDigit = 36, FloatDigit = 37, IntegerDigitCN = 38, 
    FloatDigitCN = 39, Equal = 40, Unequal = 41, Character = 42, LineComment = 43, 
    PartComment = 44, WhiteSpace = 45
  };

  enum {
    RuleProgram = 0, RuleBlock = 1, RuleStatement = 2, RuleExpression = 3, 
    RuleReturnStatement = 4, RuleAssignStatement = 5, RuleIfStatement = 6, 
    RuleIfStartState = 7, RuleIfThenState = 8, RuleIfElseState = 9, RuleForStatement = 10, 
    RuleVariable = 11, RuleApplyStatement = 12, RuleApplyFunction = 13, 
    RuleFuncVars = 14, RuleDeclarefunction = 15, RuleVariables = 16, RuleDeclareNumber = 17, 
    RuleNumber = 18, RuleDigits = 19
  };

  WenyanParser(antlr4::TokenStream *input);
  ~WenyanParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class BlockContext;
  class StatementContext;
  class ExpressionContext;
  class ReturnStatementContext;
  class AssignStatementContext;
  class IfStatementContext;
  class IfStartStateContext;
  class IfThenStateContext;
  class IfElseStateContext;
  class ForStatementContext;
  class VariableContext;
  class ApplyStatementContext;
  class ApplyFunctionContext;
  class FuncVarsContext;
  class DeclarefunctionContext;
  class VariablesContext;
  class DeclareNumberContext;
  class NumberContext;
  class DigitsContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramContext* program();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    Value *value;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockContext* block();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclareNumberContext *declareNumber();
    DeclarefunctionContext *declarefunction();
    IfStatementContext *ifStatement();
    ForStatementContext *forStatement();
    ApplyStatementContext *applyStatement();
    AssignStatementContext *assignStatement();
    ReturnStatementContext *returnStatement();
    ExpressionContext *expression();
    Value *value;
    Function *theFunction;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    WenyanParser::NumberContext *fn = nullptr;;
    WenyanParser::VariableContext *fv = nullptr;;
    WenyanParser::NumberContext *sn = nullptr;;
    WenyanParser::VariableContext *sv = nullptr;;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> OP();
    antlr4::tree::TerminalNode* OP(size_t i);
    antlr4::tree::TerminalNode *YI3();
    std::vector<NumberContext *> number();
    NumberContext* number(size_t i);
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);
    Value *value;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  ReturnStatementContext : public antlr4::ParserRuleContext {
  public:
    ReturnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Return();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ReturnStatementContext* returnStatement();

  class  AssignStatementContext : public antlr4::ParserRuleContext {
  public:
    AssignStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *XiZhi();
    VariableContext *variable();
    antlr4::tree::TerminalNode *EndDeclare();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *ShiYi();
    Value *value;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AssignStatementContext* assignStatement();

  class  IfStatementContext : public antlr4::ParserRuleContext {
  public:
    IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IfStartStateContext *ifStartState();
    antlr4::tree::TerminalNode *EndDeclare();
    IfThenStateContext *ifThenState();
    IfElseStateContext *ifElseState();
    antlr4::tree::TerminalNode *EndStatment();
    BasicBlock *thenBB;
    BasicBlock *elseBB;
    BasicBlock *mergeBB;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfStatementContext* ifStatement();

  class  IfStartStateContext : public antlr4::ParserRuleContext {
  public:
    IfStartStateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *If();
    ExpressionContext *expression();
    BasicBlock *thenBB;
    BasicBlock *elseBB;
    BasicBlock *mergeBB;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfStartStateContext* ifStartState();

  class  IfThenStateContext : public antlr4::ParserRuleContext {
  public:
    IfThenStateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    BasicBlock *thenBB;
    BasicBlock *elseBB;
    BasicBlock *mergeBB;
    Value *value;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfThenStateContext* ifThenState();

  class  IfElseStateContext : public antlr4::ParserRuleContext {
  public:
    IfElseStateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Else();
    BlockContext *block();
    BasicBlock *thenBB;
    BasicBlock *elseBB;
    BasicBlock *mergeBB;
    Value *value;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfElseStateContext* ifElseState();

  class  ForStatementContext : public antlr4::ParserRuleContext {
  public:
    ForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ForStart();
    NumberContext *number();
    antlr4::tree::TerminalNode *ForStart2();
    BlockContext *block();
    antlr4::tree::TerminalNode *ForEnd();
    Function *theFunction;
    AllocaInst *alloca;
    BasicBlock *loopBB;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ForStatementContext* forStatement();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Variable();
    Value *value;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableContext* variable();

  class  ApplyStatementContext : public antlr4::ParserRuleContext {
  public:
    ApplyStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ApplyFunctionContext *applyFunction();
    Value *value;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ApplyStatementContext* applyStatement();

  class  ApplyFunctionContext : public antlr4::ParserRuleContext {
  public:
    WenyanParser::VariableContext *fv = nullptr;;
    ApplyFunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Apply();
    VariableContext *variable();
    antlr4::tree::TerminalNode *At();
    std::vector<FuncVarsContext *> funcVars();
    FuncVarsContext* funcVars(size_t i);
    Value *value;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ApplyFunctionContext* applyFunction();

  class  FuncVarsContext : public antlr4::ParserRuleContext {
  public:
    WenyanParser::NumberContext *sn = nullptr;;
    WenyanParser::VariableContext *sv = nullptr;;
    FuncVarsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberContext *number();
    VariableContext *variable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncVarsContext* funcVars();

  class  DeclarefunctionContext : public antlr4::ParserRuleContext {
  public:
    DeclarefunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DeclareMethod();
    antlr4::tree::TerminalNode *NameAs();
    VariableContext *variable();
    antlr4::tree::TerminalNode *FunctionStart();
    BlockContext *block();
    antlr4::tree::TerminalNode *FunctionEnd();
    VariablesContext *variables();
    antlr4::tree::TerminalNode *EndStatment();
    Function *theFunction;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DeclarefunctionContext* declarefunction();

  class  VariablesContext : public antlr4::ParserRuleContext {
  public:
    VariablesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VarPref();
    antlr4::tree::TerminalNode *VariableStart();
    std::vector<antlr4::tree::TerminalNode *> NameAs();
    antlr4::tree::TerminalNode* NameAs(size_t i);
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariablesContext* variables();

  class  DeclareNumberContext : public antlr4::ParserRuleContext {
  public:
    DeclareNumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DeclareDigit();
    std::vector<antlr4::tree::TerminalNode *> ValueIs();
    antlr4::tree::TerminalNode* ValueIs(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NameAs();
    antlr4::tree::TerminalNode* NameAs(size_t i);
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);
    Value *value;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DeclareNumberContext* declareNumber();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    WenyanParser::DigitsContext *n = nullptr;;
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Left();
    antlr4::tree::TerminalNode *Right();
    DigitsContext *digits();
    Value *value;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NumberContext* number();

  class  DigitsContext : public antlr4::ParserRuleContext {
  public:
    DigitsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DigitsContext() = default;
    void copyFrom(DigitsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NumberFloatContext : public DigitsContext {
  public:
    NumberFloatContext(DigitsContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> FloatDigit();
    antlr4::tree::TerminalNode* FloatDigit(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  NumberFloatCNContext : public DigitsContext {
  public:
    NumberFloatCNContext(DigitsContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> FloatDigitCN();
    antlr4::tree::TerminalNode* FloatDigitCN(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  NumberIntegerContext : public DigitsContext {
  public:
    NumberIntegerContext(DigitsContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> IntegerDigit();
    antlr4::tree::TerminalNode* IntegerDigit(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  NumberIntegerCNContext : public DigitsContext {
  public:
    NumberIntegerCNContext(DigitsContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> IntegerDigitCN();
    antlr4::tree::TerminalNode* IntegerDigitCN(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  DigitsContext* digits();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

