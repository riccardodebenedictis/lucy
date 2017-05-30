#include "core.h"
#include "predicate.h"
#include "atom.h"
#include "method.h"
#include "field.h"
#include "type_declaration_listener.h"
#include "type_refinement_listener.h"
#include "statement_visitor.h"
#include "log.h"
#include <iostream>
#include <cassert>

namespace lucy
{

core::core() : scope(*this, *this), env(*this, this), sat(), la_th(sat), set_th(sat), active(new atom_state()), inactive(new atom_state()), unified(new atom_state())
{
    LOG("creating lucy core..");
    types.insert({BOOL_KEYWORD, new bool_type(*this)});
    types.insert({INT_KEYWORD, new int_type(*this)});
    types.insert({REAL_KEYWORD, new real_type(*this)});
    types.insert({STRING_KEYWORD, new string_type(*this)});
}

core::~core()
{
    LOG("deleting lucy core..");
    for (const auto &p : parsers)
    {
        delete p;
    }
    for (const auto &p : predicates)
    {
        delete p.second;
    }
    for (const auto &t : types)
    {
        delete t.second;
    }
    for (const auto &ms : methods)
    {
        for (const auto &m : ms.second)
        {
            delete m;
        }
    }
    delete active;
    delete inactive;
    delete unified;
}

bool core::read(const std::string &script)
{
    p = new ratioParser(new antlr4::CommonTokenStream(new ratioLexer(new antlr4::ANTLRInputStream(script))));
    parsers.push_back(p);
    ratioParser::Compilation_unitContext *cu = p->compilation_unit();
    type_declaration_listener td(*this);
    type_refinement_listener tr(*this);
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&td, cu);
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&tr, cu);
    context ctx(this);
    if (!statement_visitor(*this, ctx).visit(cu).as<bool>())
    {
        return false;
    }
    p = nullptr;
    if (!sat.check())
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool core::read(const std::vector<std::string> &files)
{
    std::vector<snippet *> snippets;
    for (const auto &f : files)
    {
        p = new ratioParser(new antlr4::CommonTokenStream(new ratioLexer(new antlr4::ANTLRFileStream(f))));
        parsers.push_back(p);
        snippet *s = new snippet(f, *p, p->compilation_unit());
        snippets.push_back(s);
    }
    type_declaration_listener td(*this);
    for (const auto &s : snippets)
    {
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&td, s->cu);
    }
    type_refinement_listener tr(*this);
    for (const auto &s : snippets)
    {
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&tr, s->cu);
    }
    context ctx(this);
    statement_visitor sv(*this, ctx);
    for (const auto &s : snippets)
    {
        p = &s->p;
        if (!sv.visit(s->cu).as<bool>())
        {
            return false;
        }
    }
    p = nullptr;
    if (!sat.check())
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool_expr core::new_bool()
{
    return new bool_item(*this, lit(sat.new_var(), true));
}

bool_expr core::new_bool(const bool &val)
{
    return new bool_item(*this, lit(val, true));
}

arith_expr core::new_int()
{
    std::cerr << "[warning] replacing an integer variable with a real variable.." << std::endl;
    return new arith_item(*this, *types.at(REAL_KEYWORD), lin(la_th.new_var(), 1));
}

arith_expr core::new_int(const long &val)
{
    return new arith_item(*this, *types.at(REAL_KEYWORD), lin(val));
}

arith_expr core::new_real()
{
    return new arith_item(*this, *types.at(REAL_KEYWORD), lin(la_th.new_var(), 1));
}

arith_expr core::new_real(const double &val)
{
    return new arith_item(*this, *types.at(REAL_KEYWORD), lin(val));
}

string_expr core::new_string()
{
    return new string_item(*this, "");
}

string_expr core::new_string(const std::string &val)
{
    return new string_item(*this, val);
}

expr core::new_enum(const type &t, const std::unordered_set<item *> &allowed_vals)
{
    assert(allowed_vals.size() > 1);
    std::unordered_set<set_item *> vals(allowed_vals.begin(), allowed_vals.end());
    if (t.name.compare(BOOL_KEYWORD) == 0)
    {
        bool_expr b = new_bool();
        std::vector<lit> eqs;
        for (const auto &v : allowed_vals)
        {
            eqs.push_back(lit(sat.new_eq(b->l, dynamic_cast<bool_item *>(v)->l), true));
        }
        bool nc = sat.new_clause(eqs);
        assert(nc);
        return b;
    }
    else if (t.name.compare(INT_KEYWORD) == 0)
    {
        arith_expr i = new_int();
        std::vector<lit> eqs;
        for (const auto &v : allowed_vals)
        {
            var leq_v = la_th.new_leq(i->l, dynamic_cast<arith_item *>(v)->l);
            var geq_v = la_th.new_geq(i->l, dynamic_cast<arith_item *>(v)->l);
            var eq_v = sat.new_conj({lit(leq_v, true), lit(geq_v, true)});
            eqs.push_back(lit(eq_v, true));
        }
        bool nc = sat.new_clause(eqs);
        assert(nc);
        return i;
    }
    else if (t.name.compare(REAL_KEYWORD) == 0)
    {
        arith_expr r = new_real();
        std::vector<lit> eqs;
        for (const auto &v : allowed_vals)
        {
            var leq_v = la_th.new_leq(r->l, dynamic_cast<arith_item *>(v)->l);
            var geq_v = la_th.new_geq(r->l, dynamic_cast<arith_item *>(v)->l);
            var eq_v = sat.new_conj({lit(leq_v, true), lit(geq_v, true)});
            eqs.push_back(lit(eq_v, true));
        }
        bool nc = sat.new_clause(eqs);
        assert(nc);
        return r;
    }
    else
    {
        return new enum_item(*this, t, set_th.new_var(vals));
    }
}

bool_expr core::negate(bool_expr var)
{
    return new bool_item(*this, !var->l);
}

bool_expr core::eq(bool_expr left, bool_expr right)
{
    return new bool_item(*this, lit(sat.new_eq(left->l, right->l), true));
}

bool_expr core::conj(const std::vector<bool_expr> &exprs)
{
    std::vector<lit> lits;
    for (const auto &bex : exprs)
    {
        lits.push_back(bex->l);
    }
    return new bool_item(*this, lit(sat.new_conj(lits), true));
}

bool_expr core::disj(const std::vector<bool_expr> &exprs)
{
    std::vector<lit> lits;
    for (const auto &bex : exprs)
    {
        lits.push_back(bex->l);
    }
    return new bool_item(*this, lit(sat.new_disj(lits), true));
}

bool_expr core::exct_one(const std::vector<bool_expr> &exprs)
{
    std::vector<lit> lits;
    for (const auto &bex : exprs)
    {
        lits.push_back(bex->l);
    }
    return new bool_item(*this, lit(sat.new_exct_one(lits), true));
}

arith_expr core::add(const std::vector<arith_expr> &exprs)
{
    lin l;
    for (const auto &aex : exprs)
    {
        l += aex->l;
    }
    return new arith_item(*this, *types.at(REAL_KEYWORD), l);
}

arith_expr core::sub(const std::vector<arith_expr> &exprs)
{
    lin l;
    for (std::vector<arith_expr>::const_iterator it = exprs.begin(); it != exprs.end(); ++it)
    {
        if (it == exprs.begin())
        {
            l += (*it)->l;
        }
        else
        {
            l -= (*it)->l;
        }
    }
    return new arith_item(*this, *types.at(REAL_KEYWORD), l);
}

arith_expr core::mult(const std::vector<arith_expr> &exprs)
{
    arith_expr ae = *std::find_if(exprs.begin(), exprs.end(), [&](arith_expr ae) { return la_th.bounds(ae->l).constant(); });
    lin l = ae->l;
    for (const auto &aex : exprs)
    {
        if (aex != ae)
        {
            assert(la_th.bounds(aex->l).constant() && "non-linear expression..");
            l *= la_th.value(aex->l);
        }
    }
    return new arith_item(*this, *types.at(REAL_KEYWORD), l);
}

arith_expr core::div(arith_expr left, arith_expr right)
{
    assert(la_th.bounds(right->l).constant() && "non-linear expression..");
    return new arith_item(*this, *types.at(REAL_KEYWORD), left->l / la_th.value(right->l));
}

arith_expr core::minus(arith_expr ex)
{
    return new arith_item(*this, *types.at(REAL_KEYWORD), -ex->l);
}

bool_expr core::lt(arith_expr left, arith_expr right)
{
    std::cerr << "[warning] replacing strict inequality (<) with non-strict inequality (<=).." << std::endl;
    return new bool_item(*this, lit(la_th.new_leq(left->l, right->l), true));
}

bool_expr core::leq(arith_expr left, arith_expr right)
{
    return new bool_item(*this, lit(la_th.new_leq(left->l, right->l), true));
}

bool_expr core::eq(arith_expr left, arith_expr right)
{
    return new bool_item(*this, lit(sat.new_conj({lit(la_th.new_leq(left->l, right->l), true), lit(la_th.new_geq(left->l, right->l), true)}), true));
}

bool_expr core::geq(arith_expr left, arith_expr right)
{
    return new bool_item(*this, lit(la_th.new_geq(left->l, right->l), true));
}

bool_expr core::gt(arith_expr left, arith_expr right)
{
    std::cerr << "[warning] replacing strict inequality (>) with non-strict inequality (>=).." << std::endl;
    return new bool_item(*this, lit(la_th.new_geq(left->l, right->l), true));
}

bool_expr core::eq(expr left, expr right)
{
    return new bool_item(*this, lit(left->eq(*right), true));
}

bool core::assert_facts(const std::vector<lit> &facts)
{
    for (const auto &f : facts)
    {
        if (!sat.new_clause({lit(ctr_var, false), f}))
        {
            return false;
        }
    }
    return true;
}

field &core::get_field(const std::string &name) const
{
    if (fields.find(name) != fields.end())
    {
        return *fields.at(name);
    }

    // not found
    throw std::out_of_range(name);
}

method &core::get_method(const std::string &name, const std::vector<const type *> &ts) const
{
    if (methods.find(name) != methods.end())
    {
        bool found = false;
        for (const auto &mthd : methods.at(name))
        {
            if (mthd->args.size() == ts.size())
            {
                found = true;
                for (size_t i = 0; i < ts.size(); i++)
                {
                    if (!mthd->args[i]->tp.is_assignable_from(*ts[i]))
                    {
                        found = false;
                        break;
                    }
                }
                if (found)
                {
                    return *mthd;
                }
            }
        }
    }

    // not found
    throw std::out_of_range(name);
}

predicate &core::get_predicate(const std::string &name) const
{
    if (predicates.find(name) != predicates.end())
    {
        return *predicates.at(name);
    }

    // not found
    throw std::out_of_range(name);
}

type &core::get_type(const std::string &name) const
{
    if (types.find(name) != types.end())
    {
        return *types.at(name);
    }

    // not found
    throw std::out_of_range(name);
}

expr core::get(const std::string &name) const
{
    if (items.find(name) != items.end())
    {
        return items.at(name);
    }

    throw std::out_of_range(name);
}

lbool core::bool_value(const bool_expr &var) const noexcept { return sat.value(var->l); }

interval core::arith_bounds(const arith_expr &var) const noexcept { return la_th.bounds(var->l); }

double core::arith_value(const arith_expr &var) const noexcept { return la_th.value(var->l); }

std::unordered_set<set_item *> core::enum_value(const enum_expr &var) const noexcept { return set_th.value(var->ev); }

bool core::new_fact(atom &atm)
{
    if (&atm.tp.get_scope() == this)
    {
        return true;
    }
    std::queue<type *> q;
    q.push(static_cast<type *>(&atm.tp.get_scope()));
    while (!q.empty())
    {
        if (!q.front()->new_fact(atm))
        {
            return false;
        }
        for (const auto &st : q.front()->get_supertypes())
        {
            q.push(st);
        }
        q.pop();
    }
    return true;
}

bool core::new_goal(atom &atm)
{
    if (&atm.tp.get_scope() == this)
    {
        return true;
    }
    std::queue<type *> q;
    q.push(static_cast<type *>(&atm.tp.get_scope()));
    while (!q.empty())
    {
        if (!q.front()->new_goal(atm))
        {
            return false;
        }
        for (const auto &st : q.front()->get_supertypes())
        {
            q.push(st);
        }
        q.pop();
    }
    return true;
}

std::string core::to_string(std::unordered_map<std::string, expr> items)
{
    std::string iss;
    for (std::unordered_map<std::string, expr>::iterator is_it = items.begin(); is_it != items.end(); ++is_it)
    {
        if (is_it != items.begin())
        {
            iss += ", ";
        }
        iss += "{ \"name\" : \"" + is_it->first + "\", \"type\" : \"" + is_it->second->tp.name + "\", \"value\" : ";
        if (bool_item *bi = dynamic_cast<bool_item *>(&*is_it->second))
        {
            std::string sign_s = bi->l.sign ? "b" : "!b";
            iss += "{ \"lit\" : \"" + sign_s + std::to_string(bi->l.v) + "\", \"val\" : ";
            switch (sat.value(bi->l))
            {
            case smt::True:
                iss += "\"True\"";
                break;
            case smt::False:
                iss += "\"False\"";
                break;
            case smt::Undefined:
                iss += "\"Undefined\"";
                break;
            }
            iss += " }";
        }
        else if (arith_item *ai = dynamic_cast<arith_item *>(&*is_it->second))
        {
            smt::interval bnds = la_th.bounds(ai->l);
            iss += "{ \"lin\" : \"" + ai->l.to_string() + "\", \"val\" : " + std::to_string(la_th.value(ai->l));
            if (bnds.lb > -std::numeric_limits<double>::infinity())
            {
                iss += ", \"lb\" : " + std::to_string(bnds.lb);
            }
            if (bnds.ub < std::numeric_limits<double>::infinity())
            {
                iss += ", \"ub\" : " + std::to_string(bnds.ub);
            }
            iss += " }";
        }
        else if (enum_item *ei = dynamic_cast<enum_item *>(&*is_it->second))
        {
            iss += "{ \"var\" : \"e" + std::to_string(ei->ev) + "\", \"vals\" : [ ";
            std::unordered_set<smt::set_item *> vals = set_th.value(ei->ev);
            for (std::unordered_set<smt::set_item *>::iterator vals_it = vals.begin(); vals_it != vals.end(); ++vals_it)
            {
                if (vals_it != vals.begin())
                {
                    iss += ", ";
                }
                iss += "\"" + std::to_string(reinterpret_cast<uintptr_t>(static_cast<item *>(*vals_it))) + "\"";
            }
            iss += " ] }";
        }
        else
        {
            iss += "\"" + std::to_string(reinterpret_cast<uintptr_t>(&*is_it->second)) + "\"";
        }
        iss += " }";
    }
    return iss;
}

std::string core::to_string(item *i)
{
    std::string is;
    is += "{ \"id\" : \"" + std::to_string(reinterpret_cast<uintptr_t>(i)) + "\", \"type\" : \"" + i->tp.name + "\"";
    std::unordered_map<std::string, expr> c_is = i->get_items();
    if (!c_is.empty())
    {
        is += ", \"items\" : [ " + to_string(c_is) + " ]";
    }
    is += "}";
    return is;
}

std::string core::to_string(atom *a)
{
    std::string as;
    as += "{ \"id\" : \"" + std::to_string(reinterpret_cast<uintptr_t>(a)) + "\", \"predicate\" : \"" + a->tp.name + "\", \"state\" : [";
    std::unordered_set<smt::set_item *> state_vals = set_th.value(a->state);
    for (std::unordered_set<smt::set_item *>::iterator vals_it = state_vals.begin(); vals_it != state_vals.end(); ++vals_it)
    {
        if (vals_it != state_vals.begin())
        {
            as += ", ";
        }
        if (*vals_it == active)
        {
            as += "\"Active\"";
        }
        else if (*vals_it == inactive)
        {
            as += "\"Inactive\"";
        }
        else if (*vals_it == unified)
        {
            as += "\"Unified\"";
        }
    }
    as += "]";
    std::unordered_map<std::string, expr> is = a->get_items();
    if (!is.empty())
    {
        as += ", \"pars\" : [ " + to_string(is) + " ]";
    }
    as += "}";
    return as;
}

std::string core::to_string()
{
    std::set<item *> all_items;
    std::set<atom *> all_atoms;
    for (const auto &p : get_predicates())
    {
        for (const auto &a : p.second->get_instances())
        {
            all_atoms.insert(static_cast<atom *>(&*a));
        }
    }
    std::queue<type *> q;
    for (const auto &t : get_types())
    {
        if (!t.second->primitive)
        {
            q.push(t.second);
        }
    }
    while (!q.empty())
    {
        for (const auto &i : q.front()->get_instances())
        {
            all_items.insert(&*i);
        }
        for (const auto &p : q.front()->get_predicates())
        {
            for (const auto &a : p.second->get_instances())
            {
                all_atoms.insert(static_cast<atom *>(&*a));
            }
        }
        q.pop();
    }

    std::string cr;
    cr += "{ ";
    if (!all_items.empty())
    {
        cr += "\"items\" : [";
        for (std::set<item *>::iterator is_it = all_items.begin(); is_it != all_items.end(); ++is_it)
        {
            if (is_it != all_items.begin())
            {
                cr += ", ";
            }
            cr += to_string(*is_it);
        }
        cr += "]";
    }
    if (!all_atoms.empty())
    {
        if (!all_items.empty())
        {
            cr += ", ";
        }
        cr += "\"atoms\" : [";
        for (std::set<atom *>::iterator as_it = all_atoms.begin(); as_it != all_atoms.end(); ++as_it)
        {
            if (as_it != all_atoms.begin())
            {
                cr += ", ";
            }
            cr += to_string(*as_it);
        }
        cr += "]";
    }
    if (!all_items.empty() || !all_atoms.empty())
    {
        cr += ", ";
    }
    cr += "\"refs\" : [" + to_string(get_items()) + "] }";
    return cr;
}
}