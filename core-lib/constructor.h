#pragma once

#include "scope.h"
#include "expression.h"
#include "statement.h"

namespace lucy
{

class context;
class item;

class DLL_PUBLIC constructor : public scope
{
  friend class type;

public:
  constructor(core &cr, scope &scp, const std::vector<field *> &args, const std::vector<std::pair<std::string, std::vector<ast::expression *>>> &il, const std::vector<ast::statement *> &stmnts);
  constructor(const constructor &orig) = delete;
  virtual ~constructor();

  expr new_instance(context &ctx, const std::vector<expr> &exprs);

private:
  bool invoke(item &i, const std::vector<expr> &exprs);

protected:
  const std::vector<field *> args;

private:
  const std::vector<std::pair<std::string, std::vector<ast::expression *>>> init_list;
  const std::vector<ast::statement *> statements;
};
}