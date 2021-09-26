#ifndef PHYS_OBJECTS_HPP
#define PHYS_OBJECTS_HPP

#include "vector2.hpp"


class PhysObject {
public:
  enum class PhysType {
    UNDEFINED = -1,
    PHYS_PLANE,
    PHYS_BALL,
    PHYS_CHARGED_BALL
  };

  PhysObject(const PhysType type);

  PhysType GetType() const;

  virtual void Move(const double dt) = 0;

  friend class PhysEngine;
protected:
  PhysType type;

  virtual ~PhysObject() {};
};


class PhysBall: public virtual PhysObject {
protected:
  Vector2f center;
  double radius;
  Vector2f velocity;
  double mass;
public:
  PhysBall(const Vector2f& center, const double radius,
           const Vector2f& velocity, const double mass);

  void SetCenter(const Vector2f& center);
  void SetRadius(const double radius);
  void SetVelocity(const Vector2f& velocity);
  void SetMass(const double mass);
  void SetImpulse(const Vector2f& impulse);

  Vector2f GetCenter() const;
  double GetRadius() const;
  Vector2f GetVelocity() const;
  double GetMass() const;
  Vector2f GetImpulse() const;
  Vector2f GetImpulseProj(const Vector2f& dir, Vector2f* parallel,
                                               Vector2f* normal) const;

  void Move(const double dt) override;
};


class PhysChargedBall: public PhysBall {
protected:
  Vector2f acceleration;
  double charge;
public:
  PhysChargedBall(const Vector2f& center, const double radius,
                  const Vector2f& velocity, const double mass,
                  const double charge);

  void SetAcceleration(const Vector2f& acceleration);
  void SetCharge(const double charge);

  Vector2f GetAcceleration() const;
  double GetCharge() const;

  void Move(const double dt) override;
};


class PhysPlane: public virtual PhysObject {
protected:
  Vector2f edge1;
  Vector2f edge2;
public:
  PhysPlane(const Vector2f& edge1, const Vector2f& edge2);
};


#endif /*phys_objects.hpp*/

