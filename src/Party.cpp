#include "Party.h"
#include "JoinPolicy.h"
#include "Graph.h"
#include "Simulation.h"
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), timer(0)
{
}
State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string &Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    if (this->getState() == Waiting)
    {
        if (this->getOffers().size() > 0)
        {
            this->timer = 1;
            this->setState(CollectingOffers);
        }
    }
    else if (timer < 3)
    {
        timer++;
    }
    else
    {
        Graph g = s.getGraph();
        int cId = this->mJoinPolicy->join(*this, g);
        s.addPartiesByCoalition(cId, this->getId());
        int aid = s.getAgents().size();
        s.addAgent(aid, this->getId(), s.getAgents()[cId].getPolicy());
        this->setState(Joined);
    }
}

const int &Party::getId() const
{
    return mId;
}

const vector<int> &Party::getOffers() const
{
    return offersbycId;
}

const void Party::AddOffer(int cId)
{
    offersbycId.push_back(cId);
}
