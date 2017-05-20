#pragma once

#include "visibility.h"

namespace lucy {

	class core;

	class DLL_PUBLIC scope {
	public:
		scope(core& cr);
		scope(const scope& orig) = delete;
		virtual ~scope();

	protected:
		core& cr;
	};
}