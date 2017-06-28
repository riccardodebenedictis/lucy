#include "declaration.h"
#include "statement.h"
#include "expression.h"
#include "core.h"
#include "field.h"
#include "constructor.h"
#include "method.h"
#include "predicate.h"
#include "typedef_type.h"
#include "enum_type.h"

namespace lucy
{

namespace ast
{

type_declaration::type_declaration(const std::string &n) : name(n) {}
type_declaration::~type_declaration() {}

typedef_declaration::typedef_declaration(const std::string &n, const std::string &pt, const expression *const e) : type_declaration(n), primitive_type(pt), xpr(e) {}
typedef_declaration::~typedef_declaration() { delete xpr; }
void typedef_declaration::declare(scope &scp) const
{
    // A new typedef type has been declared..
    typedef_type *td = new typedef_type(scp.get_core(), scp, name, scp.get_type(primitive_type), xpr);

    if (core *c = dynamic_cast<core *>(&scp))
        c->types.insert({name, td});
    else if (type *t = dynamic_cast<type *>(&scp))
        t->types.insert({name, td});
}

enum_declaration::enum_declaration(const std::string &n, const std::vector<std::string> &es, const std::vector<std::vector<std::string>> &trs) : type_declaration(n), enums(es), type_refs(trs) {}
enum_declaration::~enum_declaration() {}
void enum_declaration::declare(scope &scp) const
{
    // A new enum type has been declared..
    enum_type *et = new enum_type(scp.get_core(), scp, name);

    // We add the enum values..
    for (const auto &e : enums)
        et->instances.push_back(scp.get_core().new_string(e));

    if (core *c = dynamic_cast<core *>(&scp))
        c->types.insert({name, et});
    else if (type *t = dynamic_cast<type *>(&scp))
        t->types.insert({name, et});
}
void enum_declaration::refine(scope &scp) const
{
    if (!type_refs.empty())
    {
        enum_type *et = static_cast<enum_type *>(&scp.get_type(name));
        for (const auto &tr : type_refs)
        {
            scope *s = &scp;
            for (const auto &id : tr)
                s = &s->get_type(id);
            et->enums.push_back(static_cast<enum_type *>(s));
        }
    }
}

variable_declaration::variable_declaration(const std::string &n, const expression *const e) : name(n), xpr(e) {}
variable_declaration::~variable_declaration() { delete xpr; }

field_declaration::field_declaration(const std::vector<std::string> &tp, const std::vector<variable_declaration *> &ds) : field_type(tp), declarations(ds) {}
field_declaration::~field_declaration()
{
    for (const auto &vd : declarations)
        delete vd;
}
void field_declaration::refine(scope &scp) const
{
    // we add fields to the current scope..
    scope *s = &scp;
    for (const auto &id : field_type)
        s = &s->get_type(id);
    type *tp = static_cast<type *>(s);

    for (const auto &vd : declarations)
        scp.fields.insert({vd->name, new field(*tp, vd->name, vd->xpr)});
}

constructor_declaration::constructor_declaration(const std::vector<std::pair<std::vector<std::string>, std::string>> &pars, const std::vector<std::pair<std::string, std::vector<expression *>>> &il, const std::vector<statement *> &stmnts) : parameters(pars), init_list(il), statements(stmnts) {}
constructor_declaration::~constructor_declaration()
{
    for (const auto &i : init_list)
        for (const auto &e : i.second)
            delete e;
    for (const auto &s : statements)
        delete s;
}
void constructor_declaration::refine(scope &scp) const
{
    std::vector<field *> args;
    for (const auto &par : parameters)
    {
        scope *s = &scp;
        for (const auto &id : par.first)
            s = &s->get_type(id);
        type *tp = static_cast<type *>(s);
        args.push_back(new field(*tp, par.second));
    }

    static_cast<type &>(scp).constructors.push_back(new constructor(scp.get_core(), scp, args, init_list, statements));
}

method_declaration::method_declaration(const std::vector<std::string> &rt, const std::string &n, const std::vector<std::pair<std::vector<std::string>, std::string>> &pars, const std::vector<statement *> &stmnts) : return_type(rt), name(n), parameters(pars), statements(stmnts) {}
method_declaration::~method_declaration()
{
    for (const auto &s : statements)
        delete s;
}
void method_declaration::refine(scope &scp) const
{
    type *rt = nullptr;
    if (!return_type.empty())
    {
        scope *s = &scp;
        for (const auto &id : return_type)
            s = &s->get_type(id);
        rt = static_cast<type *>(s);
    }

    std::vector<field *> args;
    for (const auto &par : parameters)
    {
        scope *s = &scp;
        for (const auto &id : par.first)
            s = &s->get_type(id);
        type *tp = static_cast<type *>(s);
        args.push_back(new field(*tp, par.second));
    }

    method *m = new method(scp.get_core(), scp, rt, name, args, statements);

    if (core *c = dynamic_cast<core *>(&scp))
    {
        if (c->methods.find(name) == c->methods.end())
            c->methods.insert({name, *new std::vector<method *>()});
        c->methods.at(name).push_back(m);
    }
    else if (type *t = dynamic_cast<type *>(&scp))
    {
        if (t->methods.find(name) == t->methods.end())
            t->methods.insert({name, *new std::vector<method *>()});
        t->methods.at(name).push_back(m);
    }
}

predicate_declaration::predicate_declaration(const std::string &n, const std::vector<std::pair<std::vector<std::string>, std::string>> &pars, const std::vector<std::vector<std::string>> &pl, const std::vector<statement *> &stmnts) : name(n), parameters(pars), predicate_list(pl), statements(stmnts) {}
predicate_declaration::~predicate_declaration()
{
    for (const auto &s : statements)
        delete s;
}
void predicate_declaration::refine(scope &scp) const
{
    std::vector<field *> args;
    for (const auto &par : parameters)
    {
        scope *s = &scp;
        for (const auto &id : par.first)
            s = &s->get_type(id);
        type *tp = static_cast<type *>(s);
        args.push_back(new field(*tp, par.second));
    }

    predicate *p = new predicate(scp.get_core(), scp, name, args, statements);

    // we add the supertypes.. notice that we do not support forward declaration for predicate supertypes!!
    for (const auto &sp : predicate_list)
    {
        scope *s = &scp;
        for (const auto &id : sp)
            s = &s->get_predicate(id);
        p->supertypes.push_back(static_cast<predicate *>(s));
    }

    if (core *c = dynamic_cast<core *>(&scp))
        c->predicates.insert({name, p});
    else if (type *t = dynamic_cast<type *>(&scp))
    {
        t->predicates.insert({name, p});
        std::queue<type *> q;
        q.push(t);
        while (!q.empty())
        {
            q.front()->new_predicate(*p);
            for (const auto &st : q.front()->supertypes)
                q.push(st);
            q.pop();
        }
    }
}

class_declaration::class_declaration(const std::string &n, const std::vector<std::vector<std::string>> &bcs, const std::vector<field_declaration *> &fs, const std::vector<constructor_declaration *> &cs, const std::vector<method_declaration *> &ms, const std::vector<predicate_declaration *> &ps, const std::vector<type_declaration *> &ts) : type_declaration(n), base_classes(bcs), fields(fs), constructors(cs), methods(ms), predicates(ps), types(ts) {}
class_declaration::~class_declaration()
{
    for (const auto &f : fields)
        delete f;
    for (const auto &c : constructors)
        delete c;
    for (const auto &m : methods)
        delete m;
    for (const auto &p : predicates)
        delete p;
    for (const auto &t : types)
        delete t;
}
void class_declaration::declare(scope &scp) const
{
    // A new type has been declared..
    type *t = new type(scp.get_core(), scp, name);

    if (core *c = dynamic_cast<core *>(&scp))
        c->types.insert({name, t});
    else if (type *t = dynamic_cast<type *>(&scp))
        t->types.insert({name, t});

    for (const auto &tp : types)
        tp->declare(*t);
}
void class_declaration::refine(scope &scp) const
{
    type &tp = scp.get_type(name);
    for (const auto &bc : base_classes)
    {
        scope *s = &scp;
        for (const auto &id : bc)
            s = &s->get_type(id);
        tp.supertypes.push_back(static_cast<type *>(s));
    }

    for (const auto &f : fields)
        f->refine(tp);

    if (constructors.empty())
        tp.constructors.push_back(new constructor(scp.get_core(), tp, {}, {}, {})); // we add a default constructor..
    else
        for (const auto &c : constructors)
            c->refine(tp);

    for (const auto &m : methods)
        m->refine(tp);
    for (const auto &p : predicates)
        p->refine(tp);
    for (const auto &t : types)
        t->refine(tp);
}

compilation_unit::compilation_unit(const std::vector<type_declaration *> &ts, const std::vector<method_declaration *> &ms, const std::vector<predicate_declaration *> &ps, const std::vector<statement *> &stmnts) : types(ts), methods(ms), predicates(ps), statements(stmnts) {}
compilation_unit::~compilation_unit()
{
    for (const auto &t : types)
        delete t;
    for (const auto &m : methods)
        delete m;
    for (const auto &p : predicates)
        delete p;
    for (const auto &s : statements)
        delete s;
}
void compilation_unit::declare(scope &scp) const
{
    for (const auto &t : types)
        t->declare(scp);
}
void compilation_unit::refine(scope &scp) const
{
    for (const auto &t : types)
        t->refine(scp);
    for (const auto &m : methods)
        m->refine(scp);
    for (const auto &p : predicates)
        p->refine(scp);
}
void compilation_unit::execute(const scope &scp, context &ctx) const
{
    for (const auto &stmnt : statements)
        stmnt->execute(scp, ctx);
}
}
}