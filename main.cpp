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

    cg::causal_graph g;

#ifndef NDEBUG
    gui::cg_java_listener gl(g);
#endif

    std::vector<std::string> file_names;
    for (int i = 1; i < argc - 1; i++)
        file_names.push_back(argv[i]);

    std::cout << "parsing input files.." << std::endl;
    if (!g.read(file_names))
    {
        std::cerr << "the input problem is inconsistent.." << std::endl;
        return -1;
    }

    std::cout << "solving.." << std::endl;
    if (g.solve())
    {
        std::cout << "we have found a solution!!" << std::endl;
        std::ofstream sol_file;
        sol_file.open(argv[argc - 1]);
        sol_file << g.to_string();
        sol_file.close();
        return 0;
    }
    else
    {
        std::cerr << "the problem is unsolvable.." << std::endl;
        return -1;
    }
}