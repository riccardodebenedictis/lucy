#include "env.h"
#include "core.h"
#include <cassert>

namespace lucy
{

env::env(core &cr, const context ctx) : ref_count(this == &cr ? 2 : 0), cr(cr), ctx(ctx) {}

env::~env() { assert(!ref_count || (this == &*ctx && ref_count)); }

expr env::get(const std::string &name) const
{
	if (items.find(name) != items.end())
	{
		return items.at(name);
	}

	// if not here, check any enclosing environment
	return ctx->get(name);
}
}