#include "statement_visitor.h"

namespace lucy {

	statement_visitor::statement_visitor(core& cr, context& cntx) : cr(cr), cntx(cntx) {}

	statement_visitor::~statement_visitor() {}
}