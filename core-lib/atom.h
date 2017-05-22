#pragma once

#include "item.h"

namespace lucy {

	class predicate;

	class DLL_PUBLIC atom : public item {
	public:
		atom(core& cr, const context ctx, const predicate& pred);
		atom(const atom& orig) = delete;
		virtual ~atom();
	};
}