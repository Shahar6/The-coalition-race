#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), have_sixtyOne(false), Coalitions()
{
    int counter = 0;
    for (Agent Smith : agents)
    {
        Smith.setcId(counter);
        Coalitions[counter][0] = Smith.getPartyId();
        if (graph.getMandates(Smith.getPartyId()) >= 61)
        {
            have_sixtyOne = true;
        }
        counter++;
    }
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step() // running step for parties and agents
{
        vector<Party> p_list = mGraph.getParties();
        for (Party p : p_list)
        {
            p.step(*this);
        }
        for (Agent Smith : mAgents)
        {
            Smith.step(*this);
        }
}

bool Simulation::shouldTerminate() const
{
    bool flag(true); // used to signal whether all the parties are in joined state
    vector<Party> p_list = getGraph().getParties();
    for (Party p : p_list)
    {
        if (p.getState() != Joined)
        {
            flag = false;
        }
    }
    if(!flag){ // if not all are joined, checking whether a party has 61 or more mandates
        int sum = 0;
        for(vector<int> i : this->getPartiesByCoalitions()){
            for(int j : i){
                sum = sum + this->getParty(j).getMandates();
            }
            if(sum >= 61){
                return true;
            }
            else{
                sum=0;
            }
        }
    }
    else{
        return true;
    }
    return false;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    return Coalitions;
}

void Simulation::addPartiesByCoalition(int cid, int pid)
{
    this->Coalitions[cid].push_back(pid);
}

void Simulation::addAgent(int agentId, int partyId, SelectionPolicy *selectionPolicy)
{
    this->mAgents.push_back(Agent(agentId, partyId, selectionPolicy));
}