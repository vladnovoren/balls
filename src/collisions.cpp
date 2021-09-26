#include "collisions.hpp"


void CollisionManager::CollideAll(ObjectManager* obj_manager) {
  assert(obj_manager);


}


bool CollisionManager::DidCollide(const PhysBall& first, const PhysBall& second) {
  double radius_sum = first.GetRadius() + second.GetRadius();
  double distance = (first.GetCenter() - second.GetCenter()).Length();

  return IsZero(radius_sum - distance);
}


bool CollisionManager::CollideBallBall(const PhysBall& first, const PhysBall& second,
                                       Vector2f* first_d_impulse, Vector2f* second_d_impulse) {
  assert(first_d_impulse);
  assert(second_d_impulse);

  if (!DidCollide(*first, *second))
    return false;

  Vector2f center_line12 = second->GetCenter() - first->GetCenter();

  Vector2f impulse_paral_proj1;
  Vector2f impulse_norm_proj1;

  Vector2f impulse_paral_proj2;
  Vector2f impulse_norm_proj2;

  Vector2f impulse1 = first->GetImpulseProj(center_line12, &impulse_paral_proj1,
                                                           &impulse_norm_proj2);

  Vector2f impulse2 = second->GetImpulseProj(-center_line12, &impulse_paral_proj2,
                                                             &impulse_norm_proj2);
  std::swap(impulse_paral_proj1, impulse_paral_proj2);
  impulse1 = impulse_norm_proj1 + impulse_paral_proj1;
  impulse2 = impulse_norm_proj2 + impulse_paral_proj2;

  first->SetImpulse(impulse1);
  second->SetImpulse(impulse2);

  return true;
}

