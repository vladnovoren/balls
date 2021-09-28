#ifndef PHYS_OBJECTS_HPP
#define PHYS_OBJECTS_HPP

#include "vector2.hpp"


class PhysObject {
public:
  enum class PhysType {
    UNDEFINED = -1,
    PHYS_WALL,
    PHYS_BALL,
    PHYS_CHARGED_BALL
  };

  PhysObject(const PhysType type);

  virtual ~PhysObject();

  PhysType GetType() const;

  virtual void Move(const double dt) = 0;

  friend class PhysEngine;
protected:
  PhysType type;
};


class PhysBall: public PhysObject {
protected:
  Vector2f center;
  double radius;
  Vector2f velocity;
  double mass;
  Vector2f delta_impulse;
public:
  PhysBall(const Vector2f& center, const double radius,
           const Vector2f& velocity, const double mass);

  ~PhysBall() override;

  void SetCenter(const Vector2f& center);
  void SetRadius(const double radius);
  void SetVelocity(const Vector2f& velocity);
  void SetMass(const double mass);
  void SetImpulse(const Vector2f& impulse);
  void AddDeltaImpulse(const Vector2f& delta_impulse);
  void UpdateImpulse();

  Vector2f GetCenter() const;
  double GetRadius() const;
  Vector2f GetVelocity() const;
  double GetMass() const;
  Vector2f GetImpulse() const;

  void Move(const double dt) override;

  friend class PhysEngine;
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

  friend class PhysEngine;
};


class PhysWall: public virtual PhysObject {
protected:
  Vector2f edge1;
  Vector2f edge2;
public:
  PhysWall(const Vector2f& edge1, const Vector2f& edge2);

  ~PhysWall() override;

  void SetEdge1(const Vector2f& edge1);
  void SetEdge2(const Vector2f& edge2);

  void Move(const double) override {};

  Vector2f GetEdge1();
  Vector2f GetEdge2();

  friend class PhysEngine;
};


#endif /*phys_objects.hpp*/

