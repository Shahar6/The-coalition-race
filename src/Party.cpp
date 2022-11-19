#include "Party.h"
#include "Graph.h"
#include "vector"
Party::Party(int id, string name, int mandates, JoinPolicy *jp, Graph graph, vector<int> neighbor) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), coalition(-1), mGraph(graph)
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

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    // TODO: implement this method
}

const int & Party::getId() const
{
   return mId;
}

const Party::vector<int>& getOffers() const{
    return offersbycId;
}

const void Party::AddOffer(int cId){
  offersbycId.pushback(cId);  
}
const Graph Party::getGraph()
{
    return mGraph;
}
