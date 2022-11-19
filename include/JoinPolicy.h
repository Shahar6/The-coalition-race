#pragma once
#include "Party.h"
#include <vector>
#include "Graph.h"
class JoinPolicy {
    public:
      virtual const void join()=0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
      virtual const int join(Party &party);
};


class LastOfferJoinPolicy : public JoinPolicy {
    public:
      virtual const int join(Party &party, Graph &graph);
};