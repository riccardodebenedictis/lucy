#pragma once

#include "type.h"
#include "statement.h"

namespace lucy
{

class DLL_PUBLIC predicate : public type
{
public:
	predicate(core &cr, scope &scp, const std::string &name, const std::vector<field *> &args, const std::vector<ast::statement *> &stmnts);
	predicate(const predicate &orig) = delete;
	virtual ~predicate();

	const std::vector<field *> get_args() const { return args; }

	expr new_instance(context &ctx) override;

	bool apply_rule(atom &a) const;

protected:
	const std::vector<field *> args;

private:
	const std::vector<ast::statement *> statements;
};
}