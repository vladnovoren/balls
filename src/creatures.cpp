#include "creatures.hpp"


Creature::Creature(PhysObject* phys_component,
                   Renderable* rend_component):
          phys_component(phys_component),
          rend_component(rend_component) {
}


Creature::~Creature() {
  delete phys_component;
  delete rend_component;
}


Ball::Ball(const Vector2f& center, const double radius,
           const Vector2f& velocity, const double mass,
           const ColorRGB& color):
      Creature(new PhysBall(center, radius, velocity, mass),
               new RenderableBall(center, radius, color)) {
}


ChargedCube::ChargedCube(const Vector2f& position, const double len,
                         const Vector2f& velocity, const double mass,
                         const double charge, const ColorRGB& color):
             Creature(new PhysChargedBall(position, len / 2, velocity, mass,
                                          charge),
                      new RenderableSquare(position, len / 2, color)) {
}


Wall::Wall(const Vector2f& edge1, const Vector2f& edge2, const ColorRGB& color):
      Creature(new PhysWall(edge1, edge2),
               new RenderableWall(edge1, edge2, color)) {
}
