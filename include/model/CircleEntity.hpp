#pragma once

#include "Entity.hpp"

class CircleEntity : public Entity {

    // fields
    float radius;
    
public:

    // constructors
    CircleEntity(Vec position = Vec(), Vec velocity = Vec(), Vec acceleration = Vec(), float mass = 1.0f, float radius = 10.0f);

    // destructor
    ~CircleEntity() override {}

    // functions
    int getRadius();

};