#include "collide_funcs.hpp"


bool ReadyToCollide(Creature* creature) {
  assert(creature);

  return creature->activity_level == Creature::ActivityLevel::ACTIVE ||
         creature->activity_level == Creature::ActivityLevel::TO_DELETE;
}


bool DidCollideBallBall(const PhysBall* first, const PhysBall* second) {
  assert(first);
  assert(second);

  double radius_sum = first->GetRadius() + second->GetRadius();
  double distance = (first->center - second->center).Length();

  return distance < radius_sum;
}


bool DidCollideBallWall(const PhysBall* ball, const PhysWall* wall) {
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


bool CollideBallBall(PhysObject* raw_ball1,
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


bool CollideBallCube(PhysObject* raw_ball, PhysObject* raw_cube) {
  assert(raw_ball);
  assert(raw_cube);

  if (!CollideBallBall(raw_ball, raw_cube))
    return false;

  PhysBall* ball = reinterpret_cast<PhysBall*>(raw_ball);
  PhysBall* cube = reinterpret_cast<PhysBall*>(raw_cube);

  Renderable* ball_rend = ball->GetOwner()->GetRendComponent();
  Renderable* cube_rend = cube->GetOwner()->GetRendComponent();

  ColorRGB temp = ball_rend->GetColor();
  ball_rend->SetColor(cube_rend->GetColor());
  cube_rend->SetColor(temp);

  return true;
}


void PushBallFromWall(PhysBall* ball, PhysWall* wall) {
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


bool CollideBallWall(PhysObject* raw_ball,
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


bool CollideCubeCube(PhysObject* raw_cube1,
                                       PhysObject* raw_cube2) {
  assert(raw_cube1);
  assert(raw_cube2);

  if (!CollideBallBall(raw_cube1, raw_cube2))
    return false;

  PhysCube* cube1 = reinterpret_cast<PhysCube*>(raw_cube1);
  PhysCube* cube2 = reinterpret_cast<PhysCube*>(raw_cube2);

  Renderable* cube1_rend = cube1->GetOwner()->GetRendComponent();
  Renderable* cube2_rend = cube2->GetOwner()->GetRendComponent();

  ColorRGB temp = cube1_rend->GetColor();
  cube1_rend->SetColor(cube2_rend->GetColor());
  cube2_rend->SetColor(temp);

  return true;
}


bool CollideCubeWall(PhysObject* raw_cube,
                                       PhysObject* raw_wall) {
  assert(raw_cube);
  assert(raw_wall);

  return CollideBallWall(raw_cube, raw_wall);
}