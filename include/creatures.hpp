#ifndef CREATURES_HPP
#define CREATURES_HPP

#include "phys_objects.hpp"
#include "renderable.hpp"


class Ball {
  PhysBall phys_component;
  RenderableBall rend_component;
public:
  Ball(const Vector2f& center, const double radius, const Vector2f& velocity,
       const double mass, const ColorRGB& color):
  phys_component(center, radius, velocity, mass),
  rend_component(center, radius, color);
};


class ChargedCube {
public:
  ChargedCube(const Vector2f& position, const double len, const Vector2f& velocity, const double mass, const double charge, const ColorRGB& color);

  void Render(Graphics* graphics) override;
};


#endif /* creatures.hpp */
