#include "phys_objects.hpp"


bool DidCollide(const PhysBall& first, const PhysBall& second) {
  double radius_sum = first->GetRadius() + second->GetRadius();
  double distance = (first->GetCenter() - second->GetCenter()).Length();

  return 
}


void CollideBallBall(PhysBall* first, PhysBall* second) {
  assert(first);
  assert(second);

  Vector2f impulse1 = first->GetImpulse();
  Vector2f impulse2 = second->GetImpulse();
}

