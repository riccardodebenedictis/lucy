#include "item.h"

namespace lucy {

	item::item(core& cr, const type& tp) : env(cr), tp(tp) {}

	item::~item() {}

	var item::eq(item & i) noexcept {
		throw std::runtime_error("not supported yet..");
	}

	bool item::equates(const item & i) const noexcept {
		throw std::runtime_error("not supported yet..");
	}
}