#include "defined_constructor.h"
#include "context.h"
#include "item.h"
#include "type.h"
#include "instantiated_field.h"
#include "expression_visitor.h"
#include "statement_visitor.h"

namespace lucy {

	defined_constructor::defined_constructor(core& cr, scope& scp, const std::vector<field*>& args, std::vector<ratioParser::Initializer_elementContext*> init_els, ratioParser::BlockContext& b) : constructor(cr, scp, args), init_els(init_els), block(b) { }

	defined_constructor::~defined_constructor() { }

	bool defined_constructor::invoke(item& i, const std::vector<expr>& exprs) {
		context itm_ctx(&i);
		std::unordered_map<std::string, field*> scope_fields = scp.get_fields();
		for (const auto& f : scope_fields) {
			if (instantiated_field * inst_f = dynamic_cast<instantiated_field*> (f.second)) {
				set(i, f.second->name, expression_visitor(cr, itm_ctx).visit(&inst_f->expr_c).as<expr>());
			}
		}

		context cstrctr_ctx(new env(cr, &i));
		set(*cstrctr_ctx, THIS_KEYWORD, expr(&i));
		for (unsigned int j = 0; j < args.size(); j++) {
			set(*cstrctr_ctx, args[j]->name, exprs[j]);
		}
		for (const auto& el : init_els) {
			if (scope_fields.find(el->name->getText()) != scope_fields.end()) {
				// we are assigning a value to a field..
				set(i, el->name->getText(), expression_visitor(cr, cstrctr_ctx).visit(el->expr_list()->expr(0)).as<expr>());
			}
			else {
				// we are calling the constructor of a base-class..
#ifndef NDEBUG
				std::vector<type*> sts = static_cast<type&> (scp).get_supertypes();
				assert(std::any_of(sts.begin(), sts.end(), [el](type * t) { return t->name.compare(el->name->getText()) == 0; }));
#endif
				std::vector<expr> exprs;
				std::vector<const type*> par_types;
				if (el->expr_list()) {
					for (const auto& ex : el->expr_list()->expr()) {
						expr i = expression_visitor(cr, cstrctr_ctx).visit(ex).as<expr>();
						exprs.push_back(i);
						par_types.push_back(&i->tp);
					}
				}
				if (!get_type(el->name->getText()).get_constructor(par_types).invoke(i, exprs)) {
					return false;
				}
			}
		}

		// we instantiate uninstantiated fields..
		for (const auto& f : scope_fields) {
			if (!f.second->synthetic && !i.is_instantiated(f.second->name)) {
				set(i, f.second->name, f.second->new_instance(itm_ctx));
			}
		}

		return statement_visitor(cr, cstrctr_ctx).visit(&block).as<bool>();
	}
}