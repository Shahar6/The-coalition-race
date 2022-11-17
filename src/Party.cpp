#include "Party.h"
#include "Graph.h"
Party::Party(int id, string name, int mandates, JoinPolicy *jp, Graph graph, vector<int> neighbors) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), coalition(-1), mGraph(graph)
{
    for()
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

const Graph Party::getGraph()
{
    return mGraph;
}
