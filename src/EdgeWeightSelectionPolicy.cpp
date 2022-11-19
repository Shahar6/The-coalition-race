#include "SelectionPolicy.h"


virtual const int EdgeWeightSelectionPolicy::select(Agent &agent, Graph &graph, Simulation &s)
{
   vector<int> neighbors = *graph.getValidNeighborsIds(agent.getId(), agent.getcId(),s);
   int maxEdge = -1;
   int partyId = -1;
   for(int i=0; i<neighbors.size();i++){
    if(maxEdge< graph.getEdgeWeight(agent.getId(), neighbors[i])){
        maxEdge = graph.getEdgeWeight(agent.getId(), neighbors[i]);
        partyId = neighbors[i];
    }
    return partyId;
   }
};