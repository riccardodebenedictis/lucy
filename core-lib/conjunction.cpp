#include "conjunction.h"

namespace lucy {

	conjunction::conjunction(core& cr, scope& scp, const lin& cst) : scope(cr, scp), cost(cst) { }

	conjunction::~conjunction() { }
}