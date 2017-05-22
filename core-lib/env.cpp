#include "env.h"
#include "context.h"

namespace lucy {

	env::env(core& cr, const context ctx) : cr(cr), ctx(ctx) { }

	env::~env() { }
}