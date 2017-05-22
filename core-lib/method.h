#pragma once

#include "scope.h"

namespace lucy {

	class context;

	class method : public scope {
		friend class type;
		friend class core;
		friend class expression_visitor;
	public:
		method(core& cr, scope& scp, const std::string& name, const std::vector<field*>& args, const type* const return_type = nullptr);
		method(const method& orig) = delete;
		virtual ~method();

		const std::vector<field*> get_args() const { return args; }

		virtual bool invoke(context& ctx, const std::vector<expr>& exprs) = 0;

	public:
		const std::string name;

	protected:
		const std::vector<field*> args;

	public:
		const type * const return_type;
	};
}