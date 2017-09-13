#include "set_theory.h"
#include "sat_core.h"
#include "set_listener.h"
#include <cassert>
#include <algorithm>

namespace smt
{

set_theory::set_theory(sat_core &sat) : theory(sat) {}

set_theory::~set_theory() {}

var set_theory::new_var(const std::unordered_set<set_item *> &items)
{
    assert(!items.empty());
    var id = assigns.size();
    assigns.push_back(std::unordered_map<set_item *, var>());
    if (items.size() == 1)
        assigns.back().insert({*items.begin(), TRUE_var});
    else
    {
        std::vector<lit> lits;
        for (const auto &i : items)
        {
            var bv = sat.new_var();
            assigns.back().insert({i, bv});
            lits.push_back(bv);
            bind(bv);
            is_contained_in.insert({bv, id});
        }
        bool eo = sat.exct_one(lits);
        assert(eo);
    }
    return id;
}

var set_theory::allows(const var &left, set_item &right) const
{
    if (assigns[left].find(&right) != assigns[left].end())
        return assigns[left].at(&right);
    else
        return FALSE_var;
}

var set_theory::eq(const var &left, const var &right)
{
    if (left == right)
        return TRUE_var;

    if (left > right)
        return eq(right, left);

    std::string s_expr = "e" + std::to_string(left) + " == " + "e" + std::to_string(right);
    if (exprs.find(s_expr) != exprs.end()) // the expression already exists..
        return exprs.at(s_expr);
    else
    {
        std::unordered_set<set_item *> intersection;
        for (const auto &v : assigns[left])
            if (assigns[right].find(v.first) != assigns[right].end())
                intersection.insert(v.first);

        if (intersection.empty())
            return FALSE_var;

        // we need to create a new variable..
        var e = sat.new_var();
        bool nc;
        for (const auto &v : assigns[left])
        {
            if (intersection.find(v.first) == intersection.end())
            {
                nc = sat.new_clause({lit(e, false), lit(v.second, false)});
                assert(nc);
            }
        }
        for (const auto &v : assigns[right])
        {
            if (intersection.find(v.first) == intersection.end())
            {
                nc = sat.new_clause({lit(e, false), lit(v.second, false)});
                assert(nc);
            }
        }
        for (const auto &v : intersection)
        {
            nc = sat.new_clause({lit(e, false), lit(assigns[left].at(v), false), assigns[right].at(v)});
            assert(nc);
            nc = sat.new_clause({lit(e, false), assigns[left].at(v), lit(assigns[right].at(v), false)});
            assert(nc);
            nc = sat.new_clause({e, lit(assigns[left].at(v), false), lit(assigns[right].at(v), false)});
            assert(nc);
        }
        exprs.insert({s_expr, e});
        return e;
    }
}

std::unordered_set<set_item *> set_theory::value(var v) const
{
    std::unordered_set<set_item *> vals;
    for (const auto &val : assigns[v])
        if (sat.value(val.second) != False)
            vals.insert(val.first);
    return vals;
}

bool set_theory::propagate(const lit &p, std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    var set_var = is_contained_in[p.v];
    if (listening.find(set_var) != listening.end())
        for (const auto &l : listening[set_var])
            l->set_value_change(set_var);
    return true;
}

bool set_theory::check(std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    return true;
}

void set_theory::push() { layers.push_back(layer()); }

void set_theory::pop()
{
    for (const auto &v : layers.back().vars)
        if (listening.find(v) != listening.end())
            for (const auto &l : listening[v])
                l->set_value_change(v);
    layers.pop_back();
}

void set_theory::listen(const var &v, set_listener *const l) { listening[v].push_back(l); }

void set_theory::forget(const var &v, set_listener *const l)
{
    listening.at(v).erase(std::find(listening.at(v).begin(), listening.at(v).end(), l));
    if (listening.at(v).empty())
        listening.erase(v);
}
}