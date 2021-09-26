#include "renderable.hpp"


Renderable::Renderable() {};


Renderable::Renderable(const ColorRGB& color) {
  this->color = color;
}


void Renderable::SetColor(const ColorRGB& color) {
  this->color = color;
}


void RenderableBall::Render(Graphics* graphics) {
  assert(graphics);

  graphics->RenderCircle(graphics->RealToPixelVector(center),
                         graphics->RealToPixelLen(radius));
}


void RenderableSquare::Render(Graphics* graphics) {
  assert(graphics);

  graphics->RenderSquare(graphics->RealToPixelVector(center - Vector2f(
                                   side_len / 2, side_len / 2)),
                         graphics->RealToPixelLen(side_len));
}


void RenderablePlane::Render(Graphics* graphics) {
  assert(graphics);

  graphics->RenderLine(graphics->RealToPixelVector(edge1),
                       graphics->RealToPixelVector(edge2));
}
