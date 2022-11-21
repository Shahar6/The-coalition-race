#include "Party.h"
#include "JoinPolicy.h"
#include "Graph.h"
#include "Simulation.h"
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), timer(0)
{
}
Party::Party(const Party &other)
{
    *this = other;
}
Party::~Party()
{
    //delete &mName; should this be deleted?
    //delete mJoinPolicy;
}
Party &Party::operator=(const Party &other)
{
    if (this != &other)
    {
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy;
        mState = other.mState;
        timer = other.timer;
        offersbycId.clear();
        for (int i : other.offersbycId)
        {
            offersbycId.push_back(i);
        }
    }
    return *this;
}
Party::Party(Party &&other) noexcept : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState), timer(other.timer), offersbycId(other.offersbycId)
{
    //other.mName = nullptr; should this be deleted?
    //other.mJoinPolicy = nullptr;
}

Party &Party::operator=(Party &&other) noexcept
{
    mId = other.mId, mName = other.mName, mMandates = other.mMandates, mJoinPolicy = other.mJoinPolicy, mState = other.mState, timer = other.timer, offersbycId = other.offersbycId;
    other.mName = nullptr;
    other.mJoinPolicy = nullptr;
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