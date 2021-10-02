#ifndef MOLECULES_HPP
#define MOLECULES_HPP

#include "phys_objects.hpp"
#include "renderable.hpp"
#include "coord_sys.hpp"
#include "phys_engine.hpp"


class Molecule {
protected:
  PhysObject* phys_component;
  Renderable* rend_component;
public:
  Molecule(PhysObject* phys_component, Renderable* rend_component);

  ~Molecule();

  PhysObject* GetPhysComponent() const;
  Renderable* GetRendComponent() const;

  friend class MoleculesManager;
};


class Ball: public Molecule {
public:
  Ball(const double mass, const Vector2f& velocity,
       const Vector2f& acceleration, const Vector2f& center,
       const double radius, const double charge, const ColorRGB& color);

  friend class MoleculesManager;
};


class Cube: public Molecule {
public:
  Cube(const double mass, const Vector2f& velocity,
       const Vector2f& acceleration, const Vector2f& center,
       const double size_len, const double charge, const ColorRGB& color);

  friend class MoleculesManager;
};


class Wall: public Molecule {
public:
  Wall(const Vector2f& edge1, const Vector2f& edge2, const ColorRGB& color);

  friend class MoleculesManager;
};


#endif /* creatures.hpp */

