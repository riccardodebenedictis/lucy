#pragma once

#include "type.h"
#include "parser/ratioParser.h"

namespace lucy
{

class typedef_type : public type
{
  public:
	typedef_type(core &cr, scope &scp, std::string name, type &base_type, ratioParser::ExprContext &expr_c);
	typedef_type(const typedef_type &orig) = delete;
	virtual ~typedef_type();

	expr new_instance(context &ctx) override;

  private:
	type &base_type;
	ratioParser::ExprContext &expr_c;
};
}