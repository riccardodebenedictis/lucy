#include "type_declaration_listener.h"
#include "core.h"
#include "enum_type.h"
#include "typedef_type.h"
#include "type_visitor.h"

namespace lucy
{

type_declaration_listener::type_declaration_listener(core &cr) : cr(cr) {}

type_declaration_listener::~type_declaration_listener() {}

void type_declaration_listener::enterCompilation_unit(ratioParser::Compilation_unitContext *ctx)
{
	cr.scopes.insert({ctx, &cr});
	scp = &cr;
}

void type_declaration_listener::enterTypedef_declaration(ratioParser::Typedef_declarationContext *ctx)
{
	// A new typedef type has been declared..
	typedef_type *td = new typedef_type(cr, *scp, ctx->name->getText(), *type_visitor(cr).visit(ctx->primitive_type()).as<type *>(), *ctx->expr());
	if (core *c = dynamic_cast<core *>(scp))
	{
		c->types.insert({ctx->name->getText(), td});
	}
	else if (type *t = dynamic_cast<type *>(scp))
	{
		t->types.insert({ctx->name->getText(), td});
	}
}

void type_declaration_listener::enterEnum_declaration(ratioParser::Enum_declarationContext *ctx)
{
	// A new enum type has been declared..
	enum_type *et = new enum_type(cr, *scp, ctx->name->getText());
	cr.scopes.insert({ctx, et});

	// We add the enum values..
	for (const auto &cn : ctx->enum_constants())
	{
		for (const auto &l : cn->StringLiteral())
		{
			et->instances.push_back(cr.new_string(l->getText()));
		}
	}
	if (core *c = dynamic_cast<core *>(scp))
	{
		c->types.insert({ctx->name->getText(), et});
	}
	else if (type *t = dynamic_cast<type *>(scp))
	{
		t->types.insert({ctx->name->getText(), et});
	}
}

void type_declaration_listener::enterClass_declaration(ratioParser::Class_declarationContext *ctx)
{ // A new type has been declared..
	type *c_t = new type(cr, *scp, ctx->name->getText());
	cr.scopes.insert({ctx, c_t});
	if (core *rc = dynamic_cast<core *>(scp))
	{
		rc->types.insert({ctx->name->getText(), c_t});
	}
	else if (type *t = dynamic_cast<type *>(scp))
	{
		t->types.insert({ctx->name->getText(), c_t});
	}

	scp = c_t;
}

void type_declaration_listener::exitClass_declaration(ratioParser::Class_declarationContext *ctx)
{
	scp = &scp->get_scope();
}

void type_declaration_listener::enterClass_type(ratioParser::Class_typeContext *ctx)
{
	cr.scopes.insert({ctx, scp});
}
}