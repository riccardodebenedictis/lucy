#include "atom.h"
#include "predicate.h"

namespace lucy {

	atom::atom(core& cr, const predicate& pred) : item(cr,pred) {}

	atom::~atom() {}
}