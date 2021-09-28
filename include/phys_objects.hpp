#ifndef PHYS_OBJECTS_HPP
#define PHYS_OBJECTS_HPP

#include "vector2.hpp"


class PhysObject {
public:
  enum class PhysType {
    UNDEFINED = -1,
    PHYS_WALL,
    PHYS_BALL
  };

  PhysObject();

  PhysObject(const double mass, const Vector2f& velocity,
             const Vector2f& acceleration);

  void SetMass(const double mass);
  void SetVelocity(const Vector2f& velocity);
  void SetAcceleration(const Vector2f& acceleration);
  void SetImpulse(const Vector2f& impulse);
  void AddDeltaImpulse(const Vector2f& delta_impulse);
  void UpdateImpulse();

  double GetMass() const;
  Vector2f GetVelocity() const;
  Vector2f GetAcceleration() const;
  Vector2f GetImpulse() const;
  PhysType GetType() const;

  virtual void Move(const double dt) = 0;

  friend class PhysEngine;
protected:
  double mass;
  Vector2f velocity;
  Vector2f acceleration;
  Vector2f delta_impulse;
  PhysType type;
};


class PhysBall: public PhysObject {
protected:
  Vector2f center;
  double radius;
  double charge;
public:
  PhysBall(const double mass, const Vector2f& velocity,
           const Vector2f& acceleration, const Vector2f& center,
           const double radius, const double charge);

  void SetCenter(const Vector2f& center);
  void SetRadius(const double radius);
  void SetCharge(const double charge);

  Vector2f GetCenter() const;
  double GetRadius() const;
  double GetCharge() const;

  void Move(const double dt) override;

  friend class PhysEngine;
};



class PhysWall: public PhysObject {
protected:
  Vector2f edge1;
  Vector2f edge2;
public:
  PhysWall(const Vector2f& edge1, const Vector2f& edge2);

  void SetEdge1(const Vector2f& edge1);
  void SetEdge2(const Vector2f& edge2);

  Vector2f GetEdge1() const;
  Vector2f GetEdge2() const;

  void Move(const double) override;

  friend class PhysEngine;
};


#endif /*phys_objects.hpp*/

