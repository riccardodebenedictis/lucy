#pragma once

#include "predicate.h"
#include "parser/ratioParser.h"

namespace lucy
{

class defined_predicate : public predicate
{
public:
  defined_predicate(core &cr, scope &scp, const std::string &name, const std::vector<field *> &args, ratioParser::BlockContext &b);
  defined_predicate(const defined_predicate &orig) = delete;
  virtual ~defined_predicate();

private:
  ratioParser::BlockContext &block;

  bool apply_rule(atom &a) const override;
};
}