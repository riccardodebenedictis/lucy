#pragma once

#include "scope.h"

namespace lucy
{

namespace ast
{
class statement;
}

class context;
class item;

class DLL_PUBLIC constructor : public scope
{
  friend class type;

public:
  constructor(core &cr, scope &scp, const std::vector<field *> &args, const std::vector<ast::statement *> &stmnts);
  constructor(const constructor &orig) = delete;
  virtual ~constructor();

  expr new_instance(context &ctx, const std::vector<expr> &exprs);
  virtual bool invoke(item &i, const std::vector<expr> &exprs) = 0;

protected:
  const std::vector<field *> args;

private:
  std::vector<ast::statement *> statements;
};
}