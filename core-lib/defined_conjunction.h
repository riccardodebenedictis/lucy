#pragma once

#include "conjunction.h"
#include "parser/ratioParser.h"

namespace lucy
{

#pragma warning(disable : 4251)
class defined_conjunction : public conjunction
{
public:
  defined_conjunction(core &cr, scope &scp, const lin &cst, ratioParser::BlockContext &b);
  defined_conjunction(const defined_conjunction &orig) = delete;
  virtual ~defined_conjunction();

private:
  ratioParser::BlockContext &block;

  bool apply(context &ctx) const override;
};
}