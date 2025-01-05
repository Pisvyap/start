
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
      "program", "functionDecl", "externalDecl", "paramList", "param", "block", 
      "statement", "varDecl", "assignment", "arrayAssignment", "returnStatement", 
      "ifStatement", "whileStatement", "forStatement", "forInit", "forUpdate", 
      "expr", "argList", "exprList", "type", "voidType", "scalarType", "arrayType"
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
  	4,1,43,260,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,1,0,1,0,5,0,50,8,0,10,0,12,0,53,9,0,1,0,1,0,1,1,1,1,
  	1,1,1,1,3,1,61,8,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,3,2,72,8,2,1,2,
  	1,2,1,2,1,2,1,2,1,3,1,3,1,3,5,3,82,8,3,10,3,12,3,85,9,3,1,4,1,4,1,4,1,
  	4,1,5,1,5,5,5,93,8,5,10,5,12,5,96,9,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,3,6,110,8,6,1,7,1,7,1,7,1,7,1,7,1,7,3,7,118,8,7,1,7,1,
  	7,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,
  	1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,146,8,11,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,13,1,13,1,13,3,13,157,8,13,1,13,3,13,160,8,13,1,13,1,
  	13,3,13,164,8,13,1,13,1,13,1,13,1,14,1,14,3,14,171,8,14,1,15,1,15,1,16,
  	1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,
  	1,16,1,16,1,16,3,16,193,8,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,
  	1,16,1,16,1,16,3,16,206,8,16,1,16,3,16,209,8,16,1,16,1,16,1,16,1,16,1,
  	16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,5,16,223,8,16,10,16,12,16,226,9,
  	16,1,17,1,17,1,17,5,17,231,8,17,10,17,12,17,234,9,17,1,18,1,18,1,18,5,
  	18,239,8,18,10,18,12,18,242,9,18,1,19,1,19,1,19,3,19,247,8,19,1,20,1,
  	20,1,21,1,21,1,22,1,22,1,22,1,22,1,22,3,22,258,8,22,1,22,0,1,32,23,0,
  	2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,0,5,1,0,
  	23,25,1,0,21,22,1,0,26,29,1,0,30,31,1,0,13,14,275,0,51,1,0,0,0,2,56,1,
  	0,0,0,4,67,1,0,0,0,6,78,1,0,0,0,8,86,1,0,0,0,10,90,1,0,0,0,12,109,1,0,
  	0,0,14,111,1,0,0,0,16,121,1,0,0,0,18,126,1,0,0,0,20,134,1,0,0,0,22,138,
  	1,0,0,0,24,147,1,0,0,0,26,153,1,0,0,0,28,170,1,0,0,0,30,172,1,0,0,0,32,
  	208,1,0,0,0,34,227,1,0,0,0,36,235,1,0,0,0,38,246,1,0,0,0,40,248,1,0,0,
  	0,42,250,1,0,0,0,44,257,1,0,0,0,46,50,3,2,1,0,47,50,3,4,2,0,48,50,3,12,
  	6,0,49,46,1,0,0,0,49,47,1,0,0,0,49,48,1,0,0,0,50,53,1,0,0,0,51,49,1,0,
  	0,0,51,52,1,0,0,0,52,54,1,0,0,0,53,51,1,0,0,0,54,55,5,0,0,1,55,1,1,0,
  	0,0,56,57,5,1,0,0,57,58,5,17,0,0,58,60,5,38,0,0,59,61,3,6,3,0,60,59,1,
  	0,0,0,60,61,1,0,0,0,61,62,1,0,0,0,62,63,5,39,0,0,63,64,5,2,0,0,64,65,
  	3,38,19,0,65,66,3,10,5,0,66,3,1,0,0,0,67,68,5,3,0,0,68,69,5,17,0,0,69,
  	71,5,38,0,0,70,72,3,6,3,0,71,70,1,0,0,0,71,72,1,0,0,0,72,73,1,0,0,0,73,
  	74,5,39,0,0,74,75,5,2,0,0,75,76,3,38,19,0,76,77,5,42,0,0,77,5,1,0,0,0,
  	78,83,3,8,4,0,79,80,5,43,0,0,80,82,3,8,4,0,81,79,1,0,0,0,82,85,1,0,0,
  	0,83,81,1,0,0,0,83,84,1,0,0,0,84,7,1,0,0,0,85,83,1,0,0,0,86,87,5,17,0,
  	0,87,88,5,2,0,0,88,89,3,38,19,0,89,9,1,0,0,0,90,94,5,40,0,0,91,93,3,12,
  	6,0,92,91,1,0,0,0,93,96,1,0,0,0,94,92,1,0,0,0,94,95,1,0,0,0,95,97,1,0,
  	0,0,96,94,1,0,0,0,97,98,5,41,0,0,98,11,1,0,0,0,99,110,3,14,7,0,100,110,
  	3,16,8,0,101,110,3,18,9,0,102,110,3,20,10,0,103,110,3,22,11,0,104,110,
  	3,24,12,0,105,110,3,26,13,0,106,107,3,32,16,0,107,108,5,42,0,0,108,110,
  	1,0,0,0,109,99,1,0,0,0,109,100,1,0,0,0,109,101,1,0,0,0,109,102,1,0,0,
  	0,109,103,1,0,0,0,109,104,1,0,0,0,109,105,1,0,0,0,109,106,1,0,0,0,110,
  	13,1,0,0,0,111,112,5,4,0,0,112,113,5,17,0,0,113,114,5,2,0,0,114,117,3,
  	38,19,0,115,116,5,35,0,0,116,118,3,32,16,0,117,115,1,0,0,0,117,118,1,
  	0,0,0,118,119,1,0,0,0,119,120,5,42,0,0,120,15,1,0,0,0,121,122,5,17,0,
  	0,122,123,5,35,0,0,123,124,3,32,16,0,124,125,5,42,0,0,125,17,1,0,0,0,
  	126,127,5,17,0,0,127,128,5,36,0,0,128,129,3,32,16,0,129,130,5,37,0,0,
  	130,131,5,35,0,0,131,132,3,32,16,0,132,133,5,42,0,0,133,19,1,0,0,0,134,
  	135,5,5,0,0,135,136,3,32,16,0,136,137,5,42,0,0,137,21,1,0,0,0,138,139,
  	5,6,0,0,139,140,5,38,0,0,140,141,3,32,16,0,141,142,5,39,0,0,142,145,3,
  	10,5,0,143,144,5,7,0,0,144,146,3,10,5,0,145,143,1,0,0,0,145,146,1,0,0,
  	0,146,23,1,0,0,0,147,148,5,8,0,0,148,149,5,38,0,0,149,150,3,32,16,0,150,
  	151,5,39,0,0,151,152,3,10,5,0,152,25,1,0,0,0,153,154,5,9,0,0,154,156,
  	5,38,0,0,155,157,3,28,14,0,156,155,1,0,0,0,156,157,1,0,0,0,157,159,1,
  	0,0,0,158,160,3,32,16,0,159,158,1,0,0,0,159,160,1,0,0,0,160,161,1,0,0,
  	0,161,163,5,42,0,0,162,164,3,30,15,0,163,162,1,0,0,0,163,164,1,0,0,0,
  	164,165,1,0,0,0,165,166,5,39,0,0,166,167,3,10,5,0,167,27,1,0,0,0,168,
  	171,3,14,7,0,169,171,3,16,8,0,170,168,1,0,0,0,170,169,1,0,0,0,171,29,
  	1,0,0,0,172,173,3,16,8,0,173,31,1,0,0,0,174,175,6,16,-1,0,175,176,5,34,
  	0,0,176,209,3,32,16,9,177,209,5,17,0,0,178,179,5,17,0,0,179,180,5,36,
  	0,0,180,181,3,32,16,0,181,182,5,37,0,0,182,209,1,0,0,0,183,209,5,16,0,
  	0,184,209,5,15,0,0,185,186,5,38,0,0,186,187,3,32,16,0,187,188,5,39,0,
  	0,188,209,1,0,0,0,189,190,5,17,0,0,190,192,5,38,0,0,191,193,3,34,17,0,
  	192,191,1,0,0,0,192,193,1,0,0,0,193,194,1,0,0,0,194,209,5,39,0,0,195,
  	196,5,10,0,0,196,197,3,42,21,0,197,198,5,26,0,0,198,199,3,32,16,0,199,
  	200,5,28,0,0,200,209,1,0,0,0,201,202,5,11,0,0,202,203,5,17,0,0,203,205,
  	5,38,0,0,204,206,3,34,17,0,205,204,1,0,0,0,205,206,1,0,0,0,206,207,1,
  	0,0,0,207,209,5,39,0,0,208,174,1,0,0,0,208,177,1,0,0,0,208,178,1,0,0,
  	0,208,183,1,0,0,0,208,184,1,0,0,0,208,185,1,0,0,0,208,189,1,0,0,0,208,
  	195,1,0,0,0,208,201,1,0,0,0,209,224,1,0,0,0,210,211,10,13,0,0,211,212,
  	7,0,0,0,212,223,3,32,16,14,213,214,10,12,0,0,214,215,7,1,0,0,215,223,
  	3,32,16,13,216,217,10,11,0,0,217,218,7,2,0,0,218,223,3,32,16,12,219,220,
  	10,10,0,0,220,221,7,3,0,0,221,223,3,32,16,11,222,210,1,0,0,0,222,213,
  	1,0,0,0,222,216,1,0,0,0,222,219,1,0,0,0,223,226,1,0,0,0,224,222,1,0,0,
  	0,224,225,1,0,0,0,225,33,1,0,0,0,226,224,1,0,0,0,227,232,3,32,16,0,228,
  	229,5,43,0,0,229,231,3,32,16,0,230,228,1,0,0,0,231,234,1,0,0,0,232,230,
  	1,0,0,0,232,233,1,0,0,0,233,35,1,0,0,0,234,232,1,0,0,0,235,240,3,32,16,
  	0,236,237,5,43,0,0,237,239,3,32,16,0,238,236,1,0,0,0,239,242,1,0,0,0,
  	240,238,1,0,0,0,240,241,1,0,0,0,241,37,1,0,0,0,242,240,1,0,0,0,243,247,
  	3,42,21,0,244,247,3,44,22,0,245,247,3,40,20,0,246,243,1,0,0,0,246,244,
  	1,0,0,0,246,245,1,0,0,0,247,39,1,0,0,0,248,249,5,12,0,0,249,41,1,0,0,
  	0,250,251,7,4,0,0,251,43,1,0,0,0,252,258,1,0,0,0,253,254,3,42,21,0,254,
  	255,5,26,0,0,255,256,5,28,0,0,256,258,1,0,0,0,257,252,1,0,0,0,257,253,
  	1,0,0,0,258,45,1,0,0,0,22,49,51,60,71,83,94,109,117,145,156,159,163,170,
  	192,205,208,222,224,232,240,246,257
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

std::vector<typlypParser::ExternalDeclContext *> typlypParser::ProgramContext::externalDecl() {
  return getRuleContexts<typlypParser::ExternalDeclContext>();
}

typlypParser::ExternalDeclContext* typlypParser::ProgramContext::externalDecl(size_t i) {
  return getRuleContext<typlypParser::ExternalDeclContext>(i);
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
    setState(51);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 292058009466) != 0)) {
      setState(49);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case typlypParser::T__0: {
          setState(46);
          functionDecl();
          break;
        }

        case typlypParser::T__2: {
          setState(47);
          externalDecl();
          break;
        }

        case typlypParser::T__3:
        case typlypParser::T__4:
        case typlypParser::T__5:
        case typlypParser::T__7:
        case typlypParser::T__8:
        case typlypParser::T__9:
        case typlypParser::T__10:
        case typlypParser::BOOL:
        case typlypParser::INT:
        case typlypParser::ID:
        case typlypParser::NOT:
        case typlypParser::LPAREN: {
          setState(48);
          statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(53);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(54);
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
    setState(56);
    match(typlypParser::T__0);
    setState(57);
    match(typlypParser::ID);
    setState(58);
    match(typlypParser::LPAREN);
    setState(60);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::ID) {
      setState(59);
      paramList();
    }
    setState(62);
    match(typlypParser::RPAREN);
    setState(63);
    match(typlypParser::T__1);
    setState(64);
    type();
    setState(65);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternalDeclContext ------------------------------------------------------------------

typlypParser::ExternalDeclContext::ExternalDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* typlypParser::ExternalDeclContext::ID() {
  return getToken(typlypParser::ID, 0);
}

tree::TerminalNode* typlypParser::ExternalDeclContext::LPAREN() {
  return getToken(typlypParser::LPAREN, 0);
}

tree::TerminalNode* typlypParser::ExternalDeclContext::RPAREN() {
  return getToken(typlypParser::RPAREN, 0);
}

typlypParser::TypeContext* typlypParser::ExternalDeclContext::type() {
  return getRuleContext<typlypParser::TypeContext>(0);
}

tree::TerminalNode* typlypParser::ExternalDeclContext::SEMICOLON() {
  return getToken(typlypParser::SEMICOLON, 0);
}

typlypParser::ParamListContext* typlypParser::ExternalDeclContext::paramList() {
  return getRuleContext<typlypParser::ParamListContext>(0);
}


size_t typlypParser::ExternalDeclContext::getRuleIndex() const {
  return typlypParser::RuleExternalDecl;
}

void typlypParser::ExternalDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternalDecl(this);
}

void typlypParser::ExternalDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternalDecl(this);
}


std::any typlypParser::ExternalDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitExternalDecl(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::ExternalDeclContext* typlypParser::externalDecl() {
  ExternalDeclContext *_localctx = _tracker.createInstance<ExternalDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, typlypParser::RuleExternalDecl);
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
    setState(67);
    match(typlypParser::T__2);
    setState(68);
    match(typlypParser::ID);
    setState(69);
    match(typlypParser::LPAREN);
    setState(71);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::ID) {
      setState(70);
      paramList();
    }
    setState(73);
    match(typlypParser::RPAREN);
    setState(74);
    match(typlypParser::T__1);
    setState(75);
    type();
    setState(76);
    match(typlypParser::SEMICOLON);
   
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
  enterRule(_localctx, 6, typlypParser::RuleParamList);
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
    setState(78);
    param();
    setState(83);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == typlypParser::COMMA) {
      setState(79);
      match(typlypParser::COMMA);
      setState(80);
      param();
      setState(85);
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
  enterRule(_localctx, 8, typlypParser::RuleParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    match(typlypParser::ID);
    setState(87);
    match(typlypParser::T__1);
    setState(88);
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
  enterRule(_localctx, 10, typlypParser::RuleBlock);
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
    setState(90);
    match(typlypParser::LBRACE);
    setState(94);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 292058009456) != 0)) {
      setState(91);
      statement();
      setState(96);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(97);
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

tree::TerminalNode* typlypParser::StatementContext::SEMICOLON() {
  return getToken(typlypParser::SEMICOLON, 0);
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
  enterRule(_localctx, 12, typlypParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(109);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(99);
      varDecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(100);
      assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(101);
      arrayAssignment();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(102);
      returnStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(103);
      ifStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(104);
      whileStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(105);
      forStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(106);
      expr(0);
      setState(107);
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

tree::TerminalNode* typlypParser::VarDeclContext::SEMICOLON() {
  return getToken(typlypParser::SEMICOLON, 0);
}

tree::TerminalNode* typlypParser::VarDeclContext::ASSIGN() {
  return getToken(typlypParser::ASSIGN, 0);
}

typlypParser::ExprContext* typlypParser::VarDeclContext::expr() {
  return getRuleContext<typlypParser::ExprContext>(0);
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
  enterRule(_localctx, 14, typlypParser::RuleVarDecl);
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
    setState(111);
    match(typlypParser::T__3);
    setState(112);
    match(typlypParser::ID);
    setState(113);
    match(typlypParser::T__1);
    setState(114);
    type();
    setState(117);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::ASSIGN) {
      setState(115);
      match(typlypParser::ASSIGN);
      setState(116);
      expr(0);
    }
    setState(119);
    match(typlypParser::SEMICOLON);
   
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

tree::TerminalNode* typlypParser::AssignmentContext::ASSIGN() {
  return getToken(typlypParser::ASSIGN, 0);
}

typlypParser::ExprContext* typlypParser::AssignmentContext::expr() {
  return getRuleContext<typlypParser::ExprContext>(0);
}

tree::TerminalNode* typlypParser::AssignmentContext::SEMICOLON() {
  return getToken(typlypParser::SEMICOLON, 0);
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
  enterRule(_localctx, 16, typlypParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    match(typlypParser::ID);
    setState(122);
    match(typlypParser::ASSIGN);
    setState(123);
    expr(0);
    setState(124);
    match(typlypParser::SEMICOLON);
   
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

tree::TerminalNode* typlypParser::ArrayAssignmentContext::ASSIGN() {
  return getToken(typlypParser::ASSIGN, 0);
}

tree::TerminalNode* typlypParser::ArrayAssignmentContext::SEMICOLON() {
  return getToken(typlypParser::SEMICOLON, 0);
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
  enterRule(_localctx, 18, typlypParser::RuleArrayAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(126);
    match(typlypParser::ID);
    setState(127);
    match(typlypParser::LBRACKET);
    setState(128);
    expr(0);
    setState(129);
    match(typlypParser::RBRACKET);
    setState(130);
    match(typlypParser::ASSIGN);
    setState(131);
    expr(0);
    setState(132);
    match(typlypParser::SEMICOLON);
   
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

typlypParser::ExprContext* typlypParser::ReturnStatementContext::expr() {
  return getRuleContext<typlypParser::ExprContext>(0);
}

tree::TerminalNode* typlypParser::ReturnStatementContext::SEMICOLON() {
  return getToken(typlypParser::SEMICOLON, 0);
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
  enterRule(_localctx, 20, typlypParser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    match(typlypParser::T__4);
    setState(135);
    expr(0);
    setState(136);
    match(typlypParser::SEMICOLON);
   
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
  enterRule(_localctx, 22, typlypParser::RuleIfStatement);
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
    setState(138);
    match(typlypParser::T__5);
    setState(139);
    match(typlypParser::LPAREN);
    setState(140);
    expr(0);
    setState(141);
    match(typlypParser::RPAREN);
    setState(142);
    block();
    setState(145);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::T__6) {
      setState(143);
      match(typlypParser::T__6);
      setState(144);
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
  enterRule(_localctx, 24, typlypParser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    match(typlypParser::T__7);
    setState(148);
    match(typlypParser::LPAREN);
    setState(149);
    expr(0);
    setState(150);
    match(typlypParser::RPAREN);
    setState(151);
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

tree::TerminalNode* typlypParser::ForStatementContext::SEMICOLON() {
  return getToken(typlypParser::SEMICOLON, 0);
}

tree::TerminalNode* typlypParser::ForStatementContext::RPAREN() {
  return getToken(typlypParser::RPAREN, 0);
}

typlypParser::BlockContext* typlypParser::ForStatementContext::block() {
  return getRuleContext<typlypParser::BlockContext>(0);
}

typlypParser::ForInitContext* typlypParser::ForStatementContext::forInit() {
  return getRuleContext<typlypParser::ForInitContext>(0);
}

typlypParser::ExprContext* typlypParser::ForStatementContext::expr() {
  return getRuleContext<typlypParser::ExprContext>(0);
}

typlypParser::ForUpdateContext* typlypParser::ForStatementContext::forUpdate() {
  return getRuleContext<typlypParser::ForUpdateContext>(0);
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
  enterRule(_localctx, 26, typlypParser::RuleForStatement);
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
    setState(153);
    match(typlypParser::T__8);
    setState(154);
    match(typlypParser::LPAREN);
    setState(156);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(155);
      forInit();
      break;
    }

    default:
      break;
    }
    setState(159);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 292058008576) != 0)) {
      setState(158);
      expr(0);
    }
    setState(161);
    match(typlypParser::SEMICOLON);
    setState(163);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::ID) {
      setState(162);
      forUpdate();
    }
    setState(165);
    match(typlypParser::RPAREN);
    setState(166);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForInitContext ------------------------------------------------------------------

typlypParser::ForInitContext::ForInitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

typlypParser::VarDeclContext* typlypParser::ForInitContext::varDecl() {
  return getRuleContext<typlypParser::VarDeclContext>(0);
}

typlypParser::AssignmentContext* typlypParser::ForInitContext::assignment() {
  return getRuleContext<typlypParser::AssignmentContext>(0);
}


size_t typlypParser::ForInitContext::getRuleIndex() const {
  return typlypParser::RuleForInit;
}

void typlypParser::ForInitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForInit(this);
}

void typlypParser::ForInitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForInit(this);
}


std::any typlypParser::ForInitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitForInit(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::ForInitContext* typlypParser::forInit() {
  ForInitContext *_localctx = _tracker.createInstance<ForInitContext>(_ctx, getState());
  enterRule(_localctx, 28, typlypParser::RuleForInit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(170);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case typlypParser::T__3: {
        enterOuterAlt(_localctx, 1);
        setState(168);
        varDecl();
        break;
      }

      case typlypParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(169);
        assignment();
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

//----------------- ForUpdateContext ------------------------------------------------------------------

typlypParser::ForUpdateContext::ForUpdateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

typlypParser::AssignmentContext* typlypParser::ForUpdateContext::assignment() {
  return getRuleContext<typlypParser::AssignmentContext>(0);
}


size_t typlypParser::ForUpdateContext::getRuleIndex() const {
  return typlypParser::RuleForUpdate;
}

void typlypParser::ForUpdateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForUpdate(this);
}

void typlypParser::ForUpdateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForUpdate(this);
}


std::any typlypParser::ForUpdateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitForUpdate(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::ForUpdateContext* typlypParser::forUpdate() {
  ForUpdateContext *_localctx = _tracker.createInstance<ForUpdateContext>(_ctx, getState());
  enterRule(_localctx, 30, typlypParser::RuleForUpdate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    assignment();
   
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

typlypParser::ArgListContext* typlypParser::ExprContext::argList() {
  return getRuleContext<typlypParser::ArgListContext>(0);
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
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, typlypParser::RuleExpr, precedence);

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
    setState(208);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(175);
      match(typlypParser::NOT);
      setState(176);
      expr(9);
      break;
    }

    case 2: {
      setState(177);
      match(typlypParser::ID);
      break;
    }

    case 3: {
      setState(178);
      match(typlypParser::ID);
      setState(179);
      match(typlypParser::LBRACKET);
      setState(180);
      expr(0);
      setState(181);
      match(typlypParser::RBRACKET);
      break;
    }

    case 4: {
      setState(183);
      match(typlypParser::INT);
      break;
    }

    case 5: {
      setState(184);
      match(typlypParser::BOOL);
      break;
    }

    case 6: {
      setState(185);
      match(typlypParser::LPAREN);
      setState(186);
      expr(0);
      setState(187);
      match(typlypParser::RPAREN);
      break;
    }

    case 7: {
      setState(189);
      match(typlypParser::ID);
      setState(190);
      match(typlypParser::LPAREN);
      setState(192);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 292058008576) != 0)) {
        setState(191);
        argList();
      }
      setState(194);
      match(typlypParser::RPAREN);
      break;
    }

    case 8: {
      setState(195);
      match(typlypParser::T__9);
      setState(196);
      scalarType();
      setState(197);
      match(typlypParser::LT);
      setState(198);
      expr(0);
      setState(199);
      match(typlypParser::GT);
      break;
    }

    case 9: {
      setState(201);
      match(typlypParser::T__10);
      setState(202);
      match(typlypParser::ID);
      setState(203);
      match(typlypParser::LPAREN);
      setState(205);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 292058008576) != 0)) {
        setState(204);
        argList();
      }
      setState(207);
      match(typlypParser::RPAREN);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(224);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(222);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(210);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(211);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 58720256) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(212);
          expr(14);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(213);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(214);
          _la = _input->LA(1);
          if (!(_la == typlypParser::PLUS

          || _la == typlypParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(215);
          expr(13);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(216);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(217);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 1006632960) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(218);
          expr(12);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(219);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(220);
          _la = _input->LA(1);
          if (!(_la == typlypParser::EQ

          || _la == typlypParser::NEQ)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(221);
          expr(11);
          break;
        }

        default:
          break;
        } 
      }
      setState(226);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
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
  enterRule(_localctx, 34, typlypParser::RuleArgList);
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
    setState(227);
    expr(0);
    setState(232);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == typlypParser::COMMA) {
      setState(228);
      match(typlypParser::COMMA);
      setState(229);
      expr(0);
      setState(234);
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

//----------------- ExprListContext ------------------------------------------------------------------

typlypParser::ExprListContext::ExprListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<typlypParser::ExprContext *> typlypParser::ExprListContext::expr() {
  return getRuleContexts<typlypParser::ExprContext>();
}

typlypParser::ExprContext* typlypParser::ExprListContext::expr(size_t i) {
  return getRuleContext<typlypParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> typlypParser::ExprListContext::COMMA() {
  return getTokens(typlypParser::COMMA);
}

tree::TerminalNode* typlypParser::ExprListContext::COMMA(size_t i) {
  return getToken(typlypParser::COMMA, i);
}


size_t typlypParser::ExprListContext::getRuleIndex() const {
  return typlypParser::RuleExprList;
}

void typlypParser::ExprListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprList(this);
}

void typlypParser::ExprListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<typlypListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprList(this);
}


std::any typlypParser::ExprListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<typlypVisitor*>(visitor))
    return parserVisitor->visitExprList(this);
  else
    return visitor->visitChildren(this);
}

typlypParser::ExprListContext* typlypParser::exprList() {
  ExprListContext *_localctx = _tracker.createInstance<ExprListContext>(_ctx, getState());
  enterRule(_localctx, 36, typlypParser::RuleExprList);
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
    setState(235);
    expr(0);
    setState(240);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == typlypParser::COMMA) {
      setState(236);
      match(typlypParser::COMMA);
      setState(237);
      expr(0);
      setState(242);
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
  enterRule(_localctx, 38, typlypParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(246);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(243);
      scalarType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(244);
      arrayType();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(245);
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
  enterRule(_localctx, 40, typlypParser::RuleVoidType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    match(typlypParser::T__11);
   
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
  enterRule(_localctx, 42, typlypParser::RuleScalarType);
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
    setState(250);
    _la = _input->LA(1);
    if (!(_la == typlypParser::T__12

    || _la == typlypParser::T__13)) {
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
  enterRule(_localctx, 44, typlypParser::RuleArrayType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(257);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case typlypParser::ASSIGN:
      case typlypParser::RPAREN:
      case typlypParser::LBRACE:
      case typlypParser::SEMICOLON:
      case typlypParser::COMMA: {
        enterOuterAlt(_localctx, 1);

        break;
      }

      case typlypParser::T__12:
      case typlypParser::T__13: {
        enterOuterAlt(_localctx, 2);
        setState(253);
        scalarType();
        setState(254);
        match(typlypParser::LT);
        setState(255);
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
    case 16: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

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
