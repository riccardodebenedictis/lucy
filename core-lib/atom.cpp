#include "atom.h"
#include "predicate.h"
#include "core.h"

namespace lucy
{

atom::atom(core &cr, const context ctx, const predicate &pred) : item(cr, ctx, pred), sigma(cr.sat.new_var()) {}

atom::~atom() {}
}