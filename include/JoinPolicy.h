#pragma once
#include <vector>
#include "Graph.h"
class JoinPolicy
{
public:
  virtual const int join(Party &party, Graph &graph, Simulation &sim) = 0;
  virtual const char type() = 0;
  virtual ~JoinPolicy() = default;
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
  MandatesJoinPolicy();
  virtual const int join(Party &party, Graph &graph, Simulation &sim);
  virtual const char type();
  ~MandatesJoinPolicy();
};

class LastOfferJoinPolicy : public JoinPolicy
{
public:
  LastOfferJoinPolicy();
  virtual const int join(Party &party, Graph &graph, Simulation &sim);
  virtual const char type();
  ~LastOfferJoinPolicy();
};