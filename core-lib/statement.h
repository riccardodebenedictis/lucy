#pragma once

#include <vector>
#include <string>

namespace lucy
{

namespace ast
{

class expression;
class bool_expression;
class arith_expression;

class statement
{
public:
  statement();
  statement(const statement &orig) = delete;
  virtual ~statement();
};

class assignment_statement : public statement
{
public:
  assignment_statement(const std::vector<std::string> &q_id, expression *const e);
  assignment_statement(const assignment_statement &orig) = delete;
  virtual ~assignment_statement();

private:
  std::vector<std::string> qualified_id;
  expression *const xpr;
};

class local_field_statement : public statement
{
public:
  local_field_statement(const std::vector<std::string> &ft, const std::string &n, expression *const e = nullptr);
  local_field_statement(const local_field_statement &orig) = delete;
  virtual ~local_field_statement();

private:
  std::vector<std::string> field_type;
  std::string name;
  expression *const xpr;
};

class expression_statement : public statement
{
public:
  expression_statement(bool_expression *const e);
  expression_statement(const expression_statement &orig) = delete;
  virtual ~expression_statement();

private:
  bool_expression *const xpr;
};

class block_statement : public statement
{
public:
  block_statement(const std::vector<statement *> &stmnts);
  block_statement(const block_statement &orig) = delete;
  virtual ~block_statement();

private:
  std::vector<statement *> statements;
};

class disjunction_statement : public statement
{
public:
  disjunction_statement(const std::vector<block_statement *> &disjs);
  disjunction_statement(const disjunction_statement &orig) = delete;
  virtual ~disjunction_statement();

private:
  std::vector<block_statement *> disjunctions;
};

class formula_statement : public statement
{
public:
  formula_statement(const bool &isf, const std::string &fn, const std::vector<std::string> &scp, const std::string &pn, const std::vector<std::pair<std::string, expression *>> &assns);
  formula_statement(const formula_statement &orig) = delete;
  virtual ~formula_statement();

private:
  bool is_fact;
  std::string formula_name;
  std::vector<std::string> formula_scope;
  std::string predicate_name;
  std::vector<std::pair<std::string, expression *>> assignments;
};

class return_statement : public statement
{
public:
  return_statement(expression *const e);
  return_statement(const return_statement &orig) = delete;
  virtual ~return_statement();

private:
  expression *const xpr;
};
}
}