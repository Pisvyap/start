
// Generated from C:/Users/ladyp/CLionProjects/tyaplyap/grammar/typlyp.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  typlypLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, BOOL = 17, INT = 18, ID = 19, WS = 20, COMMENT = 21, 
    LINE_COMMENT = 22, PLUS = 23, MINUS = 24, MULT = 25, DIV = 26, MOD = 27, 
    LT = 28, LE = 29, GT = 30, GE = 31, EQ = 32, NEQ = 33, AND = 34, OR = 35, 
    NOT = 36, ASSIGN = 37, LBRACKET = 38, RBRACKET = 39, LPAREN = 40, RPAREN = 41, 
    LBRACE = 42, RBRACE = 43, SEMICOLON = 44, COMMA = 45
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

