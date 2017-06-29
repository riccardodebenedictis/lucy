#pragma once

#include "item.h"

namespace lucy
{

class predicate;

class atom : public item
{
public:
  atom(core &cr, const context ctx, const predicate &pred);
  atom(const atom &orig) = delete;
  virtual ~atom();

public:
  const var state;
};
}