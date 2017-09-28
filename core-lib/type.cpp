#include "type.h"
#include "item.h"
#include "core.h"
#include "field.h"
#include "constructor.h"
#include "method.h"
#include "predicate.h"
#include <algorithm>
#include <unordered_set>
#include <cassert>

namespace lucy
{

type::type(core &cr, scope &scp, const std::string &name, bool primitive) : scope(cr, scp), name(name), primitive(primitive) {}

type::~type()
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

    // we delete the constructors..
    for (const auto &c : constructors)
        delete c;
}

bool type::is_assignable_from(const type &t) const noexcept
{
    std::queue<const type *> q;
    q.push(&t);
    while (!q.empty())
    {
        if (q.front() == this)
            return true;
        else
        {
            for (const auto &st : q.front()->supertypes)
                q.push(st);
            q.pop();
        }
    }
    return false;
}

expr type::new_instance(context &ctx)
{
    expr i = new item(cr, ctx, *this);
    std::queue<type *> q;
    q.push(this);
    while (!q.empty())
    {
        q.front()->instances.push_back(i);
        for (const auto &st : q.front()->supertypes)
            q.push(st);
        q.pop();
    }

    return i;
}

expr type::new_existential()
{
    if (instances.size() == 1)
        return *instances.begin();
    else
    {
        std::unordered_set<item *> c_items;
        for (const auto &i : instances)
            c_items.insert(&*i);
        return cr.new_enum(*this, c_items);
    }
}

constructor &type::get_constructor(const std::vector<const type *> &ts) const
{
    assert(std::none_of(ts.begin(), ts.end(), [](const type *t) { return t == nullptr; }));
    bool found = false;
    for (const auto &cnstr : constructors)
        if (cnstr->args.size() == ts.size())
        {
            found = true;
            for (unsigned int i = 0; i < ts.size(); i++)
                if (!cnstr->args[i]->tp.is_assignable_from(*ts[i]))
                {
                    found = false;
                    break;
                }
            if (found)
                return *cnstr;
        }

    throw std::out_of_range(name);
}

field &type::get_field(const std::string &f_name) const
{
    if (fields.find(f_name) != fields.end())
        return *fields.at(f_name);

    // if not here, check any enclosing scope
    try
    {
        return scp.get_field(f_name);
    }
    catch (const std::out_of_range &)
    {
        // if not in any enclosing scope, check any superclass
        for (const auto &st : supertypes)
        {
            try
            {
                return st->get_field(f_name);
            }
            catch (const std::out_of_range &)
            {
            }
        }
    }

    // not found
    throw std::out_of_range(f_name);
}

method &type::get_method(const std::string &m_name, const std::vector<const type *> &ts) const
{
    if (methods.find(m_name) != methods.end())
    {
        bool found = false;
        for (const auto &mthd : methods.at(m_name))
            if (mthd->args.size() == ts.size())
            {
                found = true;
                for (unsigned int i = 0; i < ts.size(); i++)
                    if (!mthd->args[i]->tp.is_assignable_from(*ts[i]))
                    {
                        found = false;
                        break;
                    }
                if (found)
                    return *mthd;
            }
    }

    // if not here, check any enclosing scope
    try
    {
        return scp.get_method(m_name, ts);
    }
    catch (const std::out_of_range &)
    {
        // if not in any enclosing scope, check any superclass
        for (const auto &st : supertypes)
        {
            try
            {
                return st->get_method(m_name, ts);
            }
            catch (const std::out_of_range &)
            {
            }
        }
    }

    // not found
    throw std::out_of_range(m_name);
}

predicate &type::get_predicate(const std::string &p_name) const
{
    if (predicates.find(p_name) != predicates.end())
        return *predicates.at(p_name);

    // if not here, check any enclosing scope
    try
    {
        return scp.get_predicate(p_name);
    }
    catch (const std::out_of_range &)
    {
        // if not in any enclosing scope, check any superclass
        for (const auto &st : supertypes)
        {
            try
            {
                return st->get_predicate(p_name);
            }
            catch (const std::out_of_range &)
            {
            }
        }
    }

    // not found
    throw std::out_of_range(p_name);
}

type &type::get_type(const std::string &t_name) const
{
    if (types.find(t_name) != types.end())
        return *types.at(t_name);

    // if not here, check any enclosing scope
    try
    {
        return scp.get_type(t_name);
    }
    catch (const std::out_of_range &)
    {
        // if not in any enclosing scope, check any superclass
        for (const auto &st : supertypes)
        {
            try
            {
                return st->get_type(t_name);
            }
            catch (const std::out_of_range &)
            {
            }
        }
    }

    // not found
    throw std::out_of_range(t_name);
}

void type::set_var(const var &v) { cr.set_var(v); }
void type::restore_var() { cr.restore_var(); }

void type::inherit(type &base, type &derived) { derived.supertypes.push_back(&base); }

bool_type::bool_type(core &cr) : type(cr, cr, BOOL_KEYWORD, true) {}
bool_type::~bool_type() {}

expr bool_type::new_instance(context &) { return cr.new_bool(); }

int_type::int_type(core &cr) : type(cr, cr, INT_KEYWORD, true) {}
int_type::~int_type() {}

expr int_type::new_instance(context &) { return cr.new_int(); }

real_type::real_type(core &cr) : type(cr, cr, REAL_KEYWORD, true) {}
real_type::~real_type() {}

expr real_type::new_instance(context &) { return cr.new_real(); }

string_type::string_type(core &cr) : type(cr, cr, STRING_KEYWORD, true) {}
string_type::~string_type() {}

expr string_type::new_instance(context &) { return cr.new_string(); }
}