#include "causal_graph.h"
#ifdef BUILD_GUI
#include "java_gui.h"
#include "cg_java_listener.h"
#include "sat_java_listener.h"
#endif
#include <iostream>
#include <fstream>

using namespace smt;

int main(int argc, char *argv[], char *envp[])
{
    std::vector<std::string> prob_names;
    for (int i = 1; i < argc - 1; i++)
        prob_names.push_back(argv[i]);

    std::string sol_name = argv[argc - 1];

    try
    {
        std::cout << "starting lucy";
#ifndef NDEBUG
        std::cout << " in debug mode";
#endif
        std::cout << ".." << std::endl;
        cg::causal_graph g;

#ifdef BUILD_GUI
        gui::java_gui j_gui;
        gui::sat_java_listener satl(j_gui, g.core::sat);
        gui::cg_java_listener gl(j_gui, g);
#endif

        std::cout << "parsing input files.." << std::endl;
        g.read(prob_names);

        std::cout << "solving the problem.." << std::endl;
        g.solve();

        std::cout << "hurray!! we have found a solution.." << std::endl;
        std::ofstream sol_file;
        sol_file.open(sol_name);
        sol_file << g.to_string();
        sol_file.close();
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
}