#pragma once

#include "context.h"
#include <unordered_map>

namespace lucy {

	class core;

	class DLL_PUBLIC env {
		template<typename T>
		friend class env_ptr;
	public:
		env(core& cr, const context& ctx);
		env(const env& orig) = delete;
		virtual ~env();

	private:
		unsigned ref_count;

	protected:
		core& cr;
		const context ctx;
		std::unordered_map<std::string, expr> items;
	};
}