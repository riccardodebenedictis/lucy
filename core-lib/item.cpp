#include "item.h"
#include "core.h"
#include "type.h"
#include "field.h"
#include "set_theory.h"
#include <cassert>

namespace lucy
{

item::item(core &cr, const context ctx, const type &tp) : env(cr, ctx), tp(tp) {}

item::~item() {}

var item::eq(item &i) noexcept
{
	if (this == &i)
		return TRUE_var;
	else if (enum_item *ei = dynamic_cast<enum_item *>(&i))
		return ei->eq(*this);
	else
	{
		std::vector<lit> eqs;
		std::queue<const type *> q;
		q.push(&tp);
		while (!q.empty())
		{
			for (const auto &f : q.front()->get_fields())
				if (!f.second->synthetic)
					eqs.push_back(get(f.first)->eq(*i.get(f.first)));
			for (const auto &st : q.front()->get_supertypes())
				q.push(st);
			q.pop();
		}

		if (eqs.empty())
			return TRUE_var;
		else if (eqs.size() == 1)
			return eqs.begin()->v;
		else
			return cr.sat.new_conj(eqs);
	}
}

bool item::equates(const item &i) const noexcept
{
	if (this == &i)
		return true;
	else if (const enum_item *ei = dynamic_cast<const enum_item *>(&i))
		return ei->equates(*this);
	else
	{
		std::queue<const type *> q;
		q.push(&tp);
		while (!q.empty())
		{
			for (const auto &f : q.front()->get_fields())
				if (!f.second->synthetic)
					if (!get(f.first)->equates(*i.get(f.first)))
						return false;
			for (const auto &st : q.front()->get_supertypes())
				q.push(st);
			q.pop();
		}
		return true;
	}
}

bool_item::bool_item(core &cr, const lit &l) : item(cr, &cr, cr.get_type(BOOL_KEYWORD)), l(l) {}
bool_item::~bool_item() {}

var bool_item::eq(item &i) noexcept
{
	if (this == &i)
		return TRUE_var;
	else if (bool_item *be = dynamic_cast<bool_item *>(&i))
		return cr.sat.new_eq(l, be->l);
	else
		return FALSE_var;
}

bool bool_item::equates(const item &i) const noexcept
{
	if (this == &i)
		return true;
	else if (const bool_item *be = dynamic_cast<const bool_item *>(&i))
	{
		lbool c_val = cr.sat.value(l);
		lbool i_val = cr.sat.value(be->l);
		return c_val == i_val || c_val == Undefined || i_val == Undefined;
	}
	else
		return false;
}

arith_item::arith_item(core &cr, const type &t, const lin &l) : item(cr, &cr, t), l(l) { assert(&t == &cr.get_type(INT_KEYWORD) || &t == &cr.get_type(REAL_KEYWORD)); }
arith_item::~arith_item() {}

var arith_item::eq(item &i) noexcept
{
	if (this == &i)
		return TRUE_var;
	else if (arith_item *ae = dynamic_cast<arith_item *>(&i))
		return cr.sat.new_conj({cr.la_th.new_leq(l, ae->l), cr.la_th.new_geq(l, ae->l)});
	else
		return FALSE_var;
}

bool arith_item::equates(const item &i) const noexcept
{
	if (this == &i)
		return true;
	else if (const arith_item *ae = dynamic_cast<const arith_item *>(&i))
	{
		interval c_val = cr.la_th.bounds(l);
		interval i_val = cr.la_th.bounds(ae->l);
		return c_val.intersecting(i_val);
	}
	else
		return false;
}

string_item::string_item(core &cr, const std::string &l) : item(cr, &cr, cr.get_type(STRING_KEYWORD)), l(l) {}
string_item::~string_item() {}

var string_item::eq(item &i) noexcept
{
	if (this == &i)
		return TRUE_var;
	else if (string_item *se = dynamic_cast<string_item *>(&i))
		return l.compare(se->l) == 0 ? TRUE_var : FALSE_var;
	else
		return FALSE_var;
}

bool string_item::equates(const item &i) const noexcept
{
	if (this == &i)
		return true;
	else if (const string_item *se = dynamic_cast<const string_item *>(&i))
		return l.compare(se->l) == 0;
	else
		return false;
}

enum_item::enum_item(core &cr, const type &t, var ev) : item(cr, &cr, t), ev(ev) {}
enum_item::~enum_item() {}

expr enum_item::get(const std::string &name) const
{
	if (items.find(name) == items.end())
	{
		std::unordered_set<set_item *> vs = cr.set_th.value(ev);
		if (vs.size() == 1)
			return (static_cast<item *>(*vs.begin()))->get(name);
		else
		{
			std::vector<item *> c_vals;
			std::vector<item *> f_vals;
			for (const auto &val : vs)
			{
				c_vals.push_back(static_cast<item *>(val));
				f_vals.push_back(&*static_cast<item *>(val)->get(name));
				if (dynamic_cast<enum_item *>(f_vals.back()))
					std::unexpected();
			}

			std::unordered_set<item *> vals;
			for (unsigned int i = 0; i < c_vals.size(); i++)
				vals.insert(f_vals[i]);
			enum_expr e = cr.new_enum(tp.get_field(name).tp, vals);

			for (unsigned int i = 0; i < c_vals.size(); i++)
			{
				bool af = cr.sat.eq(cr.set_th.allows(ev, *c_vals[i]), cr.set_th.allows(e->ev, *f_vals[i]));
				assert(af);
			}

			const_cast<enum_item *>(this)->items.insert({name, e});
		}
	}

	return items.at(name);
}

var enum_item::eq(item &i) noexcept
{
	if (this == &i)
		return TRUE_var;
	else if (enum_item *ee = dynamic_cast<enum_item *>(&i))
		return cr.set_th.eq(ev, ee->ev);
	else
		return cr.set_th.allows(ev, i);
}

bool enum_item::equates(const item &i) const noexcept
{
	if (this == &i)
		return true;
	else if (const enum_item *ei = dynamic_cast<const enum_item *>(&i))
	{
		std::unordered_set<set_item *> c_vals = cr.set_th.value(ev);
		std::unordered_set<set_item *> i_vals = cr.set_th.value(ei->ev);
		for (const auto &c_v : c_vals)
			if (i_vals.find(c_v) != i_vals.end())
				return true;
		return false;
	}
	else
	{
		std::unordered_set<set_item *> c_vals = cr.set_th.value(ev);
		return c_vals.find(const_cast<set_item *>(static_cast<const set_item *>(&i))) != c_vals.end();
	}
}
}