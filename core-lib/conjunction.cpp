#include "conjunction.h"
#include "statement.h"

namespace lucy
{

conjunction::conjunction(core &cr, scope &scp, const lin &cst, const std::vector<ast::statement *> &stmnts) : scope(cr, scp), cost(cst), statements(stmnts) {}

conjunction::~conjunction() {}

bool conjunction::apply(context &ctx) const
{
    for (const auto &s : statements)
    {
        if (!s->execute(ctx))
            return false;
    }
    return true;
}
}