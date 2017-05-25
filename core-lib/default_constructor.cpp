#include "default_constructor.h"
#include "type.h"
#include "context.h"
#include "item.h"
#include "field.h"
#include <cassert>

namespace lucy
{

default_constructor::default_constructor(core &cr, scope &scp) : constructor(cr, scp, {}) {}

default_constructor::~default_constructor() {}

bool default_constructor::invoke(item &i, const std::vector<expr> &exprs)
{
    assert(exprs.empty());

    // we invoke superclasses constructors..
    for (const auto &st : static_cast<type &>(scp).get_supertypes())
    {
        st->get_constructor(std::vector<const type *>(0)).invoke(i, exprs);
    }

    // we initialize the fields..
    context ctx(&i);
    for (const auto &f : scp.get_fields())
    {
        if (!f.second->synthetic)
        {
            set(i, f.second->name, f.second->new_instance(ctx));
        }
    }
    return true;
}
}