#pragma once

#include "visibility.h"
#include <unordered_map>

namespace lucy {

	class core;
	class field;

	class DLL_PUBLIC scope {
	public:
		scope(core& cr, scope& scp);
		scope(const scope& orig) = delete;
		virtual ~scope();
		
	protected:
		core& cr;
		scope& scp;
		std::unordered_map<std::string, field*> fields;
	};
}