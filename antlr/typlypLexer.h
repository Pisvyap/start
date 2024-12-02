
// Generated from typlyp.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  typlypLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, ID = 14, 
    INT = 15, BOOL = 16, WS = 17, COMMENT = 18, LINE_COMMENT = 19, PLUS = 20, 
    MINUS = 21, MULT = 22, DIV = 23, MOD = 24, LT = 25, LE = 26, GT = 27, 
    GE = 28, EQ = 29, NEQ = 30, AND = 31, OR = 32, NOT = 33, ASSIGN = 34, 
    LBRACKET = 35, RBRACKET = 36, LPAREN = 37, RPAREN = 38, LBRACE = 39, 
    RBRACE = 40, SEMICOLON = 41, COMMA = 42
  };

  explicit typlypLexer(antlr4::CharStream *input);

  ~typlypLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

