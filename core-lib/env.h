#pragma once

#include "visibility.h"
#include "context.h"
#include <unordered_map>
#include <string>

namespace lucy {

	class core;

#pragma warning( disable : 4251 )
	class DLL_PUBLIC env {
		friend class context;
		friend class scope;
	public:
		env(core& cr, const context ctx);
		env(const env& orig) = delete;
		virtual ~env();

		core& get_core() const { return cr; }

		context get_ctx() const { return ctx; }

		virtual expr get(const std::string& name) const;
		std::unordered_map<std::string, expr> get_items() const noexcept;

	private:
		unsigned ref_count;

	protected:
		core& cr;
		const context ctx;
		std::unordered_map<std::string, expr> items;
	};
}