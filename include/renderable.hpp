#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include "graphics.hpp"


class Renderable {
protected:
  ColorRGB color;
public:
  Renderable();

  virtual ~Renderable();

  Renderable(const ColorRGB& color);

  void SetColor(const ColorRGB& color);

  ColorRGB GetColor();

  virtual void Render(Graphics* graphics) = 0;
};


class RenderableBall: public Renderable {
protected:
  Vector2f center;
  double radius;
public:
  RenderableBall(const Vector2f& center, const double radius,
                 const ColorRGB& color);

  void Render(Graphics* graphics) override;
};


class RenderableSquare: public Renderable {
protected:
  Vector2f center;
  double side_len;
public:
  RenderableSquare(const Vector2f& center, const double side_len,
                   const ColorRGB& color);

  void Render(Graphics* graphics) override;
};


class RenderableWall: public Renderable {
protected:
  Vector2f edge1;
  Vector2f edge2;
public:
  RenderableWall(const Vector2f& edge1, const Vector2f& edge2,
                 const ColorRGB& color);

  void Render(Graphics* graphics) override;
};


#endif /* renderable.hpp */

