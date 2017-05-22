#pragma once

#include "visibility.h"

namespace lucy {

	class env;

	class DLL_PUBLIC context {
	public:
		context(env* const ptr);
		context(const context& orig);
		virtual ~context();

		env& operator*() const { return *ptr; }
		env* operator->() const { return ptr; }
		operator context() { return context(ptr); }

	private:
		env* const ptr;
	};
}