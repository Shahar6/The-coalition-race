#include "SelectionPolicy.h"
EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy()
{
}
EdgeWeightSelectionPolicy::~EdgeWeightSelectionPolicy()
{
}
const int EdgeWeightSelectionPolicy::select(Agent &agent, Graph &graph, Simulation &s)
{
    vector<int> neighbors = *graph.getValidNeighborsIds(agent.getPartyId(), agent.getcId(), s);
    int maxEdge = -1;
    int partyId = -1;
    for (int i = 0; i < (int)(neighbors.size()); i++)
    {
        if (maxEdge < graph.getEdgeWeight(agent.getPartyId(), neighbors[i]))
        {
            maxEdge = graph.getEdgeWeight(agent.getPartyId(), neighbors[i]);
            partyId = neighbors[i];
        }
    }
    return partyId;
}
const char EdgeWeightSelectionPolicy::type(){
    return 'E';
}