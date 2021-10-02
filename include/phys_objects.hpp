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

  PhysObject(Molecule* owner);

  PhysObject(const double mass, const Vector2f& velocity,
             const Vector2f& acceleration, Molecule* owner);

  ~PhysObject();

  void SetMass(const double mass);
  void SetImpulse(const Vector2f& impulse);
  void AddDeltaImpulse(const Vector2f& delta_impulse);
  void UpdateImpulse();

  double GetMass() const;
  Vector2f GetImpulse() const;
  PhysType GetType() const;

  virtual void Move(const double dt) = 0;

  friend class PhysEngine;
protected:
  double mass;
  Vector2f delta_impulse;
  PhysType type;
  Molecule* owner;
};


class PhysBall: public PhysObject {
protected:
  double radius;
public:
  Vector2f center;
  double charge;

  PhysBall(const double mass, const Vector2f& velocity,
           const Vector2f& acceleration, const Vector2f& center,
           const double radius, const double charge, Molecule* owner);

  ~PhysBall() override;

  void SetRadius(const double radius);

  double GetRadius() const;

  void Move(const double dt) override;

  friend class PhysEngine;
};


class PhysCube: public PhysBall {
public:
  PhysCube(const double mass, const Vector2f& velocity,
           const Vector2f& acceleration, const Vector2f& center,
           const double radius, const double charge, Molecule* owner);

  ~PhysCube() override;
};


class PhysWall: public PhysObject {
public:
  Vector2f edge1;
  Vector2f edge2;

  PhysWall(const Vector2f& edge1, const Vector2f& edge2, Molecule* owner);

  ~PhysWall() override;

  void Move(const double) override;

  friend class PhysEngine;
};


#endif /*phys_objects.hpp*/

