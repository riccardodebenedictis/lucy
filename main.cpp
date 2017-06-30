#include "causal_graph.h"
#ifndef NDEBUG
#include "cg_java_listener.h"
#include <future>
#endif
#include <iostream>
#include <fstream>

using namespace smt;

bool parse_problem(cg::causal_graph &g, const std::vector<std::string> &prob_names)
{
    std::cout << "parsing input files.." << std::endl;
    if (g.read(prob_names))
        return true;
    else
    {
        std::cout << "the input problem is inconsistent.." << std::endl;
        return false;
    }
}

bool solve_problem(cg::causal_graph &g)
{
    std::cout << "solving the problem.." << std::endl;
    if (g.solve())
    {
        std::cout << "hurray!! we have found a solution.." << std::endl;
        return true;
    }
    {
        std::cout << "the problem is unsolvable.." << std::endl;
        return false;
    }
}

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

#ifndef NDEBUG
    std::future<bool> prs_ftr = std::async(std::launch::async, parse_problem, std::ref(g), std::ref(prob_names));
    bool prs = prs_ftr.get();
#else
    bool prs = parse_problem(prob_names);
#endif

    if (!prs) // the input problem is inconsistent..
        return 1;

#ifndef NDEBUG
    std::future<bool> slv_ftr = std::async(std::launch::async, solve_problem, std::ref(g));
    bool slv = slv_ftr.get();
#else
    bool slv = solve_problem();
#endif

    if (slv) // we have found a solution..
    {
        std::ofstream sol_file;
        sol_file.open(sol_name);
        sol_file << g.to_string();
        sol_file.close();
        return 0;
    }
    else // the problem is unsolvable..
        return 1;
}