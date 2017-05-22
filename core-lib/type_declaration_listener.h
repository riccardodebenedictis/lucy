#pragma once

#include "parser/ratioBaseListener.h"

namespace lucy {

	class core;
	class scope;

	class type_declaration_listener : public ratioBaseListener {
	public:
		type_declaration_listener(core& cr);
		type_declaration_listener(const type_declaration_listener& orig) = delete;
		virtual ~type_declaration_listener();

	private:
		void enterCompilation_unit(ratioParser::Compilation_unitContext* ctx) override;
		void enterTypedef_declaration(ratioParser::Typedef_declarationContext* ctx) override;
		void enterEnum_declaration(ratioParser::Enum_declarationContext* ctx) override;
		void enterClass_declaration(ratioParser::Class_declarationContext* ctx) override;
		void exitClass_declaration(ratioParser::Class_declarationContext* ctx) override;
		void enterClass_type(ratioParser::Class_typeContext* ctx) override;

	private:
		core& cr;
		scope* scp;
	};
}