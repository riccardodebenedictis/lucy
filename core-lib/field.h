#pragma once

#include "visibility.h"
#include <string>

namespace lucy {

	class type;

#pragma warning( disable : 4251 )
	class DLL_PUBLIC field {
	public:
		field(const type& tp, const std::string& name, bool synthetic = false);
		virtual ~field();

	public:
		const type& tp;
		const std::string name;
		const bool synthetic;
	};
}