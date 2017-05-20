#include "core.h"

namespace lucy {

	core::core() : scope(*this, *this), env(*this), sat(), la(sat) {}

	core::~core() {	}
}