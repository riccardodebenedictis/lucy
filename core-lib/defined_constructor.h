#pragma once

#include "constructor.h"
#include "parser/ratioParser.h"

namespace lucy
{

class defined_constructor : public constructor
{
  public:
	defined_constructor(core &cr, scope &scp, const std::vector<field *> &args, std::vector<ratioParser::Initializer_elementContext *> init_els, ratioParser::BlockContext &b);
	defined_constructor(const defined_constructor &orig) = delete;
	virtual ~defined_constructor();

  private:
	std::vector<ratioParser::Initializer_elementContext *> init_els;
	ratioParser::BlockContext &block;

	bool invoke(item &i, const std::vector<expr> &exprs) override;
};
}