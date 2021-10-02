#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include "graphics.hpp"
#include "component.hpp"
#include "coord_sys.hpp"


class Renderable: public Component {
protected:
  ColorRGB color;
public:
  Renderable(const ColorRGB& color, Molecule* owner);

  ~Renderable() override;

  void SetColor(const ColorRGB& color);

  ColorRGB GetColor();

  virtual void Render(Graphics* graphics, const CoordSys& coord_sys) = 0;
};


class RenderableBall: public Renderable {
protected:
  Vector2f center;
  double radius;
public:
  RenderableBall(const Vector2f& center, const double radius,
                 const ColorRGB& color, Molecule* owner);
  
  ~RenderableBall() override;

  void Render(Graphics* graphics, const CoordSys& coord_sys) override;
};


class RenderableSquare: public Renderable {
protected:
  Vector2f center;
  double side_len;
public:
  RenderableSquare(const Vector2f& center, const double side_len,
                   const ColorRGB& color, Molecule* owner);

  ~RenderableSquare() override;

  void Render(Graphics* graphics, const CoordSys& coord_sys) override;
};


class RenderableWall: public Renderable {
protected:
  Vector2f edge1;
  Vector2f edge2;
public:
  RenderableWall(const Vector2f& edge1, const Vector2f& edge2,
                 const ColorRGB& color, Molecule* owner);

  ~RenderableWall() override;

  void Render(Graphics* graphics, const CoordSys& coord_sys) override;
};


#endif /* renderable.hpp */

