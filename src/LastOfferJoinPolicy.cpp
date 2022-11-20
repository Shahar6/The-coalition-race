#include "JoinPolicy.h"
#include "Party.h"
#include <vector>
LastOfferJoinPolicy::LastOfferJoinPolicy()
{
}
const int LastOfferJoinPolicy::join(Party &party, Graph &graph)
{
    vector<int> offers = party.getOffers();
    return offers[offers.size() - 1];
}