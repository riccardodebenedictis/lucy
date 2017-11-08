#include "super_flaw.h"
#include "atom_flaw.h"
#include "solver.h"
#include "cartesian_product.h"
#include "combinations.h"

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
void super_flaw::super_resolver::apply()
{
    bool is_super_unification = true;
    double preconditions_cost = -std::numeric_limits<double>::infinity();
    for (const auto &r : resolvers)
        if (atom_flaw::unify_atom *ua_res = dynamic_cast<atom_flaw::unify_atom *>(r))
        {
            if (preconditions_cost < ua_res->get_cost())
                preconditions_cost = ua_res->get_cost();
        }
        else
        {
            is_super_unification = false;
            break;
        }
    assert(!is_super_unification || preconditions_cost < std::numeric_limits<double>::infinity());

    if (is_super_unification)
        slv.set_est_cost(*this, preconditions_cost);
    else
    {
        std::vector<flaw *> all_precs;
        for (const auto &r : resolvers)
            for (const auto &pre : r->get_preconditions())
                all_precs.push_back(pre);

        if (all_precs.size() >= 2)
        {
            std::vector<std::vector<flaw *>> fss = combinations(std::vector<flaw *>(all_precs.begin(), all_precs.end()), 2);
            for (const auto &fs : fss) // we create a new super flaw..
                slv.new_flaw(*new super_flaw(slv, this, fs));
        }
        else // we create a new super flaw..
            slv.new_flaw(*new super_flaw(slv, this, std::vector<flaw *>(all_precs.begin(), all_precs.end())));
    }
}
}