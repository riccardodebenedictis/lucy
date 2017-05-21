#pragma once

#include "type.h"

namespace lucy {

	class DLL_PUBLIC predicate : public type {
	public:
		predicate(core& cr, scope& scp, const std::string& name);
		predicate(const predicate& orig) = delete;
		virtual ~predicate();
	};
}