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
    void AddOffer(int cId);
    // rule of 5
    Party(const Party& other);
    ~Party();
    Party& operator=(const Party& other);
    Party(Party&& other) noexcept;
    Party& operator=(Party&& other) noexcept;
    void setTimer(int t);
private:
    int mId;
    string mName;
    int mMandates;
    int timer;
    JoinPolicy *mJoinPolicy;
    State mState;
    vector<int> offersbycId;
};
