#include "Graph.h"
#include "Simulation.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges)
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getcMandates(int cId, Simulation &sim) const
{
    const vector<int>& li = sim.getPartiesByCoalition(cId);
    int sum = 0;
    for (int i : li)
    {
        sum += this->getParty(i).getMandates();
    }
    return sum;
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}
Party &Graph::ncgetParty(int partyId)
{
    return mVertices[partyId];
}
const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}
const vector<int> &Graph::getNeighborsIds(int partyId, Simulation &s) const
{
    return mEdges[partyId];
}

// this method returns only the neighbors u may offer to join ur coalition, remember to delete the vector after usage
const vector<int> Graph::getValidNeighborsIds(int partyId, int cId, Simulation &s) const
{
    vector<int> ret;
    vector<int> all_n = getNeighborsIds(partyId, s);
    int indexCounter = 0;
    for (int p_edge : all_n)
    {
        if (p_edge != 0 && (this->getParty(indexCounter).getState() != Joined)) // checks that the party isn't in a coalition already
        {
            vector<int> p_offers = this->getParty(indexCounter).getOffers();
            if (std::count(p_offers.begin(), p_offers.end(), cId)) // checks if the party has an offer from the coalition
            {
            }
            else
            {
                ret.push_back(indexCounter); // adds the party to the vector
            }
        }
        indexCounter++;
    }

    return ret;
}
vector<Party> &Graph::ncgetParties()
{
    return mVertices;
}
// this method returns a reference to the vector containing all the parties
const vector<Party> &Graph::getParties() const
{
    return mVertices;
}
