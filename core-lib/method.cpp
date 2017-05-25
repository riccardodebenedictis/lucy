#include "method.h"
#include "type.h"
#include "field.h"
#include "context.h"

namespace lucy
{

method::method(core &cr, scope &scp, const std::string &name, const std::vector<field *> &args, const type *const return_type) : scope(cr, scp), name(name), args(args), return_type(return_type)
{
	if (type *t = dynamic_cast<type *>(&scp))
	{
		fields.insert({THIS_KEYWORD, new field(*t, THIS_KEYWORD, true)});
	}
	if (return_type)
	{
		fields.insert({RETURN_KEYWORD, new field(*return_type, RETURN_KEYWORD, true)});
	}
	for (const auto &arg : args)
	{
		fields.insert({arg->name, arg});
	}
}

method::~method() {}
}