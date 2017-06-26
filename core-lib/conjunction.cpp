#include "conjunction.h"
#include "env.h"

namespace lucy
{

conjunction::conjunction(core &cr, scope &scp, const lin &cst, const std::vector<ast::statement *> &stmnts) : scope(cr, scp), cost(cst), statements(stmnts) {}

conjunction::~conjunction() {}

bool conjunction::apply(context &ctx) const
{
    context c_ctx(new env(cr, ctx));
    for (const auto &s : statements)
    {
        if (!s->execute(*this, c_ctx))
            return false;
    }
    return true;
}
}