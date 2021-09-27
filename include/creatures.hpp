#ifndef CREATURES_HPP
#define CREATURES_HPP

#include "phys_objects.hpp"
#include "renderable.hpp"


class Creature {
protected:
  PhysObject* phys_component;
  Renderable* rend_component;
public:
  ~Creature();

  friend class CreaturesManager;
};


class Ball: public Creature {
  //PhysBall phys_component;
  //RenderableBall rend_component;
public:
  Ball(const Vector2f& center, const double radius, const Vector2f& velocity,
       const double mass, const ColorRGB& color);

  friend class CreaturesManager;

  //~Ball() {};
};


class ChargedCube: public Creature {
/*  PhysChargedBall phys_component;*/
  /*RenderableBall rend_component;*/
public:
  ChargedCube(const Vector2f& position, const double len,
              const Vector2f& velocity, const double mass,
              const double charge, const ColorRGB& color);

  friend class CreaturesManager;

  //~ChargedCube() {};
};


class Wall: public Creature {
  /*PhysWall phys_component;*/
  /*RenderableWall rend_component;*/
public:
  Wall(const Vector2f& edge1, const Vector2f& edge2, const ColorRGB& color);

  friend class CreaturesManager;

  //~Wall() override {};
};


#endif /* creatures.hpp */

