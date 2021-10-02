#include "molecules.hpp"


Molecule::Molecule(PhysObject* phys_component,
                   Renderable* rend_component):
          phys_component(phys_component),
          rend_component(rend_component) {
}


Molecule::~Molecule() {
  delete phys_component;
  delete rend_component;
}


PhysObject* Molecule::GetPhysComponent() const {
  return phys_component;
}


Renderable* Molecule::GetRendComponent() const {
  return rend_component;
}


Ball::Ball(const double mass, const Vector2f& velocity,
           const Vector2f& acceleration, const Vector2f& center,
           const double radius, const double charge, const ColorRGB& color):
      Molecule(new PhysBall(mass, velocity, acceleration, center, radius,
                            charge, this),
               new RenderableBall(center, radius, color, this)) {
}


Cube::Cube(const double mass, const Vector2f& velocity,
           const Vector2f& acceleration, const Vector2f& center,
           const double side_len, const double charge, const ColorRGB& color):
      Molecule(new PhysCube(mass, velocity, acceleration, center, side_len / 2,
                            charge, this),
               new RenderableSquare(center, side_len / 2, color, this)) {
}


Wall::Wall(const Vector2f& edge1, const Vector2f& edge2, const ColorRGB& color):
      Molecule(new PhysWall(edge1, edge2, this),
               new RenderableWall(edge1, edge2, color, this)) {
}
