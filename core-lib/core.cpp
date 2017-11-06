#include "core.h"
#include "predicate.h"
#include "atom.h"
#include "method.h"
#include "field.h"
#include "declaration.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>

namespace lucy
{

core::core() : scope(*this, *this), env(*this, this), sat_cr(), la_th(sat_cr), ov_th(sat_cr)
{
    types.insert({BOOL_KEYWORD, new bool_type(*this)});
    types.insert({INT_KEYWORD, new int_type(*this)});
    types.insert({REAL_KEYWORD, new real_type(*this)});
    types.insert({STRING_KEYWORD, new string_type(*this)});
}

core::~core()
{
    // we delete the predicates..
    for (const auto &p : predicates)
        delete p.second;

    // we delete the types..
    for (const auto &t : types)
        delete t.second;

    // we delete the methods..
    for (const auto &ms : methods)
        for (const auto &m : ms.second)
            delete m;

    // we delete the compilation units..
    for (const auto &cu : cus)
        delete cu;
}

void core::read(const std::string &script)
{
    std::stringstream ss(script);
    ast::compilation_unit *cu = prs.parse(ss);
    cus.push_back(cu);

    cu->declare(*this);
    cu->refine(*this);
    context c_ctx(this);
    cu->execute(*this, c_ctx);

    if (!sat_cr.check())
        throw unsolvable_exception("the input problem is inconsistent");
}

void core::read(const std::vector<std::string> &files)
{
    std::vector<ast::compilation_unit *> c_cus;
    for (const auto &f : files)
    {
        std::ifstream ifs(f);
        if (ifs)
        {
            ast::compilation_unit *cu = prs.parse(ifs);
            c_cus.push_back(cu);
            cus.push_back(cu);
            ifs.close();
        }
        else
            throw std::invalid_argument("file not found: " + f);
    }

    for (const auto &cu : c_cus)
        cu->declare(*this);
    for (const auto &cu : c_cus)
        cu->refine(*this);
    context c_ctx(this);
    for (const auto &cu : c_cus)
        cu->execute(*this, c_ctx);

    if (!sat_cr.check())
        throw unsolvable_exception("the input problem is inconsistent");
}

bool_expr core::new_bool() { return new bool_item(*this, sat_cr.new_var()); }
bool_expr core::new_bool(const bool &val) { return new bool_item(*this, val); }

arith_expr core::new_int()
{
    std::cerr << "[warning] replacing an integer variable with a real variable.." << std::endl;
    return new arith_item(*this, *types.at(INT_KEYWORD), lin(la_th.new_var(), 1));
}

arith_expr core::new_int(const I &val)
{
    std::cerr << "[warning] replacing an integer constant with a real constant.." << std::endl;
    return new arith_item(*this, *types.at(INT_KEYWORD), lin(val));
}

arith_expr core::new_real() { return new arith_item(*this, *types.at(REAL_KEYWORD), lin(la_th.new_var(), 1)); }
arith_expr core::new_real(const rational &val) { return new arith_item(*this, *types.at(REAL_KEYWORD), lin(val)); }

string_expr core::new_string() { return new string_item(*this, ""); }
string_expr core::new_string(const std::string &val) { return new string_item(*this, val); }

expr core::new_enum(const type &tp, const std::unordered_set<item *> &allowed_vals)
{
    assert(allowed_vals.size() > 1);
    assert(tp.name.compare(BOOL_KEYWORD) != 0);
    assert(tp.name.compare(INT_KEYWORD) != 0);
    assert(tp.name.compare(REAL_KEYWORD) != 0);
    return new var_item(*this, tp, ov_th.new_var(std::unordered_set<var_value *>(allowed_vals.begin(), allowed_vals.end())));
}

expr core::new_enum(const type &tp, const std::vector<var> &vars, const std::vector<item *> &vals)
{
    if (tp.name.compare(BOOL_KEYWORD) == 0)
    {
        bool_expr b = new_bool();
        bool nc;
        for (size_t i = 0; i < vars.size(); ++i)
        {
            nc = sat_cr.new_clause({lit(vars.at(i), false), sat_cr.new_eq(dynamic_cast<bool_item *>(vals.at(i))->l, b->l)});
            assert(nc);
        }
        return b;
    }
    else if (tp.name.compare(INT_KEYWORD) == 0)
    {
        arith_expr ie = new_int();
        bool nc;
        for (size_t i = 0; i < vars.size(); ++i)
        {
            nc = sat_cr.new_clause({lit(vars.at(i), false), sat_cr.new_conj({la_th.new_leq(ie->l, dynamic_cast<arith_item *>(vals.at(i))->l), la_th.new_geq(ie->l, dynamic_cast<arith_item *>(vals.at(i))->l)})});
            assert(nc);
        }
        return ie;
    }
    else if (tp.name.compare(REAL_KEYWORD) == 0)
    {
        arith_expr re = new_real();
        bool nc;
        for (size_t i = 0; i < vars.size(); ++i)
        {
            nc = sat_cr.new_clause({lit(vars.at(i), false), sat_cr.new_conj({la_th.new_leq(re->l, dynamic_cast<arith_item *>(vals.at(i))->l), la_th.new_geq(re->l, dynamic_cast<arith_item *>(vals.at(i))->l)})});
            assert(nc);
        }
        return re;
    }
    else
        return new var_item(*this, tp, ov_th.new_var(vars, std::vector<var_value *>(vals.begin(), vals.end())));
}

bool_expr core::negate(bool_expr var) { return new bool_item(*this, !var->l); }
bool_expr core::eq(bool_expr left, bool_expr right) { return new bool_item(*this, sat_cr.new_eq(left->l, right->l)); }

bool_expr core::conj(const std::vector<bool_expr> &exprs)
{
    std::vector<lit> lits;
    for (const auto &bex : exprs)
        lits.push_back(bex->l);
    return new bool_item(*this, sat_cr.new_conj(lits));
}

bool_expr core::disj(const std::vector<bool_expr> &exprs)
{
    std::vector<lit> lits;
    for (const auto &bex : exprs)
        lits.push_back(bex->l);
    return new bool_item(*this, sat_cr.new_disj(lits));
}

bool_expr core::exct_one(const std::vector<bool_expr> &exprs)
{
    std::vector<lit> lits;
    for (const auto &bex : exprs)
        lits.push_back(bex->l);
    return new bool_item(*this, sat_cr.new_exct_one(lits));
}

arith_expr core::add(const std::vector<arith_expr> &exprs)
{
    assert(exprs.size() > 1);
    lin l;
    for (const auto &aex : exprs)
        l += aex->l;
    return new arith_item(*this, *types.at(REAL_KEYWORD), l);
}

arith_expr core::sub(const std::vector<arith_expr> &exprs)
{
    assert(exprs.size() > 1);
    lin l;
    for (std::vector<arith_expr>::const_iterator it = exprs.begin(); it != exprs.end(); ++it)
        if (it == exprs.begin())
            l += (*it)->l;
        else
            l -= (*it)->l;
    return new arith_item(*this, *types.at(REAL_KEYWORD), l);
}

arith_expr core::mult(const std::vector<arith_expr> &exprs)
{
    assert(exprs.size() > 1);
    arith_expr ae = *std::find_if(exprs.begin(), exprs.end(), [&](arith_expr ae) { return la_th.bounds(ae->l).constant(); });
    lin l = ae->l;
    for (const auto &aex : exprs)
        if (aex != ae)
        {
            assert(la_th.bounds(aex->l).constant() && "non-linear expression..");
            l *= la_th.value(aex->l);
        }
    return new arith_item(*this, *types.at(REAL_KEYWORD), l);
}

arith_expr core::div(const std::vector<arith_expr> &exprs)
{
    assert(exprs.size() > 1);
    assert(std::all_of(++exprs.begin(), exprs.end(), [&](arith_expr ae) { return la_th.bounds(ae->l).constant(); }) && "non-linear expression..");
    rational c = la_th.value(exprs[1]->l);
    for (size_t i = 2; i < exprs.size(); i++)
        c *= la_th.value(exprs.at(i)->l);
    return new arith_item(*this, *types.at(REAL_KEYWORD), exprs[0]->l / c);
}

arith_expr core::minus(arith_expr ex) { return new arith_item(*this, *types.at(REAL_KEYWORD), -ex->l); }

bool_expr core::lt(arith_expr left, arith_expr right)
{
    std::cerr << "[warning] replacing strict inequality (<) with non-strict inequality (<=).." << std::endl;
    return new bool_item(*this, la_th.new_leq(left->l, right->l));
}

bool_expr core::leq(arith_expr left, arith_expr right) { return new bool_item(*this, la_th.new_leq(left->l, right->l)); }
bool_expr core::eq(arith_expr left, arith_expr right) { return new bool_item(*this, sat_cr.new_conj({la_th.new_leq(left->l, right->l), la_th.new_geq(left->l, right->l)})); }
bool_expr core::geq(arith_expr left, arith_expr right) { return new bool_item(*this, la_th.new_geq(left->l, right->l)); }

bool_expr core::gt(arith_expr left, arith_expr right)
{
    std::cerr << "[warning] replacing strict inequality (>) with non-strict inequality (>=).." << std::endl;
    return new bool_item(*this, la_th.new_geq(left->l, right->l));
}

bool_expr core::eq(expr left, expr right) { return new bool_item(*this, left->eq(*right)); }

void core::assert_facts(const std::vector<lit> &facts)
{
    for (const auto &f : facts)
        if (!sat_cr.new_clause({lit(ctr_var, false), f}))
            throw unsolvable_exception();
}

field &core::get_field(const std::string &name) const
{
    if (fields.find(name) != fields.end())
        return *fields.at(name);

    // not found
    throw std::out_of_range(name);
}

method &core::get_method(const std::string &name, const std::vector<const type *> &ts) const
{
    if (methods.find(name) != methods.end())
    {
        bool found = false;
        for (const auto &mthd : methods.at(name))
            if (mthd->args.size() == ts.size())
            {
                found = true;
                for (size_t i = 0; i < ts.size(); i++)
                    if (!mthd->args.at(i)->tp.is_assignable_from(*ts.at(i)))
                    {
                        found = false;
                        break;
                    }
                if (found)
                    return *mthd;
            }
    }

    // not found
    throw std::out_of_range(name);
}

predicate &core::get_predicate(const std::string &name) const
{
    if (predicates.find(name) != predicates.end())
        return *predicates.at(name);

    // not found
    throw std::out_of_range(name);
}

type &core::get_type(const std::string &name) const
{
    if (types.find(name) != types.end())
        return *types.at(name);

    // not found
    throw std::out_of_range(name);
}

expr core::get(const std::string &name) const
{
    if (items.find(name) != items.end())
        return items.at(name);

    throw std::out_of_range(name);
}

lbool core::bool_value(const bool_expr &x) const noexcept { return sat_cr.value(x->l); }

interval core::arith_bounds(const arith_expr &x) const noexcept { return la_th.bounds(x->l); }

rational core::arith_value(const arith_expr &x) const noexcept { return la_th.value(x->l); }

std::unordered_set<var_value *> core::enum_value(const var_expr &x) const noexcept { return ov_th.value(x->ev); }

std::string core::to_string(const std::map<std::string, expr> &c_items) const noexcept
{
    std::string iss;
    for (std::map<std::string, expr>::const_iterator is_it = c_items.begin(); is_it != c_items.end(); ++is_it)
    {
        if (is_it != c_items.begin())
            iss += ", ";
        iss += "{ \"name\" : \"" + is_it->first + "\", \"type\" : \"" + is_it->second->tp.name + "\", \"value\" : ";
        if (bool_item *bi = dynamic_cast<bool_item *>(&*is_it->second))
        {
            std::string sign_s = bi->l.sign ? "b" : "!b";
            iss += "{ \"lit\" : \"" + sign_s + std::to_string(bi->l.v) + "\", \"val\" : ";
            switch (sat_cr.value(bi->l))
            {
            case True:
                iss += "\"True\"";
                break;
            case False:
                iss += "\"False\"";
                break;
            case Undefined:
                iss += "\"Undefined\"";
                break;
            }
            iss += " }";
        }
        else if (arith_item *ai = dynamic_cast<arith_item *>(&*is_it->second))
        {
            interval bnds = la_th.bounds(ai->l);
            iss += "{ \"lin\" : \"" + ai->l.to_string() + "\", \"val\" : " + la_th.value(ai->l).to_string();
            if (!bnds.lb.is_negative_infinite())
                iss += ", \"lb\" : " + bnds.lb.to_string();
            if (!bnds.ub.is_positive_infinite())
                iss += ", \"ub\" : " + bnds.ub.to_string();
            iss += " }";
        }
        else if (var_item *ei = dynamic_cast<var_item *>(&*is_it->second))
        {
            iss += "{ \"var\" : \"e" + std::to_string(ei->ev) + "\", \"vals\" : [ ";
            std::unordered_set<var_value *> vals = ov_th.value(ei->ev);
            for (std::unordered_set<var_value *>::iterator vals_it = vals.begin(); vals_it != vals.end(); ++vals_it)
            {
                if (vals_it != vals.begin())
                    iss += ", ";
                iss += "\"" + std::to_string(reinterpret_cast<uintptr_t>(static_cast<item *>(*vals_it))) + "\"";
            }
            iss += " ] }";
        }
        else
            iss += "\"" + std::to_string(reinterpret_cast<uintptr_t>(&*is_it->second)) + "\"";
        iss += " }";
    }
    return iss;
}

std::string core::to_string(const item *const i) const noexcept
{
    std::string is;
    is += "{ \"id\" : \"" + std::to_string(reinterpret_cast<uintptr_t>(i)) + "\", \"type\" : \"" + i->tp.name + "\"";
    std::map<std::string, expr> c_is = i->get_items();
    if (!c_is.empty())
        is += ", \"items\" : [ " + to_string(c_is) + " ]";
    is += "}";
    return is;
}

std::string core::to_string(const atom *const a) const noexcept
{
    std::string as;
    as += "{ \"id\" : \"" + std::to_string(reinterpret_cast<uintptr_t>(a)) + "\", \"predicate\" : \"" + a->tp.name + "\", \"state\" : ";
    switch (sat_cr.value(a->sigma))
    {
    case True:
        as += "\"Active\"";
        break;
    case False:
        as += "\"Unified\"";
        break;
    case Undefined:
        as += "\"Inactive\"";
        break;
    }
    std::map<std::string, expr> is = a->get_items();
    if (!is.empty())
        as += ", \"pars\" : [ " + to_string(is) + " ]";
    as += "}";
    return as;
}

std::string core::to_string() const noexcept
{
    std::set<item *> all_items;
    std::set<atom *> all_atoms;
    for (const auto &p : get_predicates())
        for (const auto &a : p.second->get_instances())
            all_atoms.insert(static_cast<atom *>(&*a));
    std::queue<type *> q;
    for (const auto &t : get_types())
        if (!t.second->primitive)
            q.push(t.second);
    while (!q.empty())
    {
        for (const auto &i : q.front()->get_instances())
            all_items.insert(&*i);
        for (const auto &p : q.front()->get_predicates())
            for (const auto &a : p.second->get_instances())
                all_atoms.insert(static_cast<atom *>(&*a));
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
                cr += ", ";
            cr += to_string(*is_it);
        }
        cr += "]";
    }
    if (!all_atoms.empty())
    {
        if (!all_items.empty())
            cr += ", ";
        cr += "\"atoms\" : [";
        for (std::set<atom *>::iterator as_it = all_atoms.begin(); as_it != all_atoms.end(); ++as_it)
        {
            if (as_it != all_atoms.begin())
                cr += ", ";
            cr += to_string(*as_it);
        }
        cr += "]";
    }
    if (!all_items.empty() || !all_atoms.empty())
        cr += ", ";
    cr += "\"refs\" : [" + to_string(get_items()) + "] }";
    return cr;
}
}