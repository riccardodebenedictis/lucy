#pragma once

#include "scope.h"

namespace lucy {

	class conjunction;

	class disjunction : public scope {
		friend class type_refinement_listener;
	public:
		disjunction(core& cr, scope& scp);
		disjunction(const disjunction& orig) = delete;
		virtual ~disjunction();

		std::vector<conjunction*> get_conjunctions() const {
			return conjunctions;
		}

	private:
		std::vector<conjunction*> conjunctions;
	};
}