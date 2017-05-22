#pragma once

#include "visibility.h"
#include "context.h"

namespace lucy {

	class core;

	class DLL_PUBLIC env {
		friend class context;
	public:
		env(core& cr, const context ctx);
		env(const env& orig) = delete;
		virtual ~env();

	private:
		unsigned ref_count;

	protected:
		core& cr;
		const context ctx;
	};
}