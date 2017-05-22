#pragma once

#include "constructor.h"

namespace lucy {

	class default_constructor : public constructor {
	public:
		default_constructor(core& cr, scope& scp);
		default_constructor(const default_constructor& orig) = delete;
		virtual ~default_constructor();

		bool invoke(item& i, const std::vector<expr>& exprs) override;
	};
}