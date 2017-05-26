#include "causal_graph.h"

using namespace cg;

int main(int argc, char *argv[], char *envp[])
{
    causal_graph cg;

    std::vector<std::string> file_names;
    for (int i = 1; i < argc; i++)
    {
        file_names.push_back(argv[i]);
    }

    bool r = cg.read(file_names);
    assert(r);

    bool s = cg.solve();
    assert(s);
}