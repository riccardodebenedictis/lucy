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

super_flaw::super_flaw(solver &slv, resolver *const cause, const std::vector<flaw *> &fs) : flaw(slv, get_cause(cause)), flaws(fs)
{
    std::set<flaw *> c_fs(fs.begin(), fs.end());
    assert(slv.super_flaws.find(c_fs) == slv.super_flaws.end());
    slv.super_flaws.insert({c_fs, this});
}
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
        var res_var = slv.sat_cr.new_conj(vs);
        if (slv.sat_cr.value(res_var) != False)
            add_resolver(*new super_resolver(slv, *this, res_var, cst, rp));
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

    if (precs.size() > slv.accuracy) // we create sets having the size of the accuracy..
    {
        std::vector<std::vector<flaw *>> fss = combinations(std::vector<flaw *>(precs.begin(), precs.end()), slv.accuracy);
        for (const auto &fs : fss) // we create a new super flaw for each of the possible combinations..
        {
            std::set<flaw *> c_fs(fs.begin(), fs.end());
            const auto &at_sf = slv.super_flaws.find(c_fs);
            if (at_sf != slv.super_flaws.end())
            {
                slv.new_causal_link(*at_sf->second, *this);
                slv.set_est_cost(*this, at_sf->second->get_cost());
            }
            else
                slv.new_flaw(*new super_flaw(slv, this, fs));
        }
    }
    else if (!precs.empty()) // we create a new super flaw including all the preconditions of this resolver..
    {
        std::set<flaw *> c_fs(precs.begin(), precs.end());
        const auto &at_sf = slv.super_flaws.find(c_fs);
        if (at_sf != slv.super_flaws.end())
        {
            slv.new_causal_link(*at_sf->second, *this);
            slv.set_est_cost(*this, at_sf->second->get_cost());
        }
        else
            slv.new_flaw(*new super_flaw(slv, this, precs));
    }
}
}