
// Generated from ratio.g4 by ANTLR 4.7

#pragma once

#include "antlr4-runtime.h"

namespace lucy
{

class ratioParser : public antlr4::Parser
{
public:
  enum
  {
    TYPE_DEF = 1,
    REAL = 2,
    BOOL = 3,
    STRING = 4,
    ENUM = 5,
    CLASS = 6,
    GOAL = 7,
    FACT = 8,
    PREDICATE = 9,
    NEW = 10,
    OR = 11,
    THIS = 12,
    VOID = 13,
    TRUE = 14,
    FALSE = 15,
    RETURN = 16,
    DOT = 17,
    COMMA = 18,
    COLON = 19,
    SEMICOLON = 20,
    LPAREN = 21,
    RPAREN = 22,
    LBRACKET = 23,
    RBRACKET = 24,
    LBRACE = 25,
    RBRACE = 26,
    PLUS = 27,
    MINUS = 28,
    STAR = 29,
    SLASH = 30,
    AMP = 31,
    BAR = 32,
    EQUAL = 33,
    GT = 34,
    LT = 35,
    BANG = 36,
    EQEQ = 37,
    LTEQ = 38,
    GTEQ = 39,
    BANGEQ = 40,
    IMPLICATION = 41,
    CARET = 42,
    ID = 43,
    NumericLiteral = 44,
    StringLiteral = 45,
    LINE_COMMENT = 46,
    COMMENT = 47,
    WS = 48
  };

  enum
  {
    RuleCompilation_unit = 0,
    RuleType_declaration = 1,
    RuleTypedef_declaration = 2,
    RuleEnum_declaration = 3,
    RuleEnum_constants = 4,
    RuleClass_declaration = 5,
    RuleMember = 6,
    RuleField_declaration = 7,
    RuleVariable_dec = 8,
    RuleMethod_declaration = 9,
    RuleConstructor_declaration = 10,
    RuleInitializer_element = 11,
    RulePredicate_declaration = 12,
    RuleStatement = 13,
    RuleBlock = 14,
    RuleAssignment_statement = 15,
    RuleLocal_variable_statement = 16,
    RuleExpression_statement = 17,
    RuleDisjunction_statement = 18,
    RuleConjunction = 19,
    RuleFormula_statement = 20,
    RuleReturn_statement = 21,
    RuleAssignment_list = 22,
    RuleAssignment = 23,
    RuleExpr = 24,
    RuleExpr_list = 25,
    RuleLiteral = 26,
    RuleQualified_id = 27,
    RuleType = 28,
    RuleClass_type = 29,
    RulePrimitive_type = 30,
    RuleType_list = 31,
    RuleTyped_list = 32,
    RuleQualified_predicate = 33,
    RulePredicate_list = 34
  };

  ratioParser(antlr4::TokenStream *input);
  ~ratioParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN &getATN() const override { return _atn; };
  virtual const std::vector<std::string> &getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string> &getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary &getVocabulary() const override;

  class Compilation_unitContext;
  class Type_declarationContext;
  class Typedef_declarationContext;
  class Enum_declarationContext;
  class Enum_constantsContext;
  class Class_declarationContext;
  class MemberContext;
  class Field_declarationContext;
  class Variable_decContext;
  class Method_declarationContext;
  class Constructor_declarationContext;
  class Initializer_elementContext;
  class Predicate_declarationContext;
  class StatementContext;
  class BlockContext;
  class Assignment_statementContext;
  class Local_variable_statementContext;
  class Expression_statementContext;
  class Disjunction_statementContext;
  class ConjunctionContext;
  class Formula_statementContext;
  class Return_statementContext;
  class Assignment_listContext;
  class AssignmentContext;
  class ExprContext;
  class Expr_listContext;
  class LiteralContext;
  class Qualified_idContext;
  class TypeContext;
  class Class_typeContext;
  class Primitive_typeContext;
  class Type_listContext;
  class Typed_listContext;
  class Qualified_predicateContext;
  class Predicate_listContext;

  class Compilation_unitContext : public antlr4::ParserRuleContext
  {
  public:
    Compilation_unitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Type_declarationContext *> type_declaration();
    Type_declarationContext *type_declaration(size_t i);
    std::vector<Method_declarationContext *> method_declaration();
    Method_declarationContext *method_declaration(size_t i);
    std::vector<Predicate_declarationContext *> predicate_declaration();
    Predicate_declarationContext *predicate_declaration(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext *statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Compilation_unitContext *compilation_unit();

  class Type_declarationContext : public antlr4::ParserRuleContext
  {
  public:
    Type_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Typedef_declarationContext *typedef_declaration();
    Enum_declarationContext *enum_declaration();
    Class_declarationContext *class_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Type_declarationContext *type_declaration();

  class Typedef_declarationContext : public antlr4::ParserRuleContext
  {
  public:
    antlr4::Token *name = nullptr;
    ;
    Typedef_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Primitive_typeContext *primitive_type();
    ExprContext *expr();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Typedef_declarationContext *typedef_declaration();

  class Enum_declarationContext : public antlr4::ParserRuleContext
  {
  public:
    antlr4::Token *name = nullptr;
    ;
    Enum_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Enum_constantsContext *> enum_constants();
    Enum_constantsContext *enum_constants(size_t i);
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Enum_declarationContext *enum_declaration();

  class Enum_constantsContext : public antlr4::ParserRuleContext
  {
  public:
    Enum_constantsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> StringLiteral();
    antlr4::tree::TerminalNode *StringLiteral(size_t i);
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Enum_constantsContext *enum_constants();

  class Class_declarationContext : public antlr4::ParserRuleContext
  {
  public:
    antlr4::Token *name = nullptr;
    ;
    Class_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Type_listContext *type_list();
    std::vector<MemberContext *> member();
    MemberContext *member(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Class_declarationContext *class_declaration();

  class MemberContext : public antlr4::ParserRuleContext
  {
  public:
    MemberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Field_declarationContext *field_declaration();
    Method_declarationContext *method_declaration();
    Constructor_declarationContext *constructor_declaration();
    Predicate_declarationContext *predicate_declaration();
    Type_declarationContext *type_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  MemberContext *member();

  class Field_declarationContext : public antlr4::ParserRuleContext
  {
  public:
    Field_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    std::vector<Variable_decContext *> variable_dec();
    Variable_decContext *variable_dec(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Field_declarationContext *field_declaration();

  class Variable_decContext : public antlr4::ParserRuleContext
  {
  public:
    antlr4::Token *name = nullptr;
    ;
    Variable_decContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Variable_decContext *variable_dec();

  class Method_declarationContext : public antlr4::ParserRuleContext
  {
  public:
    Method_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);

    Method_declarationContext() : antlr4::ParserRuleContext() {}
    void copyFrom(Method_declarationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;
  };

  class Void_method_declarationContext : public Method_declarationContext
  {
  public:
    Void_method_declarationContext(Method_declarationContext *ctx);

    antlr4::Token *name = nullptr;
    BlockContext *block();
    antlr4::tree::TerminalNode *ID();
    Typed_listContext *typed_list();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Type_method_declarationContext : public Method_declarationContext
  {
  public:
    Type_method_declarationContext(Method_declarationContext *ctx);

    antlr4::Token *name = nullptr;
    TypeContext *type();
    BlockContext *block();
    antlr4::tree::TerminalNode *ID();
    Typed_listContext *typed_list();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Method_declarationContext *method_declaration();

  class Constructor_declarationContext : public antlr4::ParserRuleContext
  {
  public:
    antlr4::Token *name = nullptr;
    ;
    Constructor_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    antlr4::tree::TerminalNode *ID();
    Typed_listContext *typed_list();
    std::vector<Initializer_elementContext *> initializer_element();
    Initializer_elementContext *initializer_element(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Constructor_declarationContext *constructor_declaration();

  class Initializer_elementContext : public antlr4::ParserRuleContext
  {
  public:
    antlr4::Token *name = nullptr;
    ;
    Initializer_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Expr_listContext *expr_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Initializer_elementContext *initializer_element();

  class Predicate_declarationContext : public antlr4::ParserRuleContext
  {
  public:
    antlr4::Token *name = nullptr;
    ;
    Predicate_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    antlr4::tree::TerminalNode *ID();
    Typed_listContext *typed_list();
    Predicate_listContext *predicate_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Predicate_declarationContext *predicate_declaration();

  class StatementContext : public antlr4::ParserRuleContext
  {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Assignment_statementContext *assignment_statement();
    Local_variable_statementContext *local_variable_statement();
    Expression_statementContext *expression_statement();
    Disjunction_statementContext *disjunction_statement();
    Formula_statementContext *formula_statement();
    Return_statementContext *return_statement();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementContext *statement();

  class BlockContext : public antlr4::ParserRuleContext
  {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext *statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BlockContext *block();

  class Assignment_statementContext : public antlr4::ParserRuleContext
  {
  public:
    ratioParser::Qualified_idContext *object = nullptr;
    ;
    antlr4::Token *field = nullptr;
    ;
    ratioParser::ExprContext *value = nullptr;
    ;
    Assignment_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();
    Qualified_idContext *qualified_id();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Assignment_statementContext *assignment_statement();

  class Local_variable_statementContext : public antlr4::ParserRuleContext
  {
  public:
    Local_variable_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    std::vector<Variable_decContext *> variable_dec();
    Variable_decContext *variable_dec(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Local_variable_statementContext *local_variable_statement();

  class Expression_statementContext : public antlr4::ParserRuleContext
  {
  public:
    Expression_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Expression_statementContext *expression_statement();

  class Disjunction_statementContext : public antlr4::ParserRuleContext
  {
  public:
    Disjunction_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ConjunctionContext *> conjunction();
    ConjunctionContext *conjunction(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Disjunction_statementContext *disjunction_statement();

  class ConjunctionContext : public antlr4::ParserRuleContext
  {
  public:
    ratioParser::ExprContext *cost = nullptr;
    ;
    ConjunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ConjunctionContext *conjunction();

  class Formula_statementContext : public antlr4::ParserRuleContext
  {
  public:
    antlr4::Token *goal = nullptr;
    ;
    antlr4::Token *fact = nullptr;
    ;
    antlr4::Token *name = nullptr;
    ;
    ratioParser::Qualified_idContext *object = nullptr;
    ;
    antlr4::Token *predicate = nullptr;
    ;
    Formula_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode *ID(size_t i);
    Assignment_listContext *assignment_list();
    Qualified_idContext *qualified_id();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Formula_statementContext *formula_statement();

  class Return_statementContext : public antlr4::ParserRuleContext
  {
  public:
    Return_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Return_statementContext *return_statement();

  class Assignment_listContext : public antlr4::ParserRuleContext
  {
  public:
    Assignment_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AssignmentContext *> assignment();
    AssignmentContext *assignment(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Assignment_listContext *assignment_list();

  class AssignmentContext : public antlr4::ParserRuleContext
  {
  public:
    antlr4::Token *field = nullptr;
    ;
    ratioParser::ExprContext *value = nullptr;
    ;
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AssignmentContext *assignment();

  class ExprContext : public antlr4::ParserRuleContext
  {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);

    ExprContext() : antlr4::ParserRuleContext() {}
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;
  };

  class Cast_expressionContext : public ExprContext
  {
  public:
    Cast_expressionContext(ExprContext *ctx);

    TypeContext *type();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Qualified_id_expressionContext : public ExprContext
  {
  public:
    Qualified_id_expressionContext(ExprContext *ctx);

    Qualified_idContext *qualified_id();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Division_expressionContext : public ExprContext
  {
  public:
    Division_expressionContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Subtraction_expressionContext : public ExprContext
  {
  public:
    Subtraction_expressionContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Extc_one_expressionContext : public ExprContext
  {
  public:
    Extc_one_expressionContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Plus_expressionContext : public ExprContext
  {
  public:
    Plus_expressionContext(ExprContext *ctx);

    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Function_expressionContext : public ExprContext
  {
  public:
    Function_expressionContext(ExprContext *ctx);

    ratioParser::Qualified_idContext *object = nullptr;
    antlr4::Token *function_name = nullptr;
    antlr4::tree::TerminalNode *ID();
    Expr_listContext *expr_list();
    Qualified_idContext *qualified_id();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Addition_expressionContext : public ExprContext
  {
  public:
    Addition_expressionContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Parentheses_expressionContext : public ExprContext
  {
  public:
    Parentheses_expressionContext(ExprContext *ctx);

    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Minus_expressionContext : public ExprContext
  {
  public:
    Minus_expressionContext(ExprContext *ctx);

    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Implication_expressionContext : public ExprContext
  {
  public:
    Implication_expressionContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Lt_expressionContext : public ExprContext
  {
  public:
    Lt_expressionContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Not_expressionContext : public ExprContext
  {
  public:
    Not_expressionContext(ExprContext *ctx);

    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Conjunction_expressionContext : public ExprContext
  {
  public:
    Conjunction_expressionContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Geq_expressionContext : public ExprContext
  {
  public:
    Geq_expressionContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Range_expressionContext : public ExprContext
  {
  public:
    Range_expressionContext(ExprContext *ctx);

    ratioParser::ExprContext *min = nullptr;
    ratioParser::ExprContext *max = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Multiplication_expressionContext : public ExprContext
  {
  public:
    Multiplication_expressionContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Leq_expressionContext : public ExprContext
  {
  public:
    Leq_expressionContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Gt_expressionContext : public ExprContext
  {
  public:
    Gt_expressionContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Constructor_expressionContext : public ExprContext
  {
  public:
    Constructor_expressionContext(ExprContext *ctx);

    TypeContext *type();
    Expr_listContext *expr_list();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Disjunction_expressionContext : public ExprContext
  {
  public:
    Disjunction_expressionContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Literal_expressionContext : public ExprContext
  {
  public:
    Literal_expressionContext(ExprContext *ctx);

    LiteralContext *literal();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Eq_expressionContext : public ExprContext
  {
  public:
    Eq_expressionContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class Neq_expressionContext : public ExprContext
  {
  public:
    Neq_expressionContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext *expr();
  ExprContext *expr(int precedence);
  class Expr_listContext : public antlr4::ParserRuleContext
  {
  public:
    Expr_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Expr_listContext *expr_list();

  class LiteralContext : public antlr4::ParserRuleContext
  {
  public:
    antlr4::Token *numeric = nullptr;
    ;
    antlr4::Token *string = nullptr;
    ;
    antlr4::Token *t = nullptr;
    ;
    antlr4::Token *f = nullptr;
    ;
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NumericLiteral();
    antlr4::tree::TerminalNode *StringLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LiteralContext *literal();

  class Qualified_idContext : public antlr4::ParserRuleContext
  {
  public:
    antlr4::Token *t = nullptr;
    ;
    Qualified_idContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode *ID(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Qualified_idContext *qualified_id();

  class TypeContext : public antlr4::ParserRuleContext
  {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_typeContext *class_type();
    Primitive_typeContext *primitive_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeContext *type();

  class Class_typeContext : public antlr4::ParserRuleContext
  {
  public:
    Class_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode *ID(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Class_typeContext *class_type();

  class Primitive_typeContext : public antlr4::ParserRuleContext
  {
  public:
    Primitive_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Primitive_typeContext *primitive_type();

  class Type_listContext : public antlr4::ParserRuleContext
  {
  public:
    Type_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeContext *> type();
    TypeContext *type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Type_listContext *type_list();

  class Typed_listContext : public antlr4::ParserRuleContext
  {
  public:
    Typed_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeContext *> type();
    TypeContext *type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode *ID(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Typed_listContext *typed_list();

  class Qualified_predicateContext : public antlr4::ParserRuleContext
  {
  public:
    Qualified_predicateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Class_typeContext *class_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Qualified_predicateContext *qualified_predicate();

  class Predicate_listContext : public antlr4::ParserRuleContext
  {
  public:
    Predicate_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Qualified_predicateContext *> qualified_predicate();
    Qualified_predicateContext *qualified_predicate(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Predicate_listContext *predicate_list();

  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;

  struct Initializer
  {
    Initializer();
  };
  static Initializer _init;
};

} // namespace lucy
