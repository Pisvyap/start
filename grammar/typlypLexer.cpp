
// Generated from C:/Users/ladyp/CLionProjects/tyaplyap/grammar/typlyp.g4 by ANTLR 4.13.2


#include "typlypLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct TyplypLexerStaticData final {
  TyplypLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  TyplypLexerStaticData(const TyplypLexerStaticData&) = delete;
  TyplypLexerStaticData(TyplypLexerStaticData&&) = delete;
  TyplypLexerStaticData& operator=(const TyplypLexerStaticData&) = delete;
  TyplypLexerStaticData& operator=(TyplypLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag typlyplexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<TyplypLexerStaticData> typlyplexerLexerStaticData = nullptr;

void typlyplexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (typlyplexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(typlyplexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<TyplypLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "BOOL", 
      "INT", "ID", "WS", "COMMENT", "LINE_COMMENT", "PLUS", "MINUS", "MULT", 
      "DIV", "MOD", "LT", "LE", "GT", "GE", "EQ", "NEQ", "AND", "OR", "NOT", 
      "ASSIGN", "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "LBRACE", "RBRACE", 
      "SEMICOLON", "COMMA"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'delo'", "':'", "'vneshnaya'", "'pust'", "'vernut'", "'esli'", 
      "'inache'", "'poka'", "'schitaem'", "'->'", "'glaza'", "'new'", "'extern'", 
      "'nebytie'", "'chislo'", "'logika'", "", "", "", "", "", "", "'+'", 
      "'-'", "'*'", "'/'", "'%'", "'<'", "'<='", "'>'", "'>='", "'=='", 
      "'!='", "'&&'", "'||'", "'!'", "'='", "'['", "']'", "'('", "')'", 
      "'{'", "'}'", "';'", "','"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "BOOL", "INT", "ID", "WS", "COMMENT", "LINE_COMMENT", "PLUS", "MINUS", 
      "MULT", "DIV", "MOD", "LT", "LE", "GT", "GE", "EQ", "NEQ", "AND", 
      "OR", "NOT", "ASSIGN", "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", 
      "LBRACE", "RBRACE", "SEMICOLON", "COMMA"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,45,296,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,
  	10,1,10,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,
  	16,1,16,1,16,3,16,199,8,16,1,17,4,17,202,8,17,11,17,12,17,203,1,18,1,
  	18,5,18,208,8,18,10,18,12,18,211,9,18,1,19,4,19,214,8,19,11,19,12,19,
  	215,1,19,1,19,1,20,1,20,1,20,1,20,5,20,224,8,20,10,20,12,20,227,9,20,
  	1,20,1,20,1,21,1,21,1,21,1,21,5,21,235,8,21,10,21,12,21,238,9,21,1,21,
  	1,21,1,21,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,25,1,25,1,26,1,26,
  	1,27,1,27,1,28,1,28,1,28,1,29,1,29,1,30,1,30,1,30,1,31,1,31,1,31,1,32,
  	1,32,1,32,1,33,1,33,1,33,1,34,1,34,1,34,1,35,1,35,1,36,1,36,1,37,1,37,
  	1,38,1,38,1,39,1,39,1,40,1,40,1,41,1,41,1,42,1,42,1,43,1,43,1,44,1,44,
  	1,236,0,45,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,
  	25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,
  	24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,
  	71,36,73,37,75,38,77,39,79,40,81,41,83,42,85,43,87,44,89,45,1,0,5,1,0,
  	48,57,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,3,0,9,10,13,
  	13,32,32,2,0,10,10,13,13,301,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,
  	1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,
  	0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,
  	29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,
  	0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,
  	0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,
  	61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,
  	0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,
  	0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,1,91,1,0,0,0,3,
  	96,1,0,0,0,5,98,1,0,0,0,7,108,1,0,0,0,9,113,1,0,0,0,11,120,1,0,0,0,13,
  	125,1,0,0,0,15,132,1,0,0,0,17,137,1,0,0,0,19,146,1,0,0,0,21,149,1,0,0,
  	0,23,155,1,0,0,0,25,159,1,0,0,0,27,166,1,0,0,0,29,174,1,0,0,0,31,181,
  	1,0,0,0,33,198,1,0,0,0,35,201,1,0,0,0,37,205,1,0,0,0,39,213,1,0,0,0,41,
  	219,1,0,0,0,43,230,1,0,0,0,45,244,1,0,0,0,47,246,1,0,0,0,49,248,1,0,0,
  	0,51,250,1,0,0,0,53,252,1,0,0,0,55,254,1,0,0,0,57,256,1,0,0,0,59,259,
  	1,0,0,0,61,261,1,0,0,0,63,264,1,0,0,0,65,267,1,0,0,0,67,270,1,0,0,0,69,
  	273,1,0,0,0,71,276,1,0,0,0,73,278,1,0,0,0,75,280,1,0,0,0,77,282,1,0,0,
  	0,79,284,1,0,0,0,81,286,1,0,0,0,83,288,1,0,0,0,85,290,1,0,0,0,87,292,
  	1,0,0,0,89,294,1,0,0,0,91,92,5,100,0,0,92,93,5,101,0,0,93,94,5,108,0,
  	0,94,95,5,111,0,0,95,2,1,0,0,0,96,97,5,58,0,0,97,4,1,0,0,0,98,99,5,118,
  	0,0,99,100,5,110,0,0,100,101,5,101,0,0,101,102,5,115,0,0,102,103,5,104,
  	0,0,103,104,5,110,0,0,104,105,5,97,0,0,105,106,5,121,0,0,106,107,5,97,
  	0,0,107,6,1,0,0,0,108,109,5,112,0,0,109,110,5,117,0,0,110,111,5,115,0,
  	0,111,112,5,116,0,0,112,8,1,0,0,0,113,114,5,118,0,0,114,115,5,101,0,0,
  	115,116,5,114,0,0,116,117,5,110,0,0,117,118,5,117,0,0,118,119,5,116,0,
  	0,119,10,1,0,0,0,120,121,5,101,0,0,121,122,5,115,0,0,122,123,5,108,0,
  	0,123,124,5,105,0,0,124,12,1,0,0,0,125,126,5,105,0,0,126,127,5,110,0,
  	0,127,128,5,97,0,0,128,129,5,99,0,0,129,130,5,104,0,0,130,131,5,101,0,
  	0,131,14,1,0,0,0,132,133,5,112,0,0,133,134,5,111,0,0,134,135,5,107,0,
  	0,135,136,5,97,0,0,136,16,1,0,0,0,137,138,5,115,0,0,138,139,5,99,0,0,
  	139,140,5,104,0,0,140,141,5,105,0,0,141,142,5,116,0,0,142,143,5,97,0,
  	0,143,144,5,101,0,0,144,145,5,109,0,0,145,18,1,0,0,0,146,147,5,45,0,0,
  	147,148,5,62,0,0,148,20,1,0,0,0,149,150,5,103,0,0,150,151,5,108,0,0,151,
  	152,5,97,0,0,152,153,5,122,0,0,153,154,5,97,0,0,154,22,1,0,0,0,155,156,
  	5,110,0,0,156,157,5,101,0,0,157,158,5,119,0,0,158,24,1,0,0,0,159,160,
  	5,101,0,0,160,161,5,120,0,0,161,162,5,116,0,0,162,163,5,101,0,0,163,164,
  	5,114,0,0,164,165,5,110,0,0,165,26,1,0,0,0,166,167,5,110,0,0,167,168,
  	5,101,0,0,168,169,5,98,0,0,169,170,5,121,0,0,170,171,5,116,0,0,171,172,
  	5,105,0,0,172,173,5,101,0,0,173,28,1,0,0,0,174,175,5,99,0,0,175,176,5,
  	104,0,0,176,177,5,105,0,0,177,178,5,115,0,0,178,179,5,108,0,0,179,180,
  	5,111,0,0,180,30,1,0,0,0,181,182,5,108,0,0,182,183,5,111,0,0,183,184,
  	5,103,0,0,184,185,5,105,0,0,185,186,5,107,0,0,186,187,5,97,0,0,187,32,
  	1,0,0,0,188,189,5,112,0,0,189,190,5,114,0,0,190,191,5,97,0,0,191,192,
  	5,118,0,0,192,193,5,100,0,0,193,199,5,97,0,0,194,195,5,108,0,0,195,196,
  	5,111,0,0,196,197,5,122,0,0,197,199,5,104,0,0,198,188,1,0,0,0,198,194,
  	1,0,0,0,199,34,1,0,0,0,200,202,7,0,0,0,201,200,1,0,0,0,202,203,1,0,0,
  	0,203,201,1,0,0,0,203,204,1,0,0,0,204,36,1,0,0,0,205,209,7,1,0,0,206,
  	208,7,2,0,0,207,206,1,0,0,0,208,211,1,0,0,0,209,207,1,0,0,0,209,210,1,
  	0,0,0,210,38,1,0,0,0,211,209,1,0,0,0,212,214,7,3,0,0,213,212,1,0,0,0,
  	214,215,1,0,0,0,215,213,1,0,0,0,215,216,1,0,0,0,216,217,1,0,0,0,217,218,
  	6,19,0,0,218,40,1,0,0,0,219,220,5,47,0,0,220,221,5,47,0,0,221,225,1,0,
  	0,0,222,224,8,4,0,0,223,222,1,0,0,0,224,227,1,0,0,0,225,223,1,0,0,0,225,
  	226,1,0,0,0,226,228,1,0,0,0,227,225,1,0,0,0,228,229,6,20,0,0,229,42,1,
  	0,0,0,230,231,5,47,0,0,231,232,5,42,0,0,232,236,1,0,0,0,233,235,9,0,0,
  	0,234,233,1,0,0,0,235,238,1,0,0,0,236,237,1,0,0,0,236,234,1,0,0,0,237,
  	239,1,0,0,0,238,236,1,0,0,0,239,240,5,42,0,0,240,241,5,47,0,0,241,242,
  	1,0,0,0,242,243,6,21,0,0,243,44,1,0,0,0,244,245,5,43,0,0,245,46,1,0,0,
  	0,246,247,5,45,0,0,247,48,1,0,0,0,248,249,5,42,0,0,249,50,1,0,0,0,250,
  	251,5,47,0,0,251,52,1,0,0,0,252,253,5,37,0,0,253,54,1,0,0,0,254,255,5,
  	60,0,0,255,56,1,0,0,0,256,257,5,60,0,0,257,258,5,61,0,0,258,58,1,0,0,
  	0,259,260,5,62,0,0,260,60,1,0,0,0,261,262,5,62,0,0,262,263,5,61,0,0,263,
  	62,1,0,0,0,264,265,5,61,0,0,265,266,5,61,0,0,266,64,1,0,0,0,267,268,5,
  	33,0,0,268,269,5,61,0,0,269,66,1,0,0,0,270,271,5,38,0,0,271,272,5,38,
  	0,0,272,68,1,0,0,0,273,274,5,124,0,0,274,275,5,124,0,0,275,70,1,0,0,0,
  	276,277,5,33,0,0,277,72,1,0,0,0,278,279,5,61,0,0,279,74,1,0,0,0,280,281,
  	5,91,0,0,281,76,1,0,0,0,282,283,5,93,0,0,283,78,1,0,0,0,284,285,5,40,
  	0,0,285,80,1,0,0,0,286,287,5,41,0,0,287,82,1,0,0,0,288,289,5,123,0,0,
  	289,84,1,0,0,0,290,291,5,125,0,0,291,86,1,0,0,0,292,293,5,59,0,0,293,
  	88,1,0,0,0,294,295,5,44,0,0,295,90,1,0,0,0,7,0,198,203,209,215,225,236,
  	1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  typlyplexerLexerStaticData = std::move(staticData);
}

}

typlypLexer::typlypLexer(CharStream *input) : Lexer(input) {
  typlypLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *typlyplexerLexerStaticData->atn, typlyplexerLexerStaticData->decisionToDFA, typlyplexerLexerStaticData->sharedContextCache);
}

typlypLexer::~typlypLexer() {
  delete _interpreter;
}

std::string typlypLexer::getGrammarFileName() const {
  return "typlyp.g4";
}

const std::vector<std::string>& typlypLexer::getRuleNames() const {
  return typlyplexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& typlypLexer::getChannelNames() const {
  return typlyplexerLexerStaticData->channelNames;
}

const std::vector<std::string>& typlypLexer::getModeNames() const {
  return typlyplexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& typlypLexer::getVocabulary() const {
  return typlyplexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView typlypLexer::getSerializedATN() const {
  return typlyplexerLexerStaticData->serializedATN;
}

const atn::ATN& typlypLexer::getATN() const {
  return *typlyplexerLexerStaticData->atn;
}




void typlypLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  typlyplexerLexerInitialize();
#else
  ::antlr4::internal::call_once(typlyplexerLexerOnceFlag, typlyplexerLexerInitialize);
#endif
}
