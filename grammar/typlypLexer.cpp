
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
      "T__9", "T__10", "T__11", "T__12", "T__13", "BOOL", "INT", "ID", "WS", 
      "COMMENT", "LINE_COMMENT", "PLUS", "MINUS", "MULT", "DIV", "MOD", 
      "LT", "LE", "GT", "GE", "EQ", "NEQ", "AND", "OR", "NOT", "ASSIGN", 
      "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMICOLON", 
      "COMMA"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'delo'", "':'", "'vneshnaya'", "'pust'", "'vernut'", "'esli'", 
      "'inache'", "'poka'", "'schitaem'", "'new'", "'extern'", "'nebytie'", 
      "'chislo'", "'logika'", "", "", "", "", "", "", "'+'", "'-'", "'*'", 
      "'/'", "'%'", "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", "'&&'", 
      "'||'", "'!'", "'='", "'['", "']'", "'('", "')'", "'{'", "'}'", "';'", 
      "','"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "BOOL", 
      "INT", "ID", "WS", "COMMENT", "LINE_COMMENT", "PLUS", "MINUS", "MULT", 
      "DIV", "MOD", "LT", "LE", "GT", "GE", "EQ", "NEQ", "AND", "OR", "NOT", 
      "ASSIGN", "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "LBRACE", "RBRACE", 
      "SEMICOLON", "COMMA"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,43,283,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,
  	5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,
  	12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,3,14,186,8,14,1,15,4,15,189,8,15,11,15,12,15,190,1,
  	16,1,16,5,16,195,8,16,10,16,12,16,198,9,16,1,17,4,17,201,8,17,11,17,12,
  	17,202,1,17,1,17,1,18,1,18,1,18,1,18,5,18,211,8,18,10,18,12,18,214,9,
  	18,1,18,1,18,1,19,1,19,1,19,1,19,5,19,222,8,19,10,19,12,19,225,9,19,1,
  	19,1,19,1,19,1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,
  	24,1,25,1,25,1,26,1,26,1,26,1,27,1,27,1,28,1,28,1,28,1,29,1,29,1,29,1,
  	30,1,30,1,30,1,31,1,31,1,31,1,32,1,32,1,32,1,33,1,33,1,34,1,34,1,35,1,
  	35,1,36,1,36,1,37,1,37,1,38,1,38,1,39,1,39,1,40,1,40,1,41,1,41,1,42,1,
  	42,1,223,0,43,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,
  	12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,
  	47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,
  	35,71,36,73,37,75,38,77,39,79,40,81,41,83,42,85,43,1,0,5,1,0,48,57,3,
  	0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,3,0,9,10,13,13,32,32,
  	2,0,10,10,13,13,288,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,
  	9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,
  	0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,
  	0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,
  	41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,
  	0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,
  	0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,
  	73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,
  	0,0,0,0,85,1,0,0,0,1,87,1,0,0,0,3,92,1,0,0,0,5,94,1,0,0,0,7,104,1,0,0,
  	0,9,109,1,0,0,0,11,116,1,0,0,0,13,121,1,0,0,0,15,128,1,0,0,0,17,133,1,
  	0,0,0,19,142,1,0,0,0,21,146,1,0,0,0,23,153,1,0,0,0,25,161,1,0,0,0,27,
  	168,1,0,0,0,29,185,1,0,0,0,31,188,1,0,0,0,33,192,1,0,0,0,35,200,1,0,0,
  	0,37,206,1,0,0,0,39,217,1,0,0,0,41,231,1,0,0,0,43,233,1,0,0,0,45,235,
  	1,0,0,0,47,237,1,0,0,0,49,239,1,0,0,0,51,241,1,0,0,0,53,243,1,0,0,0,55,
  	246,1,0,0,0,57,248,1,0,0,0,59,251,1,0,0,0,61,254,1,0,0,0,63,257,1,0,0,
  	0,65,260,1,0,0,0,67,263,1,0,0,0,69,265,1,0,0,0,71,267,1,0,0,0,73,269,
  	1,0,0,0,75,271,1,0,0,0,77,273,1,0,0,0,79,275,1,0,0,0,81,277,1,0,0,0,83,
  	279,1,0,0,0,85,281,1,0,0,0,87,88,5,100,0,0,88,89,5,101,0,0,89,90,5,108,
  	0,0,90,91,5,111,0,0,91,2,1,0,0,0,92,93,5,58,0,0,93,4,1,0,0,0,94,95,5,
  	118,0,0,95,96,5,110,0,0,96,97,5,101,0,0,97,98,5,115,0,0,98,99,5,104,0,
  	0,99,100,5,110,0,0,100,101,5,97,0,0,101,102,5,121,0,0,102,103,5,97,0,
  	0,103,6,1,0,0,0,104,105,5,112,0,0,105,106,5,117,0,0,106,107,5,115,0,0,
  	107,108,5,116,0,0,108,8,1,0,0,0,109,110,5,118,0,0,110,111,5,101,0,0,111,
  	112,5,114,0,0,112,113,5,110,0,0,113,114,5,117,0,0,114,115,5,116,0,0,115,
  	10,1,0,0,0,116,117,5,101,0,0,117,118,5,115,0,0,118,119,5,108,0,0,119,
  	120,5,105,0,0,120,12,1,0,0,0,121,122,5,105,0,0,122,123,5,110,0,0,123,
  	124,5,97,0,0,124,125,5,99,0,0,125,126,5,104,0,0,126,127,5,101,0,0,127,
  	14,1,0,0,0,128,129,5,112,0,0,129,130,5,111,0,0,130,131,5,107,0,0,131,
  	132,5,97,0,0,132,16,1,0,0,0,133,134,5,115,0,0,134,135,5,99,0,0,135,136,
  	5,104,0,0,136,137,5,105,0,0,137,138,5,116,0,0,138,139,5,97,0,0,139,140,
  	5,101,0,0,140,141,5,109,0,0,141,18,1,0,0,0,142,143,5,110,0,0,143,144,
  	5,101,0,0,144,145,5,119,0,0,145,20,1,0,0,0,146,147,5,101,0,0,147,148,
  	5,120,0,0,148,149,5,116,0,0,149,150,5,101,0,0,150,151,5,114,0,0,151,152,
  	5,110,0,0,152,22,1,0,0,0,153,154,5,110,0,0,154,155,5,101,0,0,155,156,
  	5,98,0,0,156,157,5,121,0,0,157,158,5,116,0,0,158,159,5,105,0,0,159,160,
  	5,101,0,0,160,24,1,0,0,0,161,162,5,99,0,0,162,163,5,104,0,0,163,164,5,
  	105,0,0,164,165,5,115,0,0,165,166,5,108,0,0,166,167,5,111,0,0,167,26,
  	1,0,0,0,168,169,5,108,0,0,169,170,5,111,0,0,170,171,5,103,0,0,171,172,
  	5,105,0,0,172,173,5,107,0,0,173,174,5,97,0,0,174,28,1,0,0,0,175,176,5,
  	112,0,0,176,177,5,114,0,0,177,178,5,97,0,0,178,179,5,118,0,0,179,180,
  	5,100,0,0,180,186,5,97,0,0,181,182,5,108,0,0,182,183,5,111,0,0,183,184,
  	5,122,0,0,184,186,5,104,0,0,185,175,1,0,0,0,185,181,1,0,0,0,186,30,1,
  	0,0,0,187,189,7,0,0,0,188,187,1,0,0,0,189,190,1,0,0,0,190,188,1,0,0,0,
  	190,191,1,0,0,0,191,32,1,0,0,0,192,196,7,1,0,0,193,195,7,2,0,0,194,193,
  	1,0,0,0,195,198,1,0,0,0,196,194,1,0,0,0,196,197,1,0,0,0,197,34,1,0,0,
  	0,198,196,1,0,0,0,199,201,7,3,0,0,200,199,1,0,0,0,201,202,1,0,0,0,202,
  	200,1,0,0,0,202,203,1,0,0,0,203,204,1,0,0,0,204,205,6,17,0,0,205,36,1,
  	0,0,0,206,207,5,47,0,0,207,208,5,47,0,0,208,212,1,0,0,0,209,211,8,4,0,
  	0,210,209,1,0,0,0,211,214,1,0,0,0,212,210,1,0,0,0,212,213,1,0,0,0,213,
  	215,1,0,0,0,214,212,1,0,0,0,215,216,6,18,0,0,216,38,1,0,0,0,217,218,5,
  	47,0,0,218,219,5,42,0,0,219,223,1,0,0,0,220,222,9,0,0,0,221,220,1,0,0,
  	0,222,225,1,0,0,0,223,224,1,0,0,0,223,221,1,0,0,0,224,226,1,0,0,0,225,
  	223,1,0,0,0,226,227,5,42,0,0,227,228,5,47,0,0,228,229,1,0,0,0,229,230,
  	6,19,0,0,230,40,1,0,0,0,231,232,5,43,0,0,232,42,1,0,0,0,233,234,5,45,
  	0,0,234,44,1,0,0,0,235,236,5,42,0,0,236,46,1,0,0,0,237,238,5,47,0,0,238,
  	48,1,0,0,0,239,240,5,37,0,0,240,50,1,0,0,0,241,242,5,60,0,0,242,52,1,
  	0,0,0,243,244,5,60,0,0,244,245,5,61,0,0,245,54,1,0,0,0,246,247,5,62,0,
  	0,247,56,1,0,0,0,248,249,5,62,0,0,249,250,5,61,0,0,250,58,1,0,0,0,251,
  	252,5,61,0,0,252,253,5,61,0,0,253,60,1,0,0,0,254,255,5,33,0,0,255,256,
  	5,61,0,0,256,62,1,0,0,0,257,258,5,38,0,0,258,259,5,38,0,0,259,64,1,0,
  	0,0,260,261,5,124,0,0,261,262,5,124,0,0,262,66,1,0,0,0,263,264,5,33,0,
  	0,264,68,1,0,0,0,265,266,5,61,0,0,266,70,1,0,0,0,267,268,5,91,0,0,268,
  	72,1,0,0,0,269,270,5,93,0,0,270,74,1,0,0,0,271,272,5,40,0,0,272,76,1,
  	0,0,0,273,274,5,41,0,0,274,78,1,0,0,0,275,276,5,123,0,0,276,80,1,0,0,
  	0,277,278,5,125,0,0,278,82,1,0,0,0,279,280,5,59,0,0,280,84,1,0,0,0,281,
  	282,5,44,0,0,282,86,1,0,0,0,7,0,185,190,196,202,212,223,1,6,0,0
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
