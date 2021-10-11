#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include "graphics.hpp"
#include "component.hpp"
#include "coord_sys.hpp"


class Renderable: public Component {
protected:
  ColorRGB color;
public:
  Renderable(const ColorRGB& color, Creature* owner);

  ~Renderable() override;

  void SetColor(const ColorRGB& color);

  ColorRGB GetColor();

  virtual void Render(Graphics* graphics, const CoordSys& coord_sys) = 0;
};


class RenderableBall: public Renderable {
protected:
  double radius;
public:
  Vector2f center;

  RenderableBall(const Vector2f& center, const double radius,
                 const ColorRGB& color, Creature* owner);

  ~RenderableBall() override;
  
  void SetRadius(const double radius);

  double GetRadius() const;

  void Render(Graphics* graphics, const CoordSys& coord_sys) override;
};


class RenderableSquare: public Renderable {
protected:
  double side_len;
public:
  Vector2f center;

  RenderableSquare(const Vector2f& center, const double side_len,
                   const ColorRGB& color, Creature* owner);

  void SetSideLen(const double side_len);

  double GetSideLen() const;

  ~RenderableSquare() override;

  void Render(Graphics* graphics, const CoordSys& coord_sys) override;
};


class RenderableWall: public Renderable {
public:
  Vector2f edge1;
  Vector2f edge2;

  RenderableWall(const Vector2f& edge1, const Vector2f& edge2,
                 const ColorRGB& color, Creature* owner);

  ~RenderableWall() override;

  void Render(Graphics* graphics, const CoordSys& coord_sys) override;
};


#endif /* renderable.hpp */

