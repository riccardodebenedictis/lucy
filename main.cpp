#include "causal_graph.h"
#include <iostream>

using namespace smt;

int main(int argc, char *argv[], char *envp[])
{
    std::cout << "starting lucy.." << std::endl;
    cg::causal_graph g;

    std::vector<std::string> file_names;
    for (int i = 1; i < argc - 1; i++)
    {
        file_names.push_back(argv[i]);
    }

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
    }
    else
    {
        std::cerr << "the problem is unsolvable.." << std::endl;
        return -1;
    }
}