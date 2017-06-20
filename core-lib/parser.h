#pragma once

#include "lexer.h"
#include <vector>

namespace lucy
{

namespace ast
{
class compilation_unit;
class type_declaration;
class method_declaration;
class predicate_declaration;
class field_declaration;
class constructor_declaration;
class method_declaration;
class predicate_declaration;
class statement;
class expr;
class type_ref;

class compilation_unit
{
public:
  compilation_unit(const std::vector<type_declaration *> &ts, const std::vector<method_declaration *> &ms, const std::vector<predicate_declaration *> &ps, const std::vector<statement *> &ss) : types(ts), methods(ms), predicates(ps), statements(ss) {}
  compilation_unit(const compilation_unit &orig) = delete;
  virtual ~compilation_unit() {}

public:
  std::vector<type_declaration *> types;
  std::vector<method_declaration *> methods;
  std::vector<predicate_declaration *> predicates;
  std::vector<statement *> statements;
};

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
  enum_declaration(const std::string &n, const std::vector<std::string> &es, const std::vector<type_ref *> &trs) : type_declaration(n), enums(es), type_refs(trs) {}
  enum_declaration(const enum_declaration &orig) = delete;
  virtual ~enum_declaration() {}

public:
  std::vector<std::string> enums;
  std::vector<type_ref *> type_refs;
};

class class_declaration : public type_declaration
{
public:
  class_declaration(const std::string &n, const std::vector<type_ref *> &bcs, const std::vector<field_declaration *> &fs, const std::vector<constructor_declaration *> &cs, const std::vector<method_declaration *> &ms, const std::vector<predicate_declaration *> &ps, const std::vector<type_declaration *> &ts) : type_declaration(n), base_classes(bcs), fields(fs), constructors(cs), methods(ms), predicates(ps), types(ts) {}
  class_declaration(const class_declaration &orig) = delete;
  virtual ~class_declaration() {}

public:
  std::vector<type_ref *> base_classes;
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
  field_declaration(type_ref *const tp, const std::vector<variable_declaration *> &ds) : type(tp), declarations(ds) {}
  field_declaration(const class_declaration &orig) = delete;
  virtual ~field_declaration() {}

public:
  type_ref *const type;
  std::vector<variable_declaration *> declarations;
};

class constructor_declaration
{
public:
  constructor_declaration() {}
  constructor_declaration(const constructor_declaration &orig) = delete;
  virtual ~constructor_declaration() {}
};

class method_declaration
{
public:
  method_declaration() {}
  method_declaration(const method_declaration &orig) = delete;
  virtual ~method_declaration() {}
};

class predicate_declaration
{
public:
  predicate_declaration() {}
  predicate_declaration(const predicate_declaration &orig) = delete;
  virtual ~predicate_declaration() {}
};

class type_ref
{
public:
  type_ref(const std::vector<std::string> &ids) : ids(ids) {}
  type_ref(const type_ref &orig) = delete;
  virtual ~type_ref() {}

public:
  std::vector<std::string> ids;
};

class expr
{
public:
  expr() {}
  expr(const expr &orig) = delete;
  virtual ~expr() {}
};
}

class parser
{
public:
  parser();
  parser(const parser &orig) = delete;
  virtual ~parser();

  ast::compilation_unit *parse(std::istream &is);

private:
  token *next();
  bool match(const symbol &sym);
  void backtrack(const size_t &p);

  ast::typedef_declaration *_typedef_declaration();
  ast::enum_declaration *_enum_declaration();
  ast::class_declaration *_class_declaration();
  ast::expr *_expr(const size_t &pr = 0);
  ast::type_ref *_type_ref();

  void error(const std::string &err);

private:
  lexer *lex = nullptr;
  token *tk = nullptr;
  std::vector<token *> tks;
  size_t pos = 0;
  std::vector<ast::compilation_unit *> cus;
};
}