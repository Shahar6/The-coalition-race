#pragma once
#include "Agent.h"
#include "Party.h"
#include "Graph.h"

class SelectionPolicy {
    public:
      void select() ;
};

class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
      const Party &select(Agent &a, Graph &g) ;
};
class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
    public:
      const Party &select(Agent &a, Graph &g) ;
};
 

