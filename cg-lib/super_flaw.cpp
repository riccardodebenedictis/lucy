#include "super_flaw.h"
#include "solver.h"
#include "cartesian_product.h"

namespace cg
{

inline const std::vector<resolver *> get_cause(resolver *const cause)
{
    if (cause)
        return {cause};
    else
        return {};
}

super_flaw::super_flaw(solver &slv, resolver *const cause, const std::vector<flaw *> &fs) : flaw(slv, get_cause(cause)), flaws(fs) {}
super_flaw::~super_flaw() {}

void super_flaw::compute_resolvers()
{
    std::vector<lit> res_vars;
    std::queue<const flaw *> q;
    q.push(this);
    while (!q.empty())
    {
        for (const auto &c : q.front()->get_causes())
            if (slv.sat_cr.value(c->get_rho()) != False) // if false, the edge is broken..
            {
                res_vars.push_back(c->get_rho());
                q.push(&c->get_effect()); // we push its effect..
            }
        q.pop();
    }

    std::vector<std::vector<resolver *>> rs;
    for (const auto &f : flaws)
        rs.push_back(f->get_resolvers());
    for (const auto &rp : cartesian_product(rs))
    {
        lin cst;
        std::vector<lit> vs;
        for (const auto &r : rp)
        {
            cst += r->get_intrinsic_cost();
            vs.push_back(r->get_rho());
        }
        var res_var = slv.sat_cr.new_conj(vs);
        res_vars.push_back(res_var);
        if (slv.sat_cr.check(res_vars))
            add_resolver(*new super_resolver(slv, *this, res_var, cst, rp));
        res_vars.pop_back();
    }
}

super_flaw::super_resolver::super_resolver(solver &slv, super_flaw &s_flaw, const var &app_r, const lin &c, const std::vector<resolver *> &rs) : resolver(slv, app_r, c, s_flaw), resolvers(rs) {}
super_flaw::super_resolver::~super_resolver() {}
void super_flaw::super_resolver::apply() {}
}