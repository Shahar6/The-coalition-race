#pragma once

#include <vector>
#include "Graph.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    // rule of 5
    Agent(const Agent& other);
    ~Agent();
    Agent& operator=(const Agent other);
    Agent(Agent&& other) noexcept;
    Agent& operator=(Agent&& other) noexcept;
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    void setcId(int cId);
    int getcId() const;
    SelectionPolicy *getPolicy() const;

private:
    int cId;
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
};
