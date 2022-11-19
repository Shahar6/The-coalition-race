#include "Party.h"
#include "Graph.h"
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting)
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
    // TODO: implement this method
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
