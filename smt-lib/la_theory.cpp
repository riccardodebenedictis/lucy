#include "la_theory.h"
#include "sat_core.h"
#include "la_constr.h"
#include "la_value_listener.h"
#include <algorithm>
#include <cassert>

namespace smt
{

la_theory::la_theory(sat_core &sat) : theory(sat) {}

la_theory::~la_theory() {}

var la_theory::new_var()
{
    var id = vals.size();
    assigns.push_back({-std::numeric_limits<double>::infinity(), nullptr});
    assigns.push_back({std::numeric_limits<double>::infinity(), nullptr});
    vals.push_back(0);
    exprs.insert({"x" + std::to_string(id), id});
    a_watches.push_back(std::vector<assertion *>());
    t_watches.push_back(std::set<row *>());
    return id;
}

var la_theory::new_leq(const lin &left, const lin &right)
{
    lin expr = left - right;
    std::vector<var> vars;
    for (const auto &term : expr.vars)
        vars.push_back(term.first);
    for (const auto &v : vars)
        if (tableau.find(v) != tableau.end())
        {
            double c = expr.vars[v];
            expr.vars.erase(v);
            expr += tableau[v]->l * c;
        }

    double c_right = -expr.known_term;
    expr.known_term = 0;
    interval i = bounds(expr);

    if (i <= c_right) // the constraint is already satisfied..
        return TRUE_var;
    else if (i > c_right) // the constraint is unsatisfable..
        return FALSE_var;

    var slack = mk_slack(expr);
    std::string s_assertion = "x" + std::to_string(slack) + " <= " + std::to_string(c_right);
    if (s_asrts.find(s_assertion) != s_asrts.end()) // this assertion already exists..
        return s_asrts.at(s_assertion);
    else
    {
        var ctr = sat.new_var();
        bind(ctr);
        s_asrts.insert({s_assertion, ctr});
        v_asrts.insert({ctr, new assertion(*this, op::leq, ctr, slack, c_right)});
        return ctr;
    }
}

var la_theory::new_geq(const lin &left, const lin &right)
{
    lin expr = left - right;
    std::vector<var> vars;
    for (const auto &term : expr.vars)
        vars.push_back(term.first);
    for (const auto &v : vars)
        if (tableau.find(v) != tableau.end())
        {
            double c = expr.vars[v];
            expr.vars.erase(v);
            expr += tableau[v]->l * c;
        }

    double c_right = -expr.known_term;
    expr.known_term = 0;
    interval i = bounds(expr);

    if (i >= c_right) // the constraint is already satisfied..
        return TRUE_var;
    else if (i < c_right) // the constraint is unsatisfable..
        return FALSE_var;

    var slack = mk_slack(expr);
    std::string s_assertion = "x" + std::to_string(slack) + " >= " + std::to_string(c_right);
    if (s_asrts.find(s_assertion) != s_asrts.end()) // this assertion already exists..
        return s_asrts.at(s_assertion);
    else
    {
        var ctr = sat.new_var();
        bind(ctr);
        s_asrts.insert({s_assertion, ctr});
        v_asrts.insert({ctr, new assertion(*this, op::geq, ctr, slack, c_right)});
        return ctr;
    }
}

var la_theory::mk_slack(const lin &l)
{
    std::string s_expr = l.to_string();
    if (exprs.find(s_expr) != exprs.end()) // the expression already exists..
        return exprs.at(s_expr);
    else
    {
        // we need to create a new slack variable..
        var slack = new_var();
        exprs.insert({s_expr, slack});
        // we set the initial value of the new slack variable..
        vals[slack] = value(l);
        // we add a new row into the tableau..
        tableau.insert({slack, new row(*this, slack, l)});
        return slack;
    }
}

bool la_theory::propagate(const lit &p, std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    assertion *a = v_asrts.at(p.v);
    switch (a->o)
    {
    case op::leq:
        return p.sign ? assert_upper(a->x, a->v, p, cnfl) : assert_lower(a->x, a->v, p, cnfl);
    case op::geq:
        return p.sign ? assert_lower(a->x, a->v, p, cnfl) : assert_upper(a->x, a->v, p, cnfl);
    }

    return true;
}

bool la_theory::check(std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    while (true)
    {
        auto x_i_it = std::find_if(tableau.begin(), tableau.end(), [&](const std::pair<var, row *> &v) { return value(v.first) < lb(v.first) || value(v.first) > ub(v.first); });
        if (x_i_it == tableau.end())
            return true;
        // the current value of the x_i variable is out of its bounds..
        var x_i = (*x_i_it).first;
        // the flawed row..
        row *f_row = (*x_i_it).second;
        if (value(x_i) < lb(x_i))
        {
            auto x_j_it = std::find_if(f_row->l.vars.begin(), f_row->l.vars.end(), [&](const std::pair<var, double> &v) { return (f_row->l.vars.at(v.first) > 0 && value(v.first) < ub(v.first)) || (f_row->l.vars.at(v.first) < 0 && value(v.first) > lb(v.first)); });
            if (x_j_it != f_row->l.vars.end()) // var x_j can be used to increase the value of x_i..
                pivot_and_update(x_i, (*x_j_it).first, lb(x_i));
            else
            {
                // we generate an explanation for the conflict..
                for (auto &term : f_row->l.vars)
                {
                    if (term.second > 0)
                        cnfl.push_back(lit(s_asrts.at("x" + std::to_string(term.first) + " <= " + std::to_string(ub(term.first))), false));
                    else if (term.second < 0)
                        cnfl.push_back(lit(s_asrts.at("x" + std::to_string(term.first) + " >= " + std::to_string(lb(term.first))), false));
                }
                cnfl.push_back(lit(s_asrts.at("x" + std::to_string(x_i) + " >= " + std::to_string(lb(x_i))), false));
                return false;
            }
        }
        else if (value(x_i) > ub(x_i))
        {
            auto x_j_it = std::find_if(f_row->l.vars.begin(), f_row->l.vars.end(), [&](const std::pair<var, double> &v) { return (f_row->l.vars[v.first] < 0 && value(v.first) < ub(v.first)) || (f_row->l.vars[v.first] > 0 && value(v.first) > lb(v.first)); });
            if (x_j_it != f_row->l.vars.end()) // var x_j can be used to decrease the value of x_i..
                pivot_and_update(x_i, (*x_j_it).first, ub(x_i));
            else
            {
                // we generate an explanation for the conflict..
                for (auto &term : f_row->l.vars)
                {
                    if (term.second > 0)
                        cnfl.push_back(lit(s_asrts.at("x" + std::to_string(term.first) + " >= " + std::to_string(lb(term.first))), false));
                    else if (term.second < 0)
                        cnfl.push_back(lit(s_asrts.at("x" + std::to_string(term.first) + " <= " + std::to_string(ub(term.first))), false));
                }
                cnfl.push_back(lit(s_asrts.at("x" + std::to_string(x_i) + " <= " + std::to_string(ub(x_i))), false));
                return false;
            }
        }
    }
}

void la_theory::push() { layers.push_back(std::unordered_map<size_t, bound>()); }

void la_theory::pop()
{
    // we restore the variables' bounds and their reason..
    for (const auto &b : layers.back())
    {
        delete assigns[b.first].reason;
        assigns[b.first] = b.second;
    }
    layers.pop_back();
}

bool la_theory::assert_lower(var x_i, double val, const lit &p, std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    if (val <= lb(x_i))
        return true;
    else if (val > ub(x_i))
    {
        // either the literal 'p' is false ..
        cnfl.push_back(!p);
        // .. or what asserted the upper bound is false..
        cnfl.push_back(!*assigns[ub_index(x_i)].reason);
        return false;
    }
    else
    {
        if (!layers.empty() && layers.back().find(lb_index(x_i)) == layers.back().end())
            layers.back().insert({lb_index(x_i), {lb(x_i), assigns[lb_index(x_i)].reason}});
        assigns[lb_index(x_i)] = {val, new lit(p.v, p.sign)};

        if (vals[x_i] < val && tableau.find(x_i) == tableau.end())
            update(x_i, val);

        // unate propagation..
        for (const auto &c : a_watches[x_i])
            if (!c->propagate_lb(x_i, cnfl))
                return false;
        // bound propagation..
        for (const auto &c : t_watches[x_i])
            if (!c->propagate_lb(x_i, cnfl))
                return false;

        return true;
    }
}

bool la_theory::assert_upper(var x_i, double val, const lit &p, std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    if (val >= ub(x_i))
        return true;
    else if (val < lb(x_i))
    {
        // either the literal 'p' is false ..
        cnfl.push_back(!p);
        // .. or what asserted the lower bound is false..
        cnfl.push_back(!*assigns[lb_index(x_i)].reason);
        return false;
    }
    else
    {
        if (!layers.empty() && layers.back().find(ub_index(x_i)) == layers.back().end())
            layers.back().insert({ub_index(x_i), {ub(x_i), assigns[ub_index(x_i)].reason}});
        assigns[ub_index(x_i)] = {val, new lit(p.v, p.sign)};

        if (vals[x_i] > val && tableau.find(x_i) == tableau.end())
            update(x_i, val);

        // unate propagation..
        for (const auto &c : a_watches[x_i])
            if (!c->propagate_ub(x_i, cnfl))
                return false;
        // bound propagation..
        for (const auto &c : t_watches[x_i])
            if (!c->propagate_ub(x_i, cnfl))
                return false;

        return true;
    }
}

void la_theory::update(var x_i, double v)
{
    assert(tableau.find(x_i) == tableau.end() && "x_i should be a non-basic variable..");
    for (const auto &c : t_watches[x_i])
    {
        // x_j = x_j + a_ji(v - x_i)..
        vals[c->x] += c->l.vars[x_i] * (v - vals[x_i]);
        if (listening.find(c->x) != listening.end())
            for (const auto &l : listening[c->x])
                l->la_value_change(c->x);
    }
    // x_i = v..
    vals[x_i] = v;
    if (listening.find(x_i) != listening.end())
        for (const auto &l : listening[x_i])
            l->la_value_change(x_i);
}

void la_theory::pivot_and_update(var x_i, var x_j, double v)
{
    assert(tableau.find(x_i) != tableau.end() && "x_i should be a basic variable..");
    assert(tableau.find(x_j) == tableau.end() && "x_j should be a non-basic variable..");
    assert(tableau[x_i]->l.vars.find(x_j) != tableau[x_i]->l.vars.end());

    double theta = (v - vals[x_i]) / tableau.at(x_i)->l.vars.at(x_j);
    // x_i = v
    vals[x_i] = v;
    if (listening.find(x_i) != listening.end())
        for (const auto &l : listening[x_i])
            l->la_value_change(x_i);

    // x_j = x_j + theta
    vals[x_j] += theta;
    if (listening.find(x_j) != listening.end())
        for (const auto &l : listening[x_j])
            l->la_value_change(x_j);

    for (const auto &c : t_watches[x_j])
        if (c->x != x_i)
        {
            // x_k = x_k + a_kj * theta..
            vals[c->x] += c->l.vars[x_j] * theta;
            if (listening.find(c->x) != listening.end())
            {
                for (const auto &l : listening[c->x])
                {
                    l->la_value_change(c->x);
                }
            }
        }

    pivot(x_i, x_j);
}

void la_theory::pivot(var x_i, var x_j)
{
    // the exiting row..
    row *ex_row = tableau.at(x_i);
    lin expr = std::move(ex_row->l);
    tableau.erase(x_i);
    for (const auto &c : expr.vars)
        t_watches[c.first].erase(ex_row);
    delete ex_row;

    double c = expr.vars.at(x_j);
    expr.vars.erase(x_j);
    expr /= -c;
    expr.vars.insert({x_i, 1 / c});

    std::vector<row *> rows;
    for (const auto &c_rw : t_watches[x_j])
        rows.push_back(c_rw);
    for (const auto &r : rows)
    {
        for (const auto &term : r->l.vars)
            t_watches[term.first].erase(r);
        double cc = r->l.vars.at(x_j);
        r->l.vars.erase(x_j);
        r->l += expr * cc;
        for (const auto &term : r->l.vars)
            t_watches[term.first].insert(r);
    }

    // we add a new row into the tableau..
    tableau.insert({x_j, new row(*this, x_j, expr)});
}

void la_theory::listen(var v, la_value_listener *const l) { listening[v].push_back(l); }

void la_theory::forget(var v, la_value_listener *const l)
{
    listening.at(v).erase(std::find(listening.at(v).begin(), listening.at(v).end(), l));
    if (listening.at(v).empty())
        listening.erase(v);
}

std::string la_theory::to_string()
{
    std::string la;
    la += "{ \"vars\" : [";
    for (size_t i = 0; i < assigns.size(); i++)
    {
        if (i)
            la += ", ";
        la += "{ \"name\" : \"x" + std::to_string(i) + "\", \"value\" : " + std::to_string(value(i));
        if (lb(i) > -std::numeric_limits<double>::infinity())
            la += ", \"lb\" : " + std::to_string(lb(i));
        if (ub(i) < std::numeric_limits<double>::infinity())
            la += ", \"ub\" : " + std::to_string(ub(i));
        la += "}";
    }
    la += "], \"asrts\" : [";
    for (std::unordered_map<var, assertion *>::const_iterator it = v_asrts.begin(); it != v_asrts.end(); ++it)
    {
        if (it != v_asrts.begin())
            la += ", ";
        la += it->second->to_string();
    }
    la += "], \"tableau\" : [";
    for (std::map<var, row *>::const_iterator it = tableau.begin(); it != tableau.end(); ++it)
    {
        if (it != tableau.begin())
            la += ", ";
        la += it->second->to_string();
    }
    la += "]";
    la += "}";
    return la;
}
}