#include "SelectionPolicy.h"


virtual const int MandatesSelectionPolicy::select(Agent &agent, Graph &graph, Simulation &s)
{
   vector<int> neighbors = *graph.getValidNeighborsIds(agent.getId(), agent.getcid(),s);
   int maxMandates = -1;
   int partyId = -1;
    for(int i=0; i<neighbors.size();i++){
      if(maxMandates< graph.getMandates(neighbors[i])){
        maxMandates = graph.getMandates(neighbors[i]);
        partyId = neighbors[i];
      }
    }
    return partyId;
}