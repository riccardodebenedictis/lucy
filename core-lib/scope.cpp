#include "scope.h"

namespace lucy {

	scope::scope(core& cr, scope& scp) : cr(cr), scp(scp) { }

	scope::~scope() { }
}