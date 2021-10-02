#include "component.hpp"


Component::Component(Molecule* owner): owner(owner) {}


Component::~Component() {}


Molecule* Component::GetOwner() {
  return owner;
}
