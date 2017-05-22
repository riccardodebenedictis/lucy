#include "predicate.h"
#include "field.h"
#include "atom.h"

namespace lucy {

	predicate::predicate(core& cr, scope& scp, const std::string& name, const std::vector<field*>& args) : type(cr, scp, name) {
		if (type * t = dynamic_cast<type*> (&scp)) {
			fields.insert({ THIS_KEYWORD, new field(*t, THIS_KEYWORD, true) });
		}
		for (const auto& arg : args) {
			fields.insert({ arg->name, arg });
		}
	}

	predicate::~predicate() {}

	expr predicate::new_instance(context & ctx)	{
		atom * a = new atom(cr, ctx, *this);
		std::queue<predicate*> q;
		q.push(this);
		while (!q.empty()) {
			q.front()->instances.push_back(a);
			for (const auto& st : q.front()->supertypes) {
				q.push(static_cast<predicate*> (st));
			}
			q.pop();
		}

		return expr(a);
	}
}