#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include "graphics.hpp"


class Renderable {
protected:
  friend class Graphics;
  ColorRGB color;
public:
  Renderable();

  Renderable(const ColorRGB& color);

  void SetColor(const ColorRGB& color);

  virtual void Render(Graphics* graphics) = 0;
};


class RenderableBall: public Renderable {
protected:
  Vector2f center;
  double radius;
public:
  void Render(Graphics* graphics) override;
};


class RenderableSquare: public Renderable {
protected:
  Vector2f center;
  double side_len;
public:
  void Render(Graphics* graphics) override;
};


class RenderablePlane: public Renderable {
protected:
  Vector2f edge1;
  Vector2f edge2;
public:
  void Render(Graphics* graphics) override;
};



#endif /* renderable.hpp */

