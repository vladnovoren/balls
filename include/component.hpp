#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class Molecule;

class Component {
protected:
  Molecule* owner;
public:
  Component(Molecule* owner);

  virtual ~Component() = 0;

  Molecule* GetOwner();
};


#endif /* component.hpp */