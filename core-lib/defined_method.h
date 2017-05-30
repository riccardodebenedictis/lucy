#pragma once

#include "method.h"
#include "parser/ratioParser.h"

namespace lucy
{

#pragma warning(disable : 4251)
class defined_method : public method
{
public:
  defined_method(core &cr, scope &scp, const std::string &name, const std::vector<field *> &args, ratioParser::BlockContext &b, const type *const return_type = nullptr);
  defined_method(const defined_method &orig) = delete;
  virtual ~defined_method();

private:
  ratioParser::BlockContext &block;

  bool invoke(context &ctx, const std::vector<expr> &exprs) override;
};
}