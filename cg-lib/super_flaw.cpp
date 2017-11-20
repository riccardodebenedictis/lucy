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
    std::vector<std::vector<resolver *>> rs;
    for (const auto &f : flaws)
        rs.push_back(f->get_resolvers());
    for (const auto &rp : cartesian_product(rs))
    {
        // the resolver's cost is given by the maximum of the enclosing resolvers' costs..
        lin cst(rational::NEGATIVE_INFINITY);
        std::vector<lit> vs;
        for (const auto &r : rp)
        {
            if (slv.la_th.value(cst) < slv.la_th.value(r->get_intrinsic_cost()))
                cst = r->get_intrinsic_cost();
            vs.push_back(r->get_rho());
        }
        add_resolver(*new super_resolver(slv, *this, slv.sat_cr.new_conj(vs), cst, rp));
    }
}

super_flaw::super_resolver::super_resolver(solver &slv, super_flaw &s_flaw, const var &app_r, const lin &c, const std::vector<resolver *> &rs) : resolver(slv, app_r, c, s_flaw), resolvers(rs) {}
super_flaw::super_resolver::~super_resolver() {}
void super_flaw::super_resolver::apply()
{
    // all the resolver's preconditions..
    std::vector<flaw *> precs;
    for (const auto &r : resolvers)
        for (const auto &pre : r->get_preconditions())
            precs.push_back(pre);

    // we check whether we might have an estimated solution thanks to this resolver..
    if (precs.empty() && slv.sat_cr.value(rho) != False)
    {
        std::vector<lit> res_vars;
        res_vars.push_back(rho);
        std::queue<const flaw *> q;
        q.push(&effect);
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
        if (slv.sat_cr.check(res_vars))                                            // we check whether the resolver can be actually applied..
            slv.set_est_cost(*this, 0);                                            // it can! we have an estimated solution for this resolver..
        else if (!slv.sat_cr.new_clause({lit(rho, false)}) || !slv.sat_cr.check()) // it can't! we set its rho variable to false..
            throw unsolvable_exception();
    }
    else if (precs.size() > slv.accuracy) // we create sets having the size of the accuracy..
    {
        std::vector<std::vector<flaw *>> fss = combinations(std::vector<flaw *>(precs.begin(), precs.end()), slv.accuracy);
        for (const auto &fs : fss) // we create a new super flaw..
            slv.new_flaw(*new super_flaw(slv, this, fs));
    }
    else // we create a new super flaw including all the preconditions of this resolver..
        slv.new_flaw(*new super_flaw(slv, this, std::vector<flaw *>(precs.begin(), precs.end())));
}
}