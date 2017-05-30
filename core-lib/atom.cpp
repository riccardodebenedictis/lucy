#include "atom.h"
#include "predicate.h"
#include "core.h"

namespace lucy
{

atom::atom(core &cr, const context ctx, const predicate &pred) : item(cr, ctx, pred), state(cr.set_th.new_var({cr.active, cr.inactive, cr.unified})) {}

atom::~atom() {}
}