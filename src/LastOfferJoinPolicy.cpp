#include "JoinPolicy.h"
#include "Party.h"
#include <vector>

    virtual const int LastOfferJoinPolicy::join(Party &party, Graph &g)
    {
        vector<int> offers = party.getOffers();
        return offers[offers.size() - 1];
    }
