#include "clause.h"
#include "sat_core.h"

namespace smt
{

clause::clause(sat_core &s, const std::vector<lit> &lits) : s(s), lits(lits)
{
    s.watches[s.index(!lits[0])].push_back(this);
    s.watches[s.index(!lits[1])].push_back(this);
}

clause::~clause() {}

bool clause::propagate(const lit &p)
{
    // make sure false literal is lits[1]..
    if (lits[0].v == p.v)
    {
        lit tmp = lits[0];
        lits[0] = lits[1];
        lits[1] = tmp;
    }

    // if 0th watch is true, the clause is already satisfied..
    if (s.value(lits[0]) == True)
    {
        s.watches[s.index(p)].push_back(this);
        return true;
    }

    // we look for a new literal to watch..
    for (size_t i = 1; i < lits.size(); i++)
    {
        if (s.value(lits[i]) != False)
        {
            lit tmp = lits[1];
            lits[1] = lits[i];
            lits[i] = tmp;
            s.watches[s.index(!lits[1])].push_back(this);
            return true;
        }
    }

    // clause is unit under assignment..
    s.watches[s.index(p)].push_back(this);
    return s.enqueue(lits[0], this);
}

std::string clause::to_string() const
{
    std::string c;
    c += "{ \"lits\" : [";
    for (std::vector<lit>::const_iterator it = lits.begin(); it != lits.end(); ++it)
    {
        if (it != lits.begin())
        {
            c += ", ";
        }
        c += (*it).to_string();
    }
    c += "]}";
    return c;
}
}
