#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

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
    Party(int id, string name, int mandates, JoinPolicy *);

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    const int &getId() const;
    const vector<int> &getOffers() const;
    const void AddOffer(int cId);

private:
    int mId;
    string mName;
    int mMandates;
    int timer;
    JoinPolicy *mJoinPolicy;
    State mState;
    vector<int> offersbycId;
};
