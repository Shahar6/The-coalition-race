#include "JoinPolicy.h"
#include "Party.h"
#include <vector>
MandatesJoinPolicy::MandatesJoinPolicy() {

}
MandatesJoinPolicy::~MandatesJoinPolicy() {

}
const int MandatesJoinPolicy::join(Party &party, Graph &graph)
{
   vector<int> offers = party.getOffers();
   int maxMandates = -1;
   int firstIdParty = -1;
   for (int i = 0; i < (int)(offers.size()); i++)
   {
      if (maxMandates < graph.getMandates(offers[i]))
      {
         maxMandates = graph.getMandates(offers[i]);
         firstIdParty = offers[i];
      }
   }
   return firstIdParty;
}
const char MandatesJoinPolicy::type(){
   return 'M';
}
