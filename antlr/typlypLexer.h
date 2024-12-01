
// Generated from typlyp.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  typlypLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, ID = 13, INT = 14, 
    BOOL = 15, WS = 16, COMMENT = 17, LINE_COMMENT = 18, PLUS = 19, MINUS = 20, 
    MULT = 21, DIV = 22, MOD = 23, LT = 24, LE = 25, GT = 26, GE = 27, EQ = 28, 
    NEQ = 29, AND = 30, OR = 31, NOT = 32, ASSIGN = 33, LBRACKET = 34, RBRACKET = 35, 
    LPAREN = 36, RPAREN = 37, LBRACE = 38, RBRACE = 39, SEMICOLON = 40, 
    COMMA = 41
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

