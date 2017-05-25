#include "enum_flaw.h"
#include "causal_graph.h"

namespace cg
{

enum_flaw::enum_flaw(causal_graph &graph, enum_item &e_itm) : flaw(graph, true), e_itm(e_itm) {}

enum_flaw::~enum_flaw() {}

void enum_flaw::compute_resolvers()
{
	std::unordered_set<set_item *> vals = graph.set_th.value(e_itm.ev);
	for (const auto &v : vals)
	{
		add_resolver(*new choose_value(graph, *this, *v));
	}
}

enum_flaw::choose_value::choose_value(causal_graph &graph, enum_flaw &enm_flaw, set_item &val) : resolver(graph, lin(1.0 / graph.set_th.value(enm_flaw.e_itm.ev).size()), enm_flaw), v(enm_flaw.e_itm.ev), val(val) {}

enum_flaw::choose_value::~choose_value() {}

bool enum_flaw::choose_value::apply()
{
	return graph.core::sat.new_clause({lit(chosen, false), lit(graph.set_th.allows(v, val), true)});
}
}