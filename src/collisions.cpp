#include "collisions.hpp"


CollisionManager::CollisionManager() {
  CollideTable[int(PhysObject::PhysType::PHYS_BALL)][int(PhysObject::PhysType::PHYS_BALL)] = &CollisionManager::CollideBallBall;
  CollideTable[int(PhysObject::PhysType::PHYS_BALL)][int(PhysObject::PhysType::PHYS_CUBE)] = &CollisionManager::CollideBallCube;
  CollideTable[int(PhysObject::PhysType::PHYS_BALL)][int(PhysObject::PhysType::PHYS_WALL)] = &CollisionManager::CollideBallWall;
  CollideTable[int(PhysObject::PhysType::PHYS_CUBE)][int(PhysObject::PhysType::PHYS_CUBE)] = &CollisionManager::CollideCubeCube;
  CollideTable[int(PhysObject::PhysType::PHYS_CUBE)][int(PhysObject::PhysType::PHYS_WALL)] = &CollisionManager::CollideCubeWall;
}


void CollisionManager::CollideAll(CreaturesContainer* creatures_container) {
  assert(creatures_container);

  for (size_t i = 0; i < creatures_container->NumOfCreatures(); ++i) {
    for (size_t j = i + 1; j < creatures_container->NumOfCreatures(); ++j) {
      PhysObject* phys_obj1 = creatures_container->GetPhysComponent(i);
      PhysObject* phys_obj2 = creatures_container->GetPhysComponent(j);

      int type1 = static_cast<int>(phys_obj1->GetType());
      int type2 = static_cast<int>(phys_obj2->GetType());

      if (type1 > type2) {
        std::swap(phys_obj1, phys_obj2);
        std::swap(type1, type2);
      }

      if (CollideTable[type1][type2])
        (this->*CollideTable[type1][type2])(phys_obj1, phys_obj2);
    }
  }
}


bool CollisionManager::DidCollideBallBall(const PhysBall* first, const PhysBall* second) {
  assert(first);
  assert(second);

  double radius_sum = first->GetRadius() + second->GetRadius();
  double distance = (first->center - second->center).Length();

  return distance < radius_sum;
}


bool CollisionManager::DidCollideBallWall(const PhysBall* ball, const PhysWall* wall) {
  assert(ball);
  assert(wall);

  switch (wall->GetWallType()) {
    case PhysWall::WallType::LEFT:
    case PhysWall::WallType::RIGHT:
      return std::abs(ball->center.x - wall->edge1.x) < ball->GetRadius();
    case PhysWall::WallType::UPPER:
    case PhysWall::WallType::LOWER:
      return std::abs(ball->center.y - wall->edge1.y) < ball->GetRadius();
  }

  return false;
}


bool CollisionManager::CollideBallBall(PhysObject* raw_ball1,
                                       PhysObject* raw_ball2) {
  assert(raw_ball1);
  assert(raw_ball2);

  PhysBall* ball1 = reinterpret_cast<PhysBall*>(raw_ball1);
  PhysBall* ball2 = reinterpret_cast<PhysBall*>(raw_ball2);

  if (!DidCollideBallBall(ball1, ball2))
    return false;
  
  double res_charge = (ball1->charge + ball2->charge) / 2;

  Vector2f center_line12 = ball2->center - ball1->center;

  Vector2f impulse1 = ball1->GetImpulse();
  Vector2f impulse2 = ball2->GetImpulse();

  Vector2f impulse_proj1 = impulse1.GetProjection(center_line12);
  Vector2f impulse_proj2 = impulse2.GetProjection(-center_line12);

  Vector2f delta_impulse1 = impulse_proj2 - impulse_proj1;

  ball1->AddDeltaImpulse(delta_impulse1);
  ball2->AddDeltaImpulse(-delta_impulse1);

  ball1->charge = res_charge;
  ball2->charge = res_charge;

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

  ColorRGB ball_color = ball_rend->GetColor();
  ColorRGB cube_color = cube_rend->GetColor();

  cube_rend->SetColor(ball_color + cube_color);

  return true;
}


void CollisionManager::PushBallFromWall(PhysBall* ball, PhysWall* wall) {
  assert(ball);
  assert(wall);

  switch (wall->GetWallType()) {
    case PhysWall::WallType::LEFT:
      ball->center.x += ball->GetRadius() - std::abs(ball->center.x - wall->edge1.x);
      break;
    case PhysWall::WallType::RIGHT:
      ball->center.x -= ball->GetRadius() - std::abs(ball->center.x - wall->edge1.x);
      break;
    case PhysWall::WallType::UPPER:
      ball->center.y -= ball->GetRadius() - std::abs(ball->center.y - wall->edge1.y);
      break;
    case PhysWall::WallType::LOWER:
      ball->center.y += ball->GetRadius() - std::abs(ball->center.y - wall->edge1.y);
      break;
  }
}



bool CollisionManager::CollideBallWall(PhysObject* raw_ball,
                                       PhysObject* raw_wall) {
  assert(raw_ball);
  assert(raw_wall);

  PhysBall* ball = reinterpret_cast<PhysBall*>(raw_ball);
  PhysWall* wall = reinterpret_cast<PhysWall*>(raw_wall);

  Vector2f vel_x = Vector2f(ball->velocity.x, 0);
  Vector2f vel_y = Vector2f(0, ball->velocity.y);

  if (!DidCollideBallWall(ball, wall))
    return false;
  
  PushBallFromWall(ball, wall);

  switch (wall->GetWallType()) {
    case PhysWall::WallType::LEFT:
    case PhysWall::WallType::RIGHT:
      ball->velocity -= 2 * vel_x;
      break;
    case PhysWall::WallType::UPPER:
    case PhysWall::WallType::LOWER:
      ball->velocity -= 2 * vel_y;
      break;
  }

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


bool CollisionManager::CollideCubeWall(PhysObject* raw_cube,
                                       PhysObject* raw_wall) {
  assert(raw_cube);
  assert(raw_wall);

  return CollideBallWall(raw_cube, raw_wall);
}