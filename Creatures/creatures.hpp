#ifndef CREATURES_HPP
#define CREATURES_HPP

#include "phys_objects.hpp"
#include "renderable.hpp"


const double DEFAULT_SIDE_LEN = 10;
const double DEFAULT_CUBE_MASS = 1;


class Creature {
protected:
  PhysObject* phys_component;
  Renderable* rend_component;
public:
  enum class ActivityLevel {
    NOT_ACTIVE,
    TO_DELETE,
    TO_CREATE,
    ACTIVE
  };

  ActivityLevel activity_level;

  Creature(PhysObject* phys_component, Renderable* rend_component,
           const ActivityLevel activity_level = ActivityLevel::ACTIVE);

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
       const double radius, const double charge, const ColorRGB& color, const ActivityLevel activity_level = ActivityLevel::ACTIVE);

  ~Ball() override;

  void SyncRendWithPhys() override;

  friend class CreaturesManager;
};


class Cube: public Creature {
public:
  Cube(const double mass, const Vector2f& velocity,
       const Vector2f& acceleration, const Vector2f& center,
       const double size_len, const double charge, const ColorRGB& color, const ActivityLevel activity_level = ActivityLevel::ACTIVE);
  
  ~Cube() override;

  void SyncRendWithPhys() override;

  friend class CreaturesManager;
};


class Wall: public Creature {
public:
  Wall(const Vector2f& edge1, const Vector2f& edge2, const ColorRGB& color,
       PhysWall::WallType wall_type, const ActivityLevel activity_level = ActivityLevel::ACTIVE);

  ~Wall() override;

  void SyncRendWithPhys() override;

  friend class CreaturesManager;
};


#endif /* creatures.hpp */
