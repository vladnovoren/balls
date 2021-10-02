#include "renderable.hpp"


// Renderable
//==============================================================================
Renderable::Renderable(const ColorRGB& color, Creature* owner):
            Component(owner), color(color) {}


Renderable::~Renderable() {}


void Renderable::SetColor(const ColorRGB& color) {
  this->color = color;
}


ColorRGB Renderable::GetColor() {
  return color;
}
//==============================================================================


// RenderableBall
//==============================================================================
RenderableBall::RenderableBall(const Vector2f& center, const double radius,
                               const ColorRGB& color, Creature* owner):
                Renderable(color, owner) {
  this->center = center;
  this->radius = radius;
}


RenderableBall::~RenderableBall() {}


void RenderableBall::Render(Graphics* graphics, const CoordSys& coord_sys) {
  assert(graphics);

  graphics->RenderCircle(coord_sys.RealToPixelVector(center),
                         coord_sys.RealToPixelLen(radius));
}
//==============================================================================


// RenderableSquare
//==============================================================================
RenderableSquare::RenderableSquare(const Vector2f& center, const double side_len,
                                   const ColorRGB& color, Creature* owner):
                  Renderable(color, owner) {
  this->center = center;
  this->side_len = side_len;
}


RenderableSquare::~RenderableSquare() {}


void RenderableSquare::Render(Graphics* graphics, const CoordSys& coord_sys) {
  assert(graphics);

  graphics->RenderSquare(coord_sys.RealToPixelVector(center - Vector2f(
                                   side_len / 2, side_len / 2)),
                         coord_sys.RealToPixelLen(side_len));
}
//==============================================================================


// RenderableWall
//==============================================================================
RenderableWall::RenderableWall(const Vector2f& edge1, const Vector2f& edge2,
                               const ColorRGB& color, Creature* owner):
                Renderable(color, owner) {
  this->edge1 = edge1;
  this->edge2 = edge2;
}


RenderableWall::~RenderableWall() {}


void RenderableWall::Render(Graphics* graphics, const CoordSys& coord_sys) {
  assert(graphics);

  graphics->RenderLine(coord_sys.RealToPixelVector(edge1),
                       coord_sys.RealToPixelVector(edge2));
}
//==============================================================================
