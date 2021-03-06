#pragma once

#include "context.h"
#include <map>
#include <string>

namespace lucy
{

class core;

namespace ast
{
class assignment_statement;
class local_field_statement;
class formula_statement;
class return_statement;
}

class env
{
  friend class context;
  friend class core;
  friend class scope;
  friend class method;
  friend class predicate;
  friend class constructor;
  friend class var_item;
  friend class ast::assignment_statement;
  friend class ast::local_field_statement;
  friend class ast::formula_statement;
  friend class ast::return_statement;

public:
  env(core &cr, const context ctx);
  env(const env &orig) = delete;
  virtual ~env();

  core &get_core() const { return cr; }
  context get_ctx() const { return ctx; }

  virtual expr get(const std::string &name) const;
  std::map<std::string, expr> get_items() const noexcept { return items; }

private:
  unsigned ref_count;

protected:
  core &cr;

private:
  const context ctx;
  std::map<std::string, expr> items;
};
}