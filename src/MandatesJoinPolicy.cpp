#include "JoinPolicy.h"
#include "Party.h"
#include <vector>
MandatesJoinPolicy::MandatesJoinPolicy() {

}
MandatesJoinPolicy::~MandatesJoinPolicy() {

}
const int MandatesJoinPolicy::join(Party &party, Graph &graph, Simulation &sim)
{
   vector<int> offers = party.getOffers();
   int maxMandates = -1;
   int firstIdParty = -1;
   for (int i = 0; i < (int)(offers.size()); i++)
   {
      int temp = graph.getcMandates(offers[i], sim);
      if (maxMandates < temp)
      {
         maxMandates = temp;
         firstIdParty = offers[i];
      }
   }
   return firstIdParty;
}
const char MandatesJoinPolicy::type(){
   return 'M';
}
