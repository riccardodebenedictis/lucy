#pragma once

#include "scope.h"

namespace lucy
{

class context;
class item;

class DLL_PUBLIC constructor : public scope
{
  friend class type;

public:
  constructor(core &cr, scope &scp, const std::vector<field *> &args);
  constructor(const constructor &orig) = delete;
  virtual ~constructor();

  expr new_instance(context &ctx, const std::vector<expr> &exprs);
  virtual bool invoke(item &i, const std::vector<expr> &exprs) = 0;

protected:
  const std::vector<field *> args;
};
}