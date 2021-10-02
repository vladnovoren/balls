#include "collisions.hpp"


CollisionManager::CollisionManager() {
  CollideTable[int(PhysObject::PhysType::PHYS_BALL)][int(PhysObject::PhysType::PHYS_BALL)] = &CollisionManager::CollideBallBall;
  CollideTable[int(PhysObject::PhysType::PHYS_BALL)][int(PhysObject::PhysType::PHYS_CUBE)] = &CollisionManager::CollideBallCube;
  CollideTable[int(PhysObject::PhysType::PHYS_BALL)][int(PhysObject::PhysType::PHYS_WALL)] = &CollisionManager::CollideBallWall;
  CollideTable[int(PhysObject::PhysType::PHYS_CUBE)][int(PhysObject::PhysType::PHYS_BALL)] = nullptr;
  CollideTable[int(PhysObject::PhysType::PHYS_CUBE)][int(PhysObject::PhysType::PHYS_CUBE)] = nullptr;
  CollideTable[int(PhysObject::PhysType::PHYS_CUBE)][int(PhysObject::PhysType::PHYS_WALL)] = nullptr;
  CollideTable[int(PhysObject::PhysType::PHYS_WALL)][int(PhysObject::PhysType::PHYS_BALL)] = nullptr;
  CollideTable[int(PhysObject::PhysType::PHYS_WALL)][int(PhysObject::PhysType::PHYS_CUBE)] = nullptr;
  CollideTable[int(PhysObject::PhysType::PHYS_WALL)][int(PhysObject::PhysType::PHYS_WALL)] = nullptr;
}


void CollisionManager::CollideAll(CreaturesContainer* creatures_container) {
  assert(creatures_container);

  for (size_t i = 0; i < creatures_container->NumOfCreatures(); ++i) {
    PhysObject* phys_obj1 = creatures_container->GetPhysComponent(i);
    int id1 = int(phys_obj1->GetType());
    for (size_t j = i; j < creatures_container->NumOfCreatures(); ++j) {
      PhysObject* phys_obj2 = creatures_container->GetPhysComponent(j);
      int id2 = int(phys_obj2->GetType());
      if (id1 > id2) {
        std::swap(phys_obj1, phys_obj2);
        std::swap(id1, id2);
      }
      if (!CollideTable[i][j])
        continue;
      (this->*CollideTable[i][j])(phys_obj1, phys_obj2);
    }
  }
}


bool CollisionManager::DidCollide(const PhysBall* first, const PhysBall* second) {
  assert(first);
  assert(second);

  double radius_sum = first->GetRadius() + second->GetRadius();
  double distance = (first->center - second->center).Length();

  return IsZero(radius_sum - distance);
}


bool CollisionManager::CollideBallBall(PhysObject* raw_ball1,
                                       PhysObject* raw_ball2) {
  assert(raw_ball1);
  assert(raw_ball2);

  PhysBall* ball1 = reinterpret_cast<PhysBall*>(raw_ball1);
  PhysBall* ball2 = reinterpret_cast<PhysBall*>(raw_ball2);

  if (!DidCollide(ball1, ball2))
    return false;

  Vector2f center_line12 = ball2->center - ball1->center;

  Vector2f impulse1 = ball1->GetImpulse();
  Vector2f impulse2 = ball2->GetImpulse();

  Vector2f impulse_proj1 = impulse1.GetProjection(center_line12);
  Vector2f impulse_proj2 = impulse2.GetProjection(-center_line12);

  Vector2f delta_impulse1 = impulse_proj2 - impulse_proj1;

  ball1->AddDeltaImpulse(delta_impulse1);
  ball2->AddDeltaImpulse(-delta_impulse1);

  return true;
}


bool CollisionManager::CollideCubeCube(PhysObject* raw_cube1,
                                       PhysObject* raw_cube2) {
  assert(raw_cube1);
  assert(raw_cube2);

  if (!CollideBallBall(raw_cube1, raw_cube2))
    return false;

  PhysCube* cube1 = reinterpret_cast<PhysCube*>(raw_cube1);
  PhysCube* cube2 = reinterpret_cast<PhysCube*>(raw_cube2);

  Renderable* cube1_rend = cube1->GetOwner()->GetRendComponent();
  assert(cube1_rend);
  Renderable* cube2_rend = cube2->GetOwner()->GetRendComponent();
  assert(cube2_rend);

  ColorRGB temp = cube1_rend->GetColor();
  cube1_rend->SetColor(cube2_rend->GetColor());
  cube2_rend->SetColor(temp);

  return true;
}


bool CollisionManager::CollideBallCube(PhysObject* raw_ball,
                                       PhysObject* raw_cube) {
  assert(raw_ball);
  assert(raw_cube);

  if (!CollideBallBall(raw_ball, raw_cube))
    return false;

  PhysBall* ball = reinterpret_cast<PhysBall*>(raw_ball);
  PhysBall* cube = reinterpret_cast<PhysBall*>(raw_cube);

  Renderable* ball_rend = ball->GetOwner()->GetRendComponent();
  assert(ball_rend);
  Renderable* cube_rend = cube->GetOwner()->GetRendComponent();
  assert(cube_rend);

  cube_rend->SetColor(ball_rend->GetColor() + cube_rend->GetColor());

  return true;
}


bool CollisionManager::CollideBallWall(PhysObject* raw_ball,
                                       PhysObject* raw_wall) {
  assert(raw_ball);
  assert(raw_wall);

  PhysBall* ball = reinterpret_cast<PhysBall*>(raw_ball);
  PhysWall* wall = reinterpret_cast<PhysWall*>(raw_wall);

  Vector2f wall_line = wall->edge1 - wall->edge2;
  Vector2f center_wall_proj1 = (ball->center - wall->edge1).GetProjection(wall_line);
  Vector2f center_wall_proj2 = (wall->edge2 - ball->center).GetProjection(wall_line);

  if (center_wall_proj1 * center_wall_proj2 >= 0)
    return false;

  double rho = (wall->edge1 + center_wall_proj1 - ball->center).Length();
  if (rho > ball->GetRadius())
    return false;

  Vector2f vel_paral_proj = ball->velocity.GetProjection(wall_line) * Sign(wall_line * ball->velocity);
  Vector2f vel_norm_proj = ball->velocity - vel_paral_proj;
  ball->velocity -= 2 * vel_norm_proj;

  return true;
}
