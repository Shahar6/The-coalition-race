#include "JoinPolicy.h"
#include "Party.h"
#include <vector>
LastOfferJoinPolicy::LastOfferJoinPolicy()
{
}
LastOfferJoinPolicy::~LastOfferJoinPolicy()
{
}
const int LastOfferJoinPolicy::join(Party &party, Graph &graph, Simulation &sim)
{
    vector<int> offers = party.getOffers();
    return offers[offers.size() - 1];
}
const char LastOfferJoinPolicy::type(){
   return 'L';
}