#include "predicate.h"
#include "field.h"
#include "atom.h"

namespace lucy
{

predicate::predicate(core &cr, scope &scp, const std::string &name, const std::vector<field *> &args, const std::vector<ast::statement *> &stmnts) : type(cr, scp, name), args(args), statements(stmnts)
{
	if (type *t = dynamic_cast<type *>(&scp))
	{
		fields.insert({THIS_KEYWORD, new field(*t, THIS_KEYWORD, true)});
	}
	for (const auto &arg : args)
	{
		fields.insert({arg->name, arg});
	}
}

predicate::~predicate() {}

expr predicate::new_instance(context &ctx)
{
	atom *a = new atom(cr, ctx, *this);
	// we add the new atom to the instances of this predicate and to the instances of all the super-predicates..
	std::queue<predicate *> q;
	q.push(this);
	while (!q.empty())
	{
		q.front()->instances.push_back(a);
		for (const auto &st : q.front()->supertypes)
		{
			q.push(static_cast<predicate *>(st));
		}
		q.pop();
	}

	return expr(a);
}

bool predicate::apply_rule(atom &a) const
{
	for (const auto &sp : supertypes)
	{
		if (!static_cast<predicate *>(sp)->apply_rule(a))
		{
			return false;
		}
	}

	context ctx(new env(cr, &a));
	ctx->items.insert({THIS_KEYWORD, &a});
	for (const auto &s : statements)
	{
		if (!s->execute(*this, ctx))
			return false;
	}
	return true;
}
}