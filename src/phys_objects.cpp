#include "phys_objects.hpp"


// PhysObject
//------------------------------------------------------------------------------
PhysObject::PhysObject(Creature* owner): Component(owner) {
}


PhysObject::PhysObject(const double mass, const Vector2f& velocity,
                       const Vector2f& acceleration, Creature* owner):
            Component(owner),
            velocity(velocity), acceleration(acceleration), mass(mass),
            type(PhysType::UNDEFINED) {
}


PhysObject::~PhysObject() {
}


void PhysObject::SetMass(const double mass) {
  this->mass = mass;
}


void PhysObject::SetImpulse(const Vector2f& impulse) {
  velocity = impulse * (1.0 / mass);
}


void PhysObject::AddDeltaImpulse(const Vector2f& add) {
  velocity += add * (1.0 / mass);
}


double PhysObject::GetKineticEnergy() const {
  double velocity_module = velocity.Length();
  return mass * velocity_module * velocity_module / 2;
}



double PhysObject::GetMass() const {
  return mass;
}


Vector2f PhysObject::GetImpulse() const {
  return mass * velocity;
}


PhysObject::PhysType PhysObject::GetType() const {
  return type;
}
//------------------------------------------------------------------------------


// PhysBall
//------------------------------------------------------------------------------
PhysBall::PhysBall(const double mass, const Vector2f& velocity,
                   const Vector2f& acceleration, const Vector2f& center,
                   const double radius, const double charge, Creature* owner):
          PhysObject(mass, velocity, acceleration, owner),
          radius(radius), center(center), charge(charge) {
  this->type = PhysType::PHYS_BALL;
}


PhysBall::~PhysBall() {}


void PhysBall::SetRadius(const double radius) {
  this->radius = radius;
}


double PhysBall::GetRadius() const {
  return radius;
}


void PhysBall::Move(const double dt) {
  Vector2f dv = acceleration * dt;
  center += velocity * dt;
  center += dv * dt * 0.5;
  velocity += dv;
}


void PhysBall::AddForce(const Vector2f& force) {
  acceleration += force * (1.0 / mass);
  if (acceleration.x > 10)
    acceleration.x = 10;
  if (acceleration.x < -10)
    acceleration.x = -10;
  if (acceleration.y > 10)
    acceleration.y = 10;
  if (acceleration.y < -10)
    acceleration.y = -10;
}
//------------------------------------------------------------------------------


// PhysCube
//------------------------------------------------------------------------------
PhysCube::PhysCube(const double mass, const Vector2f& velocity,
                   const Vector2f& acceleration, const Vector2f& center,
                   const double side_len, const double charge, Creature* owner):
          PhysBall(mass, velocity, acceleration, center, side_len / 2, charge, owner) {
  type = PhysType::PHYS_CUBE;
}


PhysCube::~PhysCube() {
}
//------------------------------------------------------------------------------


// PhysWall
//------------------------------------------------------------------------------
PhysWall::PhysWall(const Vector2f& edge1, const Vector2f& edge2, Creature* owner,
          const WallType wall_type):
          PhysObject(owner), wall_type(wall_type), edge1(edge1), edge2(edge2) {
  type = PhysType::PHYS_WALL;
}


PhysWall::~PhysWall() {
}


void PhysWall::Move(const double) {};


PhysWall::WallType PhysWall::GetWallType() const {
  return wall_type;
}
//------------------------------------------------------------------------------
