#pragma once
#include <string>

using std::string;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *, Graph graph, vector<int> neighbors); 

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    const int &getId() const;
    const Graph getGraph();
    const vector<int>& getOffers() const;
    const void AddOffer(int cId);

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int coalition;
    vector<int> offersbycId;
};
