#ifndef CREATURES_HPP
#define CREATURES_HPP

#include "phys_objects.hpp"
#include "renderable.hpp"

class Ball : public PhysBall, public Renderable {
public:
  Ball(const Vector2f& center, const double radius, const Vector2f& velocity, const double mass, const ColorRGB& color);

  void Render(Graphics* graphics) override;
};

class ChargedCube : public PhysChargedBall, public Renderable {
public:
  ChargedCube(const Vector2f& position, const double len, const Vector2f& velocity, const double mass, const double charge, const ColorRGB& color);

  void Render(Graphics* graphics) override;
};

#endif /* creatures.hpp */
