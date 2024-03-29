#include "SelectionPolicy.h"
MandatesSelectionPolicy::MandatesSelectionPolicy()
{
}
MandatesSelectionPolicy::~MandatesSelectionPolicy()
{
}
const int MandatesSelectionPolicy::select(Agent &agent, Graph &graph, Simulation &s)
{
  vector<int> neighbors = graph.getValidNeighborsIds(agent.getPartyId(), agent.getcId(), s);
  int maxMandates = -1;
  int partyId = -1;
  for (int i = 0; i < (int)(neighbors.size()); i++)
  {
    if (maxMandates < graph.getMandates(neighbors[i]))
    {
      maxMandates = graph.getMandates(neighbors[i]);
      partyId = neighbors[i];
    }
  }
  return partyId;
}

const char MandatesSelectionPolicy::type()
{
  return 'M';
}
