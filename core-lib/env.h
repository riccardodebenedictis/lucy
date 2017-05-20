#pragma once

#include "visibility.h"

namespace lucy {

	class core;

	class DLL_PUBLIC env {
	public:
		env(core& cr);
		env(const env& orig) = delete;
		virtual ~env();

	protected:
		core& cr;
	};
}