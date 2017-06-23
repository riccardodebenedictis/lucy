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
class bool_expr;
class arith_expr;
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
  constructor_declaration(const std::vector<std::pair<type_ref *, std::string>> &pars, const std::vector<std::pair<std::string, std::vector<expr *>>> &il, const std::vector<statement *> &stmnts) : parameters(pars), init_list(il), statements(stmnts) {}
  constructor_declaration(const constructor_declaration &orig) = delete;
  virtual ~constructor_declaration() {}

public:
  std::vector<std::pair<type_ref *, std::string>> parameters;
  std::vector<std::pair<std::string, std::vector<expr *>>> init_list;
  std::vector<statement *> statements;
};

class method_declaration
{
public:
  method_declaration(type_ref *const rt, const std::string &n, const std::vector<std::pair<type_ref *, std::string>> &pars, const std::vector<statement *> &stmnts) : return_type(rt), name(n), parameters(pars), statements(stmnts) {}
  method_declaration(const method_declaration &orig) = delete;
  virtual ~method_declaration() {}

public:
  type_ref *const return_type;
  std::string name;
  std::vector<std::pair<type_ref *, std::string>> parameters;
  std::vector<statement *> statements;
};

class predicate_declaration
{
public:
  predicate_declaration(const std::string &n, const std::vector<std::pair<type_ref *, std::string>> &pars, const std::vector<type_ref *> &pl, const std::vector<statement *> &stmnts) : name(n), parameters(pars), predicate_list(pl), statements(stmnts) {}
  predicate_declaration(const predicate_declaration &orig) = delete;
  virtual ~predicate_declaration() {}

public:
  std::string name;
  std::vector<std::pair<type_ref *, std::string>> parameters;
  std::vector<type_ref *> predicate_list;
  std::vector<statement *> statements;
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

class statement
{
public:
  statement() {}
  statement(const statement &orig) = delete;
  virtual ~statement() {}
};

class assignment_statement : public statement
{
public:
  assignment_statement(const std::vector<std::string> &q_id, expr *const e) : qualified_id(q_id), xpr(e) {}
  assignment_statement(const assignment_statement &orig) = delete;
  virtual ~assignment_statement() {}

public:
  std::vector<std::string> qualified_id;
  expr *const xpr;
};

class local_field_statement : public statement
{
public:
  local_field_statement(type_ref *const rt, const std::string &n, expr *const e = nullptr) : field_type(rt), name(n), xpr(e) {}
  local_field_statement(const local_field_statement &orig) = delete;
  virtual ~local_field_statement() {}

public:
  type_ref *const field_type;
  std::string name;
  expr *const xpr;
};

class expression_statement : public statement
{
public:
  expression_statement(bool_expr *const e) : xpr(e) {}
  expression_statement(const expression_statement &orig) = delete;
  virtual ~expression_statement() {}

public:
  bool_expr *const xpr;
};

class block_statement : public statement
{
public:
  block_statement(const std::vector<statement *> &stmnts) : statements(stmnts) {}
  block_statement(const block_statement &orig) = delete;
  virtual ~block_statement() {}

public:
  std::vector<statement *> statements;
};

class disjunction_statement : public statement
{
public:
  disjunction_statement(const std::vector<block_statement *> &disjs) : disjunctions(disjs) {}
  disjunction_statement(const disjunction_statement &orig) = delete;
  virtual ~disjunction_statement() {}

public:
  std::vector<block_statement *> disjunctions;
};

class formula_statement : public statement
{
public:
  formula_statement(const bool &isf, const std::string &fn, const std::vector<std::string> &scp, const std::string &pn, const std::vector<std::pair<std::string, expr *>> &assns) : is_fact(isf), formula_name(fn), formula_scope(scp), predicate_name(pn), assignments(assns) {}
  formula_statement(const formula_statement &orig) = delete;
  virtual ~formula_statement() {}

public:
  bool is_fact;
  std::string formula_name;
  std::vector<std::string> formula_scope;
  std::string predicate_name;
  std::vector<std::pair<std::string, expr *>> assignments;
};

class return_statement : public statement
{
public:
  return_statement(expr *const e) : xpr(e) {}
  return_statement(const return_statement &orig) = delete;
  virtual ~return_statement() {}

public:
  expr *const xpr;
};

class cast_expr : public expr
{
public:
  cast_expr(type_ref *t, expr *const e) : cast_to_type(t), xpr(e) {}
  cast_expr(const cast_expr &orig) = delete;
  virtual ~cast_expr() {}

public:
  type_ref *cast_to_type;
  expr *xpr;
};

class constructor_expr : public expr
{
public:
  constructor_expr(type_ref *it, const std::vector<expr *> &es) : instance_type(it), exprs(es) {}
  constructor_expr(const constructor_expr &orig) = delete;
  virtual ~constructor_expr() {}

public:
  type_ref *instance_type;
  std::vector<expr *> exprs;
};

class id_expr : public expr
{
public:
  id_expr(const std::vector<std::string> &is) : ids(is) {}
  id_expr(const id_expr &orig) = delete;
  virtual ~id_expr() {}

public:
  std::vector<std::string> ids;
};

class string_literal_expr : public expr
{
public:
  string_literal_expr(const std::string &l) : literal(l) {}
  string_literal_expr(const string_literal_expr &orig) = delete;
  virtual ~string_literal_expr() {}

public:
  std::string literal;
};

class bool_expr : public expr
{
public:
  bool_expr() {}
  bool_expr(const bool_expr &orig) = delete;
  virtual ~bool_expr() {}
};

class bool_literal_expr : public bool_expr
{
public:
  bool_literal_expr(const bool &l) : literal(l) {}
  bool_literal_expr(const bool_literal_expr &orig) = delete;
  virtual ~bool_literal_expr() {}

public:
  bool literal;
};

class eq_expr : public bool_expr
{
public:
  eq_expr(expr *const l, expr *const r) : left(l), right(r) {}
  eq_expr(const eq_expr &orig) = delete;
  virtual ~eq_expr() {}

public:
  expr *left;
  expr *right;
};

class neq_expr : public bool_expr
{
public:
  neq_expr(expr *const l, expr *const r) : left(l), right(r) {}
  neq_expr(const neq_expr &orig) = delete;
  virtual ~neq_expr() {}

public:
  expr *left;
  expr *right;
};

class lt_expr : public bool_expr
{
public:
  lt_expr(arith_expr *const l, arith_expr *const r) : left(l), right(r) {}
  lt_expr(const lt_expr &orig) = delete;
  virtual ~lt_expr() {}

public:
  arith_expr *left;
  arith_expr *right;
};

class leq_expr : public bool_expr
{
public:
  leq_expr(arith_expr *const l, arith_expr *const r) : left(l), right(r) {}
  leq_expr(const leq_expr &orig) = delete;
  virtual ~leq_expr() {}

public:
  arith_expr *left;
  arith_expr *right;
};

class geq_expr : public bool_expr
{
public:
  geq_expr(arith_expr *const l, arith_expr *const r) : left(l), right(r) {}
  geq_expr(const geq_expr &orig) = delete;
  virtual ~geq_expr() {}

public:
  arith_expr *left;
  arith_expr *right;
};

class gt_expr : public bool_expr
{
public:
  gt_expr(arith_expr *const l, arith_expr *const r) : left(l), right(r) {}
  gt_expr(const gt_expr &orig) = delete;
  virtual ~gt_expr() {}

public:
  arith_expr *left;
  arith_expr *right;
};

class implication_expr : public bool_expr
{
public:
  implication_expr(bool_expr *const l, bool_expr *const r) : left(l), right(r) {}
  implication_expr(const implication_expr &orig) = delete;
  virtual ~implication_expr() {}

public:
  bool_expr *left;
  bool_expr *right;
};

class disjunction_expr : public bool_expr
{
public:
  disjunction_expr(std::vector<bool_expr *> es) : exprs(es) {}
  disjunction_expr(const disjunction_expr &orig) = delete;
  virtual ~disjunction_expr() {}

public:
  std::vector<bool_expr *> exprs;
};

class conjunction_expr : public bool_expr
{
public:
  conjunction_expr(std::vector<bool_expr *> es) : exprs(es) {}
  conjunction_expr(const conjunction_expr &orig) = delete;
  virtual ~conjunction_expr() {}

public:
  std::vector<bool_expr *> exprs;
};

class exct_one_expr : public bool_expr
{
public:
  exct_one_expr(std::vector<bool_expr *> es) : exprs(es) {}
  exct_one_expr(const exct_one_expr &orig) = delete;
  virtual ~exct_one_expr() {}

public:
  std::vector<bool_expr *> exprs;
};

class not_expr : public bool_expr
{
public:
  not_expr(bool_expr *const e) : xpr(e) {}
  not_expr(const not_expr &orig) = delete;
  virtual ~not_expr() {}

public:
  bool_expr *xpr;
};

class arith_expr : public expr
{
public:
  arith_expr() {}
  arith_expr(const arith_expr &orig) = delete;
  virtual ~arith_expr() {}
};

class arith_literal_expr : public arith_expr
{
public:
  arith_literal_expr(const double &l) : literal(l) {}
  arith_literal_expr(const arith_literal_expr &orig) = delete;
  virtual ~arith_literal_expr() {}

public:
  double literal;
};

class plus_expr : public arith_expr
{
public:
  plus_expr(arith_expr *const e) : xpr(e) {}
  plus_expr(const plus_expr &orig) = delete;
  virtual ~plus_expr() {}

public:
  arith_expr *xpr;
};

class minus_expr : public arith_expr
{
public:
  minus_expr(arith_expr *const e) : xpr(e) {}
  minus_expr(const minus_expr &orig) = delete;
  virtual ~minus_expr() {}

public:
  arith_expr *xpr;
};

class range_expr : public arith_expr
{
public:
  range_expr(arith_expr *const min_e, arith_expr *const max_e) : min_xpr(min_e), max_xpr(max_e) {}
  range_expr(const range_expr &orig) = delete;
  virtual ~range_expr() {}

public:
  arith_expr *min_xpr;
  arith_expr *max_xpr;
};

class addition_expr : public arith_expr
{
public:
  addition_expr(std::vector<arith_expr *> es) : exprs(es) {}
  addition_expr(const addition_expr &orig) = delete;
  virtual ~addition_expr() {}

public:
  std::vector<arith_expr *> exprs;
};

class subtraction_expr : public arith_expr
{
public:
  subtraction_expr(std::vector<arith_expr *> es) : exprs(es) {}
  subtraction_expr(const subtraction_expr &orig) = delete;
  virtual ~subtraction_expr() {}

public:
  std::vector<arith_expr *> exprs;
};

class multiplication_expr : public arith_expr
{
public:
  multiplication_expr(std::vector<arith_expr *> es) : exprs(es) {}
  multiplication_expr(const multiplication_expr &orig) = delete;
  virtual ~multiplication_expr() {}

public:
  std::vector<arith_expr *> exprs;
};

class division_expr : public arith_expr
{
public:
  division_expr(std::vector<arith_expr *> es) : exprs(es) {}
  division_expr(const division_expr &orig) = delete;
  virtual ~division_expr() {}

public:
  std::vector<arith_expr *> exprs;
};
}

class parser
{
public:
  parser();
  parser(const parser &orig) = delete;
  virtual ~parser();

  ast::compilation_unit *parse(std::istream &is); // generates an abstract syntax tree (ast) for the input stream..

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
  ast::type_ref *_type_ref();

  void error(const std::string &err);

private:
  lexer *lex = nullptr;                     // the current lexer..
  token *tk = nullptr;                      // the current lookahead token..
  std::vector<token *> tks;                 // all the tokens parsed so far..
  size_t pos = 0;                           // the current position within 0tks'..
  std::vector<ast::compilation_unit *> cus; // all the compilation units..
};
}