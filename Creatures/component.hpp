#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class Creature;

class Component {
protected:
  Creature* owner;
public:
  Component(Creature* owner);

  virtual ~Component() = 0;

  Creature* GetOwner();
};


#endif /* component.hpp */