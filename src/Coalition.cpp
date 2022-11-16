#include "Coalition.h"

Coalition::Coalition(int mandates, Simulation &sim) : count(mandates)
{
    update(sim);
}

int Coalition::getMandates() const{
    return count;
}

void Coalition::addParty(int mandates, Simulation &sim){
    count += mandates;
    update(sim);
}

void Coalition::update(Simulation &sim){
    if(count >= 61){
        sim.have_sixtyOne = true;
    }
}