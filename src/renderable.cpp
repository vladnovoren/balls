#include "renderable.hpp"


Renderable::Renderable() {};


Renderable::Renderable(const ColorRGB& color) {
  this->color = color;
}


void Renderable::SetColor(const ColorRGB& color) {
  this->color = color;
}


RenderableBall::RenderableBall(const Vector2f& center, const double radius,
                               const ColorRGB& color):
                Renderable(color) {
  this->center = center;
  this->radius = radius;
}


void RenderableBall::Render(Graphics* graphics) {
  assert(graphics);

  graphics->RenderCircle(graphics->RealToPixelVector(center),
                         graphics->RealToPixelLen(radius));
}


RenderableSquare::RenderableSquare(const Vector2f& center, const double side_len,
                                   const ColoRGB& color):
                  Renderable(color) {
  this->center = center;
  this->side_len = side_len;
}


void RenderableSquare::Render(Graphics* graphics) {
  assert(graphics);

  graphics->RenderSquare(graphics->RealToPixelVector(center - Vector2f(
                                   side_len / 2, side_len / 2)),
                         graphics->RealToPixelLen(side_len));
}


RenderableWall::RenderableWall(const Vector2f& edge1, const Vector2f& edge2,
                               const ColorRGB& color):
                Renderable(color) {
  this->edge1 = edge1;
  this->edge2 = edge2;
}


void RenderableWall::Render(Graphics* graphics) {
  assert(graphics);

  graphics->RenderLine(graphics->RealToPixelVector(edge1),
                       graphics->RealToPixelVector(edge2));
}
