#include "disjunction.h"

namespace lucy {

	disjunction::disjunction(core& cr, scope& scp) : scope(cr, scp) { }

	disjunction::~disjunction() {
		for (const auto& c : conjunctions) {
			delete c;
		}
	}
}