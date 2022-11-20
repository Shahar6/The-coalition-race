#pragma once
#include "Simulation.h"

class SelectionPolicy
{
public:
  virtual const int select(Agent &agent, Graph &graph, Simulation &s) = 0;
};

class MandatesSelectionPolicy : public SelectionPolicy
{
public:
  MandatesSelectionPolicy();
  virtual const int select(Agent &agent, Graph &graph, Simulation &s);
};
class EdgeWeightSelectionPolicy : public SelectionPolicy
{
public:
  EdgeWeightSelectionPolicy();
  virtual const int select(Agent &agent, Graph &graph, Simulation &s);
};
