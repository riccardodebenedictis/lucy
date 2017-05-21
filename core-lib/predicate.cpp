#include "predicate.h"

namespace lucy {

	predicate::predicate(core& cr, scope& scp, const std::string& name) : type(cr, scp, name) {}

	predicate::~predicate() {}
}