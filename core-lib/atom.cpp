#include "atom.h"
#include "predicate.h"
#include "core.h"

namespace lucy {

	atom_state* const atom::active = new atom_state();
	atom_state* const atom::inactive = new atom_state();
	atom_state* const atom::unified = new atom_state();

	atom::atom(core& cr, const context ctx, const predicate& pred) : item(cr, ctx, pred), state(cr.set.new_var({ atom::active, atom::inactive, atom::unified })) {}

	atom::~atom() {}
}