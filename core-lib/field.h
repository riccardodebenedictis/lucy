#pragma once

#include "visibility.h"
#include "expression.h"
#include <string>

namespace lucy
{

class type;
class context;
class expr;

#pragma warning(disable : 4251)
class DLL_PUBLIC field
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