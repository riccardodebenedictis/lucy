#pragma once

#include "type.h"

namespace lucy
{

class DLL_PUBLIC predicate : public type
{
public:
	predicate(core &cr, scope &scp, const std::string &name, const std::vector<field *> &args);
	predicate(const predicate &orig) = delete;
	virtual ~predicate();

	const std::vector<field *> get_args() const { return args; }

	expr new_instance(context &ctx) override;

	virtual bool apply_rule(atom &a) const = 0;

protected:
	const std::vector<field *> args;
};
}