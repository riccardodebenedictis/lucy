#include "core.h"

namespace lucy {

	core::core() : scope(*this, *this), env(*this, this), sat() {}

	core::~core() {}
}
