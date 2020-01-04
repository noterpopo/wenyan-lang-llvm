
// Generated from Wenyan.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  WenyanLexer : public antlr4::Lexer {
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

  WenyanLexer(antlr4::CharStream *input);
  ~WenyanLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

