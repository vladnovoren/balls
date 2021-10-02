#ifndef CREATURES_HPP
#define CREATURES_HPP

#include "phys_objects.hpp"
#include "renderable.hpp"


class Creature {
protected:
  PhysObject* phys_component;
  Renderable* rend_component;
public:
  Creature(PhysObject* phys_component, Renderable* rend_component);

  ~Creature();

  PhysObject* GetPhysComponent() const;
  Renderable* GetRendComponent() const;

  friend class CreaturesContainer;
};


class Ball: public Creature {
public:
  Ball(const double mass, const Vector2f& velocity,
       const Vector2f& acceleration, const Vector2f& center,
       const double radius, const double charge, const ColorRGB& color);

  friend class CreaturesManager;
};


class Cube: public Creature {
public:
  Cube(const double mass, const Vector2f& velocity,
       const Vector2f& acceleration, const Vector2f& center,
       const double size_len, const double charge, const ColorRGB& color);

  friend class CreaturesManager;
};


class Wall: public Creature {
public:
  Wall(const Vector2f& edge1, const Vector2f& edge2, const ColorRGB& color);

  friend class CreaturesManager;
};


#endif /* creatures.hpp */

