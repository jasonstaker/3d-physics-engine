#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <Vec.hpp>

class Entity {
public:

    // constructors
    Entity(Vec position = Vec(), Vec velocity = Vec(), Vec acceleration = Vec(), float mass = 1.0f);

    // destructor
    virtual ~Entity() {};

    // functions

private:

    // fields
    Vec position, velocity, acceleration;
    float mass;

};

#endif