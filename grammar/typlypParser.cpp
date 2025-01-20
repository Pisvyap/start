
// Generated from C:/Users/ladyp/CLionProjects/tyaplyap/grammar/typlyp.g4 by ANTLR 4.13.2


#include "typlypListener.h"
#include "typlypVisitor.h"

#include "typlypParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct TyplypParserStaticData final {
  TyplypParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  TyplypParserStaticData(const TyplypParserStaticData&) = delete;
  TyplypParserStaticData(TyplypParserStaticData&&) = delete;
  TyplypParserStaticData& operator=(const TyplypParserStaticData&) = delete;
  TyplypParserStaticData& operator=(TyplypParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag typlypParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<TyplypParserStaticData> typlypParserStaticData = nullptr;

void typlypParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (typlypParserStaticData != nullptr) {
    return;
  }
#else
  assert(typlypParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<TyplypParserStaticData>(
    std::vector<std::string>{
      "program", "functionDecl", "paramList", "param", "block", "statement", 
      "varDecl", "assignment", "arrayAssignment", "returnStatement", "ifStatement", 
      "whileStatement", "forStatement", "printStatement", "expr", "argList", 
      "type", "voidType", "scalarType", "arrayType"
    },
    std::vector<std::string>{
      "", "'delo'", "':'", "'otday'", "'esli'", "'inache'", "'poka'", "'perebor'", 
      "'glaza'", "'new'", "'nebytie'", "'chislo'", "'logika'", "", "", "", 
      "", "", "", "'+'", "'-'", "'*'", "'/'", "'%'", "'<'", "'<='", "'>'", 
      "'>='", "'='", "'!='", "'&&'", "'||'", "'!'", "'<-'", "'->'", "'['", 
      "']'", "'('", "')'", "'{'", "'}'", "", "','", "'|'"
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
  	4,1,43,274,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,1,0,1,0,5,0,43,8,
  	0,10,0,12,0,46,9,0,1,0,1,0,1,1,1,1,1,1,1,1,3,1,54,8,1,1,1,1,1,1,1,1,1,
  	1,1,1,2,1,2,1,2,5,2,64,8,2,10,2,12,2,67,9,2,1,3,1,3,1,3,1,3,1,4,1,4,5,
  	4,75,8,4,10,4,12,4,78,9,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,103,8,5,1,6,1,6,1,
  	6,1,6,1,6,3,6,110,8,6,1,6,1,6,1,6,3,6,115,8,6,1,6,1,6,1,6,3,6,120,8,6,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,129,8,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,
  	8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,145,8,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,
  	154,8,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,163,8,10,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,12,1,12,1,12,3,12,174,8,12,1,12,1,12,3,12,178,8,12,
  	1,12,1,12,3,12,182,8,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,3,13,194,8,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,215,8,14,1,14,1,14,
  	1,14,3,14,220,8,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,
  	231,8,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	5,14,245,8,14,10,14,12,14,248,9,14,1,15,1,15,1,15,5,15,253,8,15,10,15,
  	12,15,256,9,15,1,16,1,16,1,16,3,16,261,8,16,1,17,1,17,1,18,1,18,1,19,
  	1,19,1,19,1,19,1,19,3,19,272,8,19,1,19,0,1,28,20,0,2,4,6,8,10,12,14,16,
  	18,20,22,24,26,28,30,32,34,36,38,0,5,1,0,21,23,1,0,19,20,1,0,24,27,1,
  	0,28,29,1,0,11,12,295,0,44,1,0,0,0,2,49,1,0,0,0,4,60,1,0,0,0,6,68,1,0,
  	0,0,8,72,1,0,0,0,10,102,1,0,0,0,12,119,1,0,0,0,14,128,1,0,0,0,16,144,
  	1,0,0,0,18,153,1,0,0,0,20,155,1,0,0,0,22,164,1,0,0,0,24,170,1,0,0,0,26,
  	193,1,0,0,0,28,230,1,0,0,0,30,249,1,0,0,0,32,260,1,0,0,0,34,262,1,0,0,
  	0,36,264,1,0,0,0,38,271,1,0,0,0,40,43,3,2,1,0,41,43,3,10,5,0,42,40,1,
  	0,0,0,42,41,1,0,0,0,43,46,1,0,0,0,44,42,1,0,0,0,44,45,1,0,0,0,45,47,1,
  	0,0,0,46,44,1,0,0,0,47,48,5,0,0,1,48,1,1,0,0,0,49,50,5,1,0,0,50,51,5,
  	15,0,0,51,53,5,37,0,0,52,54,3,4,2,0,53,52,1,0,0,0,53,54,1,0,0,0,54,55,
  	1,0,0,0,55,56,5,38,0,0,56,57,5,34,0,0,57,58,3,32,16,0,58,59,3,8,4,0,59,
  	3,1,0,0,0,60,65,3,6,3,0,61,62,5,42,0,0,62,64,3,6,3,0,63,61,1,0,0,0,64,
  	67,1,0,0,0,65,63,1,0,0,0,65,66,1,0,0,0,66,5,1,0,0,0,67,65,1,0,0,0,68,
  	69,5,15,0,0,69,70,5,2,0,0,70,71,3,32,16,0,71,7,1,0,0,0,72,76,5,39,0,0,
  	73,75,3,10,5,0,74,73,1,0,0,0,75,78,1,0,0,0,76,74,1,0,0,0,76,77,1,0,0,
  	0,77,79,1,0,0,0,78,76,1,0,0,0,79,80,5,40,0,0,80,9,1,0,0,0,81,82,3,12,
  	6,0,82,83,5,41,0,0,83,103,1,0,0,0,84,85,3,26,13,0,85,86,5,41,0,0,86,103,
  	1,0,0,0,87,88,3,14,7,0,88,89,5,41,0,0,89,103,1,0,0,0,90,91,3,16,8,0,91,
  	92,5,41,0,0,92,103,1,0,0,0,93,94,3,18,9,0,94,95,5,41,0,0,95,103,1,0,0,
  	0,96,103,3,20,10,0,97,103,3,22,11,0,98,103,3,24,12,0,99,100,3,28,14,0,
  	100,101,5,41,0,0,101,103,1,0,0,0,102,81,1,0,0,0,102,84,1,0,0,0,102,87,
  	1,0,0,0,102,90,1,0,0,0,102,93,1,0,0,0,102,96,1,0,0,0,102,97,1,0,0,0,102,
  	98,1,0,0,0,102,99,1,0,0,0,103,11,1,0,0,0,104,105,5,15,0,0,105,106,5,2,
  	0,0,106,109,3,32,16,0,107,108,5,33,0,0,108,110,3,28,14,0,109,107,1,0,
  	0,0,109,110,1,0,0,0,110,120,1,0,0,0,111,112,3,28,14,0,112,113,5,34,0,
  	0,113,115,1,0,0,0,114,111,1,0,0,0,114,115,1,0,0,0,115,116,1,0,0,0,116,
  	117,5,15,0,0,117,118,5,2,0,0,118,120,3,32,16,0,119,104,1,0,0,0,119,114,
  	1,0,0,0,120,13,1,0,0,0,121,122,5,15,0,0,122,123,5,33,0,0,123,129,3,28,
  	14,0,124,125,3,28,14,0,125,126,5,34,0,0,126,127,5,15,0,0,127,129,1,0,
  	0,0,128,121,1,0,0,0,128,124,1,0,0,0,129,15,1,0,0,0,130,131,5,15,0,0,131,
  	132,5,35,0,0,132,133,3,28,14,0,133,134,5,36,0,0,134,135,5,33,0,0,135,
  	136,3,28,14,0,136,145,1,0,0,0,137,138,3,28,14,0,138,139,5,34,0,0,139,
  	140,5,15,0,0,140,141,5,35,0,0,141,142,3,28,14,0,142,143,5,36,0,0,143,
  	145,1,0,0,0,144,130,1,0,0,0,144,137,1,0,0,0,145,17,1,0,0,0,146,147,5,
  	3,0,0,147,148,5,33,0,0,148,154,3,28,14,0,149,150,3,28,14,0,150,151,5,
  	34,0,0,151,152,5,3,0,0,152,154,1,0,0,0,153,146,1,0,0,0,153,149,1,0,0,
  	0,154,19,1,0,0,0,155,156,5,4,0,0,156,157,5,37,0,0,157,158,3,28,14,0,158,
  	159,5,38,0,0,159,162,3,8,4,0,160,161,5,5,0,0,161,163,3,8,4,0,162,160,
  	1,0,0,0,162,163,1,0,0,0,163,21,1,0,0,0,164,165,5,6,0,0,165,166,5,37,0,
  	0,166,167,3,28,14,0,167,168,5,38,0,0,168,169,3,8,4,0,169,23,1,0,0,0,170,
  	171,5,7,0,0,171,173,5,37,0,0,172,174,3,12,6,0,173,172,1,0,0,0,173,174,
  	1,0,0,0,174,175,1,0,0,0,175,177,5,43,0,0,176,178,3,28,14,0,177,176,1,
  	0,0,0,177,178,1,0,0,0,178,179,1,0,0,0,179,181,5,43,0,0,180,182,3,14,7,
  	0,181,180,1,0,0,0,181,182,1,0,0,0,182,183,1,0,0,0,183,184,5,38,0,0,184,
  	185,3,8,4,0,185,25,1,0,0,0,186,187,3,28,14,0,187,188,5,34,0,0,188,189,
  	5,8,0,0,189,194,1,0,0,0,190,191,5,8,0,0,191,192,5,33,0,0,192,194,3,28,
  	14,0,193,186,1,0,0,0,193,190,1,0,0,0,194,27,1,0,0,0,195,196,6,14,-1,0,
  	196,197,5,32,0,0,197,231,3,28,14,9,198,231,5,15,0,0,199,200,5,15,0,0,
  	200,201,5,35,0,0,201,202,3,28,14,0,202,203,5,36,0,0,203,231,1,0,0,0,204,
  	231,5,14,0,0,205,231,5,13,0,0,206,207,5,37,0,0,207,208,3,28,14,0,208,
  	209,5,38,0,0,209,231,1,0,0,0,210,211,5,15,0,0,211,212,5,33,0,0,212,214,
  	5,35,0,0,213,215,3,30,15,0,214,213,1,0,0,0,214,215,1,0,0,0,215,216,1,
  	0,0,0,216,231,5,36,0,0,217,219,5,35,0,0,218,220,3,30,15,0,219,218,1,0,
  	0,0,219,220,1,0,0,0,220,221,1,0,0,0,221,222,5,36,0,0,222,223,5,34,0,0,
  	223,231,5,15,0,0,224,225,5,9,0,0,225,226,3,36,18,0,226,227,5,24,0,0,227,
  	228,3,28,14,0,228,229,5,26,0,0,229,231,1,0,0,0,230,195,1,0,0,0,230,198,
  	1,0,0,0,230,199,1,0,0,0,230,204,1,0,0,0,230,205,1,0,0,0,230,206,1,0,0,
  	0,230,210,1,0,0,0,230,217,1,0,0,0,230,224,1,0,0,0,231,246,1,0,0,0,232,
  	233,10,13,0,0,233,234,7,0,0,0,234,245,3,28,14,14,235,236,10,12,0,0,236,
  	237,7,1,0,0,237,245,3,28,14,13,238,239,10,11,0,0,239,240,7,2,0,0,240,
  	245,3,28,14,12,241,242,10,10,0,0,242,243,7,3,0,0,243,245,3,28,14,11,244,
  	232,1,0,0,0,244,235,1,0,0,0,244,238,1,0,0,0,244,241,1,0,0,0,245,248,1,
  	0,0,0,246,244,1,0,0,0,246,247,1,0,0,0,247,29,1,0,0,0,248,246,1,0,0,0,
  	249,254,3,28,14,0,250,251,5,42,0,0,251,253,3,28,14,0,252,250,1,0,0,0,
  	253,256,1,0,0,0,254,252,1,0,0,0,254,255,1,0,0,0,255,31,1,0,0,0,256,254,
  	1,0,0,0,257,261,3,36,18,0,258,261,3,38,19,0,259,261,3,34,17,0,260,257,
  	1,0,0,0,260,258,1,0,0,0,260,259,1,0,0,0,261,33,1,0,0,0,262,263,5,10,0,
  	0,263,35,1,0,0,0,264,265,7,4,0,0,265,37,1,0,0,0,266,272,1,0,0,0,267,268,
  	3,36,18,0,268,269,5,24,0,0,269,270,5,26,0,0,270,272,1,0,0,0,271,266,1,
  	0,0,0,271,267,1,0,0,0,272,39,1,0,0,0,25,42,44,53,65,76,102,109,114,119,
  	128,144,153,162,173,177,181,193,214,219,230,244,246,254,260,271
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  typlypParserStaticData = std::move(staticData);
}

}

typlypParser::typlypParser(TokenStream *input) : typlypParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

typlypParser::typlypParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  typlypParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *typlypParserStaticData->atn, typlypParserStaticData->decisionToDFA, typlypParserStaticData->sharedContextCache, options);
}

typlypParser::~typlypParser() {
  delete _interpreter;
}

const atn::ATN& typlypParser::getATN() const {
  return *typlypParserStaticData->atn;
}

std::string typlypParser::getGrammarFileName() const {
  return "typlyp.g4";
}

const std::vector<std::string>& typlypParser::getRuleNames() const {
  return typlypParserStaticData->ruleNames;
}

const dfa::Vocabulary& typlypParser::getVocabulary() const {
  return typlypParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView typlypParser::getSerializedATN() const {
  return typlypParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

typlypParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* typlypParser::ProgramContext::EOF() {
  return getToken(typlypParser::EOF, 0);
}

std::vector<typlypParser::FunctionDeclContext *> typlypParser::ProgramContext::functionDecl() {
  return getRuleContexts<typlypParser::FunctionDeclContext>();
}

typlypParser::FunctionDeclContext* typlypParser::ProgramContext::functionDecl(size_t i) {
  return getRuleContext<typlypParser::FunctionDeclContext>(i);
}

std::vector<typlypParser::StatementContext *> typlypParser::ProgramContext::statement() {
  return getRuleContexts<typlypParser::StatementContext>();
}

typlypParser::StatementContext* typlypParser::ProgramContext::statement(size_t i) {
  return getRuleContext<typlypParser::StatementContext>(i);
}


size_t typlypParser::ProgramContext::getRuleIndex() const {
  return typlypParser::RuleProgram;
}

void typlypParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void typlypParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any typlypParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::ProgramContext* typlypParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, typlypParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(44);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 176093717466) != 0)) {
      setState(42);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case typlypParser::T__0: {
          setState(40);
          functionDecl();
          break;
        }

        case typlypParser::T__2:
        case typlypParser::T__3:
        case typlypParser::T__5:
        case typlypParser::T__6:
        case typlypParser::T__7:
        case typlypParser::T__8:
        case typlypParser::BOOL:
        case typlypParser::INT:
        case typlypParser::ID:
        case typlypParser::NOT:
        case typlypParser::LBRACKET:
        case typlypParser::LPAREN: {
          setState(41);
          statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(46);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(47);
    match(typlypParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclContext ------------------------------------------------------------------

typlypParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* typlypParser::FunctionDeclContext::ID() {
  return getToken(typlypParser::ID, 0);
}

tree::TerminalNode* typlypParser::FunctionDeclContext::LPAREN() {
  return getToken(typlypParser::LPAREN, 0);
}

tree::TerminalNode* typlypParser::FunctionDeclContext::RPAREN() {
  return getToken(typlypParser::RPAREN, 0);
}

tree::TerminalNode* typlypParser::FunctionDeclContext::RASSIGN() {
  return getToken(typlypParser::RASSIGN, 0);
}

typlypParser::TypeContext* typlypParser::FunctionDeclContext::type() {
  return getRuleContext<typlypParser::TypeContext>(0);
}

typlypParser::BlockContext* typlypParser::FunctionDeclContext::block() {
  return getRuleContext<typlypParser::BlockContext>(0);
}

typlypParser::ParamListContext* typlypParser::FunctionDeclContext::paramList() {
  return getRuleContext<typlypParser::ParamListContext>(0);
}


size_t typlypParser::FunctionDeclContext::getRuleIndex() const {
  return typlypParser::RuleFunctionDecl;
}

void typlypParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void typlypParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}


std::any typlypParser::FunctionDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitFunctionDecl(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::FunctionDeclContext* typlypParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 2, typlypParser::RuleFunctionDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    match(typlypParser::T__0);
    setState(50);
    match(typlypParser::ID);
    setState(51);
    match(typlypParser::LPAREN);
    setState(53);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::ID) {
      setState(52);
      paramList();
    }
    setState(55);
    match(typlypParser::RPAREN);
    setState(56);
    match(typlypParser::RASSIGN);
    setState(57);
    type();
    setState(58);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamListContext ------------------------------------------------------------------

typlypParser::ParamListContext::ParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<typlypParser::ParamContext *> typlypParser::ParamListContext::param() {
  return getRuleContexts<typlypParser::ParamContext>();
}

typlypParser::ParamContext* typlypParser::ParamListContext::param(size_t i) {
  return getRuleContext<typlypParser::ParamContext>(i);
}

std::vector<tree::TerminalNode *> typlypParser::ParamListContext::COMMA() {
  return getTokens(typlypParser::COMMA);
}

tree::TerminalNode* typlypParser::ParamListContext::COMMA(size_t i) {
  return getToken(typlypParser::COMMA, i);
}


size_t typlypParser::ParamListContext::getRuleIndex() const {
  return typlypParser::RuleParamList;
}

void typlypParser::ParamListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamList(this);
}

void typlypParser::ParamListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamList(this);
}


std::any typlypParser::ParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitParamList(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::ParamListContext* typlypParser::paramList() {
  ParamListContext *_localctx = _tracker.createInstance<ParamListContext>(_ctx, getState());
  enterRule(_localctx, 4, typlypParser::RuleParamList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    param();
    setState(65);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == typlypParser::COMMA) {
      setState(61);
      match(typlypParser::COMMA);
      setState(62);
      param();
      setState(67);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

typlypParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* typlypParser::ParamContext::ID() {
  return getToken(typlypParser::ID, 0);
}

typlypParser::TypeContext* typlypParser::ParamContext::type() {
  return getRuleContext<typlypParser::TypeContext>(0);
}


size_t typlypParser::ParamContext::getRuleIndex() const {
  return typlypParser::RuleParam;
}

void typlypParser::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void typlypParser::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}


std::any typlypParser::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::ParamContext* typlypParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 6, typlypParser::RuleParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    match(typlypParser::ID);
    setState(69);
    match(typlypParser::T__1);
    setState(70);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

typlypParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* typlypParser::BlockContext::LBRACE() {
  return getToken(typlypParser::LBRACE, 0);
}

tree::TerminalNode* typlypParser::BlockContext::RBRACE() {
  return getToken(typlypParser::RBRACE, 0);
}

std::vector<typlypParser::StatementContext *> typlypParser::BlockContext::statement() {
  return getRuleContexts<typlypParser::StatementContext>();
}

typlypParser::StatementContext* typlypParser::BlockContext::statement(size_t i) {
  return getRuleContext<typlypParser::StatementContext>(i);
}


size_t typlypParser::BlockContext::getRuleIndex() const {
  return typlypParser::RuleBlock;
}

void typlypParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void typlypParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any typlypParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::BlockContext* typlypParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 8, typlypParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72);
    match(typlypParser::LBRACE);
    setState(76);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 176093717464) != 0)) {
      setState(73);
      statement();
      setState(78);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(79);
    match(typlypParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

typlypParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

typlypParser::VarDeclContext* typlypParser::StatementContext::varDecl() {
  return getRuleContext<typlypParser::VarDeclContext>(0);
}

tree::TerminalNode* typlypParser::StatementContext::SEMICOLON() {
  return getToken(typlypParser::SEMICOLON, 0);
}

typlypParser::PrintStatementContext* typlypParser::StatementContext::printStatement() {
  return getRuleContext<typlypParser::PrintStatementContext>(0);
}

typlypParser::AssignmentContext* typlypParser::StatementContext::assignment() {
  return getRuleContext<typlypParser::AssignmentContext>(0);
}

typlypParser::ArrayAssignmentContext* typlypParser::StatementContext::arrayAssignment() {
  return getRuleContext<typlypParser::ArrayAssignmentContext>(0);
}

typlypParser::ReturnStatementContext* typlypParser::StatementContext::returnStatement() {
  return getRuleContext<typlypParser::ReturnStatementContext>(0);
}

typlypParser::IfStatementContext* typlypParser::StatementContext::ifStatement() {
  return getRuleContext<typlypParser::IfStatementContext>(0);
}

typlypParser::WhileStatementContext* typlypParser::StatementContext::whileStatement() {
  return getRuleContext<typlypParser::WhileStatementContext>(0);
}

typlypParser::ForStatementContext* typlypParser::StatementContext::forStatement() {
  return getRuleContext<typlypParser::ForStatementContext>(0);
}

typlypParser::ExprContext* typlypParser::StatementContext::expr() {
  return getRuleContext<typlypParser::ExprContext>(0);
}


size_t typlypParser::StatementContext::getRuleIndex() const {
  return typlypParser::RuleStatement;
}

void typlypParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void typlypParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any typlypParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::StatementContext* typlypParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 10, typlypParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(102);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(81);
      varDecl();
      setState(82);
      match(typlypParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(84);
      printStatement();
      setState(85);
      match(typlypParser::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(87);
      assignment();
      setState(88);
      match(typlypParser::SEMICOLON);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(90);
      arrayAssignment();
      setState(91);
      match(typlypParser::SEMICOLON);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(93);
      returnStatement();
      setState(94);
      match(typlypParser::SEMICOLON);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(96);
      ifStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(97);
      whileStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(98);
      forStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(99);
      expr(0);
      setState(100);
      match(typlypParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

typlypParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* typlypParser::VarDeclContext::ID() {
  return getToken(typlypParser::ID, 0);
}

typlypParser::TypeContext* typlypParser::VarDeclContext::type() {
  return getRuleContext<typlypParser::TypeContext>(0);
}

tree::TerminalNode* typlypParser::VarDeclContext::LASSIGN() {
  return getToken(typlypParser::LASSIGN, 0);
}

typlypParser::ExprContext* typlypParser::VarDeclContext::expr() {
  return getRuleContext<typlypParser::ExprContext>(0);
}

tree::TerminalNode* typlypParser::VarDeclContext::RASSIGN() {
  return getToken(typlypParser::RASSIGN, 0);
}


size_t typlypParser::VarDeclContext::getRuleIndex() const {
  return typlypParser::RuleVarDecl;
}

void typlypParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void typlypParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}


std::any typlypParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::VarDeclContext* typlypParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, typlypParser::RuleVarDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(104);
      match(typlypParser::ID);
      setState(105);
      match(typlypParser::T__1);
      setState(106);
      type();
      setState(109);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == typlypParser::LASSIGN) {
        setState(107);
        match(typlypParser::LASSIGN);
        setState(108);
        expr(0);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(114);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
      case 1: {
        setState(111);
        expr(0);
        setState(112);
        match(typlypParser::RASSIGN);
        break;
      }

      default:
        break;
      }
      setState(116);
      match(typlypParser::ID);
      setState(117);
      match(typlypParser::T__1);
      setState(118);
      type();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

typlypParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* typlypParser::AssignmentContext::ID() {
  return getToken(typlypParser::ID, 0);
}

tree::TerminalNode* typlypParser::AssignmentContext::LASSIGN() {
  return getToken(typlypParser::LASSIGN, 0);
}

typlypParser::ExprContext* typlypParser::AssignmentContext::expr() {
  return getRuleContext<typlypParser::ExprContext>(0);
}

tree::TerminalNode* typlypParser::AssignmentContext::RASSIGN() {
  return getToken(typlypParser::RASSIGN, 0);
}


size_t typlypParser::AssignmentContext::getRuleIndex() const {
  return typlypParser::RuleAssignment;
}

void typlypParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void typlypParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


std::any typlypParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::AssignmentContext* typlypParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 14, typlypParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(128);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(121);
      match(typlypParser::ID);
      setState(122);
      match(typlypParser::LASSIGN);
      setState(123);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(124);
      expr(0);
      setState(125);
      match(typlypParser::RASSIGN);
      setState(126);
      match(typlypParser::ID);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayAssignmentContext ------------------------------------------------------------------

typlypParser::ArrayAssignmentContext::ArrayAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* typlypParser::ArrayAssignmentContext::ID() {
  return getToken(typlypParser::ID, 0);
}

tree::TerminalNode* typlypParser::ArrayAssignmentContext::LBRACKET() {
  return getToken(typlypParser::LBRACKET, 0);
}

std::vector<typlypParser::ExprContext *> typlypParser::ArrayAssignmentContext::expr() {
  return getRuleContexts<typlypParser::ExprContext>();
}

typlypParser::ExprContext* typlypParser::ArrayAssignmentContext::expr(size_t i) {
  return getRuleContext<typlypParser::ExprContext>(i);
}

tree::TerminalNode* typlypParser::ArrayAssignmentContext::RBRACKET() {
  return getToken(typlypParser::RBRACKET, 0);
}

tree::TerminalNode* typlypParser::ArrayAssignmentContext::LASSIGN() {
  return getToken(typlypParser::LASSIGN, 0);
}

tree::TerminalNode* typlypParser::ArrayAssignmentContext::RASSIGN() {
  return getToken(typlypParser::RASSIGN, 0);
}


size_t typlypParser::ArrayAssignmentContext::getRuleIndex() const {
  return typlypParser::RuleArrayAssignment;
}

void typlypParser::ArrayAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayAssignment(this);
}

void typlypParser::ArrayAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayAssignment(this);
}


std::any typlypParser::ArrayAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitArrayAssignment(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::ArrayAssignmentContext* typlypParser::arrayAssignment() {
  ArrayAssignmentContext *_localctx = _tracker.createInstance<ArrayAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 16, typlypParser::RuleArrayAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(144);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(130);
      match(typlypParser::ID);
      setState(131);
      match(typlypParser::LBRACKET);
      setState(132);
      expr(0);
      setState(133);
      match(typlypParser::RBRACKET);
      setState(134);
      match(typlypParser::LASSIGN);
      setState(135);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(137);
      expr(0);
      setState(138);
      match(typlypParser::RASSIGN);
      setState(139);
      match(typlypParser::ID);
      setState(140);
      match(typlypParser::LBRACKET);
      setState(141);
      expr(0);
      setState(142);
      match(typlypParser::RBRACKET);
      break;
    }

    default:
      break;
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

typlypParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* typlypParser::ReturnStatementContext::LASSIGN() {
  return getToken(typlypParser::LASSIGN, 0);
}

typlypParser::ExprContext* typlypParser::ReturnStatementContext::expr() {
  return getRuleContext<typlypParser::ExprContext>(0);
}

tree::TerminalNode* typlypParser::ReturnStatementContext::RASSIGN() {
  return getToken(typlypParser::RASSIGN, 0);
}


size_t typlypParser::ReturnStatementContext::getRuleIndex() const {
  return typlypParser::RuleReturnStatement;
}

void typlypParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void typlypParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}


std::any typlypParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::ReturnStatementContext* typlypParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 18, typlypParser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(153);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case typlypParser::T__2: {
        enterOuterAlt(_localctx, 1);
        setState(146);
        match(typlypParser::T__2);
        setState(147);
        match(typlypParser::LASSIGN);
        setState(148);
        expr(0);
        break;
      }

      case typlypParser::T__8:
      case typlypParser::BOOL:
      case typlypParser::INT:
      case typlypParser::ID:
      case typlypParser::NOT:
      case typlypParser::LBRACKET:
      case typlypParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(149);
        expr(0);
        setState(150);
        match(typlypParser::RASSIGN);
        setState(151);
        match(typlypParser::T__2);
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

//----------------- IfStatementContext ------------------------------------------------------------------

typlypParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* typlypParser::IfStatementContext::LPAREN() {
  return getToken(typlypParser::LPAREN, 0);
}

typlypParser::ExprContext* typlypParser::IfStatementContext::expr() {
  return getRuleContext<typlypParser::ExprContext>(0);
}

tree::TerminalNode* typlypParser::IfStatementContext::RPAREN() {
  return getToken(typlypParser::RPAREN, 0);
}

std::vector<typlypParser::BlockContext *> typlypParser::IfStatementContext::block() {
  return getRuleContexts<typlypParser::BlockContext>();
}

typlypParser::BlockContext* typlypParser::IfStatementContext::block(size_t i) {
  return getRuleContext<typlypParser::BlockContext>(i);
}


size_t typlypParser::IfStatementContext::getRuleIndex() const {
  return typlypParser::RuleIfStatement;
}

void typlypParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void typlypParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}


std::any typlypParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::IfStatementContext* typlypParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 20, typlypParser::RuleIfStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    match(typlypParser::T__3);
    setState(156);
    match(typlypParser::LPAREN);
    setState(157);
    expr(0);
    setState(158);
    match(typlypParser::RPAREN);
    setState(159);
    block();
    setState(162);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::T__4) {
      setState(160);
      match(typlypParser::T__4);
      setState(161);
      block();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

typlypParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* typlypParser::WhileStatementContext::LPAREN() {
  return getToken(typlypParser::LPAREN, 0);
}

typlypParser::ExprContext* typlypParser::WhileStatementContext::expr() {
  return getRuleContext<typlypParser::ExprContext>(0);
}

tree::TerminalNode* typlypParser::WhileStatementContext::RPAREN() {
  return getToken(typlypParser::RPAREN, 0);
}

typlypParser::BlockContext* typlypParser::WhileStatementContext::block() {
  return getRuleContext<typlypParser::BlockContext>(0);
}


size_t typlypParser::WhileStatementContext::getRuleIndex() const {
  return typlypParser::RuleWhileStatement;
}

void typlypParser::WhileStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStatement(this);
}

void typlypParser::WhileStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStatement(this);
}


std::any typlypParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::WhileStatementContext* typlypParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, typlypParser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    match(typlypParser::T__5);
    setState(165);
    match(typlypParser::LPAREN);
    setState(166);
    expr(0);
    setState(167);
    match(typlypParser::RPAREN);
    setState(168);
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

typlypParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* typlypParser::ForStatementContext::LPAREN() {
  return getToken(typlypParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> typlypParser::ForStatementContext::DIVIDER() {
  return getTokens(typlypParser::DIVIDER);
}

tree::TerminalNode* typlypParser::ForStatementContext::DIVIDER(size_t i) {
  return getToken(typlypParser::DIVIDER, i);
}

tree::TerminalNode* typlypParser::ForStatementContext::RPAREN() {
  return getToken(typlypParser::RPAREN, 0);
}

typlypParser::BlockContext* typlypParser::ForStatementContext::block() {
  return getRuleContext<typlypParser::BlockContext>(0);
}

typlypParser::VarDeclContext* typlypParser::ForStatementContext::varDecl() {
  return getRuleContext<typlypParser::VarDeclContext>(0);
}

typlypParser::ExprContext* typlypParser::ForStatementContext::expr() {
  return getRuleContext<typlypParser::ExprContext>(0);
}

typlypParser::AssignmentContext* typlypParser::ForStatementContext::assignment() {
  return getRuleContext<typlypParser::AssignmentContext>(0);
}


size_t typlypParser::ForStatementContext::getRuleIndex() const {
  return typlypParser::RuleForStatement;
}

void typlypParser::ForStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStatement(this);
}

void typlypParser::ForStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStatement(this);
}


std::any typlypParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::ForStatementContext* typlypParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, typlypParser::RuleForStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    match(typlypParser::T__6);
    setState(171);
    match(typlypParser::LPAREN);
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 176093716992) != 0)) {
      setState(172);
      varDecl();
    }
    setState(175);
    match(typlypParser::DIVIDER);
    setState(177);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 176093716992) != 0)) {
      setState(176);
      expr(0);
    }
    setState(179);
    match(typlypParser::DIVIDER);
    setState(181);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 176093716992) != 0)) {
      setState(180);
      assignment();
    }
    setState(183);
    match(typlypParser::RPAREN);
    setState(184);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintStatementContext ------------------------------------------------------------------

typlypParser::PrintStatementContext::PrintStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

typlypParser::ExprContext* typlypParser::PrintStatementContext::expr() {
  return getRuleContext<typlypParser::ExprContext>(0);
}

tree::TerminalNode* typlypParser::PrintStatementContext::RASSIGN() {
  return getToken(typlypParser::RASSIGN, 0);
}

tree::TerminalNode* typlypParser::PrintStatementContext::LASSIGN() {
  return getToken(typlypParser::LASSIGN, 0);
}


size_t typlypParser::PrintStatementContext::getRuleIndex() const {
  return typlypParser::RulePrintStatement;
}

void typlypParser::PrintStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrintStatement(this);
}

void typlypParser::PrintStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrintStatement(this);
}


std::any typlypParser::PrintStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitPrintStatement(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::PrintStatementContext* typlypParser::printStatement() {
  PrintStatementContext *_localctx = _tracker.createInstance<PrintStatementContext>(_ctx, getState());
  enterRule(_localctx, 26, typlypParser::RulePrintStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(193);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case typlypParser::T__8:
      case typlypParser::BOOL:
      case typlypParser::INT:
      case typlypParser::ID:
      case typlypParser::NOT:
      case typlypParser::LBRACKET:
      case typlypParser::LPAREN: {
        enterOuterAlt(_localctx, 1);
        setState(186);
        expr(0);
        setState(187);
        match(typlypParser::RASSIGN);
        setState(188);
        match(typlypParser::T__7);
        break;
      }

      case typlypParser::T__7: {
        enterOuterAlt(_localctx, 2);
        setState(190);
        match(typlypParser::T__7);
        setState(191);
        match(typlypParser::LASSIGN);
        setState(192);
        expr(0);
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

//----------------- ExprContext ------------------------------------------------------------------

typlypParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* typlypParser::ExprContext::NOT() {
  return getToken(typlypParser::NOT, 0);
}

std::vector<typlypParser::ExprContext *> typlypParser::ExprContext::expr() {
  return getRuleContexts<typlypParser::ExprContext>();
}

typlypParser::ExprContext* typlypParser::ExprContext::expr(size_t i) {
  return getRuleContext<typlypParser::ExprContext>(i);
}

tree::TerminalNode* typlypParser::ExprContext::ID() {
  return getToken(typlypParser::ID, 0);
}

tree::TerminalNode* typlypParser::ExprContext::LBRACKET() {
  return getToken(typlypParser::LBRACKET, 0);
}

tree::TerminalNode* typlypParser::ExprContext::RBRACKET() {
  return getToken(typlypParser::RBRACKET, 0);
}

tree::TerminalNode* typlypParser::ExprContext::INT() {
  return getToken(typlypParser::INT, 0);
}

tree::TerminalNode* typlypParser::ExprContext::BOOL() {
  return getToken(typlypParser::BOOL, 0);
}

tree::TerminalNode* typlypParser::ExprContext::LPAREN() {
  return getToken(typlypParser::LPAREN, 0);
}

tree::TerminalNode* typlypParser::ExprContext::RPAREN() {
  return getToken(typlypParser::RPAREN, 0);
}

tree::TerminalNode* typlypParser::ExprContext::LASSIGN() {
  return getToken(typlypParser::LASSIGN, 0);
}

typlypParser::ArgListContext* typlypParser::ExprContext::argList() {
  return getRuleContext<typlypParser::ArgListContext>(0);
}

tree::TerminalNode* typlypParser::ExprContext::RASSIGN() {
  return getToken(typlypParser::RASSIGN, 0);
}

typlypParser::ScalarTypeContext* typlypParser::ExprContext::scalarType() {
  return getRuleContext<typlypParser::ScalarTypeContext>(0);
}

tree::TerminalNode* typlypParser::ExprContext::LT() {
  return getToken(typlypParser::LT, 0);
}

tree::TerminalNode* typlypParser::ExprContext::GT() {
  return getToken(typlypParser::GT, 0);
}

tree::TerminalNode* typlypParser::ExprContext::MULT() {
  return getToken(typlypParser::MULT, 0);
}

tree::TerminalNode* typlypParser::ExprContext::DIV() {
  return getToken(typlypParser::DIV, 0);
}

tree::TerminalNode* typlypParser::ExprContext::MOD() {
  return getToken(typlypParser::MOD, 0);
}

tree::TerminalNode* typlypParser::ExprContext::PLUS() {
  return getToken(typlypParser::PLUS, 0);
}

tree::TerminalNode* typlypParser::ExprContext::MINUS() {
  return getToken(typlypParser::MINUS, 0);
}

tree::TerminalNode* typlypParser::ExprContext::LE() {
  return getToken(typlypParser::LE, 0);
}

tree::TerminalNode* typlypParser::ExprContext::GE() {
  return getToken(typlypParser::GE, 0);
}

tree::TerminalNode* typlypParser::ExprContext::EQ() {
  return getToken(typlypParser::EQ, 0);
}

tree::TerminalNode* typlypParser::ExprContext::NEQ() {
  return getToken(typlypParser::NEQ, 0);
}


size_t typlypParser::ExprContext::getRuleIndex() const {
  return typlypParser::RuleExpr;
}

void typlypParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void typlypParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any typlypParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


typlypParser::ExprContext* typlypParser::expr() {
   return expr(0);
}

typlypParser::ExprContext* typlypParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  typlypParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  typlypParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, typlypParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(230);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      setState(196);
      match(typlypParser::NOT);
      setState(197);
      expr(9);
      break;
    }

    case 2: {
      setState(198);
      match(typlypParser::ID);
      break;
    }

    case 3: {
      setState(199);
      match(typlypParser::ID);
      setState(200);
      match(typlypParser::LBRACKET);
      setState(201);
      expr(0);
      setState(202);
      match(typlypParser::RBRACKET);
      break;
    }

    case 4: {
      setState(204);
      match(typlypParser::INT);
      break;
    }

    case 5: {
      setState(205);
      match(typlypParser::BOOL);
      break;
    }

    case 6: {
      setState(206);
      match(typlypParser::LPAREN);
      setState(207);
      expr(0);
      setState(208);
      match(typlypParser::RPAREN);
      break;
    }

    case 7: {
      setState(210);
      match(typlypParser::ID);
      setState(211);
      match(typlypParser::LASSIGN);
      setState(212);
      match(typlypParser::LBRACKET);
      setState(214);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 176093716992) != 0)) {
        setState(213);
        argList();
      }
      setState(216);
      match(typlypParser::RBRACKET);
      break;
    }

    case 8: {
      setState(217);
      match(typlypParser::LBRACKET);
      setState(219);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 176093716992) != 0)) {
        setState(218);
        argList();
      }
      setState(221);
      match(typlypParser::RBRACKET);
      setState(222);
      match(typlypParser::RASSIGN);
      setState(223);
      match(typlypParser::ID);
      break;
    }

    case 9: {
      setState(224);
      match(typlypParser::T__8);
      setState(225);
      scalarType();
      setState(226);
      match(typlypParser::LT);
      setState(227);
      expr(0);
      setState(228);
      match(typlypParser::GT);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(246);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(244);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(232);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(233);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 14680064) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(234);
          expr(14);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(235);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(236);
          _la = _input->LA(1);
          if (!(_la == typlypParser::PLUS

          || _la == typlypParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(237);
          expr(13);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(238);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(239);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 251658240) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(240);
          expr(12);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(241);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(242);
          _la = _input->LA(1);
          if (!(_la == typlypParser::EQ

          || _la == typlypParser::NEQ)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(243);
          expr(11);
          break;
        }

        default:
          break;
        } 
      }
      setState(248);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ArgListContext ------------------------------------------------------------------

typlypParser::ArgListContext::ArgListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<typlypParser::ExprContext *> typlypParser::ArgListContext::expr() {
  return getRuleContexts<typlypParser::ExprContext>();
}

typlypParser::ExprContext* typlypParser::ArgListContext::expr(size_t i) {
  return getRuleContext<typlypParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> typlypParser::ArgListContext::COMMA() {
  return getTokens(typlypParser::COMMA);
}

tree::TerminalNode* typlypParser::ArgListContext::COMMA(size_t i) {
  return getToken(typlypParser::COMMA, i);
}


size_t typlypParser::ArgListContext::getRuleIndex() const {
  return typlypParser::RuleArgList;
}

void typlypParser::ArgListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgList(this);
}

void typlypParser::ArgListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgList(this);
}


std::any typlypParser::ArgListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitArgList(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::ArgListContext* typlypParser::argList() {
  ArgListContext *_localctx = _tracker.createInstance<ArgListContext>(_ctx, getState());
  enterRule(_localctx, 30, typlypParser::RuleArgList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    expr(0);
    setState(254);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == typlypParser::COMMA) {
      setState(250);
      match(typlypParser::COMMA);
      setState(251);
      expr(0);
      setState(256);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

typlypParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

typlypParser::ScalarTypeContext* typlypParser::TypeContext::scalarType() {
  return getRuleContext<typlypParser::ScalarTypeContext>(0);
}

typlypParser::ArrayTypeContext* typlypParser::TypeContext::arrayType() {
  return getRuleContext<typlypParser::ArrayTypeContext>(0);
}

typlypParser::VoidTypeContext* typlypParser::TypeContext::voidType() {
  return getRuleContext<typlypParser::VoidTypeContext>(0);
}


size_t typlypParser::TypeContext::getRuleIndex() const {
  return typlypParser::RuleType;
}

void typlypParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void typlypParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


std::any typlypParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::TypeContext* typlypParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 32, typlypParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(260);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(257);
      scalarType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(258);
      arrayType();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(259);
      voidType();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VoidTypeContext ------------------------------------------------------------------

typlypParser::VoidTypeContext::VoidTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t typlypParser::VoidTypeContext::getRuleIndex() const {
  return typlypParser::RuleVoidType;
}

void typlypParser::VoidTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVoidType(this);
}

void typlypParser::VoidTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVoidType(this);
}


std::any typlypParser::VoidTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitVoidType(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::VoidTypeContext* typlypParser::voidType() {
  VoidTypeContext *_localctx = _tracker.createInstance<VoidTypeContext>(_ctx, getState());
  enterRule(_localctx, 34, typlypParser::RuleVoidType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    match(typlypParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScalarTypeContext ------------------------------------------------------------------

typlypParser::ScalarTypeContext::ScalarTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t typlypParser::ScalarTypeContext::getRuleIndex() const {
  return typlypParser::RuleScalarType;
}

void typlypParser::ScalarTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScalarType(this);
}

void typlypParser::ScalarTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScalarType(this);
}


std::any typlypParser::ScalarTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitScalarType(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::ScalarTypeContext* typlypParser::scalarType() {
  ScalarTypeContext *_localctx = _tracker.createInstance<ScalarTypeContext>(_ctx, getState());
  enterRule(_localctx, 36, typlypParser::RuleScalarType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    _la = _input->LA(1);
    if (!(_la == typlypParser::T__10

    || _la == typlypParser::T__11)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

typlypParser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

typlypParser::ScalarTypeContext* typlypParser::ArrayTypeContext::scalarType() {
  return getRuleContext<typlypParser::ScalarTypeContext>(0);
}

tree::TerminalNode* typlypParser::ArrayTypeContext::LT() {
  return getToken(typlypParser::LT, 0);
}

tree::TerminalNode* typlypParser::ArrayTypeContext::GT() {
  return getToken(typlypParser::GT, 0);
}


size_t typlypParser::ArrayTypeContext::getRuleIndex() const {
  return typlypParser::RuleArrayType;
}

void typlypParser::ArrayTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayType(this);
}

void typlypParser::ArrayTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayType(this);
}


std::any typlypParser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::ArrayTypeContext* typlypParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 38, typlypParser::RuleArrayType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(271);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case typlypParser::LASSIGN:
      case typlypParser::RPAREN:
      case typlypParser::LBRACE:
      case typlypParser::SEMICOLON:
      case typlypParser::COMMA:
      case typlypParser::DIVIDER: {
        enterOuterAlt(_localctx, 1);

        break;
      }

      case typlypParser::T__10:
      case typlypParser::T__11: {
        enterOuterAlt(_localctx, 2);
        setState(267);
        scalarType();
        setState(268);
        match(typlypParser::LT);
        setState(269);
        match(typlypParser::GT);
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

bool typlypParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 14: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool typlypParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 13);
    case 1: return precpred(_ctx, 12);
    case 2: return precpred(_ctx, 11);
    case 3: return precpred(_ctx, 10);

  default:
    break;
  }
  return true;
}

void typlypParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  typlypParserInitialize();
#else
  ::antlr4::internal::call_once(typlypParserOnceFlag, typlypParserInitialize);
#endif
}
