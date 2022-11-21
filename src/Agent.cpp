#include "Agent.h"
#include "SelectionPolicy.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : cId(-1), mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
}
Agent::Agent(const Agent &other) : cId(other.cId), mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy()
{
    if (other.mSelectionPolicy->type() == 'M')
    {
        this->mSelectionPolicy = new MandatesSelectionPolicy();
    }
    else
    {
        this->mSelectionPolicy = new EdgeWeightSelectionPolicy();
    }
}
Agent::~Agent()
{
    if (mSelectionPolicy)
    {
        delete mSelectionPolicy;
    }
    mSelectionPolicy = nullptr;
}
Agent& Agent::operator=(const Agent other)
{
    if (this != &other)
    {
        cId = other.cId;
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        if(other.mSelectionPolicy->type() == 'M'){
            this->mSelectionPolicy = new MandatesSelectionPolicy();
        }
        else{
            this->mSelectionPolicy = new EdgeWeightSelectionPolicy();
        }
    }
    return *this;
}
Agent::Agent(Agent&& other) noexcept : cId(other.cId), mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy) {
    other.mSelectionPolicy = nullptr;
}
Agent& Agent::operator=(Agent&& other) noexcept{
    if(this != &other){
        delete mSelectionPolicy;
    }
    cId = other.cId;
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mSelectionPolicy = other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
    return *this;
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

SelectionPolicy *Agent::getPolicy() const
{
    return this->mSelectionPolicy;
}