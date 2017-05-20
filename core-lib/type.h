#pragma once

#include "scope.h"
#include <string>

namespace lucy {

#pragma warning( disable : 4251 )
	class DLL_PUBLIC type : public scope {
	public:
		type(core& cr, scope& scp, const std::string& name, bool primitive = false);
		type(const type& orig) = delete;
		virtual ~type();

	public:
		const std::string name;
		const bool primitive;
	};
}