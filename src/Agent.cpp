#include "Agent.h"
#include "SelectionPolicy.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), cId(-1)
{
    // You can change the implementation of the constructor, but not the signature!
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{
    Graph g = sim.getGraph();
    int pId = this->mSelectionPolicy->select(*this, g, sim);
    if (pId != -1)
    {
        Party toOffer = g.getParty(pId);
        toOffer.AddOffer(this->getcId());
    }
}
int Agent::getcId() const
{
    return cId;
}

void Agent::setcId(int id)
{
    cId = id;
}

SelectionPolicy* Agent::getPolicy() const{
    return this->mSelectionPolicy;
}