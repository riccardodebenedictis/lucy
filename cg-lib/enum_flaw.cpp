#include "enum_flaw.h"
#include "solver.h"

namespace cg
{

enum_flaw::enum_flaw(solver &slv, resolver *const cause, var_item &e_itm) : flaw(slv, {cause}, true, true), e_itm(e_itm) {}
enum_flaw::~enum_flaw() {}

void enum_flaw::compute_resolvers()
{
    std::unordered_set<var_value *> vals = slv.ov_th.value(e_itm.ev);
    for (const auto &v : vals)
        add_resolver(*new choose_value(slv, *this, *v));
}

enum_flaw::choose_value::choose_value(solver &slv, enum_flaw &enm_flaw, var_value &val) : resolver(slv, slv.ov_th.allows(enm_flaw.e_itm.ev, val), lin(1.0 / slv.ov_th.value(enm_flaw.e_itm.ev).size()), enm_flaw), v(enm_flaw.e_itm.ev), val(val) {}
enum_flaw::choose_value::~choose_value() {}
void enum_flaw::choose_value::apply() {}
}