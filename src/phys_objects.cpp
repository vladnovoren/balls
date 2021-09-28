#include "phys_objects.hpp"


PhysObject::PhysObject() {
  type = PhysType::UNDEFINED;
}


PhysObject::~PhysObject() {}


PhysObject::PhysType PhysObject::GetType() const {
  return type;
}


PhysBall::PhysBall(const Vector2f& center, const double radius,
                   const Vector2f& velocity, const double mass) {
  this->center = center;
  this->radius = radius;
  this->velocity = velocity;
  this->mass = mass;
  this->type = PhysType::PHYS_BALL;
}


PhysBall::~PhysBall() {}


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
  velocity = impulse * (1.0 / mass);
}


void PhysBall::AddDeltaImpulse(const Vector2f& add) {
  delta_impulse += add;
}


void PhysBall::UpdateImpulse() {
  this->velocity += delta_impulse * (1.0 / mass);
  delta_impulse = Vector2f(0, 0);
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


double PhysBall::GetMass() const {
  return mass;
}


void PhysBall::Move(const double dt) {
  center += velocity * dt;
}


PhysChargedBall::PhysChargedBall(const Vector2f& center, const double radius,
                                 const Vector2f& velocity, const double mass,
                                 const double charge):
                 PhysBall(center, radius, velocity, mass) {
  this->charge = charge;
  this->type = PhysType::PHYS_CHARGED_BALL;
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


PhysWall::PhysWall(const Vector2f& edge1, const Vector2f& edge2) {
  this->edge1 = edge1;
  this->edge2 = edge2;
  type = PhysType::PHYS_WALL;
}


PhysWall::~PhysWall() {}


void PhysWall::SetEdge1(const Vector2f& edge1) {
  this->edge1 = edge1;
}


void PhysWall::SetEdge2(const Vector2f& edge2) {
  this->edge2 = edge2;
}


Vector2f PhysWall::GetEdge1() {
  return edge1;
}


Vector2f PhysWall::GetEdge2() {
  return edge2;
}

