#include "causal_graph.h"
#ifndef NDEBUG
#include "cg_java_listener.h"
#endif
#include <iostream>
#include <fstream>

using namespace smt;

int main(int argc, char *argv[], char *envp[])
{
    std::cout << "starting lucy";
#ifndef NDEBUG
    std::cout << " in debug mode";
#endif
    std::cout << ".." << std::endl;

    std::vector<std::string> prob_names;
    for (int i = 1; i < argc - 1; i++)
        prob_names.push_back(argv[i]);

    std::string sol_name = argv[argc - 1];

    cg::causal_graph g;

#ifndef NDEBUG
    gui::cg_java_listener gl(g);
#endif

    std::cout << "parsing input files.." << std::endl;
    if (!g.read(prob_names))
    {
        std::cout << "the input problem is inconsistent.." << std::endl;
        return 1;
    }

    std::cout << "solving the problem.." << std::endl;
    if (g.solve())
    {
        std::cout << "hurray!! we have found a solution.." << std::endl;
        std::ofstream sol_file;
        sol_file.open(sol_name);
        sol_file << g.to_string();
        sol_file.close();
        return 0;
    }
    {
        std::cout << "the problem is unsolvable.." << std::endl;
        return 1;
    }
}