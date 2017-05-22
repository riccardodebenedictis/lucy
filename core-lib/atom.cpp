#include "atom.h"
#include "predicate.h"

namespace lucy {

	atom::atom(core& cr, const context ctx, const predicate& pred) : item(cr, ctx, pred) {}

	atom::~atom() {}
}