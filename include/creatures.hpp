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

  virtual ~Creature() = 0;

  PhysObject* GetPhysComponent() const;
  Renderable* GetRendComponent() const;

  virtual void SyncRendWithPhys() = 0;

  friend class CreaturesContainer;
};


class Ball: public Creature {
public:
  Ball(const double mass, const Vector2f& velocity,
       const Vector2f& acceleration, const Vector2f& center,
       const double radius, const double charge, const ColorRGB& color);

  ~Ball() override;

  void SyncRendWithPhys() override;

  friend class CreaturesManager;
};


class Cube: public Creature {
public:
  Cube(const double mass, const Vector2f& velocity,
       const Vector2f& acceleration, const Vector2f& center,
       const double size_len, const double charge, const ColorRGB& color);
  
  ~Cube() override;

  void SyncRendWithPhys() override;

  friend class CreaturesManager;
};


class Wall: public Creature {
public:
  Wall(const Vector2f& edge1, const Vector2f& edge2, const ColorRGB& color,
       PhysWall::WallType wall_type);

  ~Wall() override;

  void SyncRendWithPhys() override;

  friend class CreaturesManager;
};


#endif /* creatures.hpp */
