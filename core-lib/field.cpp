#include "field.h"
#include "context.h"
#include "type.h"
#include <cassert>

namespace lucy
{

field::field(const type &tp, const std::string &name, bool synthetic) : tp(tp), name(name), synthetic(synthetic) {}

field::~field() {}

expr field::new_instance(context &ctx)
{
    assert(!synthetic);
    if (tp.primitive)
    {
        return const_cast<type &>(tp).new_instance(ctx);
    }
    else
    {
        return const_cast<type &>(tp).new_existential();
    }
}
}