#include "component.hpp"


Component::Component(Creature* owner): owner(owner) {}


Component::~Component() {}


Creature* Component::GetOwner() {
  return owner;
}
