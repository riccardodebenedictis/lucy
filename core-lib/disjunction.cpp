#include "disjunction.h"
#include "env.h"
#include "statement.h"

namespace lucy
{

conjunction::conjunction(core &cr, scope &scp, const lin &cst, const std::vector<const ast::statement *> &stmnts) : scope(cr, scp), cost(cst), statements(stmnts) {}
conjunction::~conjunction() {}

void conjunction::apply(context &ctx) const
{
    context c_ctx(new env(cr, ctx));
    for (const auto &s : statements)
        s->execute(*this, c_ctx);
}

disjunction::disjunction(core &cr, scope &scp, const std::vector<const conjunction *> &conjs) : scope(cr, scp), conjunctions(conjs) {}
disjunction::~disjunction()
{
    for (const auto &c : conjunctions)
        delete c;
}
}