#include "Party.h"
#include "JoinPolicy.h"
#include "Graph.h"
#include "Simulation.h"
#include "SelectionPolicy.h"
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), timer(0), mJoinPolicy(jp), mState(Waiting), offersbycId()
{
}
Party::Party(const Party &other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), timer(other.timer), mJoinPolicy(), mState(other.mState), offersbycId()
{
    if (other.mJoinPolicy->type() == 'M')
    {
        this->mJoinPolicy = new MandatesJoinPolicy();
    }
    else
    {
        this->mJoinPolicy = new LastOfferJoinPolicy();
    }
    for (int i : other.offersbycId)
    {
        offersbycId.push_back(i);
    }
}
Party::~Party()
{
    if (mJoinPolicy)
    {
        delete mJoinPolicy;
    }
}
Party &Party::operator=(const Party &other)
{
    if (this != &other)
    {
        if(mJoinPolicy){
            delete mJoinPolicy;
        }
        if(other.mJoinPolicy->type() == 'M'){
            mJoinPolicy = new MandatesJoinPolicy();
        }
        else{
            mJoinPolicy = new LastOfferJoinPolicy();
        }
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        timer = other.timer;
        mState = other.mState;
        offersbycId.clear();
        for (int i : other.offersbycId)
        {
            offersbycId.push_back(i);
        }
    }
    return *this;
}
Party::Party(Party &&other) noexcept : mId(other.mId), mName{other.mName}, mMandates(other.mMandates), timer(other.timer), mJoinPolicy{other.mJoinPolicy}, mState(other.mState), offersbycId(other.offersbycId)
{
    if (other.mJoinPolicy)
    {
        other.mJoinPolicy = nullptr;
    }
}

Party &Party::operator=(Party &&other) noexcept
{
    if(mJoinPolicy) delete mJoinPolicy;
    mId = other.mId, mName = other.mName, mMandates = other.mMandates, mJoinPolicy = other.mJoinPolicy, mState = other.mState, timer = other.timer, offersbycId = other.offersbycId;
    other.mJoinPolicy = nullptr;
    return *this;
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
    if (this->getState() != Joined)
    {
        if (this->getState() == Waiting)
        {
        }
        else if (timer < 3)
        {
            timer++;
        }
        else
        {
            Graph &g = s.ncgetGraph();
            int cId = this->mJoinPolicy->join(*this, g, s);
            s.addPartiesByCoalition(cId, this->getId());
            int aid = s.getAgents().size();
            if(s.getAgents()[cId].getPolicy()->type() == 'M'){
                auto jp = new MandatesSelectionPolicy;
                s.addAgent(aid, this->getId(), jp);
            }
            else{
                auto jp = new EdgeWeightSelectionPolicy;
                s.addAgent(aid, this->getId(), jp);
            }
            Agent& sm = s.getAgent(aid);
            sm.setcId(cId);
            this->setState(Joined);
        }
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

void Party::AddOffer(int cId)
{
    offersbycId.push_back(cId);
}
void Party::setTimer(int t){
    timer = t;
}