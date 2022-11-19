#pragma once
#include "Agent.h"
#include "Party.h"
#include "Graph.h"

class SelectionPolicy
{
public:
  virtual const void select() = 0;
};

class MandatesSelectionPolicy : public SelectionPolicy
{
public:
  virtual const int select(Agent &a, Graph &g, Simulation &s);
};
class EdgeWeightSelectionPolicy : public SelectionPolicy
{
public:
  virtual const int select(Agent &a, Graph &g, Simulation &s);
};
