#include "creatures.hpp"


// Creature
//==============================================================================
Creature::Creature(PhysObject* phys_component,
                   Renderable* rend_component,
                   const ActivityLevel activity_level):
          phys_component(phys_component),
          rend_component(rend_component),
          activity_level(activity_level) {
}


Creature::~Creature() {
  delete phys_component;
  delete rend_component;
}


PhysObject* Creature::GetPhysComponent() const {
  return phys_component;
}


Renderable* Creature::GetRendComponent() const {
  return rend_component;
}
//==============================================================================


// Ball
//==============================================================================
Ball::Ball(const double mass, const Vector2f& velocity,
           const Vector2f& acceleration, const Vector2f& center,
           const double radius, const double charge, const ColorRGB& color,
           const ActivityLevel activity_level):
      Creature(new PhysBall(mass, velocity, acceleration, center, radius,
                            charge, this),
               new RenderableBall(center, radius, color, this), activity_level) {
}


Ball::~Ball() {}


void Ball::SyncRendWithPhys() {
  PhysBall* phys = reinterpret_cast<PhysBall*>(phys_component);
  RenderableBall* rend = reinterpret_cast<RenderableBall*>(rend_component);
  rend->center = phys->center;
}
//==============================================================================


// Cube
//==============================================================================
Cube::Cube(const double mass, const Vector2f& velocity,
           const Vector2f& acceleration, const Vector2f& center,
           const double side_len, const double charge, const ColorRGB& color,
           const ActivityLevel activity_level):
      Creature(new PhysCube(mass, velocity, acceleration, center, side_len,
                            charge, this),
               new RenderableSquare(center, side_len, color, this), activity_level) {
}


Cube::~Cube() {}


void Cube::SyncRendWithPhys() {
  PhysCube* phys = reinterpret_cast<PhysCube*>(phys_component);
  RenderableSquare* rend = reinterpret_cast<RenderableSquare*>(rend_component);
  rend->center = phys->center;
}
//==============================================================================


// Wall
//==============================================================================
Wall::Wall(const Vector2f& edge1, const Vector2f& edge2, const ColorRGB& color,
           const PhysWall::WallType wall_type, const ActivityLevel activity_level):
      Creature(new PhysWall(edge1, edge2, this, wall_type),
               new RenderableWall(edge1, edge2, color, this), activity_level) {
}


Wall::~Wall() {}


void Wall::SyncRendWithPhys() {
  PhysWall* phys = reinterpret_cast<PhysWall*>(phys_component);
  RenderableWall* rend = reinterpret_cast<RenderableWall*>(rend_component);
  rend->edge1 = phys->edge1;
  rend->edge2 = phys->edge2;
}
//==============================================================================