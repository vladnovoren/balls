#include "phys_objects.hpp"


// PhysObject
//------------------------------------------------------------------------------
PhysObject::PhysObject(): mass(0.0) {
}


PhysObject::PhysObject(const double mass, const Vector2f& velocity,
                       const Vector2f& acceleration):
            mass(mass), velocity(velocity), acceleration(acceleration),
            type(PhysType::UNDEFINED) {
}


void PhysObject::SetMass(const double mass) {
  this->mass = mass;
}


void PhysObject::SetVelocity(const Vector2f& velocity) {
  this->velocity = velocity;
}


void PhysObject::SetAcceleration(const Vector2f& acceleration) {
  this->acceleration = acceleration;
}


void PhysObject::SetImpulse(const Vector2f& impulse) {
  velocity = impulse * (1.0 / mass);
}


void PhysObject::AddDeltaImpulse(const Vector2f& add) {
  delta_impulse += add;
}


void PhysObject::UpdateImpulse() {
  velocity += delta_impulse * (1.0 / mass);
  delta_impulse = Vector2f(0, 0);
}


double PhysObject::GetMass() const {
  return mass;
}


Vector2f PhysObject::GetVelocity() const {
  return velocity;
}


Vector2f PhysObject::GetAcceleration() const {
  return acceleration;
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
                   const double radius, const double charge):
          PhysObject(mass, velocity, acceleration),
          center(center), radius(radius), charge(charge) {
  this->type = PhysType::PHYS_BALL;
}


void PhysBall::SetCenter(const Vector2f& center) {
  this->center = center;
}


void PhysBall::SetRadius(const double radius) {
  this->radius = radius;
}


void PhysBall::SetCharge(const double charge) {
  this->charge = charge;
}


Vector2f PhysBall::GetCenter() const {
  return center;
}


double PhysBall::GetRadius() const {
  return radius;
}


double PhysBall::GetCharge() const {
  return charge;
}


void PhysBall::Move(const double dt) {
  Vector2f dv = acceleration * dt;
  center += velocity * dt;
  center += dv * dt * 0.5;
  velocity += dv;
}
//------------------------------------------------------------------------------


// PhysWall
//------------------------------------------------------------------------------
PhysWall::PhysWall(const Vector2f& edge1, const Vector2f& edge2):
          edge1(edge1), edge2(edge2) {
}


void PhysWall::SetEdge1(const Vector2f& edge1) {
  this->edge1 = edge1;
}


void PhysWall::SetEdge2(const Vector2f& edge2) {
  this->edge2 = edge2;
}


Vector2f PhysWall::GetEdge1() const {
  return edge1;
}


Vector2f PhysWall::GetEdge2() const {
  return edge2;
}


void PhysWall::Move(const double) {};
//------------------------------------------------------------------------------
