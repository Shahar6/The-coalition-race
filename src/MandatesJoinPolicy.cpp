#include "JoinPolicy.h"
#include "Party.h"
#include <vector>
    virtual const int MandatesJoinPolicy::join(Party &party){
       vector<int> offers = party.getOffers();
       int maxMandates = -1;
       int firstIdParty = -1;
       for(int i=0; i<offers.size(); i++)
       {
          if(maxMandates < g.getMandates(offers[i])){
            maxMandates = g.getMandates(offers[i]);
            firstIdParty = offers[i];
          }
       }
    return firstIdParty;   
}
