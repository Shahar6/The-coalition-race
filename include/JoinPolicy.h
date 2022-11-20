#pragma once
#include <vector>
#include "Graph.h"
class JoinPolicy
{
public:
  virtual const int join(Party &party, Graph &graph) = 0;
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
  MandatesJoinPolicy();
  virtual const int join(Party &party, Graph &graph);
};

class LastOfferJoinPolicy : public JoinPolicy
{
public:
  LastOfferJoinPolicy();
  virtual const int join(Party &party, Graph &graph);
};