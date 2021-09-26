#include "creatures.hpp"

Ball::Ball(const Vector2f& center, const double radius, const Vector2f& velocity, const double mass, const ColorRGB& color) :
PhysBall(center, radius, velocity, mass), Renderable(color) {
}

void Ball::Render(Graphics* graphics) {
  assert(graphics);

  graphics->SetColor(color);
  graphics->RenderCircle(center, radius);
}

ChargedCube::ChargedCube(const Vector2f& position, const double len, const Vector2f& velocity, const double mass, const double charge, const ColorRGB& color) :
PhysChargedBall(position + Vector2f(len / 2, len / 2), len / 2, velocity, mass, charge), Renderable(color) {
}

void ChargedCube::Render(Graphics* graphics) {
  assert(graphics);

  graphics->SetColor(color);
  graphics->RenderRectangle(center + Vector2f(-radius, -radius), Vector2f(2 * radius, 2 * radius));
}
