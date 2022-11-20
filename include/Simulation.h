#pragma once

#include <vector>
#include "Agent.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);
    bool have_sixtyOne;
    vector<vector<int>> Coalitions;
    void step();
    bool shouldTerminate() const;
    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    void addPartiesByCoalition(int cid, int pid);
    void addAgent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

private:
    Graph mGraph;
    vector<Agent> mAgents;
};
