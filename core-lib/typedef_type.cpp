#include "typedef_type.h"
#include "context.h"
#include "item.h"
#include "core.h"
#include "expression_visitor.h"

namespace lucy {

	typedef_type::typedef_type(core& cr, scope& scp, std::string name, type& base_type, ratioParser::ExprContext& expr_c) : type(cr, scp, name), base_type(base_type), expr_c(expr_c) { }

	typedef_type::~typedef_type() { }

	expr typedef_type::new_instance(context& ctx) {
		expr i = base_type.new_instance(ctx);
		expr c_e = expression_visitor(cr, ctx).visit(&expr_c).as<expr>();
		bool assert_facts = cr.sat.new_clause({ lit(i->eq(*c_e), true) });
		assert(assert_facts && "new typedef instance creation failed..");
		return i;
	}
}