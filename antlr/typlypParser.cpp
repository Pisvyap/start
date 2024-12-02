
// Generated from typlyp.g4 by ANTLR 4.13.2


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
      "expr", "argList", "exprList", "type"
    },
    std::vector<std::string>{
      "", "'delo'", "':'", "'vneshnaya'", "'pust'", "'vernut'", "'esli'", 
      "'inache'", "'poka'", "'schitaem'", "'new'", "'extern'", "'chislo'", 
      "'logika'", "", "", "", "", "", "", "'+'", "'-'", "'*'", "'/'", "'%'", 
      "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", "'&&'", "'||'", "'!'", 
      "'='", "'['", "']'", "'('", "')'", "'{'", "'}'", "';'", "','"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "ID", "INT", 
      "BOOL", "WS", "COMMENT", "LINE_COMMENT", "PLUS", "MINUS", "MULT", 
      "DIV", "MOD", "LT", "LE", "GT", "GE", "EQ", "NEQ", "AND", "OR", "NOT", 
      "ASSIGN", "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "LBRACE", "RBRACE", 
      "SEMICOLON", "COMMA"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,42,248,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,1,0,1,0,1,0,5,0,
  	44,8,0,10,0,12,0,47,9,0,1,0,1,0,1,1,1,1,1,1,1,1,3,1,55,8,1,1,1,1,1,1,
  	1,1,1,1,1,1,2,1,2,1,2,1,2,3,2,66,8,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,
  	5,3,76,8,3,10,3,12,3,79,9,3,1,4,1,4,1,4,1,4,1,5,1,5,5,5,87,8,5,10,5,12,
  	5,90,9,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,104,8,6,
  	1,7,1,7,1,7,1,7,1,7,1,7,3,7,112,8,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,9,1,
  	9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,3,11,140,8,11,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,
  	3,13,151,8,13,1,13,3,13,154,8,13,1,13,1,13,3,13,158,8,13,1,13,1,13,1,
  	13,1,14,1,14,3,14,165,8,14,1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,16,1,
  	16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,187,8,
  	16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,200,8,
  	16,1,16,3,16,203,8,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,
  	16,1,16,1,16,5,16,217,8,16,10,16,12,16,220,9,16,1,17,1,17,1,17,5,17,225,
  	8,17,10,17,12,17,228,9,17,1,18,1,18,1,18,5,18,233,8,18,10,18,12,18,236,
  	9,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,246,8,19,1,19,0,1,32,
  	20,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,0,4,1,0,22,
  	24,1,0,20,21,1,0,25,28,1,0,29,30,266,0,45,1,0,0,0,2,50,1,0,0,0,4,61,1,
  	0,0,0,6,72,1,0,0,0,8,80,1,0,0,0,10,84,1,0,0,0,12,103,1,0,0,0,14,105,1,
  	0,0,0,16,115,1,0,0,0,18,120,1,0,0,0,20,128,1,0,0,0,22,132,1,0,0,0,24,
  	141,1,0,0,0,26,147,1,0,0,0,28,164,1,0,0,0,30,166,1,0,0,0,32,202,1,0,0,
  	0,34,221,1,0,0,0,36,229,1,0,0,0,38,245,1,0,0,0,40,44,3,2,1,0,41,44,3,
  	4,2,0,42,44,3,12,6,0,43,40,1,0,0,0,43,41,1,0,0,0,43,42,1,0,0,0,44,47,
  	1,0,0,0,45,43,1,0,0,0,45,46,1,0,0,0,46,48,1,0,0,0,47,45,1,0,0,0,48,49,
  	5,0,0,1,49,1,1,0,0,0,50,51,5,1,0,0,51,52,5,14,0,0,52,54,5,37,0,0,53,55,
  	3,6,3,0,54,53,1,0,0,0,54,55,1,0,0,0,55,56,1,0,0,0,56,57,5,38,0,0,57,58,
  	5,2,0,0,58,59,3,38,19,0,59,60,3,10,5,0,60,3,1,0,0,0,61,62,5,3,0,0,62,
  	63,5,14,0,0,63,65,5,37,0,0,64,66,3,6,3,0,65,64,1,0,0,0,65,66,1,0,0,0,
  	66,67,1,0,0,0,67,68,5,38,0,0,68,69,5,2,0,0,69,70,3,38,19,0,70,71,5,41,
  	0,0,71,5,1,0,0,0,72,77,3,8,4,0,73,74,5,42,0,0,74,76,3,8,4,0,75,73,1,0,
  	0,0,76,79,1,0,0,0,77,75,1,0,0,0,77,78,1,0,0,0,78,7,1,0,0,0,79,77,1,0,
  	0,0,80,81,5,14,0,0,81,82,5,2,0,0,82,83,3,38,19,0,83,9,1,0,0,0,84,88,5,
  	39,0,0,85,87,3,12,6,0,86,85,1,0,0,0,87,90,1,0,0,0,88,86,1,0,0,0,88,89,
  	1,0,0,0,89,91,1,0,0,0,90,88,1,0,0,0,91,92,5,40,0,0,92,11,1,0,0,0,93,104,
  	3,14,7,0,94,104,3,16,8,0,95,104,3,18,9,0,96,104,3,20,10,0,97,104,3,22,
  	11,0,98,104,3,24,12,0,99,104,3,26,13,0,100,101,3,32,16,0,101,102,5,41,
  	0,0,102,104,1,0,0,0,103,93,1,0,0,0,103,94,1,0,0,0,103,95,1,0,0,0,103,
  	96,1,0,0,0,103,97,1,0,0,0,103,98,1,0,0,0,103,99,1,0,0,0,103,100,1,0,0,
  	0,104,13,1,0,0,0,105,106,5,4,0,0,106,107,5,14,0,0,107,108,5,2,0,0,108,
  	111,3,38,19,0,109,110,5,34,0,0,110,112,3,32,16,0,111,109,1,0,0,0,111,
  	112,1,0,0,0,112,113,1,0,0,0,113,114,5,41,0,0,114,15,1,0,0,0,115,116,5,
  	14,0,0,116,117,5,34,0,0,117,118,3,32,16,0,118,119,5,41,0,0,119,17,1,0,
  	0,0,120,121,5,14,0,0,121,122,5,35,0,0,122,123,3,32,16,0,123,124,5,36,
  	0,0,124,125,5,34,0,0,125,126,3,32,16,0,126,127,5,41,0,0,127,19,1,0,0,
  	0,128,129,5,5,0,0,129,130,3,32,16,0,130,131,5,41,0,0,131,21,1,0,0,0,132,
  	133,5,6,0,0,133,134,5,37,0,0,134,135,3,32,16,0,135,136,5,38,0,0,136,139,
  	3,10,5,0,137,138,5,7,0,0,138,140,3,10,5,0,139,137,1,0,0,0,139,140,1,0,
  	0,0,140,23,1,0,0,0,141,142,5,8,0,0,142,143,5,37,0,0,143,144,3,32,16,0,
  	144,145,5,38,0,0,145,146,3,10,5,0,146,25,1,0,0,0,147,148,5,9,0,0,148,
  	150,5,37,0,0,149,151,3,28,14,0,150,149,1,0,0,0,150,151,1,0,0,0,151,153,
  	1,0,0,0,152,154,3,32,16,0,153,152,1,0,0,0,153,154,1,0,0,0,154,155,1,0,
  	0,0,155,157,5,41,0,0,156,158,3,30,15,0,157,156,1,0,0,0,157,158,1,0,0,
  	0,158,159,1,0,0,0,159,160,5,38,0,0,160,161,3,10,5,0,161,27,1,0,0,0,162,
  	165,3,14,7,0,163,165,3,16,8,0,164,162,1,0,0,0,164,163,1,0,0,0,165,29,
  	1,0,0,0,166,167,3,16,8,0,167,31,1,0,0,0,168,169,6,16,-1,0,169,170,5,33,
  	0,0,170,203,3,32,16,9,171,203,5,14,0,0,172,173,5,14,0,0,173,174,5,35,
  	0,0,174,175,3,32,16,0,175,176,5,36,0,0,176,203,1,0,0,0,177,203,5,15,0,
  	0,178,203,5,16,0,0,179,180,5,37,0,0,180,181,3,32,16,0,181,182,5,38,0,
  	0,182,203,1,0,0,0,183,184,5,14,0,0,184,186,5,37,0,0,185,187,3,34,17,0,
  	186,185,1,0,0,0,186,187,1,0,0,0,187,188,1,0,0,0,188,203,5,38,0,0,189,
  	190,5,10,0,0,190,191,3,38,19,0,191,192,5,35,0,0,192,193,3,32,16,0,193,
  	194,5,36,0,0,194,203,1,0,0,0,195,196,5,11,0,0,196,197,5,14,0,0,197,199,
  	5,37,0,0,198,200,3,34,17,0,199,198,1,0,0,0,199,200,1,0,0,0,200,201,1,
  	0,0,0,201,203,5,38,0,0,202,168,1,0,0,0,202,171,1,0,0,0,202,172,1,0,0,
  	0,202,177,1,0,0,0,202,178,1,0,0,0,202,179,1,0,0,0,202,183,1,0,0,0,202,
  	189,1,0,0,0,202,195,1,0,0,0,203,218,1,0,0,0,204,205,10,13,0,0,205,206,
  	7,0,0,0,206,217,3,32,16,14,207,208,10,12,0,0,208,209,7,1,0,0,209,217,
  	3,32,16,13,210,211,10,11,0,0,211,212,7,2,0,0,212,217,3,32,16,12,213,214,
  	10,10,0,0,214,215,7,3,0,0,215,217,3,32,16,11,216,204,1,0,0,0,216,207,
  	1,0,0,0,216,210,1,0,0,0,216,213,1,0,0,0,217,220,1,0,0,0,218,216,1,0,0,
  	0,218,219,1,0,0,0,219,33,1,0,0,0,220,218,1,0,0,0,221,226,3,32,16,0,222,
  	223,5,42,0,0,223,225,3,32,16,0,224,222,1,0,0,0,225,228,1,0,0,0,226,224,
  	1,0,0,0,226,227,1,0,0,0,227,35,1,0,0,0,228,226,1,0,0,0,229,234,3,32,16,
  	0,230,231,5,42,0,0,231,233,3,32,16,0,232,230,1,0,0,0,233,236,1,0,0,0,
  	234,232,1,0,0,0,234,235,1,0,0,0,235,37,1,0,0,0,236,234,1,0,0,0,237,246,
  	5,12,0,0,238,246,5,13,0,0,239,240,5,12,0,0,240,241,5,35,0,0,241,246,5,
  	36,0,0,242,243,5,13,0,0,243,244,5,35,0,0,244,246,5,36,0,0,245,237,1,0,
  	0,0,245,238,1,0,0,0,245,239,1,0,0,0,245,242,1,0,0,0,246,39,1,0,0,0,21,
  	43,45,54,65,77,88,103,111,139,150,153,157,164,186,199,202,216,218,226,
  	234,245
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
    setState(45);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 146029006714) != 0)) {
      setState(43);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case typlypParser::T__0: {
          setState(40);
          functionDecl();
          break;
        }

        case typlypParser::T__2: {
          setState(41);
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
        case typlypParser::ID:
        case typlypParser::INT:
        case typlypParser::BOOL:
        case typlypParser::NOT:
        case typlypParser::LPAREN: {
          setState(42);
          statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(47);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(48);
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
    setState(50);
    match(typlypParser::T__0);
    setState(51);
    match(typlypParser::ID);
    setState(52);
    match(typlypParser::LPAREN);
    setState(54);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::ID) {
      setState(53);
      paramList();
    }
    setState(56);
    match(typlypParser::RPAREN);
    setState(57);
    match(typlypParser::T__1);
    setState(58);
    type();
    setState(59);
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
    setState(61);
    match(typlypParser::T__2);
    setState(62);
    match(typlypParser::ID);
    setState(63);
    match(typlypParser::LPAREN);
    setState(65);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::ID) {
      setState(64);
      paramList();
    }
    setState(67);
    match(typlypParser::RPAREN);
    setState(68);
    match(typlypParser::T__1);
    setState(69);
    type();
    setState(70);
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
    setState(72);
    param();
    setState(77);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == typlypParser::COMMA) {
      setState(73);
      match(typlypParser::COMMA);
      setState(74);
      param();
      setState(79);
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
    setState(80);
    match(typlypParser::ID);
    setState(81);
    match(typlypParser::T__1);
    setState(82);
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
    setState(84);
    match(typlypParser::LBRACE);
    setState(88);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 146029006704) != 0)) {
      setState(85);
      statement();
      setState(90);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(91);
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
    setState(103);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(93);
      varDecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(94);
      assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(95);
      arrayAssignment();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(96);
      returnStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(97);
      ifStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(98);
      whileStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(99);
      forStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(100);
      expr(0);
      setState(101);
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
    setState(105);
    match(typlypParser::T__3);
    setState(106);
    match(typlypParser::ID);
    setState(107);
    match(typlypParser::T__1);
    setState(108);
    type();
    setState(111);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::ASSIGN) {
      setState(109);
      match(typlypParser::ASSIGN);
      setState(110);
      expr(0);
    }
    setState(113);
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
    setState(115);
    match(typlypParser::ID);
    setState(116);
    match(typlypParser::ASSIGN);
    setState(117);
    expr(0);
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
    setState(120);
    match(typlypParser::ID);
    setState(121);
    match(typlypParser::LBRACKET);
    setState(122);
    expr(0);
    setState(123);
    match(typlypParser::RBRACKET);
    setState(124);
    match(typlypParser::ASSIGN);
    setState(125);
    expr(0);
    setState(126);
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
    setState(128);
    match(typlypParser::T__4);
    setState(129);
    expr(0);
    setState(130);
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
    setState(132);
    match(typlypParser::T__5);
    setState(133);
    match(typlypParser::LPAREN);
    setState(134);
    expr(0);
    setState(135);
    match(typlypParser::RPAREN);
    setState(136);
    block();
    setState(139);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::T__6) {
      setState(137);
      match(typlypParser::T__6);
      setState(138);
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
    setState(141);
    match(typlypParser::T__7);
    setState(142);
    match(typlypParser::LPAREN);
    setState(143);
    expr(0);
    setState(144);
    match(typlypParser::RPAREN);
    setState(145);
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
    setState(147);
    match(typlypParser::T__8);
    setState(148);
    match(typlypParser::LPAREN);
    setState(150);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(149);
      forInit();
      break;
    }

    default:
      break;
    }
    setState(153);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 146029005824) != 0)) {
      setState(152);
      expr(0);
    }
    setState(155);
    match(typlypParser::SEMICOLON);
    setState(157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == typlypParser::ID) {
      setState(156);
      forUpdate();
    }
    setState(159);
    match(typlypParser::RPAREN);
    setState(160);
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
    setState(164);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case typlypParser::T__3: {
        enterOuterAlt(_localctx, 1);
        setState(162);
        varDecl();
        break;
      }

      case typlypParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(163);
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
    setState(166);
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

typlypParser::TypeContext* typlypParser::ExprContext::type() {
  return getRuleContext<typlypParser::TypeContext>(0);
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

tree::TerminalNode* typlypParser::ExprContext::LT() {
  return getToken(typlypParser::LT, 0);
}

tree::TerminalNode* typlypParser::ExprContext::LE() {
  return getToken(typlypParser::LE, 0);
}

tree::TerminalNode* typlypParser::ExprContext::GT() {
  return getToken(typlypParser::GT, 0);
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
    setState(202);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(169);
      match(typlypParser::NOT);
      setState(170);
      expr(9);
      break;
    }

    case 2: {
      setState(171);
      match(typlypParser::ID);
      break;
    }

    case 3: {
      setState(172);
      match(typlypParser::ID);
      setState(173);
      match(typlypParser::LBRACKET);
      setState(174);
      expr(0);
      setState(175);
      match(typlypParser::RBRACKET);
      break;
    }

    case 4: {
      setState(177);
      match(typlypParser::INT);
      break;
    }

    case 5: {
      setState(178);
      match(typlypParser::BOOL);
      break;
    }

    case 6: {
      setState(179);
      match(typlypParser::LPAREN);
      setState(180);
      expr(0);
      setState(181);
      match(typlypParser::RPAREN);
      break;
    }

    case 7: {
      setState(183);
      match(typlypParser::ID);
      setState(184);
      match(typlypParser::LPAREN);
      setState(186);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 146029005824) != 0)) {
        setState(185);
        argList();
      }
      setState(188);
      match(typlypParser::RPAREN);
      break;
    }

    case 8: {
      setState(189);
      match(typlypParser::T__9);
      setState(190);
      type();
      setState(191);
      match(typlypParser::LBRACKET);
      setState(192);
      expr(0);
      setState(193);
      match(typlypParser::RBRACKET);
      break;
    }

    case 9: {
      setState(195);
      match(typlypParser::T__10);
      setState(196);
      match(typlypParser::ID);
      setState(197);
      match(typlypParser::LPAREN);
      setState(199);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 146029005824) != 0)) {
        setState(198);
        argList();
      }
      setState(201);
      match(typlypParser::RPAREN);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(218);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(216);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(204);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(205);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 29360128) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(206);
          expr(14);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(207);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(208);
          _la = _input->LA(1);
          if (!(_la == typlypParser::PLUS

          || _la == typlypParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(209);
          expr(13);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(210);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(211);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 503316480) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(212);
          expr(12);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(213);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(214);
          _la = _input->LA(1);
          if (!(_la == typlypParser::EQ

          || _la == typlypParser::NEQ)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(215);
          expr(11);
          break;
        }

        default:
          break;
        } 
      }
      setState(220);
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
    setState(221);
    expr(0);
    setState(226);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == typlypParser::COMMA) {
      setState(222);
      match(typlypParser::COMMA);
      setState(223);
      expr(0);
      setState(228);
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
    setState(229);
    expr(0);
    setState(234);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == typlypParser::COMMA) {
      setState(230);
      match(typlypParser::COMMA);
      setState(231);
      expr(0);
      setState(236);
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

tree::TerminalNode* typlypParser::TypeContext::LBRACKET() {
  return getToken(typlypParser::LBRACKET, 0);
}

tree::TerminalNode* typlypParser::TypeContext::RBRACKET() {
  return getToken(typlypParser::RBRACKET, 0);
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
    setState(245);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(237);
      match(typlypParser::T__11);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(238);
      match(typlypParser::T__12);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(239);
      match(typlypParser::T__11);
      setState(240);
      match(typlypParser::LBRACKET);
      setState(241);
      match(typlypParser::RBRACKET);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(242);
      match(typlypParser::T__12);
      setState(243);
      match(typlypParser::LBRACKET);
      setState(244);
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
