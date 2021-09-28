#ifndef CREATURES_HPP
#define CREATURES_HPP

#include "phys_objects.hpp"
#include "renderable.hpp"


class Creature {
protected:
  PhysObject* phys_component;
  Renderable* rend_component;

  Creature(PhysObject* phys_component, Renderable* rend_component);

  friend class CreaturesManager;

  ~Creature();
};


class Ball: public Creature {
public:
  Ball(const Vector2f& center, const double radius, const Vector2f& velocity,
       const double mass, const ColorRGB& color);

  friend class CreaturesManager;
};


class ChargedCube: public Creature {
public:
  ChargedCube(const Vector2f& position, const double len,
              const Vector2f& velocity, const double mass,
              const double charge, const ColorRGB& color);

  friend class CreaturesManager;
};


class Wall: public Creature {
public:
  Wall(const Vector2f& edge1, const Vector2f& edge2, const ColorRGB& color);

  friend class CreaturesManager;
};


#endif /* creatures.hpp */

