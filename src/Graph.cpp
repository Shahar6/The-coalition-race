#include "Graph.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges)
{
    // You can change the implementation of the constructor, but not the signature!
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

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}
const vector<int> &Graph::getNeighborsIds(int partyId, Simulation &s) const
{
    return mEdges[partyId];
}

// this method returns only the neighbors u may offer to join ur coalition, remember to delete the vector after usage
const vector<int> *Graph::getValidNeighborsIds(int partyId, int cId, Simulation &s) const
{
    vector<int> *ret = new vector<int>;
    vector<int> all_n = getNeighborsIds(partyId, s);
    for (int p_edge : all_n)
    {
        if (this->getParty(p_edge).getState() != Joined) // checks that the party isn't in a coalition already
        {
                vector<int> p_offers = this->getParty(p_edge).getOffers();
                if (std::count(p_offers.begin(), p_offers.end(), cId)) // checks if the party has an offer from the coalition
                {
                }
                else
                {
                    (*ret).push_back(p_edge); // adds the party to the vector
                }           
        }
    }
    return ret;
}

// this method returns a reference to the vector containing all the parties
const vector<Party> &Graph::getParties() const
{
    return mVertices;
}
