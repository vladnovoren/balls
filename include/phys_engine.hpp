#ifndef PHYS_ENGINE
#define PHYS_ENGINE

#include "vector2.hpp"
#include "phys_objects.hpp"

const size_t MAX_N_CREATURES = 100;
const double COULOMBS_LAW_K = 9e9;

class PhysEngine {
  PhysBall creatures[MAX_N_CREATURES];
  size_t n_creatures;
public:
  void ResponseAllForces();

  void ResponseForcesChargedBall(const PhysChargedBall& first, const PhysChargedBall& second);

  void ResponseCollisions();
};

#endif /* phys_engine.hpp */

