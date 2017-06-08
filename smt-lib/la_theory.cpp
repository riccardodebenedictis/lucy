#include "la_theory.h"
#include "sat_core.h"
#include "la_value_listener.h"
#include <cassert>
#include <algorithm>

namespace smt
{

la_theory::la_theory(sat_core &sat) : theory(sat) {}

la_theory::~la_theory() {}

var la_theory::new_var()
{
    var id = assigns.size();
    assigns.push_back(interval());
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
    {
        vars.push_back(term.first);
    }
    for (const auto &v : vars)
    {
        if (tableau.find(v) != tableau.end())
        {
            double c = expr.vars[v];
            expr.vars.erase(v);
            expr += tableau[v]->l * c;
        }
    }

    double c_right = -expr.known_term;
    expr.known_term = 0;
    interval i = bounds(expr);
    if (i <= c_right)
    {
        return TRUE; // the constraint is already satisfied..
    }
    else if (i > c_right)
    {
        return FALSE; // the constraint is unsatisfable..
    }

    var slack = mk_slack(expr);
    std::string s_assertion = "x" + std::to_string(slack) + " <= " + std::to_string(c_right);
    if (s_asrts.find(s_assertion) != s_asrts.end())
    {
        return s_asrts.at(s_assertion); // this assertion already exists..
    }
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
    {
        vars.push_back(term.first);
    }
    for (const auto &v : vars)
    {
        if (tableau.find(v) != tableau.end())
        {
            double c = expr.vars[v];
            expr.vars.erase(v);
            expr += tableau[v]->l * c;
        }
    }

    double c_right = -expr.known_term;
    expr.known_term = 0;
    interval i = bounds(expr);
    if (i >= c_right)
    {
        return TRUE; // the constraint is already satisfied..
    }
    else if (i < c_right)
    {
        return FALSE; // the constraint is unsatisfable..
    }

    var slack = mk_slack(expr);
    std::string s_assertion = "x" + std::to_string(slack) + " >= " + std::to_string(c_right);
    if (s_asrts.find(s_assertion) != s_asrts.end())
    {
        return s_asrts.at(s_assertion); // this assertion already exists..
    }
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
    var slack;
    if (exprs.find(s_expr) != exprs.end())
    {
        // the expression already exists..
        slack = exprs.at(s_expr);
    }
    else
    {
        // we need to create a new slack variable..
        slack = new_var();
        exprs.insert({s_expr, slack});
        // we set the initial value of the new slack variable..
        vals[slack] = value(l);
        // we add a new row into the tableau..
        tableau.insert({slack, new row(*this, slack, l)});
    }
    return slack;
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
        auto x_i_it = std::find_if(tableau.begin(), tableau.end(), [&](const std::pair<var, row *> &v) { return vals[v.first] < assigns[v.first].lb || vals[v.first] > assigns[v.first].ub; });
        if (x_i_it == tableau.end())
        {
            return true;
        }
        // the current value of the x_i variable is out of its bounds..
        var x_i = (*x_i_it).first;
        // the flawed row..
        row *f_row = (*x_i_it).second;
        if (vals[x_i] < assigns[x_i].lb)
        {
            auto x_j_it = std::find_if(f_row->l.vars.begin(), f_row->l.vars.end(), [&](const std::pair<var, double> &v) { return (f_row->l.vars.at(v.first) > 0 && vals[v.first] < assigns[v.first].ub) || (f_row->l.vars.at(v.first) < 0 && vals[v.first] > assigns[v.first].lb); });
            if (x_j_it != f_row->l.vars.end())
            {
                // var x_j can be used to increase the value of x_i..
                pivot_and_update(x_i, (*x_j_it).first, assigns[x_i].lb);
            }
            else
            {
                // we generate an explanation for the conflict..
                for (auto &term : f_row->l.vars)
                {
                    if (term.second > 0)
                    {
                        cnfl.push_back(lit(s_asrts.at("x" + std::to_string(term.first) + " <= " + std::to_string(assigns[term.first].ub)), false));
                    }
                    else if (term.second < 0)
                    {
                        cnfl.push_back(lit(s_asrts.at("x" + std::to_string(term.first) + " >= " + std::to_string(assigns[term.first].lb)), false));
                    }
                }
                cnfl.push_back(lit(s_asrts.at("x" + std::to_string(x_i) + " >= " + std::to_string(assigns[x_i].lb)), false));
                return false;
            }
        }
        else if (vals[x_i] > assigns[x_i].ub)
        {
            auto x_j_it = std::find_if(f_row->l.vars.begin(), f_row->l.vars.end(), [&](const std::pair<var, double> &v) { return (f_row->l.vars[v.first] < 0 && vals[v.first] < assigns[v.first].ub) || (f_row->l.vars[v.first] > 0 && vals[v.first] > assigns[v.first].lb); });
            if (x_j_it != f_row->l.vars.end())
            {
                // var x_j can be used to decrease the value of x_i..
                pivot_and_update(x_i, (*x_j_it).first, assigns[x_i].ub);
            }
            else
            {
                // we generate an explanation for the conflict..
                for (auto &term : f_row->l.vars)
                {
                    if (term.second > 0)
                    {
                        cnfl.push_back(lit(s_asrts.at("x" + std::to_string(term.first) + " >= " + std::to_string(assigns[term.first].lb)), false));
                    }
                    else if (term.second < 0)
                    {
                        cnfl.push_back(lit(s_asrts.at("x" + std::to_string(term.first) + " <= " + std::to_string(assigns[term.first].ub)), false));
                    }
                }
                cnfl.push_back(lit(s_asrts.at("x" + std::to_string(x_i) + " <= " + std::to_string(assigns[x_i].ub)), false));
                return false;
            }
        }
    }
}

void la_theory::push()
{
    layers.push_back(layer());
}

void la_theory::pop()
{
    // we restore the variables' bounds..
    for (const auto &lb : layers.back().lbs)
    {
        assigns[lb.first].lb = lb.second;
    }
    for (const auto &ub : layers.back().ubs)
    {
        assigns[ub.first].ub = ub.second;
    }
    layers.pop_back();
}

bool la_theory::assert_lower(var x_i, double val, const lit &p, std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    if (val <= assigns[x_i].lb)
    {
        return true;
    }
    else if (val > assigns[x_i].ub)
    {
        // either the literal 'p' is false ..
        cnfl.push_back(!p);
        // .. or what asserted the upper bound is false..
        cnfl.push_back(lit(s_asrts["x" + std::to_string(x_i) + " <= " + std::to_string(assigns[x_i].ub)], false));
        return false;
    }
    else
    {
        if (!layers.empty() && layers.back().lbs.find(x_i) == layers.back().lbs.end())
        {
            layers.back().lbs.insert({x_i, assigns[x_i].lb});
        }
        assigns[x_i].lb = val;
        if (vals[x_i] < val && tableau.find(x_i) == tableau.end())
        {
            update(x_i, val);
        }

        // unate propagation..
        for (const auto &c : a_watches[x_i])
        {
            if (!c->propagate_lb(x_i, cnfl))
            {
                return false;
            }
        }
        // bound propagation..
        for (const auto &c : t_watches[x_i])
        {
            if (!c->propagate_lb(x_i, cnfl))
            {
                return false;
            }
        }

        return true;
    }
}

bool la_theory::assert_upper(var x_i, double val, const lit &p, std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    if (val >= assigns[x_i].ub)
    {
        return true;
    }
    else if (val < assigns[x_i].lb)
    {
        // either the literal 'p' is false ..
        cnfl.push_back(!p);
        // .. or what asserted the lower bound is false..
        cnfl.push_back(lit(s_asrts["x" + std::to_string(x_i) + " >= " + std::to_string(assigns[x_i].lb)], false));
        return false;
    }
    else
    {
        if (!layers.empty() && layers.back().ubs.find(x_i) == layers.back().ubs.end())
        {
            layers.back().ubs.insert({x_i, assigns[x_i].ub});
        }
        assigns[x_i].ub = val;
        if (vals[x_i] > val && tableau.find(x_i) == tableau.end())
        {
            update(x_i, val);
        }

        // unate propagation..
        for (const auto &c : a_watches[x_i])
        {
            if (!c->propagate_ub(x_i, cnfl))
            {
                return false;
            }
        }
        // bound propagation..
        for (const auto &c : t_watches[x_i])
        {
            if (!c->propagate_ub(x_i, cnfl))
            {
                return false;
            }
        }

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
        {
            for (const auto &l : listening[c->x])
            {
                l->la_value_change(c->x);
            }
        }
    }
    // x_i = v..
    vals[x_i] = v;
    if (listening.find(x_i) != listening.end())
    {
        for (const auto &l : listening[x_i])
        {
            l->la_value_change(x_i);
        }
    }
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
    {
        for (const auto &l : listening[x_i])
        {
            l->la_value_change(x_i);
        }
    }
    // x_j = x_j + theta
    vals[x_j] += theta;
    if (listening.find(x_j) != listening.end())
    {
        for (const auto &l : listening[x_j])
        {
            l->la_value_change(x_j);
        }
    }
    for (const auto &c : t_watches[x_j])
    {
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
    {
        t_watches[c.first].erase(ex_row);
    }
    delete ex_row;

    double c = expr.vars.at(x_j);
    expr.vars.erase(x_j);
    expr /= -c;
    expr.vars.insert({x_i, 1 / c});

    std::vector<row *> rows;
    for (const auto &c : t_watches[x_j])
    {
        rows.push_back(c);
    }
    for (const auto &r : rows)
    {
        for (const auto &term : r->l.vars)
        {
            t_watches[term.first].erase(r);
        }
        double cc = r->l.vars.at(x_j);
        r->l.vars.erase(x_j);
        r->l += expr * cc;
        for (const auto &term : r->l.vars)
        {
            t_watches[term.first].insert(r);
        }
    }

    // we add a new row into the tableau..
    tableau.insert({x_j, new row(*this, x_j, expr)});
}

void la_theory::listen(var v, la_value_listener *const l)
{
    listening[v].push_back(l);
}

void la_theory::forget(var v, la_value_listener *const l)
{
    listening.at(v).erase(std::find(listening.at(v).begin(), listening.at(v).end(), l));
    if (listening.at(v).empty())
    {
        listening.erase(v);
    }
}

la_theory::assertion::assertion(la_theory &th, op o, var b, var x, double v) : th(th), o(o), b(b), x(x), v(v) { th.a_watches[x].push_back(this); }

la_theory::assertion::~assertion() {}

std::string la_theory::assertion::to_string() const
{
    std::string asrt;
    asrt += "{ \"var\" : \"b" + std::to_string(b) + "\", \"val\" : \"";
    switch (th.get_core().value(b))
    {
    case True:
        asrt += "True";
        break;
    case False:
        asrt += "False";
        break;
    case Undefined:
        asrt += "Undefined";
        break;
    }
    asrt += "\", \"constr\" : \"x" + std::to_string(x);
    switch (o)
    {
    case leq:
        asrt += " <= ";
        break;
    case geq:
        asrt += " >= ";
        break;
    }
    asrt += std::to_string(v) + "\" }";
    return asrt;
}

bool la_theory::assertion::propagate_lb(var x, std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    if (th.assigns[x].lb > v)
    {
        lit p = lit(th.s_asrts["x" + std::to_string(x) + " >= " + std::to_string(th.assigns[x].lb)], false);
        switch (o)
        {
        case leq:
            // [x >= lb(x)] -> ![x <= v]..
            // the assertion is unsatisfable..
            switch (th.sat.value(b))
            {
            case True:
                // we have a propositional inconsistency..
                cnfl.push_back(p);
                cnfl.push_back(lit(b, false));
                return false;
            case False:
                // nothing to propagate..
                return true;
            case Undefined:
                // we propagate information to the sat core..
                th.record({lit(b, false), p});
                return true;
            }
            break;
        case geq:
            // [x >= lb(x)] -> [x >= v]..
            // the assertion is satisfied..
            switch (th.sat.value(b))
            {
            case True:
                // nothing to propagate..
                return true;
            case False:
                // we have a propositional inconsistency..
                cnfl.push_back(p);
                cnfl.push_back(lit(b, true));
                return false;
            case Undefined:
                // we propagate information to the sat core..
                th.record({lit(b, true), p});
                return true;
            }
            break;
        }
    }

    return true;
}

bool la_theory::assertion::propagate_ub(var x, std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    if (th.assigns[x].ub < v)
    {
        lit p = lit(th.s_asrts["x" + std::to_string(x) + " <= " + std::to_string(th.assigns[x].ub)], false);
        switch (o)
        {
        case leq:
            // [x <= ub(x)] -> [x <= v]..
            // the assertion is satisfied..
            switch (th.sat.value(b))
            {
            case True:
                // nothing to propagate..
                return true;
            case False:
                // we have a propositional inconsistency..
                cnfl.push_back(p);
                cnfl.push_back(lit(b, true));
                return false;
            case Undefined:
                // we propagate information to the sat core..
                th.record({lit(b, true), p});
                return true;
            }
            break;
        case geq:
            // [x <= ub(x)] -> ![x >= v]..
            // the assertion is unsatisfable..
            switch (th.sat.value(b))
            {
            case True:
                // we have a propositional inconsistency..
                cnfl.push_back(p);
                cnfl.push_back(lit(b, false));
                return false;
            case False:
                // nothing to propagate..
                return true;
            case Undefined:
                // we propagate information to the sat core..
                th.record({lit(b, false), p});
                return true;
            }
            break;
        }
    }

    return true;
}

la_theory::row::row(la_theory &th, var x, lin l) : th(th), x(x), l(l)
{
    for (const auto &term : l.vars)
    {
        th.t_watches[term.first].insert(this);
    }
}

la_theory::row::~row() {}

std::string la_theory::row::to_string() const
{
    return "{ \"basic-var\" : \"x" + std::to_string(x) + "\", \"expr\" : \"" + l.to_string() + "\" }";
}

bool la_theory::row::propagate_lb(var v, std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    // we make room for the first literal..
    cnfl.push_back(lit(FALSE, true));
    if (l.vars.at(v) > 0)
    {
        double lb = 0;
        for (const auto &term : l.vars)
        {
            if (term.second > 0)
            {
                if (th.bounds(term.first).lb == -std::numeric_limits<double>::infinity())
                {
                    // nothing to propagate..
                    cnfl.clear();
                    return true;
                }
                else
                {
                    lb += term.second * th.bounds(term.first).lb;
                    cnfl.push_back(lit(th.s_asrts.at("x" + std::to_string(term.first) + " >= " + std::to_string(th.assigns[term.first].lb)), false));
                }
            }
            else if (term.second < 0)
            {
                if (th.bounds(term.first).ub == std::numeric_limits<double>::infinity())
                {
                    // nothing to propagate..
                    cnfl.clear();
                    return true;
                }
                else
                {
                    lb += term.second * th.bounds(term.first).ub;
                    cnfl.push_back(lit(th.s_asrts.at("x" + std::to_string(term.first) + " <= " + std::to_string(th.assigns[term.first].ub)), false));
                }
            }
        }
        if (lb > th.bounds(x).lb)
        {
            for (const auto &c : th.a_watches[x])
            {
                if (lb > c->v)
                {
                    switch (c->o)
                    {
                    case leq:
                        cnfl[0] = lit(c->b, false);
                        // the assertion is unsatisfable..
                        switch (th.sat.value(c->b))
                        {
                        case True:
                            // we have a propositional inconsistency..
                            return false;
                        case False:
                            // nothing to propagate..
                            cnfl.clear();
                            return true;
                        case Undefined:
                            // we propagate information to the sat core..
                            th.record(cnfl);
                            cnfl.clear();
                            return true;
                        }
                        break;
                    case geq:
                        cnfl[0] = lit(c->b, true);
                        // the assertion is satisfied..
                        switch (th.sat.value(c->b))
                        {
                        case True:
                            // nothing to propagate..
                            cnfl.clear();
                            return true;
                        case False:
                            // we have a propositional inconsistency..
                            return false;
                        case Undefined:
                            // we propagate information to the sat core..
                            th.record(cnfl);
                            cnfl.clear();
                            return true;
                        }
                        break;
                    }
                }
            }
        }
    }
    else
    {
        double ub = 0;
        for (const auto &term : l.vars)
        {
            if (term.second > 0)
            {
                if (th.bounds(term.first).ub == std::numeric_limits<double>::infinity())
                {
                    // nothing to propagate..
                    cnfl.clear();
                    return true;
                }
                else
                {
                    ub += term.second * th.bounds(term.first).ub;
                    cnfl.push_back(lit(th.s_asrts.at("x" + std::to_string(term.first) + " <= " + std::to_string(th.assigns[term.first].ub)), false));
                }
            }
            else if (term.second < 0)
            {
                if (th.bounds(term.first).lb == -std::numeric_limits<double>::infinity())
                {
                    // nothing to propagate..
                    cnfl.clear();
                    return true;
                }
                else
                {
                    ub += term.second * th.bounds(term.first).lb;
                    cnfl.push_back(lit(th.s_asrts.at("x" + std::to_string(term.first) + " >= " + std::to_string(th.assigns[term.first].lb)), false));
                }
            }
        }
        if (ub < th.bounds(x).ub)
        {
            for (const auto &c : th.a_watches[x])
            {
                if (ub > c->v)
                {
                    switch (c->o)
                    {
                    case leq:
                        cnfl[0] = lit(c->b, false);
                        // the assertion is unsatisfable..
                        switch (th.sat.value(c->b))
                        {
                        case True:
                            // we have a propositional inconsistency..
                            return false;
                        case False:
                            // nothing to propagate..
                            cnfl.clear();
                            return true;
                        case Undefined:
                            // we propagate information to the sat core..
                            th.record(cnfl);
                            cnfl.clear();
                            return true;
                        }
                        break;
                    case geq:
                        cnfl[0] = lit(c->b, true);
                        // the assertion is satisfied..
                        switch (th.sat.value(c->b))
                        {
                        case True:
                            // nothing to propagate..
                            cnfl.clear();
                            return true;
                        case False:
                            // we have a propositional inconsistency..
                            return false;
                        case Undefined:
                            // we propagate information to the sat core..
                            th.record(cnfl);
                            cnfl.clear();
                            return true;
                        }
                        break;
                    }
                }
            }
        }
    }

    cnfl.clear();
    return true;
}

bool la_theory::row::propagate_ub(var v, std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    // we make room for the first literal..
    cnfl.push_back(lit(FALSE, true));
    if (l.vars.at(v) > 0)
    {
        double ub = 0;
        for (const auto &term : l.vars)
        {
            if (term.second > 0)
            {
                if (th.bounds(term.first).ub == std::numeric_limits<double>::infinity())
                {
                    // nothing to propagate..
                    cnfl.clear();
                    return true;
                }
                else
                {
                    ub += term.second * th.bounds(term.first).ub;
                    cnfl.push_back(lit(th.s_asrts["x" + std::to_string(term.first) + " <= " + std::to_string(th.assigns[term.first].ub)], false));
                }
            }
            else if (term.second < 0)
            {
                if (th.bounds(term.first).lb == -std::numeric_limits<double>::infinity())
                {
                    // nothing to propagate..
                    cnfl.clear();
                    return true;
                }
                else
                {
                    ub += term.second * th.bounds(term.first).lb;
                    cnfl.push_back(lit(th.s_asrts["x" + std::to_string(term.first) + " >= " + std::to_string(th.assigns[term.first].lb)], false));
                }
            }
        }
        if (ub < th.bounds(x).ub)
        {
            for (const auto &c : th.a_watches[x])
            {
                if (ub > c->v)
                {
                    switch (c->o)
                    {
                    case leq:
                        cnfl[0] = lit(c->b, false);
                        // the assertion is unsatisfable..
                        switch (th.sat.value(c->b))
                        {
                        case True:
                            // we have a propositional inconsistency..
                            return false;
                        case False:
                            // nothing to propagate..
                            cnfl.clear();
                            return true;
                        case Undefined:
                            // we propagate information to the sat core..
                            th.record(cnfl);
                            cnfl.clear();
                            return true;
                        }
                        break;
                    case geq:
                        cnfl[0] = lit(c->b, true);
                        // the assertion is satisfied..
                        switch (th.sat.value(c->b))
                        {
                        case True:
                            // nothing to propagate..
                            cnfl.clear();
                            return true;
                        case False:
                            // we have a propositional inconsistency..
                            return false;
                        case Undefined:
                            // we propagate information to the sat core..
                            th.record(cnfl);
                            cnfl.clear();
                            return true;
                        }
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
    else
    {
        double lb = 0;
        for (const auto &term : l.vars)
        {
            if (term.second > 0)
            {
                if (th.bounds(term.first).lb == -std::numeric_limits<double>::infinity())
                {
                    // nothing to propagate..
                    cnfl.clear();
                    return true;
                }
                else
                {
                    lb += term.second * th.bounds(term.first).lb;
                    cnfl.push_back(lit(th.s_asrts["x" + std::to_string(term.first) + " >= " + std::to_string(th.assigns[term.first].lb)], false));
                }
            }
            else if (term.second < 0)
            {
                if (th.bounds(term.first).ub == std::numeric_limits<double>::infinity())
                {
                    // nothing to propagate..
                    cnfl.clear();
                    return true;
                }
                else
                {
                    lb += term.second * th.bounds(term.first).ub;
                    cnfl.push_back(lit(th.s_asrts["x" + std::to_string(term.first) + " <= " + std::to_string(th.assigns[term.first].ub)], false));
                }
            }
        }
        if (lb > th.bounds(x).lb)
        {
            for (const auto &c : th.a_watches[x])
            {
                if (lb > c->v)
                {
                    switch (c->o)
                    {
                    case leq:
                        cnfl[0] = lit(c->b, false);
                        // the assertion is unsatisfable..
                        switch (th.sat.value(c->b))
                        {
                        case True:
                            // we have a propositional inconsistency..
                            return false;
                        case False:
                            // nothing to propagate..
                            cnfl.clear();
                            return true;
                        case Undefined:
                            // we propagate information to the sat core..
                            th.record(cnfl);
                            cnfl.clear();
                            return true;
                        }
                        break;
                    case geq:
                        cnfl[0] = lit(c->b, true);
                        // the assertion is satisfied..
                        switch (th.sat.value(c->b))
                        {
                        case True:
                            // nothing to propagate..
                            cnfl.clear();
                            return true;
                        case False:
                            // we have a propositional inconsistency..
                            return false;
                        case Undefined:
                            // we propagate information to the sat core..
                            th.record(cnfl);
                            cnfl.clear();
                            return true;
                        }
                        break;
                    }
                }
            }
        }
    }

    cnfl.clear();
    return true;
}

std::string la_theory::to_string()
{
    std::string la;
    la += "{ \"vars\" : [";
    for (size_t i = 0; i < assigns.size(); i++)
    {
        if (i)
        {
            la += ", ";
        }
        la += "{ \"name\" : \"x" + std::to_string(i) + "\", \"value\" : " + std::to_string(value(i));
        if (assigns[i].lb > -std::numeric_limits<double>::infinity())
        {
            la += ", \"lb\" : " + std::to_string(assigns[i].lb);
        }
        if (assigns[i].ub < std::numeric_limits<double>::infinity())
        {
            la += ", \"ub\" : " + std::to_string(assigns[i].ub);
        }
        la += "}";
    }
    la += "], \"asrts\" : [";
    for (std::unordered_map<var, assertion *>::const_iterator it = v_asrts.begin(); it != v_asrts.end(); ++it)
    {
        if (it != v_asrts.begin())
        {
            la += ", ";
        }
        la += it->second->to_string();
    }
    la += "], \"tableau\" : [";
    for (std::map<var, row *>::const_iterator it = tableau.begin(); it != tableau.end(); ++it)
    {
        if (it != tableau.begin())
        {
            la += ", ";
        }
        la += it->second->to_string();
    }
    la += "]";
    la += "}";
    return la;
}
}