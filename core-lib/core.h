#pragma once

#include "scope.h"
#include "env.h"
#include "sat_core.h"
#include "la_theory.h"

using namespace smt;

namespace lucy {

	class DLL_PUBLIC core : public scope, public env {
	public:
		core();
		core(const core& orig) = delete;
		~core();


	public:
		sat_core sat;
		la_theory la;
	};
}