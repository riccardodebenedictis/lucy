#pragma once

#include "field.h"
#include "parser/ratioParser.h"

namespace lucy {

	class instantiated_field : public field {
		friend class defined_constructor;
	public:
		instantiated_field(const type& t, const std::string& name, ratioParser::ExprContext& expr_c);
		instantiated_field(const instantiated_field& orig) = delete;
		virtual ~instantiated_field();

		expr new_instance(context& ctx) override;

	private:
		ratioParser::ExprContext& expr_c;
	};
}