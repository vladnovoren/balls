#include "react_funcs.hpp"


bool ReadyToReact(Creature* creature) {
  assert(creature);

  return creature->activity_level == Creature::ActivityLevel::ACTIVE;
}


bool DidReact(PhysObject* phys_obj1, PhysObject* phys_obj2) {
  assert(phys_obj1);
  assert(phys_obj2);

  return phys_obj1->GetKineticEnergy() + phys_obj2->GetKineticEnergy() >= MIN_REACT_ENERGY;
}


void TurnCubesIntoBall(PhysCube* phys_cube1, PhysCube* phys_cube2, CreaturesContainer* creatures_container) {
  assert(phys_cube1);
  assert(phys_cube2);
  assert(creatures_container);

  Cube* cube1 = static_cast<Cube*>(phys_cube1->GetOwner());
  Cube* cube2 = static_cast<Cube*>(phys_cube2->GetOwner());

  cube1->activity_level = Creature::ActivityLevel::TO_DELETE;
  cube2->activity_level = Creature::ActivityLevel::TO_DELETE;

  Renderable* rend_cube1 = cube1->GetRendComponent();
  Vector2f velocity = phys_cube1->velocity + phys_cube2->velocity;

  double ball_mass = phys_cube1->GetMass() + phys_cube2->GetMass();

  velocity.Resize(sqrt(2 * (phys_cube1->GetKineticEnergy() + phys_cube2->GetKineticEnergy()) / ball_mass));

  creatures_container->AddCreature(new Ball(ball_mass,
                                            velocity,
                                            Vector2f(0, 0),
                                            0.5 * (phys_cube1->center + phys_cube2->center),
                                            phys_cube1->GetRadius() + phys_cube2->GetRadius(),
                                            phys_cube1->charge + phys_cube2->charge,
                                            rend_cube1->GetColor(),
                                            Creature::ActivityLevel::TO_CREATE));
}


void TurnCubeBallIntoBall(PhysBall* phys_ball, PhysCube* phys_cube, CreaturesContainer* creatures_container) {
  assert(phys_cube);
  assert(phys_ball);
  assert(creatures_container);

  Cube* cube = static_cast<Cube*>(phys_cube->GetOwner());
  cube->activity_level = Creature::ActivityLevel::TO_DELETE;

  double new_ball_mass = phys_ball->GetMass() + phys_cube->GetMass();

  phys_ball->charge += phys_cube->charge;
  phys_ball->velocity = phys_cube->velocity + phys_ball->velocity;
  phys_ball->velocity.Resize(sqrt(2 * (phys_ball->GetKineticEnergy() + phys_cube->GetKineticEnergy()) / new_ball_mass));
  phys_ball->SetMass(new_ball_mass);
  phys_ball->SetRadius(sqrt(phys_ball->GetRadius() * phys_ball->GetRadius() + phys_cube->GetRadius() * phys_cube->GetRadius()));
}


void TurnBallIntoCubes(PhysBall* phys_ball, CreaturesContainer* creatures_container) {
  assert(phys_ball);
  assert(creatures_container);

  Ball* ball = static_cast<Ball*>(phys_ball->GetOwner());
  ball->activity_level = Creature::ActivityLevel::TO_DELETE;

  RenderableBall* rend_ball = static_cast<RenderableBall*>(ball->GetRendComponent());

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
                                              Creature::ActivityLevel::TO_CREATE));
  }
}


bool ReactBallBall(PhysObject* raw_ball1, PhysObject* raw_ball2, CreaturesContainer* creatures_manager) {
  assert(raw_ball1);
  assert(raw_ball2);
  assert(creatures_manager);

  PhysBall* phys_ball1 = static_cast<PhysBall*>(raw_ball1);
  PhysBall* phys_ball2 = static_cast<PhysBall*>(raw_ball2);

  if (!DidCollideBallBall(phys_ball1, phys_ball2))
    return false;

  TurnBallIntoCubes(phys_ball1, creatures_manager);
  TurnBallIntoCubes(phys_ball2, creatures_manager);

  return true;
}


bool ReactBallCube(PhysObject* raw_ball, PhysObject* raw_cube, CreaturesContainer* creatures_manager) {
  assert(raw_ball);
  assert(raw_cube);
  assert(creatures_manager);

  PhysBall* phys_ball = static_cast<PhysBall*>(raw_ball);
  PhysCube* phys_cube = static_cast<PhysCube*>(raw_cube);

  if (!DidCollideBallBall(phys_ball, phys_cube))
    return false;

  TurnCubeBallIntoBall(phys_ball, phys_cube, creatures_manager);

  return true;
}


bool ReactCubeCube(PhysObject* raw_cube1, PhysObject* raw_cube2, CreaturesContainer* creatures_manager) {
  assert(raw_cube1);
  assert(raw_cube2);
  assert(creatures_manager);

  PhysCube* phys_cube1 = static_cast<PhysCube*>(raw_cube1);
  PhysCube* phys_cube2 = static_cast<PhysCube*>(raw_cube2);

  if (!DidCollideBallBall(phys_cube1, phys_cube2))
    return false;

  TurnCubesIntoBall(phys_cube1, phys_cube2, creatures_manager);

  return true;
}
