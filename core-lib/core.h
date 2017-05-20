#pragma once

#include "scope.h"
#include "env.h"
#include "sat_core.h"

namespace lucy {

	class DLL_PUBLIC core : public scope, public env {
	public:
		core();
		core(const core& orig) = delete;
		virtual ~core();

	public:
		smt::sat_core sat;
	};
}