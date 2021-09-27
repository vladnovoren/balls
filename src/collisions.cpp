#include "collisions.hpp"


void CollisionManager::CollideAll(CreaturesManager* creatures_manager) {
  assert(creatures_manager);

  for (size_t i = 0; i < creatures_manager->NumOfCreatures(); ++i) {
    for (size_t j = i; j < creatures_manager->NumOfCreatures(); ++j) {
    }
  }
}


bool CollisionManager::DidCollide(const PhysBall* first, const PhysBall* second) {
  assert(first);
  assert(second);

  double radius_sum = first->GetRadius() + second->GetRadius();
  double distance = (first->GetCenter() - second->GetCenter()).Length();

  return IsZero(radius_sum - distance);
}


bool CollisionManager::CollideBallBall(PhysBall* first, PhysBall* second) {
  if (!DidCollide(first, second))
    return false;

  Vector2f center_line12 = second->GetCenter() - first->GetCenter();

  Vector2f impulse1 = first->GetImpulse();
  Vector2f impulse2 = second->GetImpulse();

  Vector2f impulse_proj1 = impulse1.GetProjection(center_line12);
  Vector2f impulse_proj2 = impulse2.GetProjection(-center_line12);

  Vector2f delta_impulse1 = impulse_proj2 - impulse_proj1;

  first->AddDeltaImpulse(delta_impulse1);
  second->AddDeltaImpulse(-delta_impulse1);

  return true;
}

