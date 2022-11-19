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

const Party& Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}
const vector<int>& Graph::getNeighborsIds(int partyId, Simulation &s) const{
    return mEdges[partyId];
}

const vector<int>* Graph::getValidNeighborsIds(int partyId, int cId, Simulation &s) const{
    vector<int>* ret = new vector<int>;
    vector<int> temp = s.getPartiesByCoalitions()[cId];
    vector<int> all_n = getNeighborsIds(partyId, s);
    for(int p_edge : all_n){
        bool contains = false;
        for(int e : temp){
            if(e == p_edge){
                contains = true;
            }
        }
        if(!contains){
            (*ret).push_back(p_edge);
        }
    }
    return ret;

}

// this method returns a reference to the vector containing all the parties
const vector<Party>& Graph::getParties() const{
    return mVertices;
}

vector<int> Graph::getOffers(Party &party)
{
    return offers[party.getId()]; 
}

void Graph::addOffertoAParty(Agent &a, Party &party)
{
    getOffers(&party).push_back(a.getId);
}
