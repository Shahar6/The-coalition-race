#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Party.h"

using std::vector;

class Graph
{
public:
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    Party & ncgetParty(int partyId); // nonconst getter
    const Party &getParty(int partyId) const;
    vector<Party> &ncgetParties();
    const vector<Party> &getParties() const;
    const vector<int> &getNeighborsIds(int partyId, Simulation &s) const;
    const vector<int> *getValidNeighborsIds(int partyId, int cId, Simulation &) const; // the one who uses this function is responsible to delete the object!

private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};
