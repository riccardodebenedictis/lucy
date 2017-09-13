#include "la_constr.h"
#include "la_theory.h"
#include "sat_core.h"
#include <limits>
#include <cassert>

namespace smt
{

assertion::assertion(la_theory &th, const op o, const var b, const var x, const double v) : th(th), o(o), b(b), x(x), v(v) { th.a_watches[x].push_back(this); }
assertion::~assertion() {}

std::string assertion::to_string() const
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

bool assertion::propagate_lb(const var &x_i, std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    if (th.lb(x_i) > v)
        switch (o)
        {
        case leq: // the assertion is unsatisfable: [x_i >= lb(x_i)] -> ![x_i <= v]..
            switch (th.sat.value(b))
            {
            case True:                                                         // we have a propositional inconsistency..
                cnfl.push_back(lit(b, false));                                 // either the literal 'b' is false ..
                cnfl.push_back(!*th.assigns[la_theory::lb_index(x_i)].reason); // or what asserted the lower bound is false..
                return false;
            case Undefined: // we propagate information to the sat core..
                th.record({lit(b, false), !*th.assigns[la_theory::lb_index(x_i)].reason});
            }
            break;
        case geq: // the assertion is satisfied; [x_i >= lb(x_i)] -> [x_i >= v]..
            switch (th.sat.value(b))
            {
            case False:                                                        // we have a propositional inconsistency..
                cnfl.push_back(b);                                             // either the literal 'b' is true ..
                cnfl.push_back(!*th.assigns[la_theory::lb_index(x_i)].reason); // or what asserted the lower bound is false..
                return false;
            case Undefined: // we propagate information to the sat core..
                th.record({b, !*th.assigns[la_theory::lb_index(x_i)].reason});
            }
            break;
        }

    return true;
}

bool assertion::propagate_ub(const var &x_i, std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    if (th.ub(x_i) < v)
        switch (o)
        {
        case leq: // the assertion is satisfied: [x_i <= ub(x_i)] -> [x_i <= v]..
            switch (th.sat.value(b))
            {
            case False:                                                        // we have a propositional inconsistency..
                cnfl.push_back(b);                                             // either the literal 'b' is true ..
                cnfl.push_back(!*th.assigns[la_theory::ub_index(x_i)].reason); // or what asserted the upper bound is false..
                return false;
            case Undefined: // we propagate information to the sat core..
                th.record({b, !*th.assigns[la_theory::ub_index(x_i)].reason});
            }
            break;
        case geq: // the assertion is unsatisfable; [x_i <= ub(x_i)] -> ![x_i >= v]..
            switch (th.sat.value(b))
            {
            case True:                                                         // we have a propositional inconsistency..
                cnfl.push_back(lit(b, false));                                 // either the literal 'b' is false ..
                cnfl.push_back(!*th.assigns[la_theory::ub_index(x_i)].reason); // or what asserted the upper bound is false..
                return false;
            case Undefined: // we propagate information to the sat core..
                th.record({lit(b, false), !*th.assigns[la_theory::ub_index(x_i)].reason});
            }
            break;
        }

    return true;
}

row::row(la_theory &th, const var x, lin l) : th(th), x(x), l(l)
{
    for (const auto &term : l.vars)
        th.t_watches[term.first].insert(this);
}

row::~row() {}

std::string row::to_string() const { return "{ \"basic-var\" : \"x" + std::to_string(x) + "\", \"expr\" : \"" + l.to_string() + "\" }"; }

bool row::propagate_lb(const var &v, std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    // we make room for the first literal..
    cnfl.push_back(lit());
    if (l.vars.at(v) > 0)
    {
        double lb = 0;
        for (const auto &term : l.vars)
            if (term.second > 0)
                if (th.lb(term.first) == -std::numeric_limits<double>::infinity())
                {
                    // nothing to propagate..
                    cnfl.clear();
                    return true;
                }
                else
                {
                    lb += term.second * th.lb(term.first);
                    cnfl.push_back(!*th.assigns[la_theory::lb_index(term.first)].reason);
                }
            else if (term.second < 0)
                if (th.ub(term.first) == std::numeric_limits<double>::infinity())
                {
                    // nothing to propagate..
                    cnfl.clear();
                    return true;
                }
                else
                {
                    lb += term.second * th.ub(term.first);
                    cnfl.push_back(!*th.assigns[la_theory::ub_index(term.first)].reason);
                }

        if (lb > th.lb(x))
            for (const auto &c : th.a_watches[x])
                if (lb > c->v)
                    switch (c->o)
                    {
                    case leq: // the assertion is unsatisfable..
                        cnfl[0] = lit(c->b, false);
                        switch (th.sat.value(c->b))
                        {
                        case True: // we have a propositional inconsistency..
                            return false;
                        case Undefined: // we propagate information to the sat core..
                            th.record(cnfl);
                        }
                        break;
                    case geq: // the assertion is satisfied..
                        cnfl[0] = c->b;
                        switch (th.sat.value(c->b))
                        {
                        case False: // we have a propositional inconsistency..
                            return false;
                        case Undefined: // we propagate information to the sat core..
                            th.record(cnfl);
                        }
                        break;
                    }
    }
    else
    {
        double ub = 0;
        for (const auto &term : l.vars)
            if (term.second > 0)
                if (th.ub(term.first) == std::numeric_limits<double>::infinity())
                {
                    // nothing to propagate..
                    cnfl.clear();
                    return true;
                }
                else
                {
                    ub += term.second * th.ub(term.first);
                    cnfl.push_back(!*th.assigns[la_theory::ub_index(term.first)].reason);
                }
            else if (term.second < 0)
                if (th.lb(term.first) == -std::numeric_limits<double>::infinity())
                {
                    // nothing to propagate..
                    cnfl.clear();
                    return true;
                }
                else
                {
                    ub += term.second * th.lb(term.first);
                    cnfl.push_back(!*th.assigns[la_theory::lb_index(term.first)].reason);
                }

        if (ub < th.ub(x))
            for (const auto &c : th.a_watches[x])
                if (ub < c->v)
                    switch (c->o)
                    {
                    case leq: // the assertion is satisfied..
                        cnfl[0] = c->b;
                        switch (th.sat.value(c->b))
                        {
                        case False: // we have a propositional inconsistency..
                            return false;
                        case Undefined: // we propagate information to the sat core..
                            th.record(cnfl);
                        }
                        break;
                    case geq: // the assertion is unsatisfable..
                        cnfl[0] = lit(c->b, false);
                        switch (th.sat.value(c->b))
                        {
                        case True: // we have a propositional inconsistency..
                            return false;
                        case Undefined: // we propagate information to the sat core..
                            th.record(cnfl);
                        }
                        break;
                    }
    }

    cnfl.clear();
    return true;
}

bool row::propagate_ub(const var &v, std::vector<lit> &cnfl)
{
    assert(cnfl.empty());
    // we make room for the first literal..
    cnfl.push_back(lit());
    if (l.vars.at(v) > 0)
    {
        double ub = 0;
        for (const auto &term : l.vars)
            if (term.second > 0)
                if (th.ub(term.first) == std::numeric_limits<double>::infinity())
                {
                    // nothing to propagate..
                    cnfl.clear();
                    return true;
                }
                else
                {
                    ub += term.second * th.ub(term.first);
                    cnfl.push_back(!*th.assigns[la_theory::ub_index(term.first)].reason);
                }
            else if (term.second < 0)
                if (th.lb(term.first) == -std::numeric_limits<double>::infinity())
                {
                    // nothing to propagate..
                    cnfl.clear();
                    return true;
                }
                else
                {
                    ub += term.second * th.lb(term.first);
                    cnfl.push_back(!*th.assigns[la_theory::lb_index(term.first)].reason);
                }

        if (ub < th.ub(x))
            for (const auto &c : th.a_watches[x])
                if (ub < c->v)
                    switch (c->o)
                    {
                    case leq: // the assertion is satisfied..
                        cnfl[0] = c->b;
                        switch (th.sat.value(c->b))
                        {
                        case False: // we have a propositional inconsistency..
                            return false;
                        case Undefined: // we propagate information to the sat core..
                            th.record(cnfl);
                        }
                        break;
                    case geq: // the assertion is unsatisfable..
                        cnfl[0] = lit(c->b, false);
                        switch (th.sat.value(c->b))
                        {
                        case True: // we have a propositional inconsistency..
                            return false;
                        case Undefined: // we propagate information to the sat core..
                            th.record(cnfl);
                        }
                        break;
                    }
    }
    else
    {
        double lb = 0;
        for (const auto &term : l.vars)
            if (term.second > 0)
                if (th.lb(term.first) == -std::numeric_limits<double>::infinity())
                {
                    // nothing to propagate..
                    cnfl.clear();
                    return true;
                }
                else
                {
                    lb += term.second * th.lb(term.first);
                    cnfl.push_back(!*th.assigns[la_theory::lb_index(term.first)].reason);
                }
            else if (term.second < 0)
                if (th.ub(term.first) == std::numeric_limits<double>::infinity())
                {
                    // nothing to propagate..
                    cnfl.clear();
                    return true;
                }
                else
                {
                    lb += term.second * th.ub(term.first);
                    cnfl.push_back(!*th.assigns[la_theory::ub_index(term.first)].reason);
                }

        if (lb > th.lb(x))
            for (const auto &c : th.a_watches[x])
                if (lb > c->v)
                    switch (c->o)
                    {
                    case leq: // the assertion is unsatisfable..
                        cnfl[0] = lit(c->b, false);
                        switch (th.sat.value(c->b))
                        {
                        case True: // we have a propositional inconsistency..
                            return false;
                        case Undefined: // we propagate information to the sat core..
                            th.record(cnfl);
                        }
                        break;
                    case geq: // the assertion is satisfied..
                        cnfl[0] = c->b;
                        switch (th.sat.value(c->b))
                        {
                        case False: // we have a propositional inconsistency..
                            return false;
                        case Undefined: // we propagate information to the sat core..
                            th.record(cnfl);
                        }
                        break;
                    }
    }

    cnfl.clear();
    return true;
}
}