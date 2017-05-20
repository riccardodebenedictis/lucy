#pragma once

#include "env.h"
#include "sat_core.h"

using namespace smt;

namespace lucy {

	class type;

	class DLL_PUBLIC item : public env {
	public:
		item(core& cr, const type& tp);
		item(const item& orig) = delete;
		virtual ~item();

		virtual var eq(item& i) noexcept;
		virtual bool equates(const item& i) const noexcept;

	public:
		const type& tp;
	};
}
