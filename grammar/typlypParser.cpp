
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
      "ifStatement", "whileStatement", "forStatement", "printStatement", 
      "expr", "argList", "exprList", "type", "voidType", "scalarType", "arrayType"
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
  	4,1,45,258,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,1,0,1,0,1,0,5,0,48,8,0,10,0,12,0,51,9,0,1,0,1,0,1,1,1,1,1,1,1,1,3,
  	1,59,8,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,3,2,70,8,2,1,2,1,2,1,2,1,
  	2,1,2,1,3,1,3,1,3,5,3,80,8,3,10,3,12,3,83,9,3,1,4,1,4,1,4,1,4,1,5,1,5,
  	5,5,91,8,5,10,5,12,5,94,9,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,3,6,109,8,6,1,7,1,7,1,7,1,7,1,7,1,7,3,7,117,8,7,1,7,1,7,1,8,
  	1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,145,8,11,1,12,1,12,1,12,1,12,1,
  	12,1,12,1,13,1,13,1,13,3,13,156,8,13,1,13,3,13,159,8,13,1,13,1,13,3,13,
  	163,8,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	3,15,191,8,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	3,15,204,8,15,1,15,3,15,207,8,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,5,15,221,8,15,10,15,12,15,224,9,15,1,16,1,16,1,
  	16,5,16,229,8,16,10,16,12,16,232,9,16,1,17,1,17,1,17,5,17,237,8,17,10,
  	17,12,17,240,9,17,1,18,1,18,1,18,3,18,245,8,18,1,19,1,19,1,20,1,20,1,
  	21,1,21,1,21,1,21,1,21,3,21,256,8,21,1,21,0,1,30,22,0,2,4,6,8,10,12,14,
  	16,18,20,22,24,26,28,30,32,34,36,38,40,42,0,5,1,0,25,27,1,0,23,24,1,0,
  	28,31,1,0,32,33,1,0,15,16,274,0,49,1,0,0,0,2,54,1,0,0,0,4,65,1,0,0,0,
  	6,76,1,0,0,0,8,84,1,0,0,0,10,88,1,0,0,0,12,108,1,0,0,0,14,110,1,0,0,0,
  	16,120,1,0,0,0,18,125,1,0,0,0,20,133,1,0,0,0,22,137,1,0,0,0,24,146,1,
  	0,0,0,26,152,1,0,0,0,28,167,1,0,0,0,30,206,1,0,0,0,32,225,1,0,0,0,34,
  	233,1,0,0,0,36,244,1,0,0,0,38,246,1,0,0,0,40,248,1,0,0,0,42,255,1,0,0,
  	0,44,48,3,2,1,0,45,48,3,4,2,0,46,48,3,12,6,0,47,44,1,0,0,0,47,45,1,0,
  	0,0,47,46,1,0,0,0,48,51,1,0,0,0,49,47,1,0,0,0,49,50,1,0,0,0,50,52,1,0,
  	0,0,51,49,1,0,0,0,52,53,5,0,0,1,53,1,1,0,0,0,54,55,5,1,0,0,55,56,5,19,
  	0,0,56,58,5,40,0,0,57,59,3,6,3,0,58,57,1,0,0,0,58,59,1,0,0,0,59,60,1,
  	0,0,0,60,61,5,41,0,0,61,62,5,2,0,0,62,63,3,36,18,0,63,64,3,10,5,0,64,
  	3,1,0,0,0,65,66,5,3,0,0,66,67,5,19,0,0,67,69,5,40,0,0,68,70,3,6,3,0,69,
  	68,1,0,0,0,69,70,1,0,0,0,70,71,1,0,0,0,71,72,5,41,0,0,72,73,5,2,0,0,73,
  	74,3,36,18,0,74,75,5,44,0,0,75,5,1,0,0,0,76,81,3,8,4,0,77,78,5,45,0,0,
  	78,80,3,8,4,0,79,77,1,0,0,0,80,83,1,0,0,0,81,79,1,0,0,0,81,82,1,0,0,0,
  	82,7,1,0,0,0,83,81,1,0,0,0,84,85,5,19,0,0,85,86,5,2,0,0,86,87,3,36,18,
  	0,87,9,1,0,0,0,88,92,5,42,0,0,89,91,3,12,6,0,90,89,1,0,0,0,91,94,1,0,
  	0,0,92,90,1,0,0,0,92,93,1,0,0,0,93,95,1,0,0,0,94,92,1,0,0,0,95,96,5,43,
  	0,0,96,11,1,0,0,0,97,109,3,14,7,0,98,109,3,28,14,0,99,109,3,16,8,0,100,
  	109,3,18,9,0,101,109,3,20,10,0,102,109,3,22,11,0,103,109,3,24,12,0,104,
  	109,3,26,13,0,105,106,3,30,15,0,106,107,5,44,0,0,107,109,1,0,0,0,108,
  	97,1,0,0,0,108,98,1,0,0,0,108,99,1,0,0,0,108,100,1,0,0,0,108,101,1,0,
  	0,0,108,102,1,0,0,0,108,103,1,0,0,0,108,104,1,0,0,0,108,105,1,0,0,0,109,
  	13,1,0,0,0,110,111,5,4,0,0,111,112,5,19,0,0,112,113,5,2,0,0,113,116,3,
  	36,18,0,114,115,5,37,0,0,115,117,3,30,15,0,116,114,1,0,0,0,116,117,1,
  	0,0,0,117,118,1,0,0,0,118,119,5,44,0,0,119,15,1,0,0,0,120,121,5,19,0,
  	0,121,122,5,37,0,0,122,123,3,30,15,0,123,124,5,44,0,0,124,17,1,0,0,0,
  	125,126,5,19,0,0,126,127,5,38,0,0,127,128,3,30,15,0,128,129,5,39,0,0,
  	129,130,5,37,0,0,130,131,3,30,15,0,131,132,5,44,0,0,132,19,1,0,0,0,133,
  	134,5,5,0,0,134,135,3,30,15,0,135,136,5,44,0,0,136,21,1,0,0,0,137,138,
  	5,6,0,0,138,139,5,40,0,0,139,140,3,30,15,0,140,141,5,41,0,0,141,144,3,
  	10,5,0,142,143,5,7,0,0,143,145,3,10,5,0,144,142,1,0,0,0,144,145,1,0,0,
  	0,145,23,1,0,0,0,146,147,5,8,0,0,147,148,5,40,0,0,148,149,3,30,15,0,149,
  	150,5,41,0,0,150,151,3,10,5,0,151,25,1,0,0,0,152,153,5,9,0,0,153,155,
  	5,40,0,0,154,156,3,14,7,0,155,154,1,0,0,0,155,156,1,0,0,0,156,158,1,0,
  	0,0,157,159,3,30,15,0,158,157,1,0,0,0,158,159,1,0,0,0,159,160,1,0,0,0,
  	160,162,5,44,0,0,161,163,3,16,8,0,162,161,1,0,0,0,162,163,1,0,0,0,163,
  	164,1,0,0,0,164,165,5,41,0,0,165,166,3,10,5,0,166,27,1,0,0,0,167,168,
  	3,30,15,0,168,169,5,10,0,0,169,170,5,11,0,0,170,171,5,44,0,0,171,29,1,
  	0,0,0,172,173,6,15,-1,0,173,174,5,36,0,0,174,207,3,30,15,9,175,207,5,
  	19,0,0,176,177,5,19,0,0,177,178,5,38,0,0,178,179,3,30,15,0,179,180,5,
  	39,0,0,180,207,1,0,0,0,181,207,5,18,0,0,182,207,5,17,0,0,183,184,5,40,
  	0,0,184,185,3,30,15,0,185,186,5,41,0,0,186,207,1,0,0,0,187,188,5,19,0,
  	0,188,190,5,40,0,0,189,191,3,32,16,0,190,189,1,0,0,0,190,191,1,0,0,0,
  	191,192,1,0,0,0,192,207,5,41,0,0,193,194,5,12,0,0,194,195,3,40,20,0,195,
  	196,5,28,0,0,196,197,3,30,15,0,197,198,5,30,0,0,198,207,1,0,0,0,199,200,
  	5,13,0,0,200,201,5,19,0,0,201,203,5,40,0,0,202,204,3,32,16,0,203,202,
  	1,0,0,0,203,204,1,0,0,0,204,205,1,0,0,0,205,207,5,41,0,0,206,172,1,0,
  	0,0,206,175,1,0,0,0,206,176,1,0,0,0,206,181,1,0,0,0,206,182,1,0,0,0,206,
  	183,1,0,0,0,206,187,1,0,0,0,206,193,1,0,0,0,206,199,1,0,0,0,207,222,1,
  	0,0,0,208,209,10,13,0,0,209,210,7,0,0,0,210,221,3,30,15,14,211,212,10,
  	12,0,0,212,213,7,1,0,0,213,221,3,30,15,13,214,215,10,11,0,0,215,216,7,
  	2,0,0,216,221,3,30,15,12,217,218,10,10,0,0,218,219,7,3,0,0,219,221,3,
  	30,15,11,220,208,1,0,0,0,220,211,1,0,0,0,220,214,1,0,0,0,220,217,1,0,
  	0,0,221,224,1,0,0,0,222,220,1,0,0,0,222,223,1,0,0,0,223,31,1,0,0,0,224,
  	222,1,0,0,0,225,230,3,30,15,0,226,227,5,45,0,0,227,229,3,30,15,0,228,
  	226,1,0,0,0,229,232,1,0,0,0,230,228,1,0,0,0,230,231,1,0,0,0,231,33,1,
  	0,0,0,232,230,1,0,0,0,233,238,3,30,15,0,234,235,5,45,0,0,235,237,3,30,
  	15,0,236,234,1,0,0,0,237,240,1,0,0,0,238,236,1,0,0,0,238,239,1,0,0,0,
  	239,35,1,0,0,0,240,238,1,0,0,0,241,245,3,40,20,0,242,245,3,42,21,0,243,
  	245,3,38,19,0,244,241,1,0,0,0,244,242,1,0,0,0,244,243,1,0,0,0,245,37,
  	1,0,0,0,246,247,5,14,0,0,247,39,1,0,0,0,248,249,7,4,0,0,249,41,1,0,0,
  	0,250,256,1,0,0,0,251,252,3,40,20,0,252,253,5,28,0,0,253,254,5,30,0,0,
  	254,256,1,0,0,0,255,250,1,0,0,0,255,251,1,0,0,0,256,43,1,0,0,0,21,47,
  	49,58,69,81,92,108,116,144,155,158,162,190,203,206,220,222,230,238,244,
  	255
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
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1168232035194) != 0)) {
      setState(47);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case typlypParser::T__0: {
          setState(44);
          functionDecl();
          break;
        }

        case typlypParser::T__2: {
          setState(45);
          externalDecl();
          break;
        }

        case typlypParser::T__3:
        case typlypParser::T__4:
        case typlypParser::T__5:
        case typlypParser::T__7:
        case typlypParser::T__8:
        case typlypParser::T__11:
        case typlypParser::T__12:
        case typlypParser::BOOL:
        case typlypParser::INT:
        case typlypParser::ID:
        case typlypParser::NOT:
        case typlypParser::LPAREN: {
          setState(46);
          statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(52);
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
    setState(54);
    match(typlypParser::T__0);
    setState(55);
    match(typlypParser::ID);
    setState(56);
    match(typlypParser::LPAREN);
    setState(58);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::ID) {
      setState(57);
      paramList();
    }
    setState(60);
    match(typlypParser::RPAREN);
    setState(61);
    match(typlypParser::T__1);
    setState(62);
    type();
    setState(63);
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
    setState(65);
    match(typlypParser::T__2);
    setState(66);
    match(typlypParser::ID);
    setState(67);
    match(typlypParser::LPAREN);
    setState(69);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::ID) {
      setState(68);
      paramList();
    }
    setState(71);
    match(typlypParser::RPAREN);
    setState(72);
    match(typlypParser::T__1);
    setState(73);
    type();
    setState(74);
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
    setState(76);
    param();
    setState(81);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == typlypParser::COMMA) {
      setState(77);
      match(typlypParser::COMMA);
      setState(78);
      param();
      setState(83);
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
    setState(84);
    match(typlypParser::ID);
    setState(85);
    match(typlypParser::T__1);
    setState(86);
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
    setState(88);
    match(typlypParser::LBRACE);
    setState(92);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1168232035184) != 0)) {
      setState(89);
      statement();
      setState(94);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(95);
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
    setState(108);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(97);
      varDecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(98);
      printStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(99);
      assignment();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(100);
      arrayAssignment();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(101);
      returnStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(102);
      ifStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(103);
      whileStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(104);
      forStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(105);
      expr(0);
      setState(106);
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
    setState(110);
    match(typlypParser::T__3);
    setState(111);
    match(typlypParser::ID);
    setState(112);
    match(typlypParser::T__1);
    setState(113);
    type();
    setState(116);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::ASSIGN) {
      setState(114);
      match(typlypParser::ASSIGN);
      setState(115);
      expr(0);
    }
    setState(118);
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
    setState(120);
    match(typlypParser::ID);
    setState(121);
    match(typlypParser::ASSIGN);
    setState(122);
    expr(0);
    setState(123);
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
    setState(125);
    match(typlypParser::ID);
    setState(126);
    match(typlypParser::LBRACKET);
    setState(127);
    expr(0);
    setState(128);
    match(typlypParser::RBRACKET);
    setState(129);
    match(typlypParser::ASSIGN);
    setState(130);
    expr(0);
    setState(131);
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
    setState(133);
    match(typlypParser::T__4);
    setState(134);
    expr(0);
    setState(135);
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
    setState(137);
    match(typlypParser::T__5);
    setState(138);
    match(typlypParser::LPAREN);
    setState(139);
    expr(0);
    setState(140);
    match(typlypParser::RPAREN);
    setState(141);
    block();
    setState(144);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::T__6) {
      setState(142);
      match(typlypParser::T__6);
      setState(143);
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
    setState(146);
    match(typlypParser::T__7);
    setState(147);
    match(typlypParser::LPAREN);
    setState(148);
    expr(0);
    setState(149);
    match(typlypParser::RPAREN);
    setState(150);
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
    setState(152);
    match(typlypParser::T__8);
    setState(153);
    match(typlypParser::LPAREN);
    setState(155);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::T__3) {
      setState(154);
      varDecl();
    }
    setState(158);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1168232034304) != 0)) {
      setState(157);
      expr(0);
    }
    setState(160);
    match(typlypParser::SEMICOLON);
    setState(162);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::ID) {
      setState(161);
      assignment();
    }
    setState(164);
    match(typlypParser::RPAREN);
    setState(165);
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

tree::TerminalNode* typlypParser::PrintStatementContext::SEMICOLON() {
  return getToken(typlypParser::SEMICOLON, 0);
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
  enterRule(_localctx, 28, typlypParser::RulePrintStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    expr(0);
    setState(168);
    match(typlypParser::T__9);
    setState(169);
    match(typlypParser::T__10);
    setState(170);
    match(typlypParser::SEMICOLON);
   
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
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, typlypParser::RuleExpr, precedence);

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
    setState(206);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(173);
      match(typlypParser::NOT);
      setState(174);
      expr(9);
      break;
    }

    case 2: {
      setState(175);
      match(typlypParser::ID);
      break;
    }

    case 3: {
      setState(176);
      match(typlypParser::ID);
      setState(177);
      match(typlypParser::LBRACKET);
      setState(178);
      expr(0);
      setState(179);
      match(typlypParser::RBRACKET);
      break;
    }

    case 4: {
      setState(181);
      match(typlypParser::INT);
      break;
    }

    case 5: {
      setState(182);
      match(typlypParser::BOOL);
      break;
    }

    case 6: {
      setState(183);
      match(typlypParser::LPAREN);
      setState(184);
      expr(0);
      setState(185);
      match(typlypParser::RPAREN);
      break;
    }

    case 7: {
      setState(187);
      match(typlypParser::ID);
      setState(188);
      match(typlypParser::LPAREN);
      setState(190);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1168232034304) != 0)) {
        setState(189);
        argList();
      }
      setState(192);
      match(typlypParser::RPAREN);
      break;
    }

    case 8: {
      setState(193);
      match(typlypParser::T__11);
      setState(194);
      scalarType();
      setState(195);
      match(typlypParser::LT);
      setState(196);
      expr(0);
      setState(197);
      match(typlypParser::GT);
      break;
    }

    case 9: {
      setState(199);
      match(typlypParser::T__12);
      setState(200);
      match(typlypParser::ID);
      setState(201);
      match(typlypParser::LPAREN);
      setState(203);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1168232034304) != 0)) {
        setState(202);
        argList();
      }
      setState(205);
      match(typlypParser::RPAREN);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(222);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(220);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(208);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(209);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 234881024) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(210);
          expr(14);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(211);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(212);
          _la = _input->LA(1);
          if (!(_la == typlypParser::PLUS

          || _la == typlypParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(213);
          expr(13);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(214);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(215);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 4026531840) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(216);
          expr(12);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(217);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(218);
          _la = _input->LA(1);
          if (!(_la == typlypParser::EQ

          || _la == typlypParser::NEQ)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(219);
          expr(11);
          break;
        }

        default:
          break;
        } 
      }
      setState(224);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
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
  enterRule(_localctx, 32, typlypParser::RuleArgList);
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
    setState(225);
    expr(0);
    setState(230);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == typlypParser::COMMA) {
      setState(226);
      match(typlypParser::COMMA);
      setState(227);
      expr(0);
      setState(232);
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
  enterRule(_localctx, 34, typlypParser::RuleExprList);
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
    setState(233);
    expr(0);
    setState(238);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == typlypParser::COMMA) {
      setState(234);
      match(typlypParser::COMMA);
      setState(235);
      expr(0);
      setState(240);
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
  enterRule(_localctx, 36, typlypParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(244);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(241);
      scalarType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(242);
      arrayType();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(243);
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
  enterRule(_localctx, 38, typlypParser::RuleVoidType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    match(typlypParser::T__13);
   
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
  enterRule(_localctx, 40, typlypParser::RuleScalarType);
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
    setState(248);
    _la = _input->LA(1);
    if (!(_la == typlypParser::T__14

    || _la == typlypParser::T__15)) {
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
  enterRule(_localctx, 42, typlypParser::RuleArrayType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(255);
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

      case typlypParser::T__14:
      case typlypParser::T__15: {
        enterOuterAlt(_localctx, 2);
        setState(251);
        scalarType();
        setState(252);
        match(typlypParser::LT);
        setState(253);
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
    case 15: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

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
