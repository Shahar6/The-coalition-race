#pragma once
#include "Simulation.h"

class SelectionPolicy
{
public:
  virtual const int select(Agent &agent, Graph &graph, Simulation &s) = 0;
  virtual const char type() = 0;
  virtual ~SelectionPolicy() = default;
};

class MandatesSelectionPolicy : public SelectionPolicy
{
public:
  MandatesSelectionPolicy();
  ~MandatesSelectionPolicy();
  virtual const int select(Agent &agent, Graph &graph, Simulation &s);
  virtual const char type();

};
class EdgeWeightSelectionPolicy : public SelectionPolicy
{
public:
  EdgeWeightSelectionPolicy();
  ~EdgeWeightSelectionPolicy();
  virtual const int select(Agent &agent, Graph &graph, Simulation &s); 
  virtual const char type();

};
