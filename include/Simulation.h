#pragma once
#include <iostream>
#include <vector>
#include "Agent.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);
    void step();
    bool shouldTerminate() const;
    Graph &ncgetGraph();
    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    const vector<int>& getPartiesByCoalition(int cId) const;
    void addPartiesByCoalition(int cid, int pid);
    void addAgent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent &getAgent(int agentId);

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<vector<int>> Coalitions;
};
