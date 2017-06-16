
// Generated from ratio.g4 by ANTLR 4.7

#include "ratioListener.h"
#include "ratioVisitor.h"

#include "ratioParser.h"

using namespace antlrcpp;
using namespace lucy;
using namespace antlr4;

ratioParser::ratioParser(TokenStream *input) : Parser(input)
{
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ratioParser::~ratioParser()
{
  delete _interpreter;
}

std::string ratioParser::getGrammarFileName() const
{
  return "ratio.g4";
}

const std::vector<std::string> &ratioParser::getRuleNames() const
{
  return _ruleNames;
}

dfa::Vocabulary &ratioParser::getVocabulary() const
{
  return _vocabulary;
}

//----------------- Compilation_unitContext ------------------------------------------------------------------

ratioParser::Compilation_unitContext::Compilation_unitContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *ratioParser::Compilation_unitContext::EOF()
{
  return getToken(ratioParser::EOF, 0);
}

std::vector<ratioParser::Type_declarationContext *> ratioParser::Compilation_unitContext::type_declaration()
{
  return getRuleContexts<ratioParser::Type_declarationContext>();
}

ratioParser::Type_declarationContext *ratioParser::Compilation_unitContext::type_declaration(size_t i)
{
  return getRuleContext<ratioParser::Type_declarationContext>(i);
}

std::vector<ratioParser::Method_declarationContext *> ratioParser::Compilation_unitContext::method_declaration()
{
  return getRuleContexts<ratioParser::Method_declarationContext>();
}

ratioParser::Method_declarationContext *ratioParser::Compilation_unitContext::method_declaration(size_t i)
{
  return getRuleContext<ratioParser::Method_declarationContext>(i);
}

std::vector<ratioParser::Predicate_declarationContext *> ratioParser::Compilation_unitContext::predicate_declaration()
{
  return getRuleContexts<ratioParser::Predicate_declarationContext>();
}

ratioParser::Predicate_declarationContext *ratioParser::Compilation_unitContext::predicate_declaration(size_t i)
{
  return getRuleContext<ratioParser::Predicate_declarationContext>(i);
}

std::vector<ratioParser::StatementContext *> ratioParser::Compilation_unitContext::statement()
{
  return getRuleContexts<ratioParser::StatementContext>();
}

ratioParser::StatementContext *ratioParser::Compilation_unitContext::statement(size_t i)
{
  return getRuleContext<ratioParser::StatementContext>(i);
}

size_t ratioParser::Compilation_unitContext::getRuleIndex() const
{
  return ratioParser::RuleCompilation_unit;
}

void ratioParser::Compilation_unitContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilation_unit(this);
}

void ratioParser::Compilation_unitContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilation_unit(this);
}

antlrcpp::Any ratioParser::Compilation_unitContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitCompilation_unit(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Compilation_unitContext *ratioParser::compilation_unit()
{
  Compilation_unitContext *_localctx = _tracker.createInstance<Compilation_unitContext>(_ctx, getState());
  enterRule(_localctx, 0, ratioParser::RuleCompilation_unit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(76);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << ratioParser::TYPE_DEF) | (1ULL << ratioParser::REAL) | (1ULL << ratioParser::BOOL) | (1ULL << ratioParser::STRING) | (1ULL << ratioParser::ENUM) | (1ULL << ratioParser::CLASS) | (1ULL << ratioParser::GOAL) | (1ULL << ratioParser::FACT) | (1ULL << ratioParser::PREDICATE) | (1ULL << ratioParser::NEW) | (1ULL << ratioParser::THIS) | (1ULL << ratioParser::VOID) | (1ULL << ratioParser::TRUE) | (1ULL << ratioParser::FALSE) | (1ULL << ratioParser::RETURN) | (1ULL << ratioParser::LPAREN) | (1ULL << ratioParser::LBRACKET) | (1ULL << ratioParser::LBRACE) | (1ULL << ratioParser::PLUS) | (1ULL << ratioParser::MINUS) | (1ULL << ratioParser::BANG) | (1ULL << ratioParser::ID) | (1ULL << ratioParser::NumericLiteral) | (1ULL << ratioParser::StringLiteral))) != 0))
    {
      setState(74);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx))
      {
      case 1:
      {
        setState(70);
        type_declaration();
        break;
      }

      case 2:
      {
        setState(71);
        method_declaration();
        break;
      }

      case 3:
      {
        setState(72);
        predicate_declaration();
        break;
      }

      case 4:
      {
        setState(73);
        statement();
        break;
      }
      }
      setState(78);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(79);
    match(ratioParser::EOF);
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_declarationContext ------------------------------------------------------------------

ratioParser::Type_declarationContext::Type_declarationContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

ratioParser::Typedef_declarationContext *ratioParser::Type_declarationContext::typedef_declaration()
{
  return getRuleContext<ratioParser::Typedef_declarationContext>(0);
}

ratioParser::Enum_declarationContext *ratioParser::Type_declarationContext::enum_declaration()
{
  return getRuleContext<ratioParser::Enum_declarationContext>(0);
}

ratioParser::Class_declarationContext *ratioParser::Type_declarationContext::class_declaration()
{
  return getRuleContext<ratioParser::Class_declarationContext>(0);
}

size_t ratioParser::Type_declarationContext::getRuleIndex() const
{
  return ratioParser::RuleType_declaration;
}

void ratioParser::Type_declarationContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_declaration(this);
}

void ratioParser::Type_declarationContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_declaration(this);
}

antlrcpp::Any ratioParser::Type_declarationContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitType_declaration(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Type_declarationContext *ratioParser::type_declaration()
{
  Type_declarationContext *_localctx = _tracker.createInstance<Type_declarationContext>(_ctx, getState());
  enterRule(_localctx, 2, ratioParser::RuleType_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    setState(84);
    _errHandler->sync(this);
    switch (_input->LA(1))
    {
    case ratioParser::TYPE_DEF:
    {
      enterOuterAlt(_localctx, 1);
      setState(81);
      typedef_declaration();
      break;
    }

    case ratioParser::ENUM:
    {
      enterOuterAlt(_localctx, 2);
      setState(82);
      enum_declaration();
      break;
    }

    case ratioParser::CLASS:
    {
      enterOuterAlt(_localctx, 3);
      setState(83);
      class_declaration();
      break;
    }

    default:
      throw NoViableAltException(this);
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Typedef_declarationContext ------------------------------------------------------------------

ratioParser::Typedef_declarationContext::Typedef_declarationContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

ratioParser::Primitive_typeContext *ratioParser::Typedef_declarationContext::primitive_type()
{
  return getRuleContext<ratioParser::Primitive_typeContext>(0);
}

ratioParser::ExprContext *ratioParser::Typedef_declarationContext::expr()
{
  return getRuleContext<ratioParser::ExprContext>(0);
}

tree::TerminalNode *ratioParser::Typedef_declarationContext::ID()
{
  return getToken(ratioParser::ID, 0);
}

size_t ratioParser::Typedef_declarationContext::getRuleIndex() const
{
  return ratioParser::RuleTypedef_declaration;
}

void ratioParser::Typedef_declarationContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypedef_declaration(this);
}

void ratioParser::Typedef_declarationContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypedef_declaration(this);
}

antlrcpp::Any ratioParser::Typedef_declarationContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitTypedef_declaration(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Typedef_declarationContext *ratioParser::typedef_declaration()
{
  Typedef_declarationContext *_localctx = _tracker.createInstance<Typedef_declarationContext>(_ctx, getState());
  enterRule(_localctx, 4, ratioParser::RuleTypedef_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(86);
    match(ratioParser::TYPE_DEF);
    setState(87);
    primitive_type();
    setState(88);
    expr(0);
    setState(89);
    dynamic_cast<Typedef_declarationContext *>(_localctx)->name = match(ratioParser::ID);
    setState(90);
    match(ratioParser::SEMICOLON);
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_declarationContext ------------------------------------------------------------------

ratioParser::Enum_declarationContext::Enum_declarationContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<ratioParser::Enum_constantsContext *> ratioParser::Enum_declarationContext::enum_constants()
{
  return getRuleContexts<ratioParser::Enum_constantsContext>();
}

ratioParser::Enum_constantsContext *ratioParser::Enum_declarationContext::enum_constants(size_t i)
{
  return getRuleContext<ratioParser::Enum_constantsContext>(i);
}

tree::TerminalNode *ratioParser::Enum_declarationContext::ID()
{
  return getToken(ratioParser::ID, 0);
}

size_t ratioParser::Enum_declarationContext::getRuleIndex() const
{
  return ratioParser::RuleEnum_declaration;
}

void ratioParser::Enum_declarationContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_declaration(this);
}

void ratioParser::Enum_declarationContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_declaration(this);
}

antlrcpp::Any ratioParser::Enum_declarationContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitEnum_declaration(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Enum_declarationContext *ratioParser::enum_declaration()
{
  Enum_declarationContext *_localctx = _tracker.createInstance<Enum_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, ratioParser::RuleEnum_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(92);
    match(ratioParser::ENUM);
    setState(93);
    dynamic_cast<Enum_declarationContext *>(_localctx)->name = match(ratioParser::ID);
    setState(94);
    enum_constants();
    setState(99);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ratioParser::BAR)
    {
      setState(95);
      match(ratioParser::BAR);
      setState(96);
      enum_constants();
      setState(101);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(102);
    match(ratioParser::SEMICOLON);
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_constantsContext ------------------------------------------------------------------

ratioParser::Enum_constantsContext::Enum_constantsContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<tree::TerminalNode *> ratioParser::Enum_constantsContext::StringLiteral()
{
  return getTokens(ratioParser::StringLiteral);
}

tree::TerminalNode *ratioParser::Enum_constantsContext::StringLiteral(size_t i)
{
  return getToken(ratioParser::StringLiteral, i);
}

ratioParser::TypeContext *ratioParser::Enum_constantsContext::type()
{
  return getRuleContext<ratioParser::TypeContext>(0);
}

size_t ratioParser::Enum_constantsContext::getRuleIndex() const
{
  return ratioParser::RuleEnum_constants;
}

void ratioParser::Enum_constantsContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_constants(this);
}

void ratioParser::Enum_constantsContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_constants(this);
}

antlrcpp::Any ratioParser::Enum_constantsContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitEnum_constants(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Enum_constantsContext *ratioParser::enum_constants()
{
  Enum_constantsContext *_localctx = _tracker.createInstance<Enum_constantsContext>(_ctx, getState());
  enterRule(_localctx, 8, ratioParser::RuleEnum_constants);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    setState(115);
    _errHandler->sync(this);
    switch (_input->LA(1))
    {
    case ratioParser::LBRACE:
    {
      enterOuterAlt(_localctx, 1);
      setState(104);
      match(ratioParser::LBRACE);
      setState(105);
      match(ratioParser::StringLiteral);
      setState(110);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ratioParser::COMMA)
      {
        setState(106);
        match(ratioParser::COMMA);
        setState(107);
        match(ratioParser::StringLiteral);
        setState(112);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(113);
      match(ratioParser::RBRACE);
      break;
    }

    case ratioParser::REAL:
    case ratioParser::BOOL:
    case ratioParser::STRING:
    case ratioParser::ID:
    {
      enterOuterAlt(_localctx, 2);
      setState(114);
      type();
      break;
    }

    default:
      throw NoViableAltException(this);
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_declarationContext ------------------------------------------------------------------

ratioParser::Class_declarationContext::Class_declarationContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *ratioParser::Class_declarationContext::ID()
{
  return getToken(ratioParser::ID, 0);
}

ratioParser::Type_listContext *ratioParser::Class_declarationContext::type_list()
{
  return getRuleContext<ratioParser::Type_listContext>(0);
}

std::vector<ratioParser::MemberContext *> ratioParser::Class_declarationContext::member()
{
  return getRuleContexts<ratioParser::MemberContext>();
}

ratioParser::MemberContext *ratioParser::Class_declarationContext::member(size_t i)
{
  return getRuleContext<ratioParser::MemberContext>(i);
}

size_t ratioParser::Class_declarationContext::getRuleIndex() const
{
  return ratioParser::RuleClass_declaration;
}

void ratioParser::Class_declarationContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClass_declaration(this);
}

void ratioParser::Class_declarationContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClass_declaration(this);
}

antlrcpp::Any ratioParser::Class_declarationContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitClass_declaration(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Class_declarationContext *ratioParser::class_declaration()
{
  Class_declarationContext *_localctx = _tracker.createInstance<Class_declarationContext>(_ctx, getState());
  enterRule(_localctx, 10, ratioParser::RuleClass_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(117);
    match(ratioParser::CLASS);
    setState(118);
    dynamic_cast<Class_declarationContext *>(_localctx)->name = match(ratioParser::ID);
    setState(121);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ratioParser::COLON)
    {
      setState(119);
      match(ratioParser::COLON);
      setState(120);
      type_list();
    }
    setState(123);
    match(ratioParser::LBRACE);
    setState(127);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << ratioParser::TYPE_DEF) | (1ULL << ratioParser::REAL) | (1ULL << ratioParser::BOOL) | (1ULL << ratioParser::STRING) | (1ULL << ratioParser::ENUM) | (1ULL << ratioParser::CLASS) | (1ULL << ratioParser::PREDICATE) | (1ULL << ratioParser::VOID) | (1ULL << ratioParser::ID))) != 0))
    {
      setState(124);
      member();
      setState(129);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(130);
    match(ratioParser::RBRACE);
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MemberContext ------------------------------------------------------------------

ratioParser::MemberContext::MemberContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

ratioParser::Field_declarationContext *ratioParser::MemberContext::field_declaration()
{
  return getRuleContext<ratioParser::Field_declarationContext>(0);
}

ratioParser::Method_declarationContext *ratioParser::MemberContext::method_declaration()
{
  return getRuleContext<ratioParser::Method_declarationContext>(0);
}

ratioParser::Constructor_declarationContext *ratioParser::MemberContext::constructor_declaration()
{
  return getRuleContext<ratioParser::Constructor_declarationContext>(0);
}

ratioParser::Predicate_declarationContext *ratioParser::MemberContext::predicate_declaration()
{
  return getRuleContext<ratioParser::Predicate_declarationContext>(0);
}

ratioParser::Type_declarationContext *ratioParser::MemberContext::type_declaration()
{
  return getRuleContext<ratioParser::Type_declarationContext>(0);
}

size_t ratioParser::MemberContext::getRuleIndex() const
{
  return ratioParser::RuleMember;
}

void ratioParser::MemberContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMember(this);
}

void ratioParser::MemberContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMember(this);
}

antlrcpp::Any ratioParser::MemberContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitMember(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::MemberContext *ratioParser::member()
{
  MemberContext *_localctx = _tracker.createInstance<MemberContext>(_ctx, getState());
  enterRule(_localctx, 12, ratioParser::RuleMember);

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    setState(137);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx))
    {
    case 1:
    {
      enterOuterAlt(_localctx, 1);
      setState(132);
      field_declaration();
      break;
    }

    case 2:
    {
      enterOuterAlt(_localctx, 2);
      setState(133);
      method_declaration();
      break;
    }

    case 3:
    {
      enterOuterAlt(_localctx, 3);
      setState(134);
      constructor_declaration();
      break;
    }

    case 4:
    {
      enterOuterAlt(_localctx, 4);
      setState(135);
      predicate_declaration();
      break;
    }

    case 5:
    {
      enterOuterAlt(_localctx, 5);
      setState(136);
      type_declaration();
      break;
    }
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Field_declarationContext ------------------------------------------------------------------

ratioParser::Field_declarationContext::Field_declarationContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

ratioParser::TypeContext *ratioParser::Field_declarationContext::type()
{
  return getRuleContext<ratioParser::TypeContext>(0);
}

std::vector<ratioParser::Variable_decContext *> ratioParser::Field_declarationContext::variable_dec()
{
  return getRuleContexts<ratioParser::Variable_decContext>();
}

ratioParser::Variable_decContext *ratioParser::Field_declarationContext::variable_dec(size_t i)
{
  return getRuleContext<ratioParser::Variable_decContext>(i);
}

size_t ratioParser::Field_declarationContext::getRuleIndex() const
{
  return ratioParser::RuleField_declaration;
}

void ratioParser::Field_declarationContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterField_declaration(this);
}

void ratioParser::Field_declarationContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitField_declaration(this);
}

antlrcpp::Any ratioParser::Field_declarationContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitField_declaration(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Field_declarationContext *ratioParser::field_declaration()
{
  Field_declarationContext *_localctx = _tracker.createInstance<Field_declarationContext>(_ctx, getState());
  enterRule(_localctx, 14, ratioParser::RuleField_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(139);
    type();
    setState(140);
    variable_dec();
    setState(145);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ratioParser::COMMA)
    {
      setState(141);
      match(ratioParser::COMMA);
      setState(142);
      variable_dec();
      setState(147);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(148);
    match(ratioParser::SEMICOLON);
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_decContext ------------------------------------------------------------------

ratioParser::Variable_decContext::Variable_decContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *ratioParser::Variable_decContext::ID()
{
  return getToken(ratioParser::ID, 0);
}

ratioParser::ExprContext *ratioParser::Variable_decContext::expr()
{
  return getRuleContext<ratioParser::ExprContext>(0);
}

size_t ratioParser::Variable_decContext::getRuleIndex() const
{
  return ratioParser::RuleVariable_dec;
}

void ratioParser::Variable_decContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_dec(this);
}

void ratioParser::Variable_decContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_dec(this);
}

antlrcpp::Any ratioParser::Variable_decContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitVariable_dec(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Variable_decContext *ratioParser::variable_dec()
{
  Variable_decContext *_localctx = _tracker.createInstance<Variable_decContext>(_ctx, getState());
  enterRule(_localctx, 16, ratioParser::RuleVariable_dec);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(150);
    dynamic_cast<Variable_decContext *>(_localctx)->name = match(ratioParser::ID);
    setState(153);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ratioParser::EQUAL)
    {
      setState(151);
      match(ratioParser::EQUAL);
      setState(152);
      expr(0);
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Method_declarationContext ------------------------------------------------------------------

ratioParser::Method_declarationContext::Method_declarationContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

size_t ratioParser::Method_declarationContext::getRuleIndex() const
{
  return ratioParser::RuleMethod_declaration;
}

void ratioParser::Method_declarationContext::copyFrom(Method_declarationContext *ctx)
{
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Void_method_declarationContext ------------------------------------------------------------------

ratioParser::BlockContext *ratioParser::Void_method_declarationContext::block()
{
  return getRuleContext<ratioParser::BlockContext>(0);
}

tree::TerminalNode *ratioParser::Void_method_declarationContext::ID()
{
  return getToken(ratioParser::ID, 0);
}

ratioParser::Typed_listContext *ratioParser::Void_method_declarationContext::typed_list()
{
  return getRuleContext<ratioParser::Typed_listContext>(0);
}

ratioParser::Void_method_declarationContext::Void_method_declarationContext(Method_declarationContext *ctx) { copyFrom(ctx); }

void ratioParser::Void_method_declarationContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVoid_method_declaration(this);
}
void ratioParser::Void_method_declarationContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVoid_method_declaration(this);
}

antlrcpp::Any ratioParser::Void_method_declarationContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitVoid_method_declaration(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Type_method_declarationContext ------------------------------------------------------------------

ratioParser::TypeContext *ratioParser::Type_method_declarationContext::type()
{
  return getRuleContext<ratioParser::TypeContext>(0);
}

ratioParser::BlockContext *ratioParser::Type_method_declarationContext::block()
{
  return getRuleContext<ratioParser::BlockContext>(0);
}

tree::TerminalNode *ratioParser::Type_method_declarationContext::ID()
{
  return getToken(ratioParser::ID, 0);
}

ratioParser::Typed_listContext *ratioParser::Type_method_declarationContext::typed_list()
{
  return getRuleContext<ratioParser::Typed_listContext>(0);
}

ratioParser::Type_method_declarationContext::Type_method_declarationContext(Method_declarationContext *ctx) { copyFrom(ctx); }

void ratioParser::Type_method_declarationContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_method_declaration(this);
}
void ratioParser::Type_method_declarationContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_method_declaration(this);
}

antlrcpp::Any ratioParser::Type_method_declarationContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitType_method_declaration(this);
  else
    return visitor->visitChildren(this);
}
ratioParser::Method_declarationContext *ratioParser::method_declaration()
{
  Method_declarationContext *_localctx = _tracker.createInstance<Method_declarationContext>(_ctx, getState());
  enterRule(_localctx, 18, ratioParser::RuleMethod_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    setState(177);
    _errHandler->sync(this);
    switch (_input->LA(1))
    {
    case ratioParser::VOID:
    {
      _localctx = dynamic_cast<Method_declarationContext *>(_tracker.createInstance<ratioParser::Void_method_declarationContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(155);
      match(ratioParser::VOID);
      setState(156);
      dynamic_cast<Void_method_declarationContext *>(_localctx)->name = match(ratioParser::ID);
      setState(157);
      match(ratioParser::LPAREN);
      setState(159);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~0x3fULL) == 0) &&
           ((1ULL << _la) & ((1ULL << ratioParser::REAL) | (1ULL << ratioParser::BOOL) | (1ULL << ratioParser::STRING) | (1ULL << ratioParser::ID))) != 0))
      {
        setState(158);
        typed_list();
      }
      setState(161);
      match(ratioParser::RPAREN);
      setState(162);
      match(ratioParser::LBRACE);
      setState(163);
      block();
      setState(164);
      match(ratioParser::RBRACE);
      break;
    }

    case ratioParser::REAL:
    case ratioParser::BOOL:
    case ratioParser::STRING:
    case ratioParser::ID:
    {
      _localctx = dynamic_cast<Method_declarationContext *>(_tracker.createInstance<ratioParser::Type_method_declarationContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(166);
      type();
      setState(167);
      dynamic_cast<Type_method_declarationContext *>(_localctx)->name = match(ratioParser::ID);
      setState(168);
      match(ratioParser::LPAREN);
      setState(170);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~0x3fULL) == 0) &&
           ((1ULL << _la) & ((1ULL << ratioParser::REAL) | (1ULL << ratioParser::BOOL) | (1ULL << ratioParser::STRING) | (1ULL << ratioParser::ID))) != 0))
      {
        setState(169);
        typed_list();
      }
      setState(172);
      match(ratioParser::RPAREN);
      setState(173);
      match(ratioParser::LBRACE);
      setState(174);
      block();
      setState(175);
      match(ratioParser::RBRACE);
      break;
    }

    default:
      throw NoViableAltException(this);
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constructor_declarationContext ------------------------------------------------------------------

ratioParser::Constructor_declarationContext::Constructor_declarationContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

ratioParser::BlockContext *ratioParser::Constructor_declarationContext::block()
{
  return getRuleContext<ratioParser::BlockContext>(0);
}

tree::TerminalNode *ratioParser::Constructor_declarationContext::ID()
{
  return getToken(ratioParser::ID, 0);
}

ratioParser::Typed_listContext *ratioParser::Constructor_declarationContext::typed_list()
{
  return getRuleContext<ratioParser::Typed_listContext>(0);
}

std::vector<ratioParser::Initializer_elementContext *> ratioParser::Constructor_declarationContext::initializer_element()
{
  return getRuleContexts<ratioParser::Initializer_elementContext>();
}

ratioParser::Initializer_elementContext *ratioParser::Constructor_declarationContext::initializer_element(size_t i)
{
  return getRuleContext<ratioParser::Initializer_elementContext>(i);
}

size_t ratioParser::Constructor_declarationContext::getRuleIndex() const
{
  return ratioParser::RuleConstructor_declaration;
}

void ratioParser::Constructor_declarationContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstructor_declaration(this);
}

void ratioParser::Constructor_declarationContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstructor_declaration(this);
}

antlrcpp::Any ratioParser::Constructor_declarationContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitConstructor_declaration(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Constructor_declarationContext *ratioParser::constructor_declaration()
{
  Constructor_declarationContext *_localctx = _tracker.createInstance<Constructor_declarationContext>(_ctx, getState());
  enterRule(_localctx, 20, ratioParser::RuleConstructor_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(179);
    dynamic_cast<Constructor_declarationContext *>(_localctx)->name = match(ratioParser::ID);
    setState(180);
    match(ratioParser::LPAREN);
    setState(182);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~0x3fULL) == 0) &&
         ((1ULL << _la) & ((1ULL << ratioParser::REAL) | (1ULL << ratioParser::BOOL) | (1ULL << ratioParser::STRING) | (1ULL << ratioParser::ID))) != 0))
    {
      setState(181);
      typed_list();
    }
    setState(184);
    match(ratioParser::RPAREN);
    setState(194);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ratioParser::COLON)
    {
      setState(185);
      match(ratioParser::COLON);
      setState(186);
      initializer_element();
      setState(191);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ratioParser::COMMA)
      {
        setState(187);
        match(ratioParser::COMMA);
        setState(188);
        initializer_element();
        setState(193);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(196);
    match(ratioParser::LBRACE);
    setState(197);
    block();
    setState(198);
    match(ratioParser::RBRACE);
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Initializer_elementContext ------------------------------------------------------------------

ratioParser::Initializer_elementContext::Initializer_elementContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *ratioParser::Initializer_elementContext::ID()
{
  return getToken(ratioParser::ID, 0);
}

ratioParser::Expr_listContext *ratioParser::Initializer_elementContext::expr_list()
{
  return getRuleContext<ratioParser::Expr_listContext>(0);
}

size_t ratioParser::Initializer_elementContext::getRuleIndex() const
{
  return ratioParser::RuleInitializer_element;
}

void ratioParser::Initializer_elementContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitializer_element(this);
}

void ratioParser::Initializer_elementContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitializer_element(this);
}

antlrcpp::Any ratioParser::Initializer_elementContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitInitializer_element(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Initializer_elementContext *ratioParser::initializer_element()
{
  Initializer_elementContext *_localctx = _tracker.createInstance<Initializer_elementContext>(_ctx, getState());
  enterRule(_localctx, 22, ratioParser::RuleInitializer_element);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(200);
    dynamic_cast<Initializer_elementContext *>(_localctx)->name = match(ratioParser::ID);
    setState(201);
    match(ratioParser::LPAREN);
    setState(203);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~0x3fULL) == 0) &&
         ((1ULL << _la) & ((1ULL << ratioParser::NEW) | (1ULL << ratioParser::THIS) | (1ULL << ratioParser::TRUE) | (1ULL << ratioParser::FALSE) | (1ULL << ratioParser::LPAREN) | (1ULL << ratioParser::LBRACKET) | (1ULL << ratioParser::PLUS) | (1ULL << ratioParser::MINUS) | (1ULL << ratioParser::BANG) | (1ULL << ratioParser::ID) | (1ULL << ratioParser::NumericLiteral) | (1ULL << ratioParser::StringLiteral))) != 0))
    {
      setState(202);
      expr_list();
    }
    setState(205);
    match(ratioParser::RPAREN);
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Predicate_declarationContext ------------------------------------------------------------------

ratioParser::Predicate_declarationContext::Predicate_declarationContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

ratioParser::BlockContext *ratioParser::Predicate_declarationContext::block()
{
  return getRuleContext<ratioParser::BlockContext>(0);
}

tree::TerminalNode *ratioParser::Predicate_declarationContext::ID()
{
  return getToken(ratioParser::ID, 0);
}

ratioParser::Typed_listContext *ratioParser::Predicate_declarationContext::typed_list()
{
  return getRuleContext<ratioParser::Typed_listContext>(0);
}

ratioParser::Predicate_listContext *ratioParser::Predicate_declarationContext::predicate_list()
{
  return getRuleContext<ratioParser::Predicate_listContext>(0);
}

size_t ratioParser::Predicate_declarationContext::getRuleIndex() const
{
  return ratioParser::RulePredicate_declaration;
}

void ratioParser::Predicate_declarationContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPredicate_declaration(this);
}

void ratioParser::Predicate_declarationContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPredicate_declaration(this);
}

antlrcpp::Any ratioParser::Predicate_declarationContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitPredicate_declaration(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Predicate_declarationContext *ratioParser::predicate_declaration()
{
  Predicate_declarationContext *_localctx = _tracker.createInstance<Predicate_declarationContext>(_ctx, getState());
  enterRule(_localctx, 24, ratioParser::RulePredicate_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(207);
    match(ratioParser::PREDICATE);
    setState(208);
    dynamic_cast<Predicate_declarationContext *>(_localctx)->name = match(ratioParser::ID);
    setState(209);
    match(ratioParser::LPAREN);
    setState(211);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~0x3fULL) == 0) &&
         ((1ULL << _la) & ((1ULL << ratioParser::REAL) | (1ULL << ratioParser::BOOL) | (1ULL << ratioParser::STRING) | (1ULL << ratioParser::ID))) != 0))
    {
      setState(210);
      typed_list();
    }
    setState(213);
    match(ratioParser::RPAREN);
    setState(216);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ratioParser::COLON)
    {
      setState(214);
      match(ratioParser::COLON);
      setState(215);
      predicate_list();
    }
    setState(218);
    match(ratioParser::LBRACE);
    setState(219);
    block();
    setState(220);
    match(ratioParser::RBRACE);
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

ratioParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

ratioParser::Assignment_statementContext *ratioParser::StatementContext::assignment_statement()
{
  return getRuleContext<ratioParser::Assignment_statementContext>(0);
}

ratioParser::Local_variable_statementContext *ratioParser::StatementContext::local_variable_statement()
{
  return getRuleContext<ratioParser::Local_variable_statementContext>(0);
}

ratioParser::Expression_statementContext *ratioParser::StatementContext::expression_statement()
{
  return getRuleContext<ratioParser::Expression_statementContext>(0);
}

ratioParser::Disjunction_statementContext *ratioParser::StatementContext::disjunction_statement()
{
  return getRuleContext<ratioParser::Disjunction_statementContext>(0);
}

ratioParser::Formula_statementContext *ratioParser::StatementContext::formula_statement()
{
  return getRuleContext<ratioParser::Formula_statementContext>(0);
}

ratioParser::Return_statementContext *ratioParser::StatementContext::return_statement()
{
  return getRuleContext<ratioParser::Return_statementContext>(0);
}

ratioParser::BlockContext *ratioParser::StatementContext::block()
{
  return getRuleContext<ratioParser::BlockContext>(0);
}

size_t ratioParser::StatementContext::getRuleIndex() const
{
  return ratioParser::RuleStatement;
}

void ratioParser::StatementContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void ratioParser::StatementContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

antlrcpp::Any ratioParser::StatementContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::StatementContext *ratioParser::statement()
{
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 26, ratioParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    setState(232);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx))
    {
    case 1:
    {
      enterOuterAlt(_localctx, 1);
      setState(222);
      assignment_statement();
      break;
    }

    case 2:
    {
      enterOuterAlt(_localctx, 2);
      setState(223);
      local_variable_statement();
      break;
    }

    case 3:
    {
      enterOuterAlt(_localctx, 3);
      setState(224);
      expression_statement();
      break;
    }

    case 4:
    {
      enterOuterAlt(_localctx, 4);
      setState(225);
      disjunction_statement();
      break;
    }

    case 5:
    {
      enterOuterAlt(_localctx, 5);
      setState(226);
      formula_statement();
      break;
    }

    case 6:
    {
      enterOuterAlt(_localctx, 6);
      setState(227);
      return_statement();
      break;
    }

    case 7:
    {
      enterOuterAlt(_localctx, 7);
      setState(228);
      match(ratioParser::LBRACE);
      setState(229);
      block();
      setState(230);
      match(ratioParser::RBRACE);
      break;
    }
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

ratioParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<ratioParser::StatementContext *> ratioParser::BlockContext::statement()
{
  return getRuleContexts<ratioParser::StatementContext>();
}

ratioParser::StatementContext *ratioParser::BlockContext::statement(size_t i)
{
  return getRuleContext<ratioParser::StatementContext>(i);
}

size_t ratioParser::BlockContext::getRuleIndex() const
{
  return ratioParser::RuleBlock;
}

void ratioParser::BlockContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void ratioParser::BlockContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

antlrcpp::Any ratioParser::BlockContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::BlockContext *ratioParser::block()
{
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 28, ratioParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(237);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << ratioParser::REAL) | (1ULL << ratioParser::BOOL) | (1ULL << ratioParser::STRING) | (1ULL << ratioParser::GOAL) | (1ULL << ratioParser::FACT) | (1ULL << ratioParser::NEW) | (1ULL << ratioParser::THIS) | (1ULL << ratioParser::TRUE) | (1ULL << ratioParser::FALSE) | (1ULL << ratioParser::RETURN) | (1ULL << ratioParser::LPAREN) | (1ULL << ratioParser::LBRACKET) | (1ULL << ratioParser::LBRACE) | (1ULL << ratioParser::PLUS) | (1ULL << ratioParser::MINUS) | (1ULL << ratioParser::BANG) | (1ULL << ratioParser::ID) | (1ULL << ratioParser::NumericLiteral) | (1ULL << ratioParser::StringLiteral))) != 0))
    {
      setState(234);
      statement();
      setState(239);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assignment_statementContext ------------------------------------------------------------------

ratioParser::Assignment_statementContext::Assignment_statementContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *ratioParser::Assignment_statementContext::ID()
{
  return getToken(ratioParser::ID, 0);
}

ratioParser::ExprContext *ratioParser::Assignment_statementContext::expr()
{
  return getRuleContext<ratioParser::ExprContext>(0);
}

ratioParser::Qualified_idContext *ratioParser::Assignment_statementContext::qualified_id()
{
  return getRuleContext<ratioParser::Qualified_idContext>(0);
}

size_t ratioParser::Assignment_statementContext::getRuleIndex() const
{
  return ratioParser::RuleAssignment_statement;
}

void ratioParser::Assignment_statementContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment_statement(this);
}

void ratioParser::Assignment_statementContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment_statement(this);
}

antlrcpp::Any ratioParser::Assignment_statementContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitAssignment_statement(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Assignment_statementContext *ratioParser::assignment_statement()
{
  Assignment_statementContext *_localctx = _tracker.createInstance<Assignment_statementContext>(_ctx, getState());
  enterRule(_localctx, 30, ratioParser::RuleAssignment_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(243);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx))
    {
    case 1:
    {
      setState(240);
      dynamic_cast<Assignment_statementContext *>(_localctx)->object = qualified_id();
      setState(241);
      match(ratioParser::DOT);
      break;
    }
    }
    setState(245);
    dynamic_cast<Assignment_statementContext *>(_localctx)->field = match(ratioParser::ID);
    setState(246);
    match(ratioParser::EQUAL);
    setState(247);
    dynamic_cast<Assignment_statementContext *>(_localctx)->value = expr(0);
    setState(248);
    match(ratioParser::SEMICOLON);
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Local_variable_statementContext ------------------------------------------------------------------

ratioParser::Local_variable_statementContext::Local_variable_statementContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

ratioParser::TypeContext *ratioParser::Local_variable_statementContext::type()
{
  return getRuleContext<ratioParser::TypeContext>(0);
}

std::vector<ratioParser::Variable_decContext *> ratioParser::Local_variable_statementContext::variable_dec()
{
  return getRuleContexts<ratioParser::Variable_decContext>();
}

ratioParser::Variable_decContext *ratioParser::Local_variable_statementContext::variable_dec(size_t i)
{
  return getRuleContext<ratioParser::Variable_decContext>(i);
}

size_t ratioParser::Local_variable_statementContext::getRuleIndex() const
{
  return ratioParser::RuleLocal_variable_statement;
}

void ratioParser::Local_variable_statementContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocal_variable_statement(this);
}

void ratioParser::Local_variable_statementContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocal_variable_statement(this);
}

antlrcpp::Any ratioParser::Local_variable_statementContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitLocal_variable_statement(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Local_variable_statementContext *ratioParser::local_variable_statement()
{
  Local_variable_statementContext *_localctx = _tracker.createInstance<Local_variable_statementContext>(_ctx, getState());
  enterRule(_localctx, 32, ratioParser::RuleLocal_variable_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(250);
    type();
    setState(251);
    variable_dec();
    setState(256);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ratioParser::COMMA)
    {
      setState(252);
      match(ratioParser::COMMA);
      setState(253);
      variable_dec();
      setState(258);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(259);
    match(ratioParser::SEMICOLON);
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_statementContext ------------------------------------------------------------------

ratioParser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

ratioParser::ExprContext *ratioParser::Expression_statementContext::expr()
{
  return getRuleContext<ratioParser::ExprContext>(0);
}

size_t ratioParser::Expression_statementContext::getRuleIndex() const
{
  return ratioParser::RuleExpression_statement;
}

void ratioParser::Expression_statementContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_statement(this);
}

void ratioParser::Expression_statementContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_statement(this);
}

antlrcpp::Any ratioParser::Expression_statementContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitExpression_statement(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Expression_statementContext *ratioParser::expression_statement()
{
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 34, ratioParser::RuleExpression_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(261);
    expr(0);
    setState(262);
    match(ratioParser::SEMICOLON);
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Disjunction_statementContext ------------------------------------------------------------------

ratioParser::Disjunction_statementContext::Disjunction_statementContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<ratioParser::ConjunctionContext *> ratioParser::Disjunction_statementContext::conjunction()
{
  return getRuleContexts<ratioParser::ConjunctionContext>();
}

ratioParser::ConjunctionContext *ratioParser::Disjunction_statementContext::conjunction(size_t i)
{
  return getRuleContext<ratioParser::ConjunctionContext>(i);
}

size_t ratioParser::Disjunction_statementContext::getRuleIndex() const
{
  return ratioParser::RuleDisjunction_statement;
}

void ratioParser::Disjunction_statementContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDisjunction_statement(this);
}

void ratioParser::Disjunction_statementContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDisjunction_statement(this);
}

antlrcpp::Any ratioParser::Disjunction_statementContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitDisjunction_statement(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Disjunction_statementContext *ratioParser::disjunction_statement()
{
  Disjunction_statementContext *_localctx = _tracker.createInstance<Disjunction_statementContext>(_ctx, getState());
  enterRule(_localctx, 36, ratioParser::RuleDisjunction_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(264);
    conjunction();
    setState(267);
    _errHandler->sync(this);
    _la = _input->LA(1);
    do
    {
      setState(265);
      match(ratioParser::OR);
      setState(266);
      conjunction();
      setState(269);
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == ratioParser::OR);
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConjunctionContext ------------------------------------------------------------------

ratioParser::ConjunctionContext::ConjunctionContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

ratioParser::BlockContext *ratioParser::ConjunctionContext::block()
{
  return getRuleContext<ratioParser::BlockContext>(0);
}

ratioParser::ExprContext *ratioParser::ConjunctionContext::expr()
{
  return getRuleContext<ratioParser::ExprContext>(0);
}

size_t ratioParser::ConjunctionContext::getRuleIndex() const
{
  return ratioParser::RuleConjunction;
}

void ratioParser::ConjunctionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConjunction(this);
}

void ratioParser::ConjunctionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConjunction(this);
}

antlrcpp::Any ratioParser::ConjunctionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitConjunction(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::ConjunctionContext *ratioParser::conjunction()
{
  ConjunctionContext *_localctx = _tracker.createInstance<ConjunctionContext>(_ctx, getState());
  enterRule(_localctx, 38, ratioParser::RuleConjunction);

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(271);
    match(ratioParser::LBRACE);
    setState(272);
    block();
    setState(273);
    match(ratioParser::RBRACE);
    setState(278);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx))
    {
    case 1:
    {
      setState(274);
      match(ratioParser::LBRACKET);
      setState(275);
      dynamic_cast<ConjunctionContext *>(_localctx)->cost = expr(0);
      setState(276);
      match(ratioParser::RBRACKET);
      break;
    }
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Formula_statementContext ------------------------------------------------------------------

ratioParser::Formula_statementContext::Formula_statementContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<tree::TerminalNode *> ratioParser::Formula_statementContext::ID()
{
  return getTokens(ratioParser::ID);
}

tree::TerminalNode *ratioParser::Formula_statementContext::ID(size_t i)
{
  return getToken(ratioParser::ID, i);
}

ratioParser::Assignment_listContext *ratioParser::Formula_statementContext::assignment_list()
{
  return getRuleContext<ratioParser::Assignment_listContext>(0);
}

ratioParser::Qualified_idContext *ratioParser::Formula_statementContext::qualified_id()
{
  return getRuleContext<ratioParser::Qualified_idContext>(0);
}

size_t ratioParser::Formula_statementContext::getRuleIndex() const
{
  return ratioParser::RuleFormula_statement;
}

void ratioParser::Formula_statementContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormula_statement(this);
}

void ratioParser::Formula_statementContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormula_statement(this);
}

antlrcpp::Any ratioParser::Formula_statementContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitFormula_statement(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Formula_statementContext *ratioParser::formula_statement()
{
  Formula_statementContext *_localctx = _tracker.createInstance<Formula_statementContext>(_ctx, getState());
  enterRule(_localctx, 40, ratioParser::RuleFormula_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(282);
    _errHandler->sync(this);
    switch (_input->LA(1))
    {
    case ratioParser::GOAL:
    {
      setState(280);
      dynamic_cast<Formula_statementContext *>(_localctx)->goal = match(ratioParser::GOAL);
      break;
    }

    case ratioParser::FACT:
    {
      setState(281);
      dynamic_cast<Formula_statementContext *>(_localctx)->fact = match(ratioParser::FACT);
      break;
    }

    default:
      throw NoViableAltException(this);
    }
    setState(284);
    dynamic_cast<Formula_statementContext *>(_localctx)->name = match(ratioParser::ID);
    setState(285);
    match(ratioParser::EQUAL);
    setState(286);
    match(ratioParser::NEW);
    setState(290);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx))
    {
    case 1:
    {
      setState(287);
      dynamic_cast<Formula_statementContext *>(_localctx)->object = qualified_id();
      setState(288);
      match(ratioParser::DOT);
      break;
    }
    }
    setState(292);
    dynamic_cast<Formula_statementContext *>(_localctx)->predicate = match(ratioParser::ID);
    setState(293);
    match(ratioParser::LPAREN);
    setState(295);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ratioParser::ID)
    {
      setState(294);
      assignment_list();
    }
    setState(297);
    match(ratioParser::RPAREN);
    setState(298);
    match(ratioParser::SEMICOLON);
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_statementContext ------------------------------------------------------------------

ratioParser::Return_statementContext::Return_statementContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

ratioParser::ExprContext *ratioParser::Return_statementContext::expr()
{
  return getRuleContext<ratioParser::ExprContext>(0);
}

size_t ratioParser::Return_statementContext::getRuleIndex() const
{
  return ratioParser::RuleReturn_statement;
}

void ratioParser::Return_statementContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_statement(this);
}

void ratioParser::Return_statementContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_statement(this);
}

antlrcpp::Any ratioParser::Return_statementContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitReturn_statement(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Return_statementContext *ratioParser::return_statement()
{
  Return_statementContext *_localctx = _tracker.createInstance<Return_statementContext>(_ctx, getState());
  enterRule(_localctx, 42, ratioParser::RuleReturn_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(300);
    match(ratioParser::RETURN);
    setState(301);
    expr(0);
    setState(302);
    match(ratioParser::SEMICOLON);
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assignment_listContext ------------------------------------------------------------------

ratioParser::Assignment_listContext::Assignment_listContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<ratioParser::AssignmentContext *> ratioParser::Assignment_listContext::assignment()
{
  return getRuleContexts<ratioParser::AssignmentContext>();
}

ratioParser::AssignmentContext *ratioParser::Assignment_listContext::assignment(size_t i)
{
  return getRuleContext<ratioParser::AssignmentContext>(i);
}

size_t ratioParser::Assignment_listContext::getRuleIndex() const
{
  return ratioParser::RuleAssignment_list;
}

void ratioParser::Assignment_listContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment_list(this);
}

void ratioParser::Assignment_listContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment_list(this);
}

antlrcpp::Any ratioParser::Assignment_listContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitAssignment_list(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Assignment_listContext *ratioParser::assignment_list()
{
  Assignment_listContext *_localctx = _tracker.createInstance<Assignment_listContext>(_ctx, getState());
  enterRule(_localctx, 44, ratioParser::RuleAssignment_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(304);
    assignment();
    setState(309);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ratioParser::COMMA)
    {
      setState(305);
      match(ratioParser::COMMA);
      setState(306);
      assignment();
      setState(311);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

ratioParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *ratioParser::AssignmentContext::ID()
{
  return getToken(ratioParser::ID, 0);
}

ratioParser::ExprContext *ratioParser::AssignmentContext::expr()
{
  return getRuleContext<ratioParser::ExprContext>(0);
}

size_t ratioParser::AssignmentContext::getRuleIndex() const
{
  return ratioParser::RuleAssignment;
}

void ratioParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void ratioParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}

antlrcpp::Any ratioParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::AssignmentContext *ratioParser::assignment()
{
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 46, ratioParser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(312);
    dynamic_cast<AssignmentContext *>(_localctx)->field = match(ratioParser::ID);
    setState(313);
    match(ratioParser::COLON);
    setState(314);
    dynamic_cast<AssignmentContext *>(_localctx)->value = expr(0);
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ratioParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

size_t ratioParser::ExprContext::getRuleIndex() const
{
  return ratioParser::RuleExpr;
}

void ratioParser::ExprContext::copyFrom(ExprContext *ctx)
{
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Cast_expressionContext ------------------------------------------------------------------

ratioParser::TypeContext *ratioParser::Cast_expressionContext::type()
{
  return getRuleContext<ratioParser::TypeContext>(0);
}

ratioParser::ExprContext *ratioParser::Cast_expressionContext::expr()
{
  return getRuleContext<ratioParser::ExprContext>(0);
}

ratioParser::Cast_expressionContext::Cast_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Cast_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCast_expression(this);
}
void ratioParser::Cast_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCast_expression(this);
}

antlrcpp::Any ratioParser::Cast_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitCast_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Qualified_id_expressionContext ------------------------------------------------------------------

ratioParser::Qualified_idContext *ratioParser::Qualified_id_expressionContext::qualified_id()
{
  return getRuleContext<ratioParser::Qualified_idContext>(0);
}

ratioParser::Qualified_id_expressionContext::Qualified_id_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Qualified_id_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualified_id_expression(this);
}
void ratioParser::Qualified_id_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualified_id_expression(this);
}

antlrcpp::Any ratioParser::Qualified_id_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitQualified_id_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Division_expressionContext ------------------------------------------------------------------

std::vector<ratioParser::ExprContext *> ratioParser::Division_expressionContext::expr()
{
  return getRuleContexts<ratioParser::ExprContext>();
}

ratioParser::ExprContext *ratioParser::Division_expressionContext::expr(size_t i)
{
  return getRuleContext<ratioParser::ExprContext>(i);
}

ratioParser::Division_expressionContext::Division_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Division_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDivision_expression(this);
}
void ratioParser::Division_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDivision_expression(this);
}

antlrcpp::Any ratioParser::Division_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitDivision_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Subtraction_expressionContext ------------------------------------------------------------------

std::vector<ratioParser::ExprContext *> ratioParser::Subtraction_expressionContext::expr()
{
  return getRuleContexts<ratioParser::ExprContext>();
}

ratioParser::ExprContext *ratioParser::Subtraction_expressionContext::expr(size_t i)
{
  return getRuleContext<ratioParser::ExprContext>(i);
}

ratioParser::Subtraction_expressionContext::Subtraction_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Subtraction_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubtraction_expression(this);
}
void ratioParser::Subtraction_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubtraction_expression(this);
}

antlrcpp::Any ratioParser::Subtraction_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitSubtraction_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Extc_one_expressionContext ------------------------------------------------------------------

std::vector<ratioParser::ExprContext *> ratioParser::Extc_one_expressionContext::expr()
{
  return getRuleContexts<ratioParser::ExprContext>();
}

ratioParser::ExprContext *ratioParser::Extc_one_expressionContext::expr(size_t i)
{
  return getRuleContext<ratioParser::ExprContext>(i);
}

ratioParser::Extc_one_expressionContext::Extc_one_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Extc_one_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtc_one_expression(this);
}
void ratioParser::Extc_one_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtc_one_expression(this);
}

antlrcpp::Any ratioParser::Extc_one_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitExtc_one_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Plus_expressionContext ------------------------------------------------------------------

ratioParser::ExprContext *ratioParser::Plus_expressionContext::expr()
{
  return getRuleContext<ratioParser::ExprContext>(0);
}

ratioParser::Plus_expressionContext::Plus_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Plus_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPlus_expression(this);
}
void ratioParser::Plus_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPlus_expression(this);
}

antlrcpp::Any ratioParser::Plus_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitPlus_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Function_expressionContext ------------------------------------------------------------------

tree::TerminalNode *ratioParser::Function_expressionContext::ID()
{
  return getToken(ratioParser::ID, 0);
}

ratioParser::Expr_listContext *ratioParser::Function_expressionContext::expr_list()
{
  return getRuleContext<ratioParser::Expr_listContext>(0);
}

ratioParser::Qualified_idContext *ratioParser::Function_expressionContext::qualified_id()
{
  return getRuleContext<ratioParser::Qualified_idContext>(0);
}

ratioParser::Function_expressionContext::Function_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Function_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_expression(this);
}
void ratioParser::Function_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_expression(this);
}

antlrcpp::Any ratioParser::Function_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitFunction_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Addition_expressionContext ------------------------------------------------------------------

std::vector<ratioParser::ExprContext *> ratioParser::Addition_expressionContext::expr()
{
  return getRuleContexts<ratioParser::ExprContext>();
}

ratioParser::ExprContext *ratioParser::Addition_expressionContext::expr(size_t i)
{
  return getRuleContext<ratioParser::ExprContext>(i);
}

ratioParser::Addition_expressionContext::Addition_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Addition_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddition_expression(this);
}
void ratioParser::Addition_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddition_expression(this);
}

antlrcpp::Any ratioParser::Addition_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitAddition_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Parentheses_expressionContext ------------------------------------------------------------------

ratioParser::ExprContext *ratioParser::Parentheses_expressionContext::expr()
{
  return getRuleContext<ratioParser::ExprContext>(0);
}

ratioParser::Parentheses_expressionContext::Parentheses_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Parentheses_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParentheses_expression(this);
}
void ratioParser::Parentheses_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParentheses_expression(this);
}

antlrcpp::Any ratioParser::Parentheses_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitParentheses_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Minus_expressionContext ------------------------------------------------------------------

ratioParser::ExprContext *ratioParser::Minus_expressionContext::expr()
{
  return getRuleContext<ratioParser::ExprContext>(0);
}

ratioParser::Minus_expressionContext::Minus_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Minus_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMinus_expression(this);
}
void ratioParser::Minus_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMinus_expression(this);
}

antlrcpp::Any ratioParser::Minus_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitMinus_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Implication_expressionContext ------------------------------------------------------------------

std::vector<ratioParser::ExprContext *> ratioParser::Implication_expressionContext::expr()
{
  return getRuleContexts<ratioParser::ExprContext>();
}

ratioParser::ExprContext *ratioParser::Implication_expressionContext::expr(size_t i)
{
  return getRuleContext<ratioParser::ExprContext>(i);
}

ratioParser::Implication_expressionContext::Implication_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Implication_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImplication_expression(this);
}
void ratioParser::Implication_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImplication_expression(this);
}

antlrcpp::Any ratioParser::Implication_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitImplication_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lt_expressionContext ------------------------------------------------------------------

std::vector<ratioParser::ExprContext *> ratioParser::Lt_expressionContext::expr()
{
  return getRuleContexts<ratioParser::ExprContext>();
}

ratioParser::ExprContext *ratioParser::Lt_expressionContext::expr(size_t i)
{
  return getRuleContext<ratioParser::ExprContext>(i);
}

ratioParser::Lt_expressionContext::Lt_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Lt_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLt_expression(this);
}
void ratioParser::Lt_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLt_expression(this);
}

antlrcpp::Any ratioParser::Lt_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitLt_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Not_expressionContext ------------------------------------------------------------------

ratioParser::ExprContext *ratioParser::Not_expressionContext::expr()
{
  return getRuleContext<ratioParser::ExprContext>(0);
}

ratioParser::Not_expressionContext::Not_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Not_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNot_expression(this);
}
void ratioParser::Not_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNot_expression(this);
}

antlrcpp::Any ratioParser::Not_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitNot_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Conjunction_expressionContext ------------------------------------------------------------------

std::vector<ratioParser::ExprContext *> ratioParser::Conjunction_expressionContext::expr()
{
  return getRuleContexts<ratioParser::ExprContext>();
}

ratioParser::ExprContext *ratioParser::Conjunction_expressionContext::expr(size_t i)
{
  return getRuleContext<ratioParser::ExprContext>(i);
}

ratioParser::Conjunction_expressionContext::Conjunction_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Conjunction_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConjunction_expression(this);
}
void ratioParser::Conjunction_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConjunction_expression(this);
}

antlrcpp::Any ratioParser::Conjunction_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitConjunction_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Geq_expressionContext ------------------------------------------------------------------

std::vector<ratioParser::ExprContext *> ratioParser::Geq_expressionContext::expr()
{
  return getRuleContexts<ratioParser::ExprContext>();
}

ratioParser::ExprContext *ratioParser::Geq_expressionContext::expr(size_t i)
{
  return getRuleContext<ratioParser::ExprContext>(i);
}

ratioParser::Geq_expressionContext::Geq_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Geq_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeq_expression(this);
}
void ratioParser::Geq_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeq_expression(this);
}

antlrcpp::Any ratioParser::Geq_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitGeq_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Range_expressionContext ------------------------------------------------------------------

std::vector<ratioParser::ExprContext *> ratioParser::Range_expressionContext::expr()
{
  return getRuleContexts<ratioParser::ExprContext>();
}

ratioParser::ExprContext *ratioParser::Range_expressionContext::expr(size_t i)
{
  return getRuleContext<ratioParser::ExprContext>(i);
}

ratioParser::Range_expressionContext::Range_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Range_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRange_expression(this);
}
void ratioParser::Range_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRange_expression(this);
}

antlrcpp::Any ratioParser::Range_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitRange_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Multiplication_expressionContext ------------------------------------------------------------------

std::vector<ratioParser::ExprContext *> ratioParser::Multiplication_expressionContext::expr()
{
  return getRuleContexts<ratioParser::ExprContext>();
}

ratioParser::ExprContext *ratioParser::Multiplication_expressionContext::expr(size_t i)
{
  return getRuleContext<ratioParser::ExprContext>(i);
}

ratioParser::Multiplication_expressionContext::Multiplication_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Multiplication_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplication_expression(this);
}
void ratioParser::Multiplication_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplication_expression(this);
}

antlrcpp::Any ratioParser::Multiplication_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitMultiplication_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Leq_expressionContext ------------------------------------------------------------------

std::vector<ratioParser::ExprContext *> ratioParser::Leq_expressionContext::expr()
{
  return getRuleContexts<ratioParser::ExprContext>();
}

ratioParser::ExprContext *ratioParser::Leq_expressionContext::expr(size_t i)
{
  return getRuleContext<ratioParser::ExprContext>(i);
}

ratioParser::Leq_expressionContext::Leq_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Leq_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeq_expression(this);
}
void ratioParser::Leq_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeq_expression(this);
}

antlrcpp::Any ratioParser::Leq_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitLeq_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Gt_expressionContext ------------------------------------------------------------------

std::vector<ratioParser::ExprContext *> ratioParser::Gt_expressionContext::expr()
{
  return getRuleContexts<ratioParser::ExprContext>();
}

ratioParser::ExprContext *ratioParser::Gt_expressionContext::expr(size_t i)
{
  return getRuleContext<ratioParser::ExprContext>(i);
}

ratioParser::Gt_expressionContext::Gt_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Gt_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGt_expression(this);
}
void ratioParser::Gt_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGt_expression(this);
}

antlrcpp::Any ratioParser::Gt_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitGt_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Constructor_expressionContext ------------------------------------------------------------------

ratioParser::TypeContext *ratioParser::Constructor_expressionContext::type()
{
  return getRuleContext<ratioParser::TypeContext>(0);
}

ratioParser::Expr_listContext *ratioParser::Constructor_expressionContext::expr_list()
{
  return getRuleContext<ratioParser::Expr_listContext>(0);
}

ratioParser::Constructor_expressionContext::Constructor_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Constructor_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstructor_expression(this);
}
void ratioParser::Constructor_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstructor_expression(this);
}

antlrcpp::Any ratioParser::Constructor_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitConstructor_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Disjunction_expressionContext ------------------------------------------------------------------

std::vector<ratioParser::ExprContext *> ratioParser::Disjunction_expressionContext::expr()
{
  return getRuleContexts<ratioParser::ExprContext>();
}

ratioParser::ExprContext *ratioParser::Disjunction_expressionContext::expr(size_t i)
{
  return getRuleContext<ratioParser::ExprContext>(i);
}

ratioParser::Disjunction_expressionContext::Disjunction_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Disjunction_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDisjunction_expression(this);
}
void ratioParser::Disjunction_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDisjunction_expression(this);
}

antlrcpp::Any ratioParser::Disjunction_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitDisjunction_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Literal_expressionContext ------------------------------------------------------------------

ratioParser::LiteralContext *ratioParser::Literal_expressionContext::literal()
{
  return getRuleContext<ratioParser::LiteralContext>(0);
}

ratioParser::Literal_expressionContext::Literal_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Literal_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral_expression(this);
}
void ratioParser::Literal_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral_expression(this);
}

antlrcpp::Any ratioParser::Literal_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitLiteral_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Eq_expressionContext ------------------------------------------------------------------

std::vector<ratioParser::ExprContext *> ratioParser::Eq_expressionContext::expr()
{
  return getRuleContexts<ratioParser::ExprContext>();
}

ratioParser::ExprContext *ratioParser::Eq_expressionContext::expr(size_t i)
{
  return getRuleContext<ratioParser::ExprContext>(i);
}

ratioParser::Eq_expressionContext::Eq_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Eq_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEq_expression(this);
}
void ratioParser::Eq_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEq_expression(this);
}

antlrcpp::Any ratioParser::Eq_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitEq_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Neq_expressionContext ------------------------------------------------------------------

std::vector<ratioParser::ExprContext *> ratioParser::Neq_expressionContext::expr()
{
  return getRuleContexts<ratioParser::ExprContext>();
}

ratioParser::ExprContext *ratioParser::Neq_expressionContext::expr(size_t i)
{
  return getRuleContext<ratioParser::ExprContext>(i);
}

ratioParser::Neq_expressionContext::Neq_expressionContext(ExprContext *ctx) { copyFrom(ctx); }

void ratioParser::Neq_expressionContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNeq_expression(this);
}
void ratioParser::Neq_expressionContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNeq_expression(this);
}

antlrcpp::Any ratioParser::Neq_expressionContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitNeq_expression(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::ExprContext *ratioParser::expr()
{
  return expr(0);
}

ratioParser::ExprContext *ratioParser::expr(int precedence)
{
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ratioParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ratioParser::ExprContext *previousContext = _localctx;
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, ratioParser::RuleExpr, precedence);

  size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try
  {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(359);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx))
    {
    case 1:
    {
      _localctx = _tracker.createInstance<Literal_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(317);
      literal();
      break;
    }

    case 2:
    {
      _localctx = _tracker.createInstance<Parentheses_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(318);
      match(ratioParser::LPAREN);
      setState(319);
      expr(0);
      setState(320);
      match(ratioParser::RPAREN);
      break;
    }

    case 3:
    {
      _localctx = _tracker.createInstance<Plus_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(322);
      match(ratioParser::PLUS);
      setState(323);
      expr(18);
      break;
    }

    case 4:
    {
      _localctx = _tracker.createInstance<Minus_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(324);
      match(ratioParser::MINUS);
      setState(325);
      expr(17);
      break;
    }

    case 5:
    {
      _localctx = _tracker.createInstance<Not_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(326);
      match(ratioParser::BANG);
      setState(327);
      expr(16);
      break;
    }

    case 6:
    {
      _localctx = _tracker.createInstance<Qualified_id_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(328);
      qualified_id();
      break;
    }

    case 7:
    {
      _localctx = _tracker.createInstance<Function_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(332);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx))
      {
      case 1:
      {
        setState(329);
        dynamic_cast<Function_expressionContext *>(_localctx)->object = qualified_id();
        setState(330);
        match(ratioParser::DOT);
        break;
      }
      }
      setState(334);
      dynamic_cast<Function_expressionContext *>(_localctx)->function_name = match(ratioParser::ID);
      setState(335);
      match(ratioParser::LPAREN);
      setState(337);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~0x3fULL) == 0) &&
           ((1ULL << _la) & ((1ULL << ratioParser::NEW) | (1ULL << ratioParser::THIS) | (1ULL << ratioParser::TRUE) | (1ULL << ratioParser::FALSE) | (1ULL << ratioParser::LPAREN) | (1ULL << ratioParser::LBRACKET) | (1ULL << ratioParser::PLUS) | (1ULL << ratioParser::MINUS) | (1ULL << ratioParser::BANG) | (1ULL << ratioParser::ID) | (1ULL << ratioParser::NumericLiteral) | (1ULL << ratioParser::StringLiteral))) != 0))
      {
        setState(336);
        expr_list();
      }
      setState(339);
      match(ratioParser::RPAREN);
      break;
    }

    case 8:
    {
      _localctx = _tracker.createInstance<Cast_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(340);
      match(ratioParser::LPAREN);
      setState(341);
      type();
      setState(342);
      match(ratioParser::RPAREN);
      setState(343);
      expr(13);
      break;
    }

    case 9:
    {
      _localctx = _tracker.createInstance<Range_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(345);
      match(ratioParser::LBRACKET);
      setState(346);
      dynamic_cast<Range_expressionContext *>(_localctx)->min = expr(0);
      setState(347);
      match(ratioParser::COMMA);
      setState(348);
      dynamic_cast<Range_expressionContext *>(_localctx)->max = expr(0);
      setState(349);
      match(ratioParser::RBRACKET);
      break;
    }

    case 10:
    {
      _localctx = _tracker.createInstance<Constructor_expressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(351);
      match(ratioParser::NEW);
      setState(352);
      type();
      setState(353);
      match(ratioParser::LPAREN);
      setState(355);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~0x3fULL) == 0) &&
           ((1ULL << _la) & ((1ULL << ratioParser::NEW) | (1ULL << ratioParser::THIS) | (1ULL << ratioParser::TRUE) | (1ULL << ratioParser::FALSE) | (1ULL << ratioParser::LPAREN) | (1ULL << ratioParser::LBRACKET) | (1ULL << ratioParser::PLUS) | (1ULL << ratioParser::MINUS) | (1ULL << ratioParser::BANG) | (1ULL << ratioParser::ID) | (1ULL << ratioParser::NumericLiteral) | (1ULL << ratioParser::StringLiteral))) != 0))
      {
        setState(354);
        expr_list();
      }
      setState(357);
      match(ratioParser::RPAREN);
      break;
    }
    }
    _ctx->stop = _input->LT(-1);
    setState(405);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER)
    {
      if (alt == 1)
      {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(403);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx))
        {
        case 1:
        {
          auto newContext = _tracker.createInstance<Multiplication_expressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(361);

          if (!(precpred(_ctx, 22)))
            throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(362);
          match(ratioParser::STAR);
          setState(363);
          expr(23);
          break;
        }

        case 2:
        {
          auto newContext = _tracker.createInstance<Division_expressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(364);

          if (!(precpred(_ctx, 21)))
            throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(365);
          match(ratioParser::SLASH);
          setState(366);
          expr(22);
          break;
        }

        case 3:
        {
          auto newContext = _tracker.createInstance<Addition_expressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(367);

          if (!(precpred(_ctx, 20)))
            throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(368);
          match(ratioParser::PLUS);
          setState(369);
          expr(21);
          break;
        }

        case 4:
        {
          auto newContext = _tracker.createInstance<Subtraction_expressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(370);

          if (!(precpred(_ctx, 19)))
            throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(371);
          match(ratioParser::MINUS);
          setState(372);
          expr(20);
          break;
        }

        case 5:
        {
          auto newContext = _tracker.createInstance<Eq_expressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(373);

          if (!(precpred(_ctx, 10)))
            throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(374);
          match(ratioParser::EQEQ);
          setState(375);
          expr(11);
          break;
        }

        case 6:
        {
          auto newContext = _tracker.createInstance<Geq_expressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(376);

          if (!(precpred(_ctx, 9)))
            throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(377);
          match(ratioParser::GTEQ);
          setState(378);
          expr(10);
          break;
        }

        case 7:
        {
          auto newContext = _tracker.createInstance<Leq_expressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(379);

          if (!(precpred(_ctx, 8)))
            throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(380);
          match(ratioParser::LTEQ);
          setState(381);
          expr(9);
          break;
        }

        case 8:
        {
          auto newContext = _tracker.createInstance<Gt_expressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(382);

          if (!(precpred(_ctx, 7)))
            throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(383);
          match(ratioParser::GT);
          setState(384);
          expr(8);
          break;
        }

        case 9:
        {
          auto newContext = _tracker.createInstance<Lt_expressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(385);

          if (!(precpred(_ctx, 6)))
            throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(386);
          match(ratioParser::LT);
          setState(387);
          expr(7);
          break;
        }

        case 10:
        {
          auto newContext = _tracker.createInstance<Neq_expressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(388);

          if (!(precpred(_ctx, 5)))
            throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(389);
          match(ratioParser::BANGEQ);
          setState(390);
          expr(6);
          break;
        }

        case 11:
        {
          auto newContext = _tracker.createInstance<Implication_expressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(391);

          if (!(precpred(_ctx, 4)))
            throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(392);
          match(ratioParser::IMPLICATION);
          setState(393);
          expr(5);
          break;
        }

        case 12:
        {
          auto newContext = _tracker.createInstance<Disjunction_expressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(394);

          if (!(precpred(_ctx, 3)))
            throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(395);
          match(ratioParser::BAR);
          setState(396);
          expr(4);
          break;
        }

        case 13:
        {
          auto newContext = _tracker.createInstance<Conjunction_expressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(397);

          if (!(precpred(_ctx, 2)))
            throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(398);
          match(ratioParser::AMP);
          setState(399);
          expr(3);
          break;
        }

        case 14:
        {
          auto newContext = _tracker.createInstance<Extc_one_expressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(400);

          if (!(precpred(_ctx, 1)))
            throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(401);
          match(ratioParser::CARET);
          setState(402);
          expr(2);
          break;
        }
        }
      }
      setState(407);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Expr_listContext ------------------------------------------------------------------

ratioParser::Expr_listContext::Expr_listContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<ratioParser::ExprContext *> ratioParser::Expr_listContext::expr()
{
  return getRuleContexts<ratioParser::ExprContext>();
}

ratioParser::ExprContext *ratioParser::Expr_listContext::expr(size_t i)
{
  return getRuleContext<ratioParser::ExprContext>(i);
}

size_t ratioParser::Expr_listContext::getRuleIndex() const
{
  return ratioParser::RuleExpr_list;
}

void ratioParser::Expr_listContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_list(this);
}

void ratioParser::Expr_listContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_list(this);
}

antlrcpp::Any ratioParser::Expr_listContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitExpr_list(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Expr_listContext *ratioParser::expr_list()
{
  Expr_listContext *_localctx = _tracker.createInstance<Expr_listContext>(_ctx, getState());
  enterRule(_localctx, 50, ratioParser::RuleExpr_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(408);
    expr(0);
    setState(413);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ratioParser::COMMA)
    {
      setState(409);
      match(ratioParser::COMMA);
      setState(410);
      expr(0);
      setState(415);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

ratioParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *ratioParser::LiteralContext::NumericLiteral()
{
  return getToken(ratioParser::NumericLiteral, 0);
}

tree::TerminalNode *ratioParser::LiteralContext::StringLiteral()
{
  return getToken(ratioParser::StringLiteral, 0);
}

size_t ratioParser::LiteralContext::getRuleIndex() const
{
  return ratioParser::RuleLiteral;
}

void ratioParser::LiteralContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void ratioParser::LiteralContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}

antlrcpp::Any ratioParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::LiteralContext *ratioParser::literal()
{
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 52, ratioParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    setState(420);
    _errHandler->sync(this);
    switch (_input->LA(1))
    {
    case ratioParser::NumericLiteral:
    {
      enterOuterAlt(_localctx, 1);
      setState(416);
      dynamic_cast<LiteralContext *>(_localctx)->numeric = match(ratioParser::NumericLiteral);
      break;
    }

    case ratioParser::StringLiteral:
    {
      enterOuterAlt(_localctx, 2);
      setState(417);
      dynamic_cast<LiteralContext *>(_localctx)->string = match(ratioParser::StringLiteral);
      break;
    }

    case ratioParser::TRUE:
    {
      enterOuterAlt(_localctx, 3);
      setState(418);
      dynamic_cast<LiteralContext *>(_localctx)->t = match(ratioParser::TRUE);
      break;
    }

    case ratioParser::FALSE:
    {
      enterOuterAlt(_localctx, 4);
      setState(419);
      dynamic_cast<LiteralContext *>(_localctx)->f = match(ratioParser::FALSE);
      break;
    }

    default:
      throw NoViableAltException(this);
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Qualified_idContext ------------------------------------------------------------------

ratioParser::Qualified_idContext::Qualified_idContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<tree::TerminalNode *> ratioParser::Qualified_idContext::ID()
{
  return getTokens(ratioParser::ID);
}

tree::TerminalNode *ratioParser::Qualified_idContext::ID(size_t i)
{
  return getToken(ratioParser::ID, i);
}

size_t ratioParser::Qualified_idContext::getRuleIndex() const
{
  return ratioParser::RuleQualified_id;
}

void ratioParser::Qualified_idContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualified_id(this);
}

void ratioParser::Qualified_idContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualified_id(this);
}

antlrcpp::Any ratioParser::Qualified_idContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitQualified_id(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Qualified_idContext *ratioParser::qualified_id()
{
  Qualified_idContext *_localctx = _tracker.createInstance<Qualified_idContext>(_ctx, getState());
  enterRule(_localctx, 54, ratioParser::RuleQualified_id);

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(424);
    _errHandler->sync(this);
    switch (_input->LA(1))
    {
    case ratioParser::THIS:
    {
      setState(422);
      dynamic_cast<Qualified_idContext *>(_localctx)->t = match(ratioParser::THIS);
      break;
    }

    case ratioParser::ID:
    {
      setState(423);
      match(ratioParser::ID);
      break;
    }

    default:
      throw NoViableAltException(this);
    }
    setState(430);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER)
    {
      if (alt == 1)
      {
        setState(426);
        match(ratioParser::DOT);
        setState(427);
        match(ratioParser::ID);
      }
      setState(432);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

ratioParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

ratioParser::Class_typeContext *ratioParser::TypeContext::class_type()
{
  return getRuleContext<ratioParser::Class_typeContext>(0);
}

ratioParser::Primitive_typeContext *ratioParser::TypeContext::primitive_type()
{
  return getRuleContext<ratioParser::Primitive_typeContext>(0);
}

size_t ratioParser::TypeContext::getRuleIndex() const
{
  return ratioParser::RuleType;
}

void ratioParser::TypeContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void ratioParser::TypeContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

antlrcpp::Any ratioParser::TypeContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::TypeContext *ratioParser::type()
{
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 56, ratioParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    setState(435);
    _errHandler->sync(this);
    switch (_input->LA(1))
    {
    case ratioParser::ID:
    {
      enterOuterAlt(_localctx, 1);
      setState(433);
      class_type();
      break;
    }

    case ratioParser::REAL:
    case ratioParser::BOOL:
    case ratioParser::STRING:
    {
      enterOuterAlt(_localctx, 2);
      setState(434);
      primitive_type();
      break;
    }

    default:
      throw NoViableAltException(this);
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_typeContext ------------------------------------------------------------------

ratioParser::Class_typeContext::Class_typeContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<tree::TerminalNode *> ratioParser::Class_typeContext::ID()
{
  return getTokens(ratioParser::ID);
}

tree::TerminalNode *ratioParser::Class_typeContext::ID(size_t i)
{
  return getToken(ratioParser::ID, i);
}

size_t ratioParser::Class_typeContext::getRuleIndex() const
{
  return ratioParser::RuleClass_type;
}

void ratioParser::Class_typeContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClass_type(this);
}

void ratioParser::Class_typeContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClass_type(this);
}

antlrcpp::Any ratioParser::Class_typeContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitClass_type(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Class_typeContext *ratioParser::class_type()
{
  Class_typeContext *_localctx = _tracker.createInstance<Class_typeContext>(_ctx, getState());
  enterRule(_localctx, 58, ratioParser::RuleClass_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(437);
    match(ratioParser::ID);
    setState(442);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER)
    {
      if (alt == 1)
      {
        setState(438);
        match(ratioParser::DOT);
        setState(439);
        match(ratioParser::ID);
      }
      setState(444);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Primitive_typeContext ------------------------------------------------------------------

ratioParser::Primitive_typeContext::Primitive_typeContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

size_t ratioParser::Primitive_typeContext::getRuleIndex() const
{
  return ratioParser::RulePrimitive_type;
}

void ratioParser::Primitive_typeContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimitive_type(this);
}

void ratioParser::Primitive_typeContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimitive_type(this);
}

antlrcpp::Any ratioParser::Primitive_typeContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitPrimitive_type(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Primitive_typeContext *ratioParser::primitive_type()
{
  Primitive_typeContext *_localctx = _tracker.createInstance<Primitive_typeContext>(_ctx, getState());
  enterRule(_localctx, 60, ratioParser::RulePrimitive_type);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(445);
    _la = _input->LA(1);
    if (!((((_la & ~0x3fULL) == 0) &&
           ((1ULL << _la) & ((1ULL << ratioParser::REAL) | (1ULL << ratioParser::BOOL) | (1ULL << ratioParser::STRING))) != 0)))
    {
      _errHandler->recoverInline(this);
    }
    else
    {
      _errHandler->reportMatch(this);
      consume();
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_listContext ------------------------------------------------------------------

ratioParser::Type_listContext::Type_listContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<ratioParser::TypeContext *> ratioParser::Type_listContext::type()
{
  return getRuleContexts<ratioParser::TypeContext>();
}

ratioParser::TypeContext *ratioParser::Type_listContext::type(size_t i)
{
  return getRuleContext<ratioParser::TypeContext>(i);
}

size_t ratioParser::Type_listContext::getRuleIndex() const
{
  return ratioParser::RuleType_list;
}

void ratioParser::Type_listContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_list(this);
}

void ratioParser::Type_listContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_list(this);
}

antlrcpp::Any ratioParser::Type_listContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitType_list(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Type_listContext *ratioParser::type_list()
{
  Type_listContext *_localctx = _tracker.createInstance<Type_listContext>(_ctx, getState());
  enterRule(_localctx, 62, ratioParser::RuleType_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(447);
    type();
    setState(452);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ratioParser::COMMA)
    {
      setState(448);
      match(ratioParser::COMMA);
      setState(449);
      type();
      setState(454);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Typed_listContext ------------------------------------------------------------------

ratioParser::Typed_listContext::Typed_listContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<ratioParser::TypeContext *> ratioParser::Typed_listContext::type()
{
  return getRuleContexts<ratioParser::TypeContext>();
}

ratioParser::TypeContext *ratioParser::Typed_listContext::type(size_t i)
{
  return getRuleContext<ratioParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> ratioParser::Typed_listContext::ID()
{
  return getTokens(ratioParser::ID);
}

tree::TerminalNode *ratioParser::Typed_listContext::ID(size_t i)
{
  return getToken(ratioParser::ID, i);
}

size_t ratioParser::Typed_listContext::getRuleIndex() const
{
  return ratioParser::RuleTyped_list;
}

void ratioParser::Typed_listContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTyped_list(this);
}

void ratioParser::Typed_listContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTyped_list(this);
}

antlrcpp::Any ratioParser::Typed_listContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitTyped_list(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Typed_listContext *ratioParser::typed_list()
{
  Typed_listContext *_localctx = _tracker.createInstance<Typed_listContext>(_ctx, getState());
  enterRule(_localctx, 64, ratioParser::RuleTyped_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(455);
    type();
    setState(456);
    match(ratioParser::ID);
    setState(463);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ratioParser::COMMA)
    {
      setState(457);
      match(ratioParser::COMMA);
      setState(458);
      type();
      setState(459);
      match(ratioParser::ID);
      setState(465);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Qualified_predicateContext ------------------------------------------------------------------

ratioParser::Qualified_predicateContext::Qualified_predicateContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode *ratioParser::Qualified_predicateContext::ID()
{
  return getToken(ratioParser::ID, 0);
}

ratioParser::Class_typeContext *ratioParser::Qualified_predicateContext::class_type()
{
  return getRuleContext<ratioParser::Class_typeContext>(0);
}

size_t ratioParser::Qualified_predicateContext::getRuleIndex() const
{
  return ratioParser::RuleQualified_predicate;
}

void ratioParser::Qualified_predicateContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualified_predicate(this);
}

void ratioParser::Qualified_predicateContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualified_predicate(this);
}

antlrcpp::Any ratioParser::Qualified_predicateContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitQualified_predicate(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Qualified_predicateContext *ratioParser::qualified_predicate()
{
  Qualified_predicateContext *_localctx = _tracker.createInstance<Qualified_predicateContext>(_ctx, getState());
  enterRule(_localctx, 66, ratioParser::RuleQualified_predicate);

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(469);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx))
    {
    case 1:
    {
      setState(466);
      class_type();
      setState(467);
      match(ratioParser::DOT);
      break;
    }
    }
    setState(471);
    match(ratioParser::ID);
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Predicate_listContext ------------------------------------------------------------------

ratioParser::Predicate_listContext::Predicate_listContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{
}

std::vector<ratioParser::Qualified_predicateContext *> ratioParser::Predicate_listContext::qualified_predicate()
{
  return getRuleContexts<ratioParser::Qualified_predicateContext>();
}

ratioParser::Qualified_predicateContext *ratioParser::Predicate_listContext::qualified_predicate(size_t i)
{
  return getRuleContext<ratioParser::Qualified_predicateContext>(i);
}

size_t ratioParser::Predicate_listContext::getRuleIndex() const
{
  return ratioParser::RulePredicate_list;
}

void ratioParser::Predicate_listContext::enterRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPredicate_list(this);
}

void ratioParser::Predicate_listContext::exitRule(tree::ParseTreeListener *listener)
{
  auto parserListener = dynamic_cast<ratioListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPredicate_list(this);
}

antlrcpp::Any ratioParser::Predicate_listContext::accept(tree::ParseTreeVisitor *visitor)
{
  if (auto parserVisitor = dynamic_cast<ratioVisitor *>(visitor))
    return parserVisitor->visitPredicate_list(this);
  else
    return visitor->visitChildren(this);
}

ratioParser::Predicate_listContext *ratioParser::predicate_list()
{
  Predicate_listContext *_localctx = _tracker.createInstance<Predicate_listContext>(_ctx, getState());
  enterRule(_localctx, 68, ratioParser::RulePredicate_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try
  {
    enterOuterAlt(_localctx, 1);
    setState(473);
    qualified_predicate();
    setState(478);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ratioParser::COMMA)
    {
      setState(474);
      match(ratioParser::COMMA);
      setState(475);
      qualified_predicate();
      setState(480);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
  }
  catch (RecognitionException &e)
  {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ratioParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex)
{
  switch (ruleIndex)
  {
  case 24:
    return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ratioParser::exprSempred(ExprContext *_localctx, size_t predicateIndex)
{
  switch (predicateIndex)
  {
  case 0:
    return precpred(_ctx, 22);
  case 1:
    return precpred(_ctx, 21);
  case 2:
    return precpred(_ctx, 20);
  case 3:
    return precpred(_ctx, 19);
  case 4:
    return precpred(_ctx, 10);
  case 5:
    return precpred(_ctx, 9);
  case 6:
    return precpred(_ctx, 8);
  case 7:
    return precpred(_ctx, 7);
  case 8:
    return precpred(_ctx, 6);
  case 9:
    return precpred(_ctx, 5);
  case 10:
    return precpred(_ctx, 4);
  case 11:
    return precpred(_ctx, 3);
  case 12:
    return precpred(_ctx, 2);
  case 13:
    return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ratioParser::_decisionToDFA;
atn::PredictionContextCache ratioParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ratioParser::_atn;
std::vector<uint16_t> ratioParser::_serializedATN;

std::vector<std::string> ratioParser::_ruleNames = {
    "compilation_unit", "type_declaration", "typedef_declaration", "enum_declaration",
    "enum_constants", "class_declaration", "member", "field_declaration",
    "variable_dec", "method_declaration", "constructor_declaration", "initializer_element",
    "predicate_declaration", "statement", "block", "assignment_statement",
    "local_variable_statement", "expression_statement", "disjunction_statement",
    "conjunction", "formula_statement", "return_statement", "assignment_list",
    "assignment", "expr", "expr_list", "literal", "qualified_id", "type",
    "class_type", "primitive_type", "type_list", "typed_list", "qualified_predicate",
    "predicate_list"};

std::vector<std::string> ratioParser::_literalNames = {
    "", "'typedef'", "'real'", "'bool'", "'string'", "'enum'", "'class'",
    "'goal'", "'fact'", "'predicate'", "'new'", "'or'", "'this'", "'void'",
    "'true'", "'false'", "'return'", "'.'", "','", "':'", "';'", "'('", "')'",
    "'['", "']'", "'{'", "'}'", "'+'", "'-'", "'*'", "'/'", "'&'", "'|'",
    "'='", "'>'", "'<'", "'!'", "'=='", "'<='", "'>='", "'!='", "'->'", "'^'"};

std::vector<std::string> ratioParser::_symbolicNames = {
    "", "TYPE_DEF", "REAL", "BOOL", "STRING", "ENUM", "CLASS", "GOAL", "FACT",
    "PREDICATE", "NEW", "OR", "THIS", "VOID", "TRUE", "FALSE", "RETURN", "DOT",
    "COMMA", "COLON", "SEMICOLON", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
    "LBRACE", "RBRACE", "PLUS", "MINUS", "STAR", "SLASH", "AMP", "BAR", "EQUAL",
    "GT", "LT", "BANG", "EQEQ", "LTEQ", "GTEQ", "BANGEQ", "IMPLICATION", "CARET",
    "ID", "NumericLiteral", "StringLiteral", "LINE_COMMENT", "COMMENT", "WS"};

dfa::Vocabulary ratioParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ratioParser::_tokenNames;

ratioParser::Initializer::Initializer()
{
  for (size_t i = 0; i < _symbolicNames.size(); ++i)
  {
    std::string name = _vocabulary.getLiteralName(i);
    if (name.empty())
    {
      name = _vocabulary.getSymbolicName(i);
    }

    if (name.empty())
    {
      _tokenNames.push_back("<INVALID>");
    }
    else
    {
      _tokenNames.push_back(name);
    }
  }

  _serializedATN = {
      0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964,
      0x3, 0x32, 0x1e4, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4,
      0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7,
      0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb,
      0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe,
      0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4,
      0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15,
      0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9,
      0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b,
      0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4,
      0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22,
      0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x3, 0x2, 0x3,
      0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x4d, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2,
      0x50, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5,
      0x3, 0x57, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4,
      0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5,
      0x64, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x67, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5,
      0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x6f, 0xa, 0x6, 0xc,
      0x6, 0xe, 0x6, 0x72, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x76, 0xa,
      0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x7c, 0xa, 0x7,
      0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x80, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x83,
      0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8,
      0x3, 0x8, 0x5, 0x8, 0x8c, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3,
      0x9, 0x7, 0x9, 0x92, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x95, 0xb, 0x9, 0x3,
      0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x9c, 0xa, 0xa,
      0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xa2, 0xa, 0xb, 0x3,
      0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3,
      0xb, 0x3, 0xb, 0x5, 0xb, 0xad, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb,
      0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xb4, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3,
      0xc, 0x5, 0xc, 0xb9, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc,
      0x3, 0xc, 0x7, 0xc, 0xc0, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xc3, 0xb, 0xc,
      0x5, 0xc, 0xc5, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3,
      0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xce, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd,
      0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xd6, 0xa, 0xe, 0x3,
      0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xdb, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe,
      0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf,
      0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xeb, 0xa,
      0xf, 0x3, 0x10, 0x7, 0x10, 0xee, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xf1,
      0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xf6, 0xa, 0x11,
      0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3,
      0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x101, 0xa, 0x12, 0xc, 0x12,
      0xe, 0x12, 0x104, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13,
      0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x6, 0x14, 0x10e, 0xa, 0x14,
      0xd, 0x14, 0xe, 0x14, 0x10f, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15,
      0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x119, 0xa, 0x15, 0x3, 0x16,
      0x3, 0x16, 0x5, 0x16, 0x11d, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16,
      0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x125, 0xa, 0x16, 0x3, 0x16,
      0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x12a, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16,
      0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3,
      0x18, 0x3, 0x18, 0x7, 0x18, 0x136, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18,
      0x139, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a,
      0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3,
      0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a,
      0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x14f, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a,
      0x3, 0x1a, 0x5, 0x1a, 0x154, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a,
      0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3,
      0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a,
      0x5, 0x1a, 0x166, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x16a,
      0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3,
      0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a,
      0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3,
      0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a,
      0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3,
      0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a,
      0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x196, 0xa, 0x1a,
      0xc, 0x1a, 0xe, 0x1a, 0x199, 0xb, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b,
      0x7, 0x1b, 0x19e, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x1a1, 0xb, 0x1b,
      0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x1a7, 0xa, 0x1c,
      0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x1ab, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d,
      0x7, 0x1d, 0x1af, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x1b2, 0xb, 0x1d,
      0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x1b6, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f,
      0x3, 0x1f, 0x7, 0x1f, 0x1bb, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x1be,
      0xb, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7,
      0x21, 0x1c5, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x1c8, 0xb, 0x21, 0x3,
      0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x7, 0x22,
      0x1d0, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x1d3, 0xb, 0x22, 0x3, 0x23,
      0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x1d8, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23,
      0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x1df, 0xa, 0x24, 0xc, 0x24,
      0xe, 0x24, 0x1e2, 0xb, 0x24, 0x3, 0x24, 0x2, 0x3, 0x32, 0x25, 0x2, 0x4,
      0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e,
      0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36,
      0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x2, 0x3, 0x3, 0x2,
      0x4, 0x6, 0x2, 0x20f, 0x2, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4, 0x56, 0x3,
      0x2, 0x2, 0x2, 0x6, 0x58, 0x3, 0x2, 0x2, 0x2, 0x8, 0x5e, 0x3, 0x2, 0x2,
      0x2, 0xa, 0x75, 0x3, 0x2, 0x2, 0x2, 0xc, 0x77, 0x3, 0x2, 0x2, 0x2, 0xe,
      0x8b, 0x3, 0x2, 0x2, 0x2, 0x10, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x12, 0x98,
      0x3, 0x2, 0x2, 0x2, 0x14, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x16, 0xb5, 0x3,
      0x2, 0x2, 0x2, 0x18, 0xca, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xd1, 0x3, 0x2,
      0x2, 0x2, 0x1c, 0xea, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xef, 0x3, 0x2, 0x2,
      0x2, 0x20, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x22, 0xfc, 0x3, 0x2, 0x2, 0x2,
      0x24, 0x107, 0x3, 0x2, 0x2, 0x2, 0x26, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x28,
      0x111, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x12e,
      0x3, 0x2, 0x2, 0x2, 0x2e, 0x132, 0x3, 0x2, 0x2, 0x2, 0x30, 0x13a, 0x3,
      0x2, 0x2, 0x2, 0x32, 0x169, 0x3, 0x2, 0x2, 0x2, 0x34, 0x19a, 0x3, 0x2,
      0x2, 0x2, 0x36, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x38, 0x1aa, 0x3, 0x2, 0x2,
      0x2, 0x3a, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x1b7, 0x3, 0x2, 0x2, 0x2,
      0x3e, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x40, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x42,
      0x1c9, 0x3, 0x2, 0x2, 0x2, 0x44, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x46, 0x1db,
      0x3, 0x2, 0x2, 0x2, 0x48, 0x4d, 0x5, 0x4, 0x3, 0x2, 0x49, 0x4d, 0x5,
      0x14, 0xb, 0x2, 0x4a, 0x4d, 0x5, 0x1a, 0xe, 0x2, 0x4b, 0x4d, 0x5, 0x1c,
      0xf, 0x2, 0x4c, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x49, 0x3, 0x2, 0x2,
      0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4b, 0x3, 0x2, 0x2, 0x2,
      0x4d, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4e,
      0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x51, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4e,
      0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0x2, 0x2, 0x3, 0x52, 0x3, 0x3,
      0x2, 0x2, 0x2, 0x53, 0x57, 0x5, 0x6, 0x4, 0x2, 0x54, 0x57, 0x5, 0x8,
      0x5, 0x2, 0x55, 0x57, 0x5, 0xc, 0x7, 0x2, 0x56, 0x53, 0x3, 0x2, 0x2,
      0x2, 0x56, 0x54, 0x3, 0x2, 0x2, 0x2, 0x56, 0x55, 0x3, 0x2, 0x2, 0x2,
      0x57, 0x5, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x7, 0x3, 0x2, 0x2, 0x59,
      0x5a, 0x5, 0x3e, 0x20, 0x2, 0x5a, 0x5b, 0x5, 0x32, 0x1a, 0x2, 0x5b,
      0x5c, 0x7, 0x2d, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x16, 0x2, 0x2, 0x5d, 0x7,
      0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x7, 0x2, 0x2, 0x5f, 0x60, 0x7,
      0x2d, 0x2, 0x2, 0x60, 0x65, 0x5, 0xa, 0x6, 0x2, 0x61, 0x62, 0x7, 0x22,
      0x2, 0x2, 0x62, 0x64, 0x5, 0xa, 0x6, 0x2, 0x63, 0x61, 0x3, 0x2, 0x2,
      0x2, 0x64, 0x67, 0x3, 0x2, 0x2, 0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 0x2,
      0x65, 0x66, 0x3, 0x2, 0x2, 0x2, 0x66, 0x68, 0x3, 0x2, 0x2, 0x2, 0x67,
      0x65, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x7, 0x16, 0x2, 0x2, 0x69, 0x9,
      0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0x1b, 0x2, 0x2, 0x6b, 0x70, 0x7,
      0x2f, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x14, 0x2, 0x2, 0x6d, 0x6f, 0x7, 0x2f,
      0x2, 0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x72, 0x3, 0x2, 0x2,
      0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2,
      0x71, 0x73, 0x3, 0x2, 0x2, 0x2, 0x72, 0x70, 0x3, 0x2, 0x2, 0x2, 0x73,
      0x76, 0x7, 0x1c, 0x2, 0x2, 0x74, 0x76, 0x5, 0x3a, 0x1e, 0x2, 0x75, 0x6a,
      0x3, 0x2, 0x2, 0x2, 0x75, 0x74, 0x3, 0x2, 0x2, 0x2, 0x76, 0xb, 0x3,
      0x2, 0x2, 0x2, 0x77, 0x78, 0x7, 0x8, 0x2, 0x2, 0x78, 0x7b, 0x7, 0x2d,
      0x2, 0x2, 0x79, 0x7a, 0x7, 0x15, 0x2, 0x2, 0x7a, 0x7c, 0x5, 0x40, 0x21,
      0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x3, 0x2, 0x2, 0x2,
      0x7c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x81, 0x7, 0x1b, 0x2, 0x2, 0x7e,
      0x80, 0x5, 0xe, 0x8, 0x2, 0x7f, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x83,
      0x3, 0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3,
      0x2, 0x2, 0x2, 0x82, 0x84, 0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2,
      0x2, 0x2, 0x84, 0x85, 0x7, 0x1c, 0x2, 0x2, 0x85, 0xd, 0x3, 0x2, 0x2,
      0x2, 0x86, 0x8c, 0x5, 0x10, 0x9, 0x2, 0x87, 0x8c, 0x5, 0x14, 0xb, 0x2,
      0x88, 0x8c, 0x5, 0x16, 0xc, 0x2, 0x89, 0x8c, 0x5, 0x1a, 0xe, 0x2, 0x8a,
      0x8c, 0x5, 0x4, 0x3, 0x2, 0x8b, 0x86, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x87,
      0x3, 0x2, 0x2, 0x2, 0x8b, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x89, 0x3,
      0x2, 0x2, 0x2, 0x8b, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8c, 0xf, 0x3, 0x2,
      0x2, 0x2, 0x8d, 0x8e, 0x5, 0x3a, 0x1e, 0x2, 0x8e, 0x93, 0x5, 0x12, 0xa,
      0x2, 0x8f, 0x90, 0x7, 0x14, 0x2, 0x2, 0x90, 0x92, 0x5, 0x12, 0xa, 0x2,
      0x91, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x92, 0x95, 0x3, 0x2, 0x2, 0x2, 0x93,
      0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 0x2, 0x94, 0x96,
      0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x7,
      0x16, 0x2, 0x2, 0x97, 0x11, 0x3, 0x2, 0x2, 0x2, 0x98, 0x9b, 0x7, 0x2d,
      0x2, 0x2, 0x99, 0x9a, 0x7, 0x23, 0x2, 0x2, 0x9a, 0x9c, 0x5, 0x32, 0x1a,
      0x2, 0x9b, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x3, 0x2, 0x2, 0x2,
      0x9c, 0x13, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0xf, 0x2, 0x2, 0x9e,
      0x9f, 0x7, 0x2d, 0x2, 0x2, 0x9f, 0xa1, 0x7, 0x17, 0x2, 0x2, 0xa0, 0xa2,
      0x5, 0x42, 0x22, 0x2, 0xa1, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3,
      0x2, 0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x18,
      0x2, 0x2, 0xa4, 0xa5, 0x7, 0x1b, 0x2, 0x2, 0xa5, 0xa6, 0x5, 0x1e, 0x10,
      0x2, 0xa6, 0xa7, 0x7, 0x1c, 0x2, 0x2, 0xa7, 0xb4, 0x3, 0x2, 0x2, 0x2,
      0xa8, 0xa9, 0x5, 0x3a, 0x1e, 0x2, 0xa9, 0xaa, 0x7, 0x2d, 0x2, 0x2, 0xaa,
      0xac, 0x7, 0x17, 0x2, 0x2, 0xab, 0xad, 0x5, 0x42, 0x22, 0x2, 0xac, 0xab,
      0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3,
      0x2, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x18, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x1b,
      0x2, 0x2, 0xb0, 0xb1, 0x5, 0x1e, 0x10, 0x2, 0xb1, 0xb2, 0x7, 0x1c, 0x2,
      0x2, 0xb2, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb3, 0x9d, 0x3, 0x2, 0x2, 0x2,
      0xb3, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x15, 0x3, 0x2, 0x2, 0x2, 0xb5,
      0xb6, 0x7, 0x2d, 0x2, 0x2, 0xb6, 0xb8, 0x7, 0x17, 0x2, 0x2, 0xb7, 0xb9,
      0x5, 0x42, 0x22, 0x2, 0xb8, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x3,
      0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 0xc4, 0x7, 0x18,
      0x2, 0x2, 0xbb, 0xbc, 0x7, 0x15, 0x2, 0x2, 0xbc, 0xc1, 0x5, 0x18, 0xd,
      0x2, 0xbd, 0xbe, 0x7, 0x14, 0x2, 0x2, 0xbe, 0xc0, 0x5, 0x18, 0xd, 0x2,
      0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc1,
      0xbf, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc5,
      0x3, 0x2, 0x2, 0x2, 0xc3, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xbb, 0x3,
      0x2, 0x2, 0x2, 0xc4, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 0x3, 0x2,
      0x2, 0x2, 0xc6, 0xc7, 0x7, 0x1b, 0x2, 0x2, 0xc7, 0xc8, 0x5, 0x1e, 0x10,
      0x2, 0xc8, 0xc9, 0x7, 0x1c, 0x2, 0x2, 0xc9, 0x17, 0x3, 0x2, 0x2, 0x2,
      0xca, 0xcb, 0x7, 0x2d, 0x2, 0x2, 0xcb, 0xcd, 0x7, 0x17, 0x2, 0x2, 0xcc,
      0xce, 0x5, 0x34, 0x1b, 0x2, 0xcd, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce,
      0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x7,
      0x18, 0x2, 0x2, 0xd0, 0x19, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0xb,
      0x2, 0x2, 0xd2, 0xd3, 0x7, 0x2d, 0x2, 0x2, 0xd3, 0xd5, 0x7, 0x17, 0x2,
      0x2, 0xd4, 0xd6, 0x5, 0x42, 0x22, 0x2, 0xd5, 0xd4, 0x3, 0x2, 0x2, 0x2,
      0xd5, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd7,
      0xda, 0x7, 0x18, 0x2, 0x2, 0xd8, 0xd9, 0x7, 0x15, 0x2, 0x2, 0xd9, 0xdb,
      0x5, 0x46, 0x24, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x3,
      0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x1b,
      0x2, 0x2, 0xdd, 0xde, 0x5, 0x1e, 0x10, 0x2, 0xde, 0xdf, 0x7, 0x1c, 0x2,
      0x2, 0xdf, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xeb, 0x5, 0x20, 0x11, 0x2,
      0xe1, 0xeb, 0x5, 0x22, 0x12, 0x2, 0xe2, 0xeb, 0x5, 0x24, 0x13, 0x2,
      0xe3, 0xeb, 0x5, 0x26, 0x14, 0x2, 0xe4, 0xeb, 0x5, 0x2a, 0x16, 0x2,
      0xe5, 0xeb, 0x5, 0x2c, 0x17, 0x2, 0xe6, 0xe7, 0x7, 0x1b, 0x2, 0x2, 0xe7,
      0xe8, 0x5, 0x1e, 0x10, 0x2, 0xe8, 0xe9, 0x7, 0x1c, 0x2, 0x2, 0xe9, 0xeb,
      0x3, 0x2, 0x2, 0x2, 0xea, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe1, 0x3,
      0x2, 0x2, 0x2, 0xea, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe3, 0x3, 0x2,
      0x2, 0x2, 0xea, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe5, 0x3, 0x2, 0x2,
      0x2, 0xea, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xeb, 0x1d, 0x3, 0x2, 0x2, 0x2,
      0xec, 0xee, 0x5, 0x1c, 0xf, 0x2, 0xed, 0xec, 0x3, 0x2, 0x2, 0x2, 0xee,
      0xf1, 0x3, 0x2, 0x2, 0x2, 0xef, 0xed, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0,
      0x3, 0x2, 0x2, 0x2, 0xf0, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xef, 0x3,
      0x2, 0x2, 0x2, 0xf2, 0xf3, 0x5, 0x38, 0x1d, 0x2, 0xf3, 0xf4, 0x7, 0x13,
      0x2, 0x2, 0xf4, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf2, 0x3, 0x2, 0x2,
      0x2, 0xf5, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x3, 0x2, 0x2, 0x2,
      0xf7, 0xf8, 0x7, 0x2d, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x23, 0x2, 0x2, 0xf9,
      0xfa, 0x5, 0x32, 0x1a, 0x2, 0xfa, 0xfb, 0x7, 0x16, 0x2, 0x2, 0xfb, 0x21,
      0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x5, 0x3a, 0x1e, 0x2, 0xfd, 0x102, 0x5,
      0x12, 0xa, 0x2, 0xfe, 0xff, 0x7, 0x14, 0x2, 0x2, 0xff, 0x101, 0x5, 0x12,
      0xa, 0x2, 0x100, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x101, 0x104, 0x3, 0x2, 0x2,
      0x2, 0x102, 0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x3, 0x2, 0x2,
      0x2, 0x103, 0x105, 0x3, 0x2, 0x2, 0x2, 0x104, 0x102, 0x3, 0x2, 0x2,
      0x2, 0x105, 0x106, 0x7, 0x16, 0x2, 0x2, 0x106, 0x23, 0x3, 0x2, 0x2,
      0x2, 0x107, 0x108, 0x5, 0x32, 0x1a, 0x2, 0x108, 0x109, 0x7, 0x16, 0x2,
      0x2, 0x109, 0x25, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10d, 0x5, 0x28, 0x15,
      0x2, 0x10b, 0x10c, 0x7, 0xd, 0x2, 0x2, 0x10c, 0x10e, 0x5, 0x28, 0x15,
      0x2, 0x10d, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 0x2,
      0x2, 0x10f, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x3, 0x2, 0x2,
      0x2, 0x110, 0x27, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x7, 0x1b, 0x2,
      0x2, 0x112, 0x113, 0x5, 0x1e, 0x10, 0x2, 0x113, 0x118, 0x7, 0x1c, 0x2,
      0x2, 0x114, 0x115, 0x7, 0x19, 0x2, 0x2, 0x115, 0x116, 0x5, 0x32, 0x1a,
      0x2, 0x116, 0x117, 0x7, 0x1a, 0x2, 0x2, 0x117, 0x119, 0x3, 0x2, 0x2,
      0x2, 0x118, 0x114, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x3, 0x2, 0x2,
      0x2, 0x119, 0x29, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11d, 0x7, 0x9, 0x2, 0x2,
      0x11b, 0x11d, 0x7, 0xa, 0x2, 0x2, 0x11c, 0x11a, 0x3, 0x2, 0x2, 0x2,
      0x11c, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x3, 0x2, 0x2, 0x2,
      0x11e, 0x11f, 0x7, 0x2d, 0x2, 0x2, 0x11f, 0x120, 0x7, 0x23, 0x2, 0x2,
      0x120, 0x124, 0x7, 0xc, 0x2, 0x2, 0x121, 0x122, 0x5, 0x38, 0x1d, 0x2,
      0x122, 0x123, 0x7, 0x13, 0x2, 0x2, 0x123, 0x125, 0x3, 0x2, 0x2, 0x2,
      0x124, 0x121, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x3, 0x2, 0x2, 0x2,
      0x125, 0x126, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x7, 0x2d, 0x2, 0x2,
      0x127, 0x129, 0x7, 0x17, 0x2, 0x2, 0x128, 0x12a, 0x5, 0x2e, 0x18, 0x2,
      0x129, 0x128, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x3, 0x2, 0x2, 0x2,
      0x12a, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x7, 0x18, 0x2, 0x2,
      0x12c, 0x12d, 0x7, 0x16, 0x2, 0x2, 0x12d, 0x2b, 0x3, 0x2, 0x2, 0x2,
      0x12e, 0x12f, 0x7, 0x12, 0x2, 0x2, 0x12f, 0x130, 0x5, 0x32, 0x1a, 0x2,
      0x130, 0x131, 0x7, 0x16, 0x2, 0x2, 0x131, 0x2d, 0x3, 0x2, 0x2, 0x2,
      0x132, 0x137, 0x5, 0x30, 0x19, 0x2, 0x133, 0x134, 0x7, 0x14, 0x2, 0x2,
      0x134, 0x136, 0x5, 0x30, 0x19, 0x2, 0x135, 0x133, 0x3, 0x2, 0x2, 0x2,
      0x136, 0x139, 0x3, 0x2, 0x2, 0x2, 0x137, 0x135, 0x3, 0x2, 0x2, 0x2,
      0x137, 0x138, 0x3, 0x2, 0x2, 0x2, 0x138, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x139,
      0x137, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 0x7, 0x2d, 0x2, 0x2, 0x13b,
      0x13c, 0x7, 0x15, 0x2, 0x2, 0x13c, 0x13d, 0x5, 0x32, 0x1a, 0x2, 0x13d,
      0x31, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x8, 0x1a, 0x1, 0x2, 0x13f,
      0x16a, 0x5, 0x36, 0x1c, 0x2, 0x140, 0x141, 0x7, 0x17, 0x2, 0x2, 0x141,
      0x142, 0x5, 0x32, 0x1a, 0x2, 0x142, 0x143, 0x7, 0x18, 0x2, 0x2, 0x143,
      0x16a, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x7, 0x1d, 0x2, 0x2, 0x145,
      0x16a, 0x5, 0x32, 0x1a, 0x14, 0x146, 0x147, 0x7, 0x1e, 0x2, 0x2, 0x147,
      0x16a, 0x5, 0x32, 0x1a, 0x13, 0x148, 0x149, 0x7, 0x26, 0x2, 0x2, 0x149,
      0x16a, 0x5, 0x32, 0x1a, 0x12, 0x14a, 0x16a, 0x5, 0x38, 0x1d, 0x2, 0x14b,
      0x14c, 0x5, 0x38, 0x1d, 0x2, 0x14c, 0x14d, 0x7, 0x13, 0x2, 0x2, 0x14d,
      0x14f, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14e,
      0x14f, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 0x150,
      0x151, 0x7, 0x2d, 0x2, 0x2, 0x151, 0x153, 0x7, 0x17, 0x2, 0x2, 0x152,
      0x154, 0x5, 0x34, 0x1b, 0x2, 0x153, 0x152, 0x3, 0x2, 0x2, 0x2, 0x153,
      0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x3, 0x2, 0x2, 0x2, 0x155,
      0x16a, 0x7, 0x18, 0x2, 0x2, 0x156, 0x157, 0x7, 0x17, 0x2, 0x2, 0x157,
      0x158, 0x5, 0x3a, 0x1e, 0x2, 0x158, 0x159, 0x7, 0x18, 0x2, 0x2, 0x159,
      0x15a, 0x5, 0x32, 0x1a, 0xf, 0x15a, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x15b,
      0x15c, 0x7, 0x19, 0x2, 0x2, 0x15c, 0x15d, 0x5, 0x32, 0x1a, 0x2, 0x15d,
      0x15e, 0x7, 0x14, 0x2, 0x2, 0x15e, 0x15f, 0x5, 0x32, 0x1a, 0x2, 0x15f,
      0x160, 0x7, 0x1a, 0x2, 0x2, 0x160, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x161,
      0x162, 0x7, 0xc, 0x2, 0x2, 0x162, 0x163, 0x5, 0x3a, 0x1e, 0x2, 0x163,
      0x165, 0x7, 0x17, 0x2, 0x2, 0x164, 0x166, 0x5, 0x34, 0x1b, 0x2, 0x165,
      0x164, 0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x3, 0x2, 0x2, 0x2, 0x166,
      0x167, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x7, 0x18, 0x2, 0x2, 0x168,
      0x16a, 0x3, 0x2, 0x2, 0x2, 0x169, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x169,
      0x140, 0x3, 0x2, 0x2, 0x2, 0x169, 0x144, 0x3, 0x2, 0x2, 0x2, 0x169,
      0x146, 0x3, 0x2, 0x2, 0x2, 0x169, 0x148, 0x3, 0x2, 0x2, 0x2, 0x169,
      0x14a, 0x3, 0x2, 0x2, 0x2, 0x169, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x169,
      0x156, 0x3, 0x2, 0x2, 0x2, 0x169, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x169,
      0x161, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x197, 0x3, 0x2, 0x2, 0x2, 0x16b,
      0x16c, 0xc, 0x18, 0x2, 0x2, 0x16c, 0x16d, 0x7, 0x1f, 0x2, 0x2, 0x16d,
      0x196, 0x5, 0x32, 0x1a, 0x19, 0x16e, 0x16f, 0xc, 0x17, 0x2, 0x2, 0x16f,
      0x170, 0x7, 0x20, 0x2, 0x2, 0x170, 0x196, 0x5, 0x32, 0x1a, 0x18, 0x171,
      0x172, 0xc, 0x16, 0x2, 0x2, 0x172, 0x173, 0x7, 0x1d, 0x2, 0x2, 0x173,
      0x196, 0x5, 0x32, 0x1a, 0x17, 0x174, 0x175, 0xc, 0x15, 0x2, 0x2, 0x175,
      0x176, 0x7, 0x1e, 0x2, 0x2, 0x176, 0x196, 0x5, 0x32, 0x1a, 0x16, 0x177,
      0x178, 0xc, 0xc, 0x2, 0x2, 0x178, 0x179, 0x7, 0x27, 0x2, 0x2, 0x179,
      0x196, 0x5, 0x32, 0x1a, 0xd, 0x17a, 0x17b, 0xc, 0xb, 0x2, 0x2, 0x17b,
      0x17c, 0x7, 0x29, 0x2, 0x2, 0x17c, 0x196, 0x5, 0x32, 0x1a, 0xc, 0x17d,
      0x17e, 0xc, 0xa, 0x2, 0x2, 0x17e, 0x17f, 0x7, 0x28, 0x2, 0x2, 0x17f,
      0x196, 0x5, 0x32, 0x1a, 0xb, 0x180, 0x181, 0xc, 0x9, 0x2, 0x2, 0x181,
      0x182, 0x7, 0x24, 0x2, 0x2, 0x182, 0x196, 0x5, 0x32, 0x1a, 0xa, 0x183,
      0x184, 0xc, 0x8, 0x2, 0x2, 0x184, 0x185, 0x7, 0x25, 0x2, 0x2, 0x185,
      0x196, 0x5, 0x32, 0x1a, 0x9, 0x186, 0x187, 0xc, 0x7, 0x2, 0x2, 0x187,
      0x188, 0x7, 0x2a, 0x2, 0x2, 0x188, 0x196, 0x5, 0x32, 0x1a, 0x8, 0x189,
      0x18a, 0xc, 0x6, 0x2, 0x2, 0x18a, 0x18b, 0x7, 0x2b, 0x2, 0x2, 0x18b,
      0x196, 0x5, 0x32, 0x1a, 0x7, 0x18c, 0x18d, 0xc, 0x5, 0x2, 0x2, 0x18d,
      0x18e, 0x7, 0x22, 0x2, 0x2, 0x18e, 0x196, 0x5, 0x32, 0x1a, 0x6, 0x18f,
      0x190, 0xc, 0x4, 0x2, 0x2, 0x190, 0x191, 0x7, 0x21, 0x2, 0x2, 0x191,
      0x196, 0x5, 0x32, 0x1a, 0x5, 0x192, 0x193, 0xc, 0x3, 0x2, 0x2, 0x193,
      0x194, 0x7, 0x2c, 0x2, 0x2, 0x194, 0x196, 0x5, 0x32, 0x1a, 0x4, 0x195,
      0x16b, 0x3, 0x2, 0x2, 0x2, 0x195, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x195,
      0x171, 0x3, 0x2, 0x2, 0x2, 0x195, 0x174, 0x3, 0x2, 0x2, 0x2, 0x195,
      0x177, 0x3, 0x2, 0x2, 0x2, 0x195, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x195,
      0x17d, 0x3, 0x2, 0x2, 0x2, 0x195, 0x180, 0x3, 0x2, 0x2, 0x2, 0x195,
      0x183, 0x3, 0x2, 0x2, 0x2, 0x195, 0x186, 0x3, 0x2, 0x2, 0x2, 0x195,
      0x189, 0x3, 0x2, 0x2, 0x2, 0x195, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x195,
      0x18f, 0x3, 0x2, 0x2, 0x2, 0x195, 0x192, 0x3, 0x2, 0x2, 0x2, 0x196,
      0x199, 0x3, 0x2, 0x2, 0x2, 0x197, 0x195, 0x3, 0x2, 0x2, 0x2, 0x197,
      0x198, 0x3, 0x2, 0x2, 0x2, 0x198, 0x33, 0x3, 0x2, 0x2, 0x2, 0x199, 0x197,
      0x3, 0x2, 0x2, 0x2, 0x19a, 0x19f, 0x5, 0x32, 0x1a, 0x2, 0x19b, 0x19c,
      0x7, 0x14, 0x2, 0x2, 0x19c, 0x19e, 0x5, 0x32, 0x1a, 0x2, 0x19d, 0x19b,
      0x3, 0x2, 0x2, 0x2, 0x19e, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x19d,
      0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x35, 0x3,
      0x2, 0x2, 0x2, 0x1a1, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a7, 0x7,
      0x2e, 0x2, 0x2, 0x1a3, 0x1a7, 0x7, 0x2f, 0x2, 0x2, 0x1a4, 0x1a7, 0x7,
      0x10, 0x2, 0x2, 0x1a5, 0x1a7, 0x7, 0x11, 0x2, 0x2, 0x1a6, 0x1a2, 0x3,
      0x2, 0x2, 0x2, 0x1a6, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a4, 0x3,
      0x2, 0x2, 0x2, 0x1a6, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x37, 0x3, 0x2,
      0x2, 0x2, 0x1a8, 0x1ab, 0x7, 0xe, 0x2, 0x2, 0x1a9, 0x1ab, 0x7, 0x2d,
      0x2, 0x2, 0x1aa, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a9, 0x3, 0x2,
      0x2, 0x2, 0x1ab, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 0x7, 0x13,
      0x2, 0x2, 0x1ad, 0x1af, 0x7, 0x2d, 0x2, 0x2, 0x1ae, 0x1ac, 0x3, 0x2,
      0x2, 0x2, 0x1af, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1ae, 0x3, 0x2,
      0x2, 0x2, 0x1b0, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x39, 0x3, 0x2, 0x2,
      0x2, 0x1b2, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b6, 0x5, 0x3c, 0x1f,
      0x2, 0x1b4, 0x1b6, 0x5, 0x3e, 0x20, 0x2, 0x1b5, 0x1b3, 0x3, 0x2, 0x2,
      0x2, 0x1b5, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x3b, 0x3, 0x2, 0x2, 0x2,
      0x1b7, 0x1bc, 0x7, 0x2d, 0x2, 0x2, 0x1b8, 0x1b9, 0x7, 0x13, 0x2, 0x2,
      0x1b9, 0x1bb, 0x7, 0x2d, 0x2, 0x2, 0x1ba, 0x1b8, 0x3, 0x2, 0x2, 0x2,
      0x1bb, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1ba, 0x3, 0x2, 0x2, 0x2,
      0x1bc, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x1be,
      0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c0, 0x9, 0x2, 0x2, 0x2, 0x1c0,
      0x3f, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c6, 0x5, 0x3a, 0x1e, 0x2, 0x1c2,
      0x1c3, 0x7, 0x14, 0x2, 0x2, 0x1c3, 0x1c5, 0x5, 0x3a, 0x1e, 0x2, 0x1c4,
      0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1c6,
      0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1c7,
      0x41, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ca,
      0x5, 0x3a, 0x1e, 0x2, 0x1ca, 0x1d1, 0x7, 0x2d, 0x2, 0x2, 0x1cb, 0x1cc,
      0x7, 0x14, 0x2, 0x2, 0x1cc, 0x1cd, 0x5, 0x3a, 0x1e, 0x2, 0x1cd, 0x1ce,
      0x7, 0x2d, 0x2, 0x2, 0x1ce, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1cb,
      0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1cf,
      0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x43, 0x3,
      0x2, 0x2, 0x2, 0x1d3, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d5, 0x5,
      0x3c, 0x1f, 0x2, 0x1d5, 0x1d6, 0x7, 0x13, 0x2, 0x2, 0x1d6, 0x1d8, 0x3,
      0x2, 0x2, 0x2, 0x1d7, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d8, 0x3,
      0x2, 0x2, 0x2, 0x1d8, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1da, 0x7,
      0x2d, 0x2, 0x2, 0x1da, 0x45, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1e0, 0x5,
      0x44, 0x23, 0x2, 0x1dc, 0x1dd, 0x7, 0x14, 0x2, 0x2, 0x1dd, 0x1df, 0x5,
      0x44, 0x23, 0x2, 0x1de, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e2, 0x3,
      0x2, 0x2, 0x2, 0x1e0, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e1, 0x3,
      0x2, 0x2, 0x2, 0x1e1, 0x47, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e0, 0x3, 0x2,
      0x2, 0x2, 0x30, 0x4c, 0x4e, 0x56, 0x65, 0x70, 0x75, 0x7b, 0x81, 0x8b,
      0x93, 0x9b, 0xa1, 0xac, 0xb3, 0xb8, 0xc1, 0xc4, 0xcd, 0xd5, 0xda, 0xea,
      0xef, 0xf5, 0x102, 0x10f, 0x118, 0x11c, 0x124, 0x129, 0x137, 0x14e,
      0x153, 0x165, 0x169, 0x195, 0x197, 0x19f, 0x1a6, 0x1aa, 0x1b0, 0x1b5,
      0x1bc, 0x1c6, 0x1d1, 0x1d7, 0x1e0,
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++)
  {
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ratioParser::Initializer ratioParser::_init;
