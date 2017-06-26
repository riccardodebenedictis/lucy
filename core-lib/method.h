#pragma once

#include "scope.h"
#include "statement.h"

namespace lucy
{

class context;

class method : public scope
{
	friend class type;
	friend class core;

public:
	method(core &cr, scope &scp, const type *const return_type, const std::string &name, const std::vector<field *> &args, const std::vector<ast::statement *> &stmnts);
	method(const method &orig) = delete;
	virtual ~method();

	const std::vector<field *> get_args() const { return args; }

	bool invoke(context &ctx, const std::vector<expr> &exprs);

public:
	const type *const return_type;

public:
	const std::string name;

protected:
	const std::vector<field *> args;

private:
	const std::vector<ast::statement *> statements;
};
}