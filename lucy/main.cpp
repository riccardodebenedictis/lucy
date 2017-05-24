#include "sat_core.h"
#include <iostream>

using namespace smt;

int main(int argc, char *argv[], char *envp[]) {
	std::cout << "starting lucy.." << std::endl;

	sat_core c;

	var b0 = c.new_var();
	var b1 = c.new_var();
	var b2 = c.new_var();
	var b3 = c.new_var();
	var b4 = c.new_var();
	var b5 = c.new_var();
	var b6 = c.new_var();
	var b7 = c.new_var();
	var b8 = c.new_var();

	bool cs;
	cs = c.new_clause({ lit(b0, true), lit(b1, true) });
}