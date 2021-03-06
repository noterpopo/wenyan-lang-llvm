
// Generated from Wenyan.g4 by ANTLR 4.7.2


#include "antlrgen/WenyanListener.h"

#include "antlrgen/WenyanParser.h"


using namespace antlrcpp;
using namespace antlr4;

WenyanParser::WenyanParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

WenyanParser::~WenyanParser() {
  delete _interpreter;
}

std::string WenyanParser::getGrammarFileName() const {
  return "Wenyan.g4";
}

const std::vector<std::string>& WenyanParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& WenyanParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

WenyanParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WenyanParser::ProgramContext::EOF() {
  return getToken(WenyanParser::EOF, 0);
}

std::vector<WenyanParser::BlockContext *> WenyanParser::ProgramContext::block() {
  return getRuleContexts<WenyanParser::BlockContext>();
}

WenyanParser::BlockContext* WenyanParser::ProgramContext::block(size_t i) {
  return getRuleContext<WenyanParser::BlockContext>(i);
}


size_t WenyanParser::ProgramContext::getRuleIndex() const {
  return WenyanParser::RuleProgram;
}

void WenyanParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void WenyanParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

WenyanParser::ProgramContext* WenyanParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, WenyanParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WenyanParser::OP)
      | (1ULL << WenyanParser::Return)
      | (1ULL << WenyanParser::XiZhi)
      | (1ULL << WenyanParser::If)
      | (1ULL << WenyanParser::ForStart)
      | (1ULL << WenyanParser::Variable)
      | (1ULL << WenyanParser::Left)
      | (1ULL << WenyanParser::Apply)
      | (1ULL << WenyanParser::DeclareMethod)
      | (1ULL << WenyanParser::DeclareDigit)
      | (1ULL << WenyanParser::IntegerDigit)
      | (1ULL << WenyanParser::FloatDigit)
      | (1ULL << WenyanParser::IntegerDigitCN)
      | (1ULL << WenyanParser::FloatDigitCN))) != 0)) {
      setState(40);
      block();
      setState(45);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(46);
    match(WenyanParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

WenyanParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<WenyanParser::StatementContext *> WenyanParser::BlockContext::statement() {
  return getRuleContexts<WenyanParser::StatementContext>();
}

WenyanParser::StatementContext* WenyanParser::BlockContext::statement(size_t i) {
  return getRuleContext<WenyanParser::StatementContext>(i);
}


size_t WenyanParser::BlockContext::getRuleIndex() const {
  return WenyanParser::RuleBlock;
}

void WenyanParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void WenyanParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

WenyanParser::BlockContext* WenyanParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 2, WenyanParser::RuleBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(49); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(48);
              statement();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(51); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

WenyanParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WenyanParser::DeclareNumberContext* WenyanParser::StatementContext::declareNumber() {
  return getRuleContext<WenyanParser::DeclareNumberContext>(0);
}

WenyanParser::DeclarefunctionContext* WenyanParser::StatementContext::declarefunction() {
  return getRuleContext<WenyanParser::DeclarefunctionContext>(0);
}

WenyanParser::IfStatementContext* WenyanParser::StatementContext::ifStatement() {
  return getRuleContext<WenyanParser::IfStatementContext>(0);
}

WenyanParser::ForStatementContext* WenyanParser::StatementContext::forStatement() {
  return getRuleContext<WenyanParser::ForStatementContext>(0);
}

WenyanParser::AssignStatementContext* WenyanParser::StatementContext::assignStatement() {
  return getRuleContext<WenyanParser::AssignStatementContext>(0);
}

WenyanParser::ReturnStatementContext* WenyanParser::StatementContext::returnStatement() {
  return getRuleContext<WenyanParser::ReturnStatementContext>(0);
}

WenyanParser::ExpressionContext* WenyanParser::StatementContext::expression() {
  return getRuleContext<WenyanParser::ExpressionContext>(0);
}


size_t WenyanParser::StatementContext::getRuleIndex() const {
  return WenyanParser::RuleStatement;
}

void WenyanParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void WenyanParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

WenyanParser::StatementContext* WenyanParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, WenyanParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(60);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WenyanParser::DeclareDigit: {
        enterOuterAlt(_localctx, 1);
        setState(53);
        declareNumber();
        break;
      }

      case WenyanParser::DeclareMethod: {
        enterOuterAlt(_localctx, 2);
        setState(54);
        declarefunction();
        break;
      }

      case WenyanParser::If: {
        enterOuterAlt(_localctx, 3);
        setState(55);
        ifStatement();
        break;
      }

      case WenyanParser::ForStart: {
        enterOuterAlt(_localctx, 4);
        setState(56);
        forStatement();
        break;
      }

      case WenyanParser::XiZhi: {
        enterOuterAlt(_localctx, 5);
        setState(57);
        assignStatement();
        break;
      }

      case WenyanParser::Return: {
        enterOuterAlt(_localctx, 6);
        setState(58);
        returnStatement();
        break;
      }

      case WenyanParser::OP:
      case WenyanParser::Variable:
      case WenyanParser::Left:
      case WenyanParser::Apply:
      case WenyanParser::IntegerDigit:
      case WenyanParser::FloatDigit:
      case WenyanParser::IntegerDigitCN:
      case WenyanParser::FloatDigitCN: {
        enterOuterAlt(_localctx, 7);
        setState(59);
        expression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

WenyanParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> WenyanParser::ExpressionContext::OP() {
  return getTokens(WenyanParser::OP);
}

tree::TerminalNode* WenyanParser::ExpressionContext::OP(size_t i) {
  return getToken(WenyanParser::OP, i);
}

tree::TerminalNode* WenyanParser::ExpressionContext::YI3() {
  return getToken(WenyanParser::YI3, 0);
}

std::vector<WenyanParser::NumberContext *> WenyanParser::ExpressionContext::number() {
  return getRuleContexts<WenyanParser::NumberContext>();
}

WenyanParser::NumberContext* WenyanParser::ExpressionContext::number(size_t i) {
  return getRuleContext<WenyanParser::NumberContext>(i);
}

std::vector<WenyanParser::VariableContext *> WenyanParser::ExpressionContext::variable() {
  return getRuleContexts<WenyanParser::VariableContext>();
}

WenyanParser::VariableContext* WenyanParser::ExpressionContext::variable(size_t i) {
  return getRuleContext<WenyanParser::VariableContext>(i);
}

WenyanParser::ApplyStatementContext* WenyanParser::ExpressionContext::applyStatement() {
  return getRuleContext<WenyanParser::ApplyStatementContext>(0);
}


size_t WenyanParser::ExpressionContext::getRuleIndex() const {
  return WenyanParser::RuleExpression;
}

void WenyanParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void WenyanParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

WenyanParser::ExpressionContext* WenyanParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 6, WenyanParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(87);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WenyanParser::OP: {
        enterOuterAlt(_localctx, 1);
        setState(62);
        match(WenyanParser::OP);
        setState(65);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case WenyanParser::Left:
          case WenyanParser::IntegerDigit:
          case WenyanParser::FloatDigit:
          case WenyanParser::IntegerDigitCN:
          case WenyanParser::FloatDigitCN: {
            setState(63);
            dynamic_cast<ExpressionContext *>(_localctx)->fn = number();
            break;
          }

          case WenyanParser::Variable: {
            setState(64);
            dynamic_cast<ExpressionContext *>(_localctx)->fv = variable();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(67);
        match(WenyanParser::YI3);
        setState(70);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case WenyanParser::Left:
          case WenyanParser::IntegerDigit:
          case WenyanParser::FloatDigit:
          case WenyanParser::IntegerDigitCN:
          case WenyanParser::FloatDigitCN: {
            setState(68);
            dynamic_cast<ExpressionContext *>(_localctx)->sn = number();
            break;
          }

          case WenyanParser::Variable: {
            setState(69);
            dynamic_cast<ExpressionContext *>(_localctx)->sv = variable();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case WenyanParser::Variable:
      case WenyanParser::Left:
      case WenyanParser::IntegerDigit:
      case WenyanParser::FloatDigit:
      case WenyanParser::IntegerDigitCN:
      case WenyanParser::FloatDigitCN: {
        enterOuterAlt(_localctx, 2);
        setState(74);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case WenyanParser::Left:
          case WenyanParser::IntegerDigit:
          case WenyanParser::FloatDigit:
          case WenyanParser::IntegerDigitCN:
          case WenyanParser::FloatDigitCN: {
            setState(72);
            dynamic_cast<ExpressionContext *>(_localctx)->fn = number();
            break;
          }

          case WenyanParser::Variable: {
            setState(73);
            dynamic_cast<ExpressionContext *>(_localctx)->fv = variable();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(83);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(76);
            match(WenyanParser::OP);
            setState(79);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case WenyanParser::Left:
              case WenyanParser::IntegerDigit:
              case WenyanParser::FloatDigit:
              case WenyanParser::IntegerDigitCN:
              case WenyanParser::FloatDigitCN: {
                setState(77);
                dynamic_cast<ExpressionContext *>(_localctx)->sn = number();
                break;
              }

              case WenyanParser::Variable: {
                setState(78);
                dynamic_cast<ExpressionContext *>(_localctx)->sv = variable();
                break;
              }

            default:
              throw NoViableAltException(this);
            } 
          }
          setState(85);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
        }
        break;
      }

      case WenyanParser::Apply: {
        enterOuterAlt(_localctx, 3);
        setState(86);
        applyStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

WenyanParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WenyanParser::ReturnStatementContext::Return() {
  return getToken(WenyanParser::Return, 0);
}

WenyanParser::ExpressionContext* WenyanParser::ReturnStatementContext::expression() {
  return getRuleContext<WenyanParser::ExpressionContext>(0);
}


size_t WenyanParser::ReturnStatementContext::getRuleIndex() const {
  return WenyanParser::RuleReturnStatement;
}

void WenyanParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void WenyanParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}

WenyanParser::ReturnStatementContext* WenyanParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 8, WenyanParser::RuleReturnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    match(WenyanParser::Return);
    setState(90);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignStatementContext ------------------------------------------------------------------

WenyanParser::AssignStatementContext::AssignStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WenyanParser::AssignStatementContext::XiZhi() {
  return getToken(WenyanParser::XiZhi, 0);
}

WenyanParser::VariableContext* WenyanParser::AssignStatementContext::variable() {
  return getRuleContext<WenyanParser::VariableContext>(0);
}

tree::TerminalNode* WenyanParser::AssignStatementContext::EndDeclare() {
  return getToken(WenyanParser::EndDeclare, 0);
}

WenyanParser::ExpressionContext* WenyanParser::AssignStatementContext::expression() {
  return getRuleContext<WenyanParser::ExpressionContext>(0);
}

tree::TerminalNode* WenyanParser::AssignStatementContext::ShiYi() {
  return getToken(WenyanParser::ShiYi, 0);
}


size_t WenyanParser::AssignStatementContext::getRuleIndex() const {
  return WenyanParser::RuleAssignStatement;
}

void WenyanParser::AssignStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignStatement(this);
}

void WenyanParser::AssignStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignStatement(this);
}

WenyanParser::AssignStatementContext* WenyanParser::assignStatement() {
  AssignStatementContext *_localctx = _tracker.createInstance<AssignStatementContext>(_ctx, getState());
  enterRule(_localctx, 10, WenyanParser::RuleAssignStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    match(WenyanParser::XiZhi);
    setState(93);
    variable();
    setState(94);
    match(WenyanParser::EndDeclare);
    setState(95);
    match(WenyanParser::T__0);
    setState(96);
    expression();
    setState(97);
    match(WenyanParser::ShiYi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

WenyanParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WenyanParser::IfStartStateContext* WenyanParser::IfStatementContext::ifStartState() {
  return getRuleContext<WenyanParser::IfStartStateContext>(0);
}

tree::TerminalNode* WenyanParser::IfStatementContext::EndDeclare() {
  return getToken(WenyanParser::EndDeclare, 0);
}

WenyanParser::IfThenStateContext* WenyanParser::IfStatementContext::ifThenState() {
  return getRuleContext<WenyanParser::IfThenStateContext>(0);
}

WenyanParser::IfElseStateContext* WenyanParser::IfStatementContext::ifElseState() {
  return getRuleContext<WenyanParser::IfElseStateContext>(0);
}

tree::TerminalNode* WenyanParser::IfStatementContext::EndStatment() {
  return getToken(WenyanParser::EndStatment, 0);
}


size_t WenyanParser::IfStatementContext::getRuleIndex() const {
  return WenyanParser::RuleIfStatement;
}

void WenyanParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void WenyanParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}

WenyanParser::IfStatementContext* WenyanParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 12, WenyanParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    ifStartState();
    setState(100);
    match(WenyanParser::EndDeclare);
    setState(101);
    ifThenState();
    setState(102);
    ifElseState();
    setState(104);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(103);
      match(WenyanParser::EndStatment);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStartStateContext ------------------------------------------------------------------

WenyanParser::IfStartStateContext::IfStartStateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WenyanParser::IfStartStateContext::If() {
  return getToken(WenyanParser::If, 0);
}

WenyanParser::ExpressionContext* WenyanParser::IfStartStateContext::expression() {
  return getRuleContext<WenyanParser::ExpressionContext>(0);
}


size_t WenyanParser::IfStartStateContext::getRuleIndex() const {
  return WenyanParser::RuleIfStartState;
}

void WenyanParser::IfStartStateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStartState(this);
}

void WenyanParser::IfStartStateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStartState(this);
}

WenyanParser::IfStartStateContext* WenyanParser::ifStartState() {
  IfStartStateContext *_localctx = _tracker.createInstance<IfStartStateContext>(_ctx, getState());
  enterRule(_localctx, 14, WenyanParser::RuleIfStartState);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    match(WenyanParser::If);
    setState(107);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfThenStateContext ------------------------------------------------------------------

WenyanParser::IfThenStateContext::IfThenStateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WenyanParser::BlockContext* WenyanParser::IfThenStateContext::block() {
  return getRuleContext<WenyanParser::BlockContext>(0);
}


size_t WenyanParser::IfThenStateContext::getRuleIndex() const {
  return WenyanParser::RuleIfThenState;
}

void WenyanParser::IfThenStateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfThenState(this);
}

void WenyanParser::IfThenStateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfThenState(this);
}

WenyanParser::IfThenStateContext* WenyanParser::ifThenState() {
  IfThenStateContext *_localctx = _tracker.createInstance<IfThenStateContext>(_ctx, getState());
  enterRule(_localctx, 16, WenyanParser::RuleIfThenState);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfElseStateContext ------------------------------------------------------------------

WenyanParser::IfElseStateContext::IfElseStateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WenyanParser::IfElseStateContext::Else() {
  return getToken(WenyanParser::Else, 0);
}

WenyanParser::BlockContext* WenyanParser::IfElseStateContext::block() {
  return getRuleContext<WenyanParser::BlockContext>(0);
}


size_t WenyanParser::IfElseStateContext::getRuleIndex() const {
  return WenyanParser::RuleIfElseState;
}

void WenyanParser::IfElseStateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfElseState(this);
}

void WenyanParser::IfElseStateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfElseState(this);
}

WenyanParser::IfElseStateContext* WenyanParser::ifElseState() {
  IfElseStateContext *_localctx = _tracker.createInstance<IfElseStateContext>(_ctx, getState());
  enterRule(_localctx, 18, WenyanParser::RuleIfElseState);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    match(WenyanParser::Else);
    setState(112);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

WenyanParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WenyanParser::ForStatementContext::ForStart() {
  return getToken(WenyanParser::ForStart, 0);
}

WenyanParser::NumberContext* WenyanParser::ForStatementContext::number() {
  return getRuleContext<WenyanParser::NumberContext>(0);
}

tree::TerminalNode* WenyanParser::ForStatementContext::ForStart2() {
  return getToken(WenyanParser::ForStart2, 0);
}

WenyanParser::BlockContext* WenyanParser::ForStatementContext::block() {
  return getRuleContext<WenyanParser::BlockContext>(0);
}

tree::TerminalNode* WenyanParser::ForStatementContext::ForEnd() {
  return getToken(WenyanParser::ForEnd, 0);
}


size_t WenyanParser::ForStatementContext::getRuleIndex() const {
  return WenyanParser::RuleForStatement;
}

void WenyanParser::ForStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStatement(this);
}

void WenyanParser::ForStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStatement(this);
}

WenyanParser::ForStatementContext* WenyanParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 20, WenyanParser::RuleForStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    match(WenyanParser::ForStart);
    setState(115);
    number();
    setState(116);
    match(WenyanParser::ForStart2);
    setState(117);
    block();
    setState(118);
    match(WenyanParser::ForEnd);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

WenyanParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WenyanParser::VariableContext::Variable() {
  return getToken(WenyanParser::Variable, 0);
}


size_t WenyanParser::VariableContext::getRuleIndex() const {
  return WenyanParser::RuleVariable;
}

void WenyanParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void WenyanParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

WenyanParser::VariableContext* WenyanParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 22, WenyanParser::RuleVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    match(WenyanParser::Variable);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ApplyStatementContext ------------------------------------------------------------------

WenyanParser::ApplyStatementContext::ApplyStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WenyanParser::ApplyFunctionContext* WenyanParser::ApplyStatementContext::applyFunction() {
  return getRuleContext<WenyanParser::ApplyFunctionContext>(0);
}


size_t WenyanParser::ApplyStatementContext::getRuleIndex() const {
  return WenyanParser::RuleApplyStatement;
}

void WenyanParser::ApplyStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterApplyStatement(this);
}

void WenyanParser::ApplyStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitApplyStatement(this);
}

WenyanParser::ApplyStatementContext* WenyanParser::applyStatement() {
  ApplyStatementContext *_localctx = _tracker.createInstance<ApplyStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, WenyanParser::RuleApplyStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    applyFunction();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ApplyFunctionContext ------------------------------------------------------------------

WenyanParser::ApplyFunctionContext::ApplyFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WenyanParser::ApplyFunctionContext::Apply() {
  return getToken(WenyanParser::Apply, 0);
}

WenyanParser::VariableContext* WenyanParser::ApplyFunctionContext::variable() {
  return getRuleContext<WenyanParser::VariableContext>(0);
}

tree::TerminalNode* WenyanParser::ApplyFunctionContext::At() {
  return getToken(WenyanParser::At, 0);
}

std::vector<WenyanParser::FuncVarsContext *> WenyanParser::ApplyFunctionContext::funcVars() {
  return getRuleContexts<WenyanParser::FuncVarsContext>();
}

WenyanParser::FuncVarsContext* WenyanParser::ApplyFunctionContext::funcVars(size_t i) {
  return getRuleContext<WenyanParser::FuncVarsContext>(i);
}


size_t WenyanParser::ApplyFunctionContext::getRuleIndex() const {
  return WenyanParser::RuleApplyFunction;
}

void WenyanParser::ApplyFunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterApplyFunction(this);
}

void WenyanParser::ApplyFunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitApplyFunction(this);
}

WenyanParser::ApplyFunctionContext* WenyanParser::applyFunction() {
  ApplyFunctionContext *_localctx = _tracker.createInstance<ApplyFunctionContext>(_ctx, getState());
  enterRule(_localctx, 26, WenyanParser::RuleApplyFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(124);
    match(WenyanParser::Apply);
    setState(125);
    dynamic_cast<ApplyFunctionContext *>(_localctx)->fv = variable();
    setState(127);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WenyanParser::At) {
      setState(126);
      match(WenyanParser::At);
    }
    setState(132);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(129);
        funcVars(); 
      }
      setState(134);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncVarsContext ------------------------------------------------------------------

WenyanParser::FuncVarsContext::FuncVarsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WenyanParser::NumberContext* WenyanParser::FuncVarsContext::number() {
  return getRuleContext<WenyanParser::NumberContext>(0);
}

WenyanParser::VariableContext* WenyanParser::FuncVarsContext::variable() {
  return getRuleContext<WenyanParser::VariableContext>(0);
}


size_t WenyanParser::FuncVarsContext::getRuleIndex() const {
  return WenyanParser::RuleFuncVars;
}

void WenyanParser::FuncVarsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncVars(this);
}

void WenyanParser::FuncVarsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncVars(this);
}

WenyanParser::FuncVarsContext* WenyanParser::funcVars() {
  FuncVarsContext *_localctx = _tracker.createInstance<FuncVarsContext>(_ctx, getState());
  enterRule(_localctx, 28, WenyanParser::RuleFuncVars);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(137);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WenyanParser::Left:
      case WenyanParser::IntegerDigit:
      case WenyanParser::FloatDigit:
      case WenyanParser::IntegerDigitCN:
      case WenyanParser::FloatDigitCN: {
        enterOuterAlt(_localctx, 1);
        setState(135);
        dynamic_cast<FuncVarsContext *>(_localctx)->sn = number();
        break;
      }

      case WenyanParser::Variable: {
        enterOuterAlt(_localctx, 2);
        setState(136);
        dynamic_cast<FuncVarsContext *>(_localctx)->sv = variable();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarefunctionContext ------------------------------------------------------------------

WenyanParser::DeclarefunctionContext::DeclarefunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WenyanParser::DeclarefunctionContext::DeclareMethod() {
  return getToken(WenyanParser::DeclareMethod, 0);
}

tree::TerminalNode* WenyanParser::DeclarefunctionContext::NameAs() {
  return getToken(WenyanParser::NameAs, 0);
}

WenyanParser::VariableContext* WenyanParser::DeclarefunctionContext::variable() {
  return getRuleContext<WenyanParser::VariableContext>(0);
}

tree::TerminalNode* WenyanParser::DeclarefunctionContext::FunctionStart() {
  return getToken(WenyanParser::FunctionStart, 0);
}

WenyanParser::BlockContext* WenyanParser::DeclarefunctionContext::block() {
  return getRuleContext<WenyanParser::BlockContext>(0);
}

tree::TerminalNode* WenyanParser::DeclarefunctionContext::FunctionEnd() {
  return getToken(WenyanParser::FunctionEnd, 0);
}

WenyanParser::VariablesContext* WenyanParser::DeclarefunctionContext::variables() {
  return getRuleContext<WenyanParser::VariablesContext>(0);
}

tree::TerminalNode* WenyanParser::DeclarefunctionContext::EndStatment() {
  return getToken(WenyanParser::EndStatment, 0);
}


size_t WenyanParser::DeclarefunctionContext::getRuleIndex() const {
  return WenyanParser::RuleDeclarefunction;
}

void WenyanParser::DeclarefunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarefunction(this);
}

void WenyanParser::DeclarefunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarefunction(this);
}

WenyanParser::DeclarefunctionContext* WenyanParser::declarefunction() {
  DeclarefunctionContext *_localctx = _tracker.createInstance<DeclarefunctionContext>(_ctx, getState());
  enterRule(_localctx, 30, WenyanParser::RuleDeclarefunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    match(WenyanParser::DeclareMethod);
    setState(140);
    match(WenyanParser::NameAs);
    setState(141);
    variable();
    setState(143);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WenyanParser::VarPref) {
      setState(142);
      variables();
    }
    setState(145);
    match(WenyanParser::FunctionStart);
    setState(146);
    block();
    setState(147);
    match(WenyanParser::FunctionEnd);
    setState(149);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(148);
      match(WenyanParser::EndStatment);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariablesContext ------------------------------------------------------------------

WenyanParser::VariablesContext::VariablesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WenyanParser::VariablesContext::VarPref() {
  return getToken(WenyanParser::VarPref, 0);
}

tree::TerminalNode* WenyanParser::VariablesContext::VariableStart() {
  return getToken(WenyanParser::VariableStart, 0);
}

std::vector<tree::TerminalNode *> WenyanParser::VariablesContext::NameAs() {
  return getTokens(WenyanParser::NameAs);
}

tree::TerminalNode* WenyanParser::VariablesContext::NameAs(size_t i) {
  return getToken(WenyanParser::NameAs, i);
}

std::vector<WenyanParser::VariableContext *> WenyanParser::VariablesContext::variable() {
  return getRuleContexts<WenyanParser::VariableContext>();
}

WenyanParser::VariableContext* WenyanParser::VariablesContext::variable(size_t i) {
  return getRuleContext<WenyanParser::VariableContext>(i);
}


size_t WenyanParser::VariablesContext::getRuleIndex() const {
  return WenyanParser::RuleVariables;
}

void WenyanParser::VariablesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariables(this);
}

void WenyanParser::VariablesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariables(this);
}

WenyanParser::VariablesContext* WenyanParser::variables() {
  VariablesContext *_localctx = _tracker.createInstance<VariablesContext>(_ctx, getState());
  enterRule(_localctx, 32, WenyanParser::RuleVariables);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    match(WenyanParser::VarPref);
    setState(152);
    match(WenyanParser::VariableStart);
    setState(155); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(153);
      match(WenyanParser::NameAs);
      setState(154);
      variable();
      setState(157); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == WenyanParser::NameAs);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclareNumberContext ------------------------------------------------------------------

WenyanParser::DeclareNumberContext::DeclareNumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WenyanParser::DeclareNumberContext::DeclareDigit() {
  return getToken(WenyanParser::DeclareDigit, 0);
}

std::vector<tree::TerminalNode *> WenyanParser::DeclareNumberContext::ValueIs() {
  return getTokens(WenyanParser::ValueIs);
}

tree::TerminalNode* WenyanParser::DeclareNumberContext::ValueIs(size_t i) {
  return getToken(WenyanParser::ValueIs, i);
}

std::vector<WenyanParser::ExpressionContext *> WenyanParser::DeclareNumberContext::expression() {
  return getRuleContexts<WenyanParser::ExpressionContext>();
}

WenyanParser::ExpressionContext* WenyanParser::DeclareNumberContext::expression(size_t i) {
  return getRuleContext<WenyanParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> WenyanParser::DeclareNumberContext::NameAs() {
  return getTokens(WenyanParser::NameAs);
}

tree::TerminalNode* WenyanParser::DeclareNumberContext::NameAs(size_t i) {
  return getToken(WenyanParser::NameAs, i);
}

std::vector<WenyanParser::VariableContext *> WenyanParser::DeclareNumberContext::variable() {
  return getRuleContexts<WenyanParser::VariableContext>();
}

WenyanParser::VariableContext* WenyanParser::DeclareNumberContext::variable(size_t i) {
  return getRuleContext<WenyanParser::VariableContext>(i);
}


size_t WenyanParser::DeclareNumberContext::getRuleIndex() const {
  return WenyanParser::RuleDeclareNumber;
}

void WenyanParser::DeclareNumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclareNumber(this);
}

void WenyanParser::DeclareNumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclareNumber(this);
}

WenyanParser::DeclareNumberContext* WenyanParser::declareNumber() {
  DeclareNumberContext *_localctx = _tracker.createInstance<DeclareNumberContext>(_ctx, getState());
  enterRule(_localctx, 34, WenyanParser::RuleDeclareNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(WenyanParser::DeclareDigit);
    setState(164);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WenyanParser::ValueIs) {
      setState(160);
      match(WenyanParser::ValueIs);
      setState(161);
      expression();
      setState(166);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(169); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(167);
      match(WenyanParser::NameAs);
      setState(168);
      variable();
      setState(171); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == WenyanParser::NameAs);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

WenyanParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WenyanParser::NumberContext::Left() {
  return getToken(WenyanParser::Left, 0);
}

tree::TerminalNode* WenyanParser::NumberContext::Right() {
  return getToken(WenyanParser::Right, 0);
}

WenyanParser::DigitsContext* WenyanParser::NumberContext::digits() {
  return getRuleContext<WenyanParser::DigitsContext>(0);
}


size_t WenyanParser::NumberContext::getRuleIndex() const {
  return WenyanParser::RuleNumber;
}

void WenyanParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void WenyanParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}

WenyanParser::NumberContext* WenyanParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 36, WenyanParser::RuleNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(178);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WenyanParser::Left: {
        enterOuterAlt(_localctx, 1);
        setState(173);
        match(WenyanParser::Left);
        setState(174);
        dynamic_cast<NumberContext *>(_localctx)->n = digits();
        setState(175);
        match(WenyanParser::Right);
        break;
      }

      case WenyanParser::IntegerDigit:
      case WenyanParser::FloatDigit:
      case WenyanParser::IntegerDigitCN:
      case WenyanParser::FloatDigitCN: {
        enterOuterAlt(_localctx, 2);
        setState(177);
        dynamic_cast<NumberContext *>(_localctx)->n = digits();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DigitsContext ------------------------------------------------------------------

WenyanParser::DigitsContext::DigitsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t WenyanParser::DigitsContext::getRuleIndex() const {
  return WenyanParser::RuleDigits;
}

void WenyanParser::DigitsContext::copyFrom(DigitsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NumberFloatContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> WenyanParser::NumberFloatContext::FloatDigit() {
  return getTokens(WenyanParser::FloatDigit);
}

tree::TerminalNode* WenyanParser::NumberFloatContext::FloatDigit(size_t i) {
  return getToken(WenyanParser::FloatDigit, i);
}

WenyanParser::NumberFloatContext::NumberFloatContext(DigitsContext *ctx) { copyFrom(ctx); }

void WenyanParser::NumberFloatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberFloat(this);
}
void WenyanParser::NumberFloatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberFloat(this);
}
//----------------- NumberFloatCNContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> WenyanParser::NumberFloatCNContext::FloatDigitCN() {
  return getTokens(WenyanParser::FloatDigitCN);
}

tree::TerminalNode* WenyanParser::NumberFloatCNContext::FloatDigitCN(size_t i) {
  return getToken(WenyanParser::FloatDigitCN, i);
}

WenyanParser::NumberFloatCNContext::NumberFloatCNContext(DigitsContext *ctx) { copyFrom(ctx); }

void WenyanParser::NumberFloatCNContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberFloatCN(this);
}
void WenyanParser::NumberFloatCNContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberFloatCN(this);
}
//----------------- NumberIntegerContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> WenyanParser::NumberIntegerContext::IntegerDigit() {
  return getTokens(WenyanParser::IntegerDigit);
}

tree::TerminalNode* WenyanParser::NumberIntegerContext::IntegerDigit(size_t i) {
  return getToken(WenyanParser::IntegerDigit, i);
}

WenyanParser::NumberIntegerContext::NumberIntegerContext(DigitsContext *ctx) { copyFrom(ctx); }

void WenyanParser::NumberIntegerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberInteger(this);
}
void WenyanParser::NumberIntegerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberInteger(this);
}
//----------------- NumberIntegerCNContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> WenyanParser::NumberIntegerCNContext::IntegerDigitCN() {
  return getTokens(WenyanParser::IntegerDigitCN);
}

tree::TerminalNode* WenyanParser::NumberIntegerCNContext::IntegerDigitCN(size_t i) {
  return getToken(WenyanParser::IntegerDigitCN, i);
}

WenyanParser::NumberIntegerCNContext::NumberIntegerCNContext(DigitsContext *ctx) { copyFrom(ctx); }

void WenyanParser::NumberIntegerCNContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberIntegerCN(this);
}
void WenyanParser::NumberIntegerCNContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WenyanListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberIntegerCN(this);
}
WenyanParser::DigitsContext* WenyanParser::digits() {
  DigitsContext *_localctx = _tracker.createInstance<DigitsContext>(_ctx, getState());
  enterRule(_localctx, 38, WenyanParser::RuleDigits);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(200);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WenyanParser::IntegerDigit: {
        _localctx = dynamic_cast<DigitsContext *>(_tracker.createInstance<WenyanParser::NumberIntegerContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(181); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(180);
                  match(WenyanParser::IntegerDigit);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(183); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      case WenyanParser::IntegerDigitCN: {
        _localctx = dynamic_cast<DigitsContext *>(_tracker.createInstance<WenyanParser::NumberIntegerCNContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(186); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(185);
                  match(WenyanParser::IntegerDigitCN);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(188); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      case WenyanParser::FloatDigit: {
        _localctx = dynamic_cast<DigitsContext *>(_tracker.createInstance<WenyanParser::NumberFloatContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(191); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(190);
                  match(WenyanParser::FloatDigit);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(193); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      case WenyanParser::FloatDigitCN: {
        _localctx = dynamic_cast<DigitsContext *>(_tracker.createInstance<WenyanParser::NumberFloatCNContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(196); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(195);
                  match(WenyanParser::FloatDigitCN);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(198); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> WenyanParser::_decisionToDFA;
atn::PredictionContextCache WenyanParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN WenyanParser::_atn;
std::vector<uint16_t> WenyanParser::_serializedATN;

std::vector<std::string> WenyanParser::_ruleNames = {
  "program", "block", "statement", "expression", "returnStatement", "assignStatement", 
  "ifStatement", "ifStartState", "ifThenState", "ifElseState", "forStatement", 
  "variable", "applyStatement", "applyFunction", "funcVars", "declarefunction", 
  "variables", "declareNumber", "number", "digits"
};

std::vector<std::string> WenyanParser::_literalNames = {
  "", "'\u4ECA'", "", "", "", "'\u6614\u4E4B'", "'\u662F\u77E3'", "", "", 
  "", "", "", "", "", "'['", "']'", "'\u300C'", "'\u300D'"
};

std::vector<std::string> WenyanParser::_symbolicNames = {
  "", "", "OP", "YI3", "Return", "XiZhi", "ShiYi", "If", "EndDeclare", "Else", 
  "ForStart", "ForStart2", "ForEnd", "Variable", "Left", "Right", "Left4", 
  "Right4", "Apply", "At", "The", "End", "FunctionStart", "FunctionEnd", 
  "VarPref", "VariableStart", "DeclareMethod", "ThisIs", "Is", "Said", "MethodOf", 
  "EndStatment", "IHave", "NameAs", "ValueIs", "DeclareDigit", "IntegerDigit", 
  "FloatDigit", "IntegerDigitCN", "FloatDigitCN", "Equal", "Unequal", "Character", 
  "LineComment", "PartComment", "WhiteSpace"
};

dfa::Vocabulary WenyanParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> WenyanParser::_tokenNames;

WenyanParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2f, 0xcd, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x3, 0x2, 0x7, 0x2, 0x2c, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x2f, 
    0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x6, 0x3, 0x34, 0xa, 0x3, 0xd, 
    0x3, 0xe, 0x3, 0x35, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x3f, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x5, 0x5, 0x44, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x49, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x4d, 0xa, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x52, 0xa, 0x5, 0x7, 0x5, 0x54, 0xa, 0x5, 
    0xc, 0x5, 0xe, 0x5, 0x57, 0xb, 0x5, 0x3, 0x5, 0x5, 0x5, 0x5a, 0xa, 0x5, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0x6b, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x82, 0xa, 0xf, 0x3, 0xf, 
    0x7, 0xf, 0x85, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x88, 0xb, 0xf, 0x3, 0x10, 
    0x3, 0x10, 0x5, 0x10, 0x8c, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x5, 0x11, 0x92, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x5, 0x11, 0x98, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x6, 0x12, 0x9e, 0xa, 0x12, 0xd, 0x12, 0xe, 0x12, 0x9f, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0xa5, 0xa, 0x13, 0xc, 0x13, 0xe, 
    0x13, 0xa8, 0xb, 0x13, 0x3, 0x13, 0x3, 0x13, 0x6, 0x13, 0xac, 0xa, 0x13, 
    0xd, 0x13, 0xe, 0x13, 0xad, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x5, 0x14, 0xb5, 0xa, 0x14, 0x3, 0x15, 0x6, 0x15, 0xb8, 0xa, 
    0x15, 0xd, 0x15, 0xe, 0x15, 0xb9, 0x3, 0x15, 0x6, 0x15, 0xbd, 0xa, 0x15, 
    0xd, 0x15, 0xe, 0x15, 0xbe, 0x3, 0x15, 0x6, 0x15, 0xc2, 0xa, 0x15, 0xd, 
    0x15, 0xe, 0x15, 0xc3, 0x3, 0x15, 0x6, 0x15, 0xc7, 0xa, 0x15, 0xd, 0x15, 
    0xe, 0x15, 0xc8, 0x5, 0x15, 0xcb, 0xa, 0x15, 0x3, 0x15, 0x2, 0x2, 0x16, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2, 0x2, 0x2, 0xd8, 0x2, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x4, 0x33, 0x3, 0x2, 0x2, 0x2, 0x6, 0x3e, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x59, 0x3, 0x2, 0x2, 0x2, 0xa, 0x5b, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x5e, 0x3, 0x2, 0x2, 0x2, 0xe, 0x65, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x12, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x71, 0x3, 0x2, 0x2, 0x2, 0x16, 0x74, 0x3, 0x2, 0x2, 0x2, 0x18, 0x7a, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x7e, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x20, 0x8d, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x99, 0x3, 0x2, 0x2, 0x2, 0x24, 0xa1, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0xb4, 0x3, 0x2, 0x2, 0x2, 0x28, 0xca, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x2c, 0x5, 0x4, 0x3, 0x2, 0x2b, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0x30, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x31, 0x7, 0x2, 0x2, 0x3, 0x31, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x34, 0x5, 0x6, 0x4, 0x2, 0x33, 0x32, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x5, 0x3, 0x2, 0x2, 0x2, 0x37, 
    0x3f, 0x5, 0x24, 0x13, 0x2, 0x38, 0x3f, 0x5, 0x20, 0x11, 0x2, 0x39, 
    0x3f, 0x5, 0xe, 0x8, 0x2, 0x3a, 0x3f, 0x5, 0x16, 0xc, 0x2, 0x3b, 0x3f, 
    0x5, 0xc, 0x7, 0x2, 0x3c, 0x3f, 0x5, 0xa, 0x6, 0x2, 0x3d, 0x3f, 0x5, 
    0x8, 0x5, 0x2, 0x3e, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x38, 0x3, 0x2, 
    0x2, 0x2, 0x3e, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3a, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 
    0x3e, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x7, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x43, 0x7, 0x4, 0x2, 0x2, 0x41, 0x44, 0x5, 0x26, 0x14, 0x2, 0x42, 0x44, 
    0x5, 0x18, 0xd, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x42, 0x3, 
    0x2, 0x2, 0x2, 0x44, 0x45, 0x3, 0x2, 0x2, 0x2, 0x45, 0x48, 0x7, 0x5, 
    0x2, 0x2, 0x46, 0x49, 0x5, 0x26, 0x14, 0x2, 0x47, 0x49, 0x5, 0x18, 0xd, 
    0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x49, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4d, 0x5, 0x26, 0x14, 0x2, 0x4b, 
    0x4d, 0x5, 0x18, 0xd, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4b, 
    0x3, 0x2, 0x2, 0x2, 0x4d, 0x55, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x51, 0x7, 
    0x4, 0x2, 0x2, 0x4f, 0x52, 0x5, 0x26, 0x14, 0x2, 0x50, 0x52, 0x5, 0x18, 
    0xd, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x50, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x54, 0x3, 0x2, 0x2, 0x2, 0x53, 0x4e, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x57, 0x3, 0x2, 0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 
    0x56, 0x3, 0x2, 0x2, 0x2, 0x56, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 
    0x3, 0x2, 0x2, 0x2, 0x58, 0x5a, 0x5, 0x1a, 0xe, 0x2, 0x59, 0x40, 0x3, 
    0x2, 0x2, 0x2, 0x59, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x59, 0x58, 0x3, 0x2, 
    0x2, 0x2, 0x5a, 0x9, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x6, 0x2, 
    0x2, 0x5c, 0x5d, 0x5, 0x8, 0x5, 0x2, 0x5d, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x5e, 0x5f, 0x7, 0x7, 0x2, 0x2, 0x5f, 0x60, 0x5, 0x18, 0xd, 0x2, 0x60, 
    0x61, 0x7, 0xa, 0x2, 0x2, 0x61, 0x62, 0x7, 0x3, 0x2, 0x2, 0x62, 0x63, 
    0x5, 0x8, 0x5, 0x2, 0x63, 0x64, 0x7, 0x8, 0x2, 0x2, 0x64, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0x65, 0x66, 0x5, 0x10, 0x9, 0x2, 0x66, 0x67, 0x7, 0xa, 
    0x2, 0x2, 0x67, 0x68, 0x5, 0x12, 0xa, 0x2, 0x68, 0x6a, 0x5, 0x14, 0xb, 
    0x2, 0x69, 0x6b, 0x7, 0x21, 0x2, 0x2, 0x6a, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x6a, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6b, 0xf, 0x3, 0x2, 0x2, 0x2, 0x6c, 
    0x6d, 0x7, 0x9, 0x2, 0x2, 0x6d, 0x6e, 0x5, 0x8, 0x5, 0x2, 0x6e, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x5, 0x4, 0x3, 0x2, 0x70, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0xb, 0x2, 0x2, 0x72, 0x73, 0x5, 0x4, 
    0x3, 0x2, 0x73, 0x15, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x7, 0xc, 0x2, 
    0x2, 0x75, 0x76, 0x5, 0x26, 0x14, 0x2, 0x76, 0x77, 0x7, 0xd, 0x2, 0x2, 
    0x77, 0x78, 0x5, 0x4, 0x3, 0x2, 0x78, 0x79, 0x7, 0xe, 0x2, 0x2, 0x79, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0xf, 0x2, 0x2, 0x7b, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x5, 0x1c, 0xf, 0x2, 0x7d, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x14, 0x2, 0x2, 0x7f, 0x81, 0x5, 0x18, 
    0xd, 0x2, 0x80, 0x82, 0x7, 0x15, 0x2, 0x2, 0x81, 0x80, 0x3, 0x2, 0x2, 
    0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 0x86, 0x3, 0x2, 0x2, 0x2, 
    0x83, 0x85, 0x5, 0x1e, 0x10, 0x2, 0x84, 0x83, 0x3, 0x2, 0x2, 0x2, 0x85, 
    0x88, 0x3, 0x2, 0x2, 0x2, 0x86, 0x84, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 
    0x3, 0x2, 0x2, 0x2, 0x87, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x88, 0x86, 0x3, 
    0x2, 0x2, 0x2, 0x89, 0x8c, 0x5, 0x26, 0x14, 0x2, 0x8a, 0x8c, 0x5, 0x18, 
    0xd, 0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8a, 0x3, 0x2, 0x2, 
    0x2, 0x8c, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x1c, 0x2, 0x2, 
    0x8e, 0x8f, 0x7, 0x23, 0x2, 0x2, 0x8f, 0x91, 0x5, 0x18, 0xd, 0x2, 0x90, 
    0x92, 0x5, 0x22, 0x12, 0x2, 0x91, 0x90, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 
    0x18, 0x2, 0x2, 0x94, 0x95, 0x5, 0x4, 0x3, 0x2, 0x95, 0x97, 0x7, 0x19, 
    0x2, 0x2, 0x96, 0x98, 0x7, 0x21, 0x2, 0x2, 0x97, 0x96, 0x3, 0x2, 0x2, 
    0x2, 0x97, 0x98, 0x3, 0x2, 0x2, 0x2, 0x98, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x99, 0x9a, 0x7, 0x1a, 0x2, 0x2, 0x9a, 0x9d, 0x7, 0x1b, 0x2, 0x2, 0x9b, 
    0x9c, 0x7, 0x23, 0x2, 0x2, 0x9c, 0x9e, 0x5, 0x18, 0xd, 0x2, 0x9d, 0x9b, 
    0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9d, 0x3, 
    0x2, 0x2, 0x2, 0x9f, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0xa1, 0xa6, 0x7, 0x25, 0x2, 0x2, 0xa2, 0xa3, 0x7, 0x24, 0x2, 
    0x2, 0xa3, 0xa5, 0x5, 0x8, 0x5, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 
    0xa5, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa6, 
    0xa7, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xab, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa6, 
    0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x23, 0x2, 0x2, 0xaa, 0xac, 0x5, 
    0x18, 0xd, 0x2, 0xab, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 
    0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 
    0x2, 0xae, 0x25, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x10, 0x2, 0x2, 
    0xb0, 0xb1, 0x5, 0x28, 0x15, 0x2, 0xb1, 0xb2, 0x7, 0x11, 0x2, 0x2, 0xb2, 
    0xb5, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb5, 0x5, 0x28, 0x15, 0x2, 0xb4, 0xaf, 
    0x3, 0x2, 0x2, 0x2, 0xb4, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0xb6, 0xb8, 0x7, 0x26, 0x2, 0x2, 0xb7, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb7, 0x3, 0x2, 0x2, 
    0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 0xcb, 0x3, 0x2, 0x2, 0x2, 
    0xbb, 0xbd, 0x7, 0x28, 0x2, 0x2, 0xbc, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 
    0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc2, 0x7, 
    0x27, 0x2, 0x2, 0xc1, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 
    0x2, 0x2, 0xc3, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 
    0x2, 0xc4, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc7, 0x7, 0x29, 0x2, 0x2, 
    0xc6, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc8, 
    0xc6, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xcb, 
    0x3, 0x2, 0x2, 0x2, 0xca, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xca, 0xbc, 0x3, 
    0x2, 0x2, 0x2, 0xca, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc6, 0x3, 0x2, 
    0x2, 0x2, 0xcb, 0x29, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x2d, 0x35, 0x3e, 0x43, 
    0x48, 0x4c, 0x51, 0x55, 0x59, 0x6a, 0x81, 0x86, 0x8b, 0x91, 0x97, 0x9f, 
    0xa6, 0xad, 0xb4, 0xb9, 0xbe, 0xc3, 0xc8, 0xca, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

WenyanParser::Initializer WenyanParser::_init;
