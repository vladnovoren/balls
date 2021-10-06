#include "react_funcs.hpp"


void TurnCubesIntoBall(Cube* cube1, Cube* cube2, CreaturesContainer* creatures_container) {
  assert(cube1);
  assert(cube2);
  assert(creatures_container);

  cube1->activity_level = Creature::ActivityLevel::NOT_ACTIVE;
  cube2->activity_level = Creature::ActivityLevel::NOT_ACTIVE;

  PhysCube* phys_cube1 = reinterpret_cast<PhysCube*>(cube1->GetPhysComponent());
  PhysCube* phys_cube2 = reinterpret_cast<PhysCube*>(cube2->GetPhysComponent());

  RenderableSquare* rend_cube1 = reinterpret_cast<RenderableSquare*>(cube1->GetRendComponent());
  // RenderableSquare* rend_cube2 = reinterpret_cast<RenderableSquare*>(cube2->GetRendComponent());

  Vector2f velocity = phys_cube1->velocity + phys_cube2->velocity;
  // velocity.Resize(sqrt((phys_cube1->velocity * phys_cube1->velocity + 
  //                       phys_cube2->velocity * phys_cube2->velocity) / 2));

  creatures_container->AddCreature(new Ball(phys_cube1->GetMass() + phys_cube2->GetMass(),
                                            velocity,
                                            Vector2f(0, 0),
                                            0.5 * (phys_cube1->center + phys_cube2->center),
                                            DEFAULT_SIDE_LEN * sqrt(2.0 / M_PI),
                                            phys_cube1->charge + phys_cube2->charge,
                                            rend_cube1->GetColor(),
                                            Creature::ActivityLevel::ACTIVE));
}


void TurnCubeBallIntoBall(Cube* cube, Ball* ball, CreaturesContainer* creatures_container) {
  assert(cube);
  assert(ball);
  assert(creatures_container);

  cube->activity_level = Creature::ActivityLevel::NOT_ACTIVE;

  PhysCube* phys_cube = reinterpret_cast<PhysCube*>(cube->GetPhysComponent());
  PhysBall* phys_ball = reinterpret_cast<PhysBall*>(ball->GetPhysComponent());

  phys_ball->charge += phys_cube->charge;
  phys_ball->SetMass(phys_ball->GetMass() + phys_cube->GetMass());
  phys_ball->velocity = phys_cube->velocity + phys_ball->velocity;;
  phys_ball->SetRadius(sqrt(phys_ball->GetRadius() * phys_ball->GetRadius() + phys_cube->GetRadius() * phys_cube->GetRadius()));
}


void TurnBallIntoCubes(Ball* ball, CreaturesContainer* creatures_container) {
  assert(ball);
  assert(creatures_container);

  ball->activity_level = Creature::ActivityLevel::NOT_ACTIVE;

  PhysBall* phys_ball = reinterpret_cast<PhysBall*>(ball->GetPhysComponent());
  RenderableBall* rend_ball = reinterpret_cast<RenderableBall*>(ball->GetRendComponent());

  size_t n_cubes = phys_ball->GetMass();
  double d_phi = 2.0 * M_PI / n_cubes;
  double charge = phys_ball->charge / n_cubes;

  double abs_velocity = phys_ball->velocity.Length();
  Vector2f velocity = Vector2f(abs_velocity, 0);

  Vector2f arrow = Vector2f(phys_ball->GetRadius(), 0);

  for (size_t i = 0; i < n_cubes; ++i) {
    arrow.Rotate(d_phi);
    velocity.Rotate(d_phi);
    creatures_container->AddCreature(new Cube(DEFAULT_CUBE_MASS,
                                              velocity,
                                              Vector2f(0, 0),
                                              phys_ball->center + arrow,
                                              DEFAULT_SIDE_LEN,
                                              charge,
                                              rend_ball->GetColor(),
                                              Creature::ActivityLevel::ACTIVE));
  }
}


bool ReactBallBall(Creature* raw_ball1, Creature* raw_ball2, CreaturesContainer* creatures_manager) {
  assert(raw_ball1);
  assert(raw_ball2);
  assert(creatures_manager);

  Ball* ball1 = reinterpret_cast<Ball*>(raw_ball1);
  Ball* ball2 = reinterpret_cast<Ball*>(raw_ball2);

  PhysBall* phys_ball1 = reinterpret_cast<PhysBall*>(ball1->GetPhysComponent());
  PhysBall* phys_ball2 = reinterpret_cast<PhysBall*>(ball2->GetPhysComponent());

  if (!DidCollideBallBall(phys_ball1, phys_ball2))
    return false;

  TurnBallIntoCubes(ball1, creatures_manager);
  TurnBallIntoCubes(ball2, creatures_manager);

  return true;
}


bool ReactBallCube(Creature* raw_ball, Creature* raw_cube, CreaturesContainer* creatures_manager) {
  assert(raw_ball);
  assert(raw_cube);
  assert(creatures_manager);

  Ball* ball = reinterpret_cast<Ball*>(raw_ball);
  Cube* cube = reinterpret_cast<Cube*>(raw_cube);

  PhysBall* phys_ball = reinterpret_cast<PhysBall*>(ball->GetPhysComponent());
  PhysBall* phys_cube = reinterpret_cast<PhysCube*>(cube->GetPhysComponent());

  if (!DidCollideBallBall(phys_ball, phys_cube))
    return false;

  TurnCubeBallIntoBall(cube, ball, creatures_manager);
  
  return true;
}


bool ReactCubeCube(Creature* raw_cube1, Creature* raw_cube2, CreaturesContainer* creatures_manager) {
  assert(raw_cube1);
  assert(raw_cube2);
  assert(creatures_manager);

  Cube* cube1 = reinterpret_cast<Cube*>(raw_cube1);
  Cube* cube2 = reinterpret_cast<Cube*>(raw_cube2);

  PhysCube* phys_cube1 = reinterpret_cast<PhysCube*>(cube1->GetPhysComponent());
  PhysCube* phys_cube2 = reinterpret_cast<PhysCube*>(cube2->GetPhysComponent());

  if (!DidCollideBallBall(phys_cube1, phys_cube2))
    return false;

  TurnCubesIntoBall(cube1, cube2, creatures_manager);

  return true;
}
