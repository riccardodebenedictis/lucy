#pragma once

#include "expression.h"
#include <string>

namespace lucy
{

class type;
class context;
class expr;

class field
{
public:
  field(const type &tp, const std::string &name, const ast::expression *const e = nullptr, bool synthetic = false);
  virtual ~field();

public:
  const type &tp;
  const std::string name;
  const ast::expression *const xpr;
  const bool synthetic;
};
}