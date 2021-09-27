#include "creatures.hpp"


Creature::~Creature() {
  delete phys_component;
  delete rend_component;
}


Ball::Ball(const Vector2f& center, const double radius,
           const Vector2f& velocity, const double mass,
           const ColorRGB& color):
      phys_component(new PhysObject(center, radius, velocity, mass)),
      rend_component(new Renderable(center, radius, color))
{
  phys_component = new PhysBall(center, radius, velocity, mass);
  rend_component = new RenderableBall(center, radius, color);
}


ChargedCube::ChargedCube(const Vector2f& position, const double len,
                         const Vector2f& velocity, const double mass,
                         const double charge, const ColorRGB& color) {
  phys_component = new PhysChargedBall(position, len / 2, velocity, mass, charge);
  rend_component = new RenderableSquare(position, len / 2, color);
}


Wall::Wall(const Vector2f& edge1, const Vector2f& edge2, const ColorRGB& color) {
  phys_component = new PhysWall(edge1, edge2);
  rend_component = new RenderableWall(edge1, edge2, color);
}
