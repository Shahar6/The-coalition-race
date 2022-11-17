#pragma once

#include <vector>
#include "Graph.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);

private:
    int cId;
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    
};
