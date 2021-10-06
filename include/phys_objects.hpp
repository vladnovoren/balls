#ifndef PHYS_OBJECTS_HPP
#define PHYS_OBJECTS_HPP

#include "vector2.hpp"
#include "component.hpp"


const size_t N_PHYS_OBJECTS = 3;

class PhysObject: public Component {
public:
  Vector2f velocity;
  Vector2f acceleration;

  enum class PhysType {
    UNDEFINED = -1,
    PHYS_BALL,
    PHYS_CUBE,
    PHYS_WALL
  };

  PhysObject(Creature* owner);

  PhysObject(const double mass, const Vector2f& velocity,
             const Vector2f& acceleration, Creature* owner);

  ~PhysObject();

  void SetMass(const double mass);
  void SetImpulse(const Vector2f& impulse);
  void AddDeltaImpulse(const Vector2f& delta_impulse);
  void UpdateImpulse();

  double GetMass() const;
  Vector2f GetImpulse() const;
  PhysType GetType() const;
  double GetKineticEnergy() const;

  virtual void Move(const double dt) = 0;

  friend class PhysEngine;
protected:
  double mass;
  PhysType type;
  Creature* owner;
};


class PhysBall: public PhysObject {
protected:
  double radius;
public:
  Vector2f center;
  double charge;

  PhysBall(const double mass, const Vector2f& velocity,
           const Vector2f& acceleration, const Vector2f& center,
           const double radius, const double charge, Creature* owner);

  ~PhysBall() override;

  void SetRadius(const double radius);

  double GetRadius() const;

  void Move(const double dt) override;

  void AddForce(const Vector2f& force);

  friend class PhysEngine;
};


class PhysCube: public PhysBall {
public:
  PhysCube(const double mass, const Vector2f& velocity,
           const Vector2f& acceleration, const Vector2f& center,
           const double side_len, const double charge, Creature* owner);

  ~PhysCube() override;
};


class PhysWall: public PhysObject {
public:
  enum class WallType;
protected:
  WallType wall_type;
public:
  enum class WallType {
    LEFT,
    RIGHT,
    UPPER,
    LOWER
  };

  Vector2f edge1;
  Vector2f edge2;

  PhysWall(const Vector2f& edge1, const Vector2f& edge2, Creature* owner,
           const WallType wall_type);

  ~PhysWall() override;

  WallType GetWallType() const;

  void Move(const double) override;

  friend class PhysEngine;
};


#endif /*phys_objects.hpp*/

