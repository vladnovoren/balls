#include "phys_objects.hpp"


PhysObject::PhysObject(const PhysType type) {
  this->type = type;
}


PhysObject::PhysType PhysObject::GetType() const {
  return type;
}


PhysBall::PhysBall(const Vector2f& center, const double radius,
                   const Vector2f& velocity, const double mass):
                   PhysObject(PhysType::PHYS_BALL) {
  this->center = center;
  this->radius = radius;
  this->velocity = velocity;
  this->mass = mass;
}


void PhysBall::SetCenter(const Vector2f& center) {
  this->center = center;
}


void PhysBall::SetRadius(const double radius) {
  this->radius = radius;
}


void PhysBall::SetVelocity(const Vector2f& velocity) {
  this->velocity = velocity;
}


void PhysBall::SetMass(const double mass) {
  this->mass = mass;
}


void PhysBall::SetImpulse(const Vector2f& impulse) {
  velocity = impulse / mass;
}


Vector2f PhysBall::GetCenter() const {
  return center;
}


double PhysBall::GetRadius() const {
  return radius;
}


Vector2f PhysBall::GetVelocity() const {
  return velocity;
}


Vector2f PhysBall::GetImpulse() const {
  return mass * velocity;
}


Vector2f PhysBall::GetImpulseProj(const Vector2f& dir, Vector2f* parallel,
                                                       Vector2f* normal) const {
  assert(parallel);
  assert(normal);

  Vector2f impulse = GetImpulse();

  Vector2f normal_dir = dir;
  normal_dir.Normalize();

  *parallel = normal_dir * (impulse * dir);
  *normal = impulse - *parallel;

  return impulse;
}



double PhysBall::GetMass() const {
  return mass;
}


void PhysBall::Move(const double dt) {
  center += velocity * dt;
}


PhysChargedBall::PhysChargedBall(const Vector2f& center, const double radius,
                                 const Vector2f& velocity, const double mass,
                                 const double charge):
                                 PhysObject(PhysType::PHYS_CHARGED_BALL),
                                 PhysBall(center, radius, velocity, mass) {
  this->charge = charge;
}


void PhysChargedBall::Move(const double dt) {
  PhysBall::Move(dt);
  Vector2f dv = acceleration * dt;
  center += dv * dt * 0.5;
  velocity += dv;
}


void PhysChargedBall::SetAcceleration(const Vector2f& acceleration) {
  this->acceleration = acceleration;
}


void PhysChargedBall::SetCharge(const double charge) {
  this->charge = charge;
}


Vector2f PhysChargedBall::GetAcceleration() const {
  return acceleration;
}


double PhysChargedBall::GetCharge() const {
  return charge;
}


PhysPlane::PhysPlane(const Vector2f& edge1, const Vector2f& edge2):
           PhysObject(PhysType::PHYS_PLANE) {
  this->edge1 = edge1;
  this->edge2 = edge2;
}

