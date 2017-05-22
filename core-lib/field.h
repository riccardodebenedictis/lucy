#pragma once

#include "visibility.h"
#include <string>

namespace lucy {

	class type;
	class context;
	class expr;

#pragma warning( disable : 4251 )
	class DLL_PUBLIC field {
	public:
		field(const type& tp, const std::string& name, bool synthetic = false);
		virtual ~field();

		virtual expr new_instance(context& ctx);
	public:
		const type& tp;
		const std::string name;
		const bool synthetic;
	};
}