#pragma once
#include "Simulation.h"

class Coalition
{
public:
    Coalition(int mandates, Simulation &);
    int getMandates() const;
    void addParty(int mandates, Simulation &);

private:
    int count;
    void update(Simulation &);
};
