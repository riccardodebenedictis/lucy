#include "atom.h"
#include "predicate.h"
#include "core.h"

namespace lucy {

	atom::atom(core& cr, const context ctx, const predicate& pred) : item(cr, ctx, pred), state(cr.set.new_var({ atom::active, atom::inactive, atom::unified })) {}

	atom::~atom() {}
}