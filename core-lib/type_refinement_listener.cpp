#include "type_refinement_listener.h"
#include "core.h"
#include "enum_type.h"
#include "default_constructor.h"
#include "defined_constructor.h"
#include "defined_method.h"
#include "defined_predicate.h"
#include "disjunction.h"
#include "context.h"
#include "item.h"
#include "defined_conjunction.h"
#include "instantiated_field.h"
#include "type_visitor.h"
#include "expression_visitor.h"

namespace lucy {

	type_refinement_listener::type_refinement_listener(core& cr) : cr(cr) {}

	type_refinement_listener::~type_refinement_listener() {}

	void type_refinement_listener::enterCompilation_unit(ratioParser::Compilation_unitContext* ctx) {
		scp = cr.scopes.at(ctx);
	}

	void type_refinement_listener::enterEnum_declaration(ratioParser::Enum_declarationContext* ctx) {
		enum_type* et = static_cast<enum_type*> (cr.scopes.at(ctx));
		for (const auto& ec : ctx->enum_constants()) {
			if (ec->type()) {
				et->enums.push_back(static_cast<enum_type*> (type_visitor(cr).visit(ec->type()).as<type*>()));
			}
		}
	}

	void type_refinement_listener::enterClass_declaration(ratioParser::Class_declarationContext* ctx) {
		// we set the superclasses of the type..
		scp = cr.scopes.at(ctx);
		if (ctx->type_list()) {
			type* t = static_cast<type*> (scp);
			for (const auto& st : ctx->type_list()->type()) {
				t->supertypes.push_back(type_visitor(cr).visit(st).as<type*>());
			}
		}
	}

	void type_refinement_listener::exitClass_declaration(ratioParser::Class_declarationContext* ctx) {
		// if the current type has no constructor..
		type* t = static_cast<type*> (scp);
		if (t->constructors.empty()) {
			// .. we define a default empty constructor..
			t->constructors.push_back(new default_constructor(cr, *scp));
		}
		scp = &scp->get_scope();
	}

	void type_refinement_listener::enterField_declaration(ratioParser::Field_declarationContext* ctx) {
		// we add a field to the current scope..
		type* t = type_visitor(cr).visit(ctx->type()).as<type*>();
		for (const auto& dec : ctx->variable_dec()) {
			if (dec->expr()) {
				instantiated_field* inst_f = new instantiated_field(*t, dec->name->getText(), *dec->expr());
				scp->fields.insert({ dec->name->getText(), inst_f });
			}
			else {
				field* f = new field(*t, dec->name->getText());
				scp->fields.insert({ dec->name->getText(), f });
			}
		}
	}

	void type_refinement_listener::enterConstructor_declaration(ratioParser::Constructor_declarationContext* ctx) {
		// we add a new constructor to the current type..
		// these are the parameters of the new constructor..
		std::vector<field*> args;
		if (ctx->typed_list()) {
			std::vector<ratioParser::TypeContext*> types = ctx->typed_list()->type();
			std::vector<antlr4::tree::TerminalNode*> ids = ctx->typed_list()->ID();
			for (unsigned int i = 0; i < types.size(); i++) {
				args.push_back(new field(*type_visitor(cr).visit(types[i]).as<type*>(), ids[i]->getText()));
			}
		}

		defined_constructor* dc = new defined_constructor(cr, *scp, args, ctx->initializer_element(), *ctx->block());
		static_cast<type*> (scp)->constructors.push_back(dc);
		cr.scopes.insert({ ctx, dc });
		scp = dc;
	}

	void type_refinement_listener::exitConstructor_declaration(ratioParser::Constructor_declarationContext* ctx) {
		// we restore the scope as the enclosing scope of the current scope..
		scp = &scp->scp;
	}

	void type_refinement_listener::enterVoid_method_declaration(ratioParser::Void_method_declarationContext* ctx) {
		// we add a new method without return type to the current scope..
		// these are the parameters of the new method..
		std::vector<field*> args;
		if (ctx->typed_list()) {
			std::vector<ratioParser::TypeContext*> types = ctx->typed_list()->type();
			std::vector<antlr4::tree::TerminalNode*> ids = ctx->typed_list()->ID();
			for (unsigned int i = 0; i < types.size(); i++) {
				args.push_back(new field(*type_visitor(cr).visit(types[i]).as<type*>(), ids[i]->getText()));
			}
		}

		defined_method* m = new defined_method(cr, *scp, ctx->name->getText(), args, *ctx->block());
		if (core * c = dynamic_cast<core*> (scp)) {
			if (c->methods.find(ctx->name->getText()) == c->methods.end()) {
				c->methods.insert({ ctx->name->getText(), *new std::vector<method*>() });
			}
			c->methods.at(ctx->name->getText()).push_back(m);
		}
		else if (type * t = dynamic_cast<type*> (scp)) {
			if (t->methods.find(ctx->name->getText()) == t->methods.end()) {
				t->methods.insert({ ctx->name->getText(), *new std::vector<method*>() });
			}
			t->methods.at(ctx->name->getText()).push_back(m);
		}
		cr.scopes.insert({ ctx, m });
		scp = m;
	}

	void type_refinement_listener::exitVoid_method_declaration(ratioParser::Void_method_declarationContext* ctx) {
		// we restore the scope as the enclosing scope of the current scope..
		scp = &scp->scp;
	}

	void type_refinement_listener::enterType_method_declaration(ratioParser::Type_method_declarationContext* ctx) {
		// we add a new method with a return type to the current scope..
		// these are the parameters of the new method..
		type* return_type = type_visitor(cr).visit(ctx->type()).as<type*>();
		std::vector<field*> args;
		if (ctx->typed_list()) {
			std::vector<ratioParser::TypeContext*> types = ctx->typed_list()->type();
			std::vector<antlr4::tree::TerminalNode*> ids = ctx->typed_list()->ID();
			for (unsigned int i = 0; i < types.size(); i++) {
				args.push_back(new field(*type_visitor(cr).visit(types[i]).as<type*>(), ids[i]->getText()));
			}
		}

		defined_method* m = new defined_method(cr, *scp, ctx->name->getText(), args, *ctx->block(), return_type);
		if (core * c = dynamic_cast<core*> (scp)) {
			if (c->methods.find(ctx->name->getText()) == c->methods.end()) {
				c->methods.insert({ ctx->name->getText(), *new std::vector<method*>() });
			}
			c->methods.at(ctx->name->getText()).push_back(m);
		}
		else if (type * t = dynamic_cast<type*> (scp)) {
			if (t->methods.find(ctx->name->getText()) == t->methods.end()) {
				t->methods.insert({ ctx->name->getText(), *new std::vector<method*>() });
			}
			t->methods.at(ctx->name->getText()).push_back(m);
		}
		cr.scopes.insert({ ctx, m });
		scp = m;
	}

	void type_refinement_listener::exitType_method_declaration(ratioParser::Type_method_declarationContext* ctx) {
		// we restore the scope as the enclosing scope of the current scope..
		scp = &scp->scp;
	}

	void type_refinement_listener::enterPredicate_declaration(ratioParser::Predicate_declarationContext* ctx) {
		// we add a new predicate to the current scope..
		// these are the parameters of the new predicate..
		std::vector<field*> args;
		if (ctx->typed_list()) {
			std::vector<ratioParser::TypeContext*> types = ctx->typed_list()->type();
			std::vector<antlr4::tree::TerminalNode*> ids = ctx->typed_list()->ID();
			for (unsigned int i = 0; i < types.size(); i++) {
				args.push_back(new field(*type_visitor(cr).visit(types[i]).as<type*>(), ids[i]->getText()));
			}
		}
		defined_predicate* p = new defined_predicate(cr, *scp, ctx->name->getText(), args, *ctx->block());

		if (ctx->predicate_list()) {
			for (const auto& qp : ctx->predicate_list()->qualified_predicate()) {
				if (qp->class_type()) {
					p->supertypes.push_back(&type_visitor(cr).visit(qp->class_type()).as<type*>()->get_predicate(qp->ID()->getText()));
				}
				else {
					p->supertypes.push_back(&scp->get_predicate(qp->ID()->getText()));
				}
			}
		}

		std::queue<type*> q;
		if (core * c = dynamic_cast<core*> (scp)) {
			c->predicates.insert({ ctx->name->getText(), p });
		}
		else if (type * t = dynamic_cast<type*> (scp)) {
			t->predicates.insert({ ctx->name->getText(), p });
			q.push(t);
		}
		while (!q.empty()) {
			q.front()->new_predicate(*p);
			for (const auto& st : q.front()->supertypes) {
				q.push(st);
			}
			q.pop();
		}

		cr.scopes.insert({ ctx, p });
		scp = p;
	}

	void type_refinement_listener::exitPredicate_declaration(ratioParser::Predicate_declarationContext* ctx) {
		// we restore the scope as the enclosing scope of the current scope..
		scp = &scp->scp;
	}

	void type_refinement_listener::enterDisjunction_statement(ratioParser::Disjunction_statementContext* ctx) {
		disjunction* d = new disjunction(cr, *scp);
		cr.scopes.insert({ ctx, d });
		scp = d;
	}

	void type_refinement_listener::exitDisjunction_statement(ratioParser::Disjunction_statementContext* ctx) {
		// we restore the scope as the enclosing scope of the current scope..
		scp = &scp->scp;
	}

	void type_refinement_listener::enterConjunction(ratioParser::ConjunctionContext* ctx) {
		defined_conjunction* dc;
		if (ctx->cost) {
			context c(&cr);
			arith_expr cst = expression_visitor(cr, c).visit(ctx->cost).as<expr>();
			dc = new defined_conjunction(cr, *scp, cst->l, *ctx->block());
		}
		else {
			dc = new defined_conjunction(cr, *scp, smt::lin(1), *ctx->block());
		}
		static_cast<disjunction*> (scp)->conjunctions.push_back(dc);
		cr.scopes.insert({ ctx, dc });
		scp = dc;
	}

	void type_refinement_listener::exitConjunction(ratioParser::ConjunctionContext* ctx) {
		// we restore the scope as the enclosing scope of the current scope..
		scp = &scp->scp;
	}

	void type_refinement_listener::enterLocal_variable_statement(ratioParser::Local_variable_statementContext* ctx) {
		cr.scopes.insert({ ctx, scp });
	}

	void type_refinement_listener::enterAssignment_statement(ratioParser::Assignment_statementContext* ctx) {
		cr.scopes.insert({ ctx, scp });
	}

	void type_refinement_listener::enterExpression_statement(ratioParser::Expression_statementContext* ctx) {
		cr.scopes.insert({ ctx, scp });
	}

	void type_refinement_listener::enterFormula_statement(ratioParser::Formula_statementContext* ctx) {
		cr.scopes.insert({ ctx, scp });
	}

	void type_refinement_listener::enterReturn_statement(ratioParser::Return_statementContext* ctx) {
		cr.scopes.insert({ ctx, scp });
	}

	void type_refinement_listener::enterQualified_id_expression(ratioParser::Qualified_id_expressionContext* ctx) {
		cr.scopes.insert({ ctx, scp });
	}

	void type_refinement_listener::enterFunction_expression(ratioParser::Function_expressionContext* ctx) {
		cr.scopes.insert({ ctx, scp });
	}
}