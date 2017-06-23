#pragma once

#include "lexer.h"
#include <vector>

namespace lucy
{

class core;

namespace ast
{

class type_declaration;
class method_declaration;
class predicate_declaration;
class field_declaration;
class constructor_declaration;
class method_declaration;
class predicate_declaration;
class statement;
class expr;

class type_declaration
{
public:
  type_declaration(const std::string &n) : name(n) {}
  type_declaration(const type_declaration &orig) = delete;
  virtual ~type_declaration() {}

public:
  std::string name;
};

class typedef_declaration : public type_declaration
{
public:
  typedef_declaration(const std::string &n, const std::string &pt, expr *const e) : type_declaration(n), primitive_type(pt), xpr(e) {}
  typedef_declaration(const typedef_declaration &orig) = delete;
  virtual ~typedef_declaration() {}

public:
  std::string primitive_type;
  expr *const xpr;
};

class enum_declaration : public type_declaration
{
public:
  enum_declaration(const std::string &n, const std::vector<std::string> &es, const std::vector<std::vector<std::string>> &trs) : type_declaration(n), enums(es), type_refs(trs) {}
  enum_declaration(const enum_declaration &orig) = delete;
  virtual ~enum_declaration() {}

public:
  std::vector<std::string> enums;
  std::vector<std::vector<std::string>> type_refs;
};

class class_declaration : public type_declaration
{
public:
  class_declaration(const std::string &n, const std::vector<std::vector<std::string>> &bcs, const std::vector<field_declaration *> &fs, const std::vector<constructor_declaration *> &cs, const std::vector<method_declaration *> &ms, const std::vector<predicate_declaration *> &ps, const std::vector<type_declaration *> &ts) : type_declaration(n), base_classes(bcs), fields(fs), constructors(cs), methods(ms), predicates(ps), types(ts) {}
  class_declaration(const class_declaration &orig) = delete;
  virtual ~class_declaration() {}

public:
  std::vector<std::vector<std::string>> base_classes;
  std::vector<field_declaration *> fields;
  std::vector<constructor_declaration *> constructors;
  std::vector<method_declaration *> methods;
  std::vector<predicate_declaration *> predicates;
  std::vector<type_declaration *> types;
};

class variable_declaration
{
public:
  variable_declaration(const std::string &n, expr *const e = nullptr) : name(n), xpr(e) {}
  variable_declaration(const class_declaration &orig) = delete;
  virtual ~variable_declaration() {}

public:
  std::string name;
  expr *const xpr;
};

class field_declaration
{
public:
  field_declaration(const std::vector<std::string> &tp, const std::vector<variable_declaration *> &ds) : type(tp), declarations(ds) {}
  field_declaration(const class_declaration &orig) = delete;
  virtual ~field_declaration() {}

public:
  std::vector<std::string> type;
  std::vector<variable_declaration *> declarations;
};

class constructor_declaration
{
public:
  constructor_declaration(const std::vector<std::pair<std::vector<std::string>, std::string>> &pars, const std::vector<std::pair<std::string, std::vector<expr *>>> &il, const std::vector<statement *> &stmnts) : parameters(pars), init_list(il), statements(stmnts) {}
  constructor_declaration(const constructor_declaration &orig) = delete;
  virtual ~constructor_declaration() {}

public:
  std::vector<std::pair<std::vector<std::string>, std::string>> parameters;
  std::vector<std::pair<std::string, std::vector<expr *>>> init_list;
  std::vector<statement *> statements;
};

class method_declaration
{
public:
  method_declaration(const std::vector<std::string> &rt, const std::string &n, const std::vector<std::pair<std::vector<std::string>, std::string>> &pars, const std::vector<statement *> &stmnts) : return_type(rt), name(n), parameters(pars), statements(stmnts) {}
  method_declaration(const method_declaration &orig) = delete;
  virtual ~method_declaration() {}

public:
  std::vector<std::string> return_type;
  std::string name;
  std::vector<std::pair<std::vector<std::string>, std::string>> parameters;
  std::vector<statement *> statements;
};

class predicate_declaration
{
public:
  predicate_declaration(const std::string &n, const std::vector<std::pair<std::vector<std::string>, std::string>> &pars, const std::vector<std::vector<std::string>> &pl, const std::vector<statement *> &stmnts) : name(n), parameters(pars), predicate_list(pl), statements(stmnts) {}
  predicate_declaration(const predicate_declaration &orig) = delete;
  virtual ~predicate_declaration() {}

public:
  std::string name;
  std::vector<std::pair<std::vector<std::string>, std::string>> parameters;
  std::vector<std::vector<std::string>> predicate_list;
  std::vector<statement *> statements;
};
}

class parser
{
public:
  parser(core &cr);
  parser(const parser &orig) = delete;
  virtual ~parser();

  void parse(std::istream &is);

private:
  token *next();
  bool match(const symbol &sym);
  void backtrack(const size_t &p);

  ast::typedef_declaration *_typedef_declaration();
  ast::enum_declaration *_enum_declaration();
  ast::class_declaration *_class_declaration();
  ast::field_declaration *_field_declaration();
  ast::method_declaration *_method_declaration();
  ast::constructor_declaration *_constructor_declaration();
  ast::predicate_declaration *_predicate_declaration();
  ast::statement *_statement();
  ast::expr *_expr(const size_t &pr = 0);

  void error(const std::string &err);

private:
  core &cr;
  lexer *lex = nullptr;     // the current lexer..
  token *tk = nullptr;      // the current lookahead token..
  std::vector<token *> tks; // all the tokens parsed so far..
  size_t pos = 0;           // the current position within 0tks'..
};
}