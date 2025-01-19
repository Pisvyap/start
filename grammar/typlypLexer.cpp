
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
      "T__9", "T__10", "T__11", "BOOL", "INT", "ID", "WS", "COMMENT", "LINE_COMMENT", 
      "PLUS", "MINUS", "MULT", "DIV", "MOD", "LT", "LE", "GT", "GE", "EQ", 
      "NEQ", "AND", "OR", "NOT", "LASSIGN", "RASSIGN", "LBRACKET", "RBRACKET", 
      "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMICOLON", "COMMA", "DIVIDER"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'delo'", "'kak'", "'otdau'", "'esli'", "'inache'", "'poka'", 
      "'perebor'", "'glaza'", "'new'", "'nebytie'", "'chislo'", "'logika'", 
      "", "", "", "", "", "", "'+'", "'-'", "'*'", "'/'", "'%'", "'<'", 
      "'<='", "'>'", "'>='", "'='", "'!='", "'&&'", "'||'", "'!'", "'<-'", 
      "'->'", "'['", "']'", "'('", "')'", "'{'", "'}'", "';'", "','", "'|'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "BOOL", "INT", 
      "ID", "WS", "COMMENT", "LINE_COMMENT", "PLUS", "MINUS", "MULT", "DIV", 
      "MOD", "LT", "LE", "GT", "GE", "EQ", "NEQ", "AND", "OR", "NOT", "LASSIGN", 
      "RASSIGN", "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "LBRACE", "RBRACE", 
      "SEMICOLON", "COMMA", "DIVIDER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,43,267,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,3,
  	1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,3,12,165,8,12,1,
  	13,4,13,168,8,13,11,13,12,13,169,1,14,1,14,5,14,174,8,14,10,14,12,14,
  	177,9,14,1,15,4,15,180,8,15,11,15,12,15,181,1,15,1,15,1,16,1,16,1,16,
  	1,16,5,16,190,8,16,10,16,12,16,193,9,16,1,16,1,16,1,17,1,17,1,17,1,17,
  	5,17,201,8,17,10,17,12,17,204,9,17,1,17,1,17,1,17,1,17,1,17,1,18,1,18,
  	1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,24,1,25,
  	1,25,1,26,1,26,1,26,1,27,1,27,1,28,1,28,1,28,1,29,1,29,1,29,1,30,1,30,
  	1,30,1,31,1,31,1,32,1,32,1,32,1,33,1,33,1,33,1,34,1,34,1,35,1,35,1,36,
  	1,36,1,37,1,37,1,38,1,38,1,39,1,39,1,40,1,40,1,41,1,41,1,42,1,42,1,202,
  	0,43,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,
  	27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,
  	25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,
  	73,37,75,38,77,39,79,40,81,41,83,42,85,43,1,0,5,1,0,48,57,3,0,65,90,95,
  	95,97,122,4,0,48,57,65,90,95,95,97,122,3,0,9,10,13,13,32,32,2,0,10,10,
  	13,13,272,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,
  	0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,
  	1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,
  	0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,
  	0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,
  	1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,
  	0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,
  	0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,
  	1,0,0,0,1,87,1,0,0,0,3,92,1,0,0,0,5,96,1,0,0,0,7,102,1,0,0,0,9,107,1,
  	0,0,0,11,114,1,0,0,0,13,119,1,0,0,0,15,127,1,0,0,0,17,133,1,0,0,0,19,
  	137,1,0,0,0,21,145,1,0,0,0,23,152,1,0,0,0,25,164,1,0,0,0,27,167,1,0,0,
  	0,29,171,1,0,0,0,31,179,1,0,0,0,33,185,1,0,0,0,35,196,1,0,0,0,37,210,
  	1,0,0,0,39,212,1,0,0,0,41,214,1,0,0,0,43,216,1,0,0,0,45,218,1,0,0,0,47,
  	220,1,0,0,0,49,222,1,0,0,0,51,225,1,0,0,0,53,227,1,0,0,0,55,230,1,0,0,
  	0,57,232,1,0,0,0,59,235,1,0,0,0,61,238,1,0,0,0,63,241,1,0,0,0,65,243,
  	1,0,0,0,67,246,1,0,0,0,69,249,1,0,0,0,71,251,1,0,0,0,73,253,1,0,0,0,75,
  	255,1,0,0,0,77,257,1,0,0,0,79,259,1,0,0,0,81,261,1,0,0,0,83,263,1,0,0,
  	0,85,265,1,0,0,0,87,88,5,100,0,0,88,89,5,101,0,0,89,90,5,108,0,0,90,91,
  	5,111,0,0,91,2,1,0,0,0,92,93,5,107,0,0,93,94,5,97,0,0,94,95,5,107,0,0,
  	95,4,1,0,0,0,96,97,5,111,0,0,97,98,5,116,0,0,98,99,5,100,0,0,99,100,5,
  	97,0,0,100,101,5,117,0,0,101,6,1,0,0,0,102,103,5,101,0,0,103,104,5,115,
  	0,0,104,105,5,108,0,0,105,106,5,105,0,0,106,8,1,0,0,0,107,108,5,105,0,
  	0,108,109,5,110,0,0,109,110,5,97,0,0,110,111,5,99,0,0,111,112,5,104,0,
  	0,112,113,5,101,0,0,113,10,1,0,0,0,114,115,5,112,0,0,115,116,5,111,0,
  	0,116,117,5,107,0,0,117,118,5,97,0,0,118,12,1,0,0,0,119,120,5,112,0,0,
  	120,121,5,101,0,0,121,122,5,114,0,0,122,123,5,101,0,0,123,124,5,98,0,
  	0,124,125,5,111,0,0,125,126,5,114,0,0,126,14,1,0,0,0,127,128,5,103,0,
  	0,128,129,5,108,0,0,129,130,5,97,0,0,130,131,5,122,0,0,131,132,5,97,0,
  	0,132,16,1,0,0,0,133,134,5,110,0,0,134,135,5,101,0,0,135,136,5,119,0,
  	0,136,18,1,0,0,0,137,138,5,110,0,0,138,139,5,101,0,0,139,140,5,98,0,0,
  	140,141,5,121,0,0,141,142,5,116,0,0,142,143,5,105,0,0,143,144,5,101,0,
  	0,144,20,1,0,0,0,145,146,5,99,0,0,146,147,5,104,0,0,147,148,5,105,0,0,
  	148,149,5,115,0,0,149,150,5,108,0,0,150,151,5,111,0,0,151,22,1,0,0,0,
  	152,153,5,108,0,0,153,154,5,111,0,0,154,155,5,103,0,0,155,156,5,105,0,
  	0,156,157,5,107,0,0,157,158,5,97,0,0,158,24,1,0,0,0,159,160,5,100,0,0,
  	160,165,5,97,0,0,161,162,5,110,0,0,162,163,5,101,0,0,163,165,5,116,0,
  	0,164,159,1,0,0,0,164,161,1,0,0,0,165,26,1,0,0,0,166,168,7,0,0,0,167,
  	166,1,0,0,0,168,169,1,0,0,0,169,167,1,0,0,0,169,170,1,0,0,0,170,28,1,
  	0,0,0,171,175,7,1,0,0,172,174,7,2,0,0,173,172,1,0,0,0,174,177,1,0,0,0,
  	175,173,1,0,0,0,175,176,1,0,0,0,176,30,1,0,0,0,177,175,1,0,0,0,178,180,
  	7,3,0,0,179,178,1,0,0,0,180,181,1,0,0,0,181,179,1,0,0,0,181,182,1,0,0,
  	0,182,183,1,0,0,0,183,184,6,15,0,0,184,32,1,0,0,0,185,186,5,47,0,0,186,
  	187,5,47,0,0,187,191,1,0,0,0,188,190,8,4,0,0,189,188,1,0,0,0,190,193,
  	1,0,0,0,191,189,1,0,0,0,191,192,1,0,0,0,192,194,1,0,0,0,193,191,1,0,0,
  	0,194,195,6,16,0,0,195,34,1,0,0,0,196,197,5,47,0,0,197,198,5,42,0,0,198,
  	202,1,0,0,0,199,201,9,0,0,0,200,199,1,0,0,0,201,204,1,0,0,0,202,203,1,
  	0,0,0,202,200,1,0,0,0,203,205,1,0,0,0,204,202,1,0,0,0,205,206,5,42,0,
  	0,206,207,5,47,0,0,207,208,1,0,0,0,208,209,6,17,0,0,209,36,1,0,0,0,210,
  	211,5,43,0,0,211,38,1,0,0,0,212,213,5,45,0,0,213,40,1,0,0,0,214,215,5,
  	42,0,0,215,42,1,0,0,0,216,217,5,47,0,0,217,44,1,0,0,0,218,219,5,37,0,
  	0,219,46,1,0,0,0,220,221,5,60,0,0,221,48,1,0,0,0,222,223,5,60,0,0,223,
  	224,5,61,0,0,224,50,1,0,0,0,225,226,5,62,0,0,226,52,1,0,0,0,227,228,5,
  	62,0,0,228,229,5,61,0,0,229,54,1,0,0,0,230,231,5,61,0,0,231,56,1,0,0,
  	0,232,233,5,33,0,0,233,234,5,61,0,0,234,58,1,0,0,0,235,236,5,38,0,0,236,
  	237,5,38,0,0,237,60,1,0,0,0,238,239,5,124,0,0,239,240,5,124,0,0,240,62,
  	1,0,0,0,241,242,5,33,0,0,242,64,1,0,0,0,243,244,5,60,0,0,244,245,5,45,
  	0,0,245,66,1,0,0,0,246,247,5,45,0,0,247,248,5,62,0,0,248,68,1,0,0,0,249,
  	250,5,91,0,0,250,70,1,0,0,0,251,252,5,93,0,0,252,72,1,0,0,0,253,254,5,
  	40,0,0,254,74,1,0,0,0,255,256,5,41,0,0,256,76,1,0,0,0,257,258,5,123,0,
  	0,258,78,1,0,0,0,259,260,5,125,0,0,260,80,1,0,0,0,261,262,5,59,0,0,262,
  	82,1,0,0,0,263,264,5,44,0,0,264,84,1,0,0,0,265,266,5,124,0,0,266,86,1,
  	0,0,0,7,0,164,169,175,181,191,202,1,6,0,0
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
