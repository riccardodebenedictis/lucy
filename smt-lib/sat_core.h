#pragma once

#include "lit.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>

namespace smt
{

class clause;
class theory;
class sat_value_listener;

static const var FALSE_var = 0;
static const var TRUE_var = 1;

enum lbool
{
    False,
    True,
    Undefined
};

class sat_core
{
    friend class clause;
    friend class theory;
    friend class sat_value_listener;

  public:
    sat_core();
    sat_core(const sat_core &orig) = delete;
    virtual ~sat_core();

    const var new_var();
    bool new_clause(const std::vector<lit> &lits);

    const var new_eq(const lit &left, const lit &right);
    const var new_conj(const std::vector<lit> &ls);
    const var new_disj(const std::vector<lit> &ls);
    const var new_exct_one(const std::vector<lit> &ls);

    bool eq(const lit &left, const lit &right) { return new_clause({!left, right}) && new_clause({left, !right}); }

    bool exct_one(const std::vector<lit> &lits)
    {
        // the at-least-one clause..
        std::vector<lit> ls;
        for (size_t i = 0; i < lits.size(); i++)
        {
            for (size_t j = i + 1; j < lits.size(); j++)
                // the at-most-one clauses..
                if (!new_clause({!lits[i], !lits[j]}))
                    return false;
            ls.push_back(lits[i]);
        }
        return new_clause(ls);
    }

    bool assume(const lit &p);
    void pop();

    size_t n_vars() { return assigns.size(); }             // the number of variables..
    size_t n_assigns() { return trail.size(); }            // the number of assigned variables..
    size_t n_constrs() { return constrs.size(); }          // the number of constraints..
    lbool value(const var &x) const { return assigns[x]; } // returns the value of variable 'v'..

    lbool value(const lit &p) const
    {
        switch (value(p.v))
        {
        case True:
            return p.sign ? True : False;
        case False:
            return p.sign ? False : True;
        case Undefined:
            return Undefined;
        default:
            throw std::logic_error("invalid value..");
        }
    }

    clause &get_constr(const size_t &id) { return *constrs.at(id); }

    size_t decision_level() { return trail_lim.size(); } // returns the current decision level..
    bool root_level() { return trail_lim.empty(); }      // checks whether this decision level is root level..

    bool check();
    bool check(const std::vector<lit> &lits);

  private:
    bool propagate(std::vector<lit> &cnfl);
    void analyze(const std::vector<lit> &cnfl, std::vector<lit> &out_learnt, size_t &out_btlevel);
    void record(const std::vector<lit> &lits);

    bool enqueue(const lit &p, clause *const c = nullptr);
    void pop_one();

    size_t index(const lit &p) const { return p.sign ? p.v << 1 : (p.v << 1) ^ 1; }

    void add_theory(theory &th);
    void remove_theory(theory &th);
    void bind(const var &v, theory &th);
    void unbind(const var &v, theory &th);

    void listen(const var &v, sat_value_listener *const l);
    void forget(const var &v, sat_value_listener *const l);

  private:
    std::vector<clause *> constrs;              // collection of problem constraints..
    std::vector<std::vector<clause *>> watches; // for each literal 'p', a list of constraints watching 'p'..
    std::queue<lit> prop_q;                     // propagation queue..
    std::vector<lbool> assigns;                 // the current assignments..
    std::vector<lit> trail;                     // the list of assignment in chronological order..
    std::vector<size_t> trail_lim;              // separator indices for different decision levels in 'trail'..
    std::vector<clause *> reason;               // for each variable, the constraint that implied its value..
    std::vector<size_t> level;                  // for each variable, the decision level it was assigned..
    std::unordered_map<std::string, var> exprs; // the already existing expressions (string to bool variable)..

    std::vector<theory *> theories; // all the theories..
    std::unordered_map<var, std::list<theory *>> bounds;
    std::unordered_map<var, std::list<sat_value_listener *>> listening;
};

class sat_value_listener
{
    friend class sat_core;

  public:
    sat_value_listener(sat_core &s) : sat(s) {}
    sat_value_listener(const sat_value_listener &that) = delete;

    virtual ~sat_value_listener()
    {
        for (const auto &v : sat_vars)
            sat.forget(v, this);
    }

  protected:
    void listen_sat(var v)
    {
        sat.listen(v, this);
        sat_vars.push_back(v);
    }

  private:
    virtual void sat_value_change(const var &) {}

  private:
    sat_core &sat;
    std::vector<var> sat_vars;
};
}
