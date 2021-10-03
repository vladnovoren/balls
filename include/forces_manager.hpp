#ifndef FORCES_MANAGER_HPP
#define FORCES_MANAGER_HPP

#include "creatures_container.hpp"


const double COULOMBS_LAW_K = 1e5;

class ForcesManager {
  typedef void (ForcesManager::*ResponseFunc)(PhysObject*, PhysObject*);
  ResponseFunc ResponseTable[N_PHYS_OBJECTS][N_PHYS_OBJECTS] = {};
public:
  ForcesManager();

  void CoulombsLawBallBall(PhysObject* raw_ball1, PhysObject* raw_ball2);

  void ResetAccelerations(CreaturesContainer* creatures_manager);

  void ResponseAll(CreaturesContainer* creatures_container);
};

#endif /* forces_manager.hpp */
