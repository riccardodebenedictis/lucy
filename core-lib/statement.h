#pragma once

#include <vector>
#include <string>

namespace lucy
{

class scope;
class context;

namespace ast
{

class expression;

class statement
{
public:
  statement();
  statement(const statement &orig) = delete;
  virtual ~statement();

  virtual void execute(const scope &scp, context &ctx) const = 0;
};

class assignment_statement : public statement
{
public:
  assignment_statement(const std::vector<std::string> &is, const std::string &i, const expression *const e);
  assignment_statement(const assignment_statement &orig) = delete;
  virtual ~assignment_statement();

  void execute(const scope &scp, context &ctx) const override;

private:
  const std::vector<std::string> ids;
  const std::string id;
  const expression *const xpr;
};

class local_field_statement : public statement
{
public:
  local_field_statement(const std::vector<std::string> &ft, const std::string &n, const expression *const e = nullptr);
  local_field_statement(const local_field_statement &orig) = delete;
  virtual ~local_field_statement();

  void execute(const scope &scp, context &ctx) const override;

private:
  const std::vector<std::string> field_type;
  const std::string name;
  const expression *const xpr;
};

class expression_statement : public statement
{
public:
  expression_statement(const expression *const e);
  expression_statement(const expression_statement &orig) = delete;
  virtual ~expression_statement();

  void execute(const scope &scp, context &ctx) const override;

private:
  const expression *const xpr;
};

class block_statement : public statement
{
public:
  block_statement(const std::vector<const statement *> &stmnts);
  block_statement(const block_statement &orig) = delete;
  virtual ~block_statement();

  void execute(const scope &scp, context &ctx) const override;

private:
  const std::vector<const statement *> statements;
};

class disjunction_statement : public statement
{
public:
  disjunction_statement(const std::vector<std::pair<std::vector<const statement *>, const expression *const>> &conjs);
  disjunction_statement(const disjunction_statement &orig) = delete;
  virtual ~disjunction_statement();

  void execute(const scope &scp, context &ctx) const override;

private:
  const std::vector<std::pair<std::vector<const statement *>, const expression *const>> conjunctions;
};

class formula_statement : public statement
{
public:
  formula_statement(const bool &isf, const std::string &fn, const std::vector<std::string> &scp, const std::string &pn, const std::vector<std::pair<std::string, const expression *>> &assns);
  formula_statement(const formula_statement &orig) = delete;
  virtual ~formula_statement();

  void execute(const scope &scp, context &ctx) const override;

private:
  const bool is_fact;
  const std::string formula_name;
  const std::vector<std::string> formula_scope;
  const std::string predicate_name;
  const std::vector<std::pair<std::string, const expression *>> assignments;
};

class return_statement : public statement
{
public:
  return_statement(const expression *const e);
  return_statement(const return_statement &orig) = delete;
  virtual ~return_statement();

  void execute(const scope &scp, context &ctx) const override;

private:
  const expression *const xpr;
};
}
}