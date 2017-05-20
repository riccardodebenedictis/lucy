#pragma once

#include "scope.h"

namespace lucy {

	class type : public scope {
	public:
		type(core& cr, scope& scp, const std::string& name, bool primitive = false);
		type(const type& orig) = delete;
		virtual ~type();

	public:
		const std::string name;
		const bool primitive;
	};
}