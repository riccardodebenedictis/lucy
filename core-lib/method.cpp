#include "method.h"
#include "type.h"
#include "field.h"
#include "env.h"
#include <cassert>

namespace lucy
{

method::method(core &cr, scope &scp, const type *const return_type, const std::string &name, const std::vector<field *> &args, const std::vector<ast::statement *> &stmnts) : scope(cr, scp), return_type(return_type), name(name), args(args), statements(stmnts)
{
	if (type *t = dynamic_cast<type *>(&scp))
	{
		fields.insert({THIS_KEYWORD, new field(*t, THIS_KEYWORD, true)});
	}
	if (return_type)
	{
		fields.insert({RETURN_KEYWORD, new field(*return_type, RETURN_KEYWORD, true)});
	}
	for (const auto &arg : args)
	{
		fields.insert({arg->name, arg});
	}
}

method::~method() {}

bool method::invoke(context &ctx, const std::vector<expr> &exprs)
{
	assert(args.size() == exprs.size());
	context c_ctx(new env(cr, ctx));
	for (size_t i = 0; i < args.size(); i++)
	{
		c_ctx->items.insert({args[i]->name, exprs[i]});
	}

	for (const auto &s : statements)
	{
		if (!s->execute(c_ctx))
			return false;
	}
	return true;
}
}