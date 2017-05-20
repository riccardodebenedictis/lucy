#pragma once

#include "sat_core.h"

namespace lucy {

	class DLL_PUBLIC core {
	public:
		core();
		core(const core& orig) = delete;
		~core();

	public:
		smt::sat_core sat;
	};
}