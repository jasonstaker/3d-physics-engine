#pragma once

#include "Vec.hpp"
#include <memory>
#include "SFML/Graphics.hpp"

class Entity : public std::enable_shared_from_this<Entity> {

    // fields
    Vec position, velocity, acceleration;
    float mass;
    std::shared_ptr<sf::Shape> drawable;
    
public:

    // constructors
    Entity(Vec position = Vec(), Vec velocity = Vec(), Vec acceleration = Vec(), float mass = 1.0f);

    // destructors
    virtual ~Entity() {};

    // functions
    Vec& getPosition();
    Vec& getVelocity();
    Vec& getAcceleration();
    float getMass();
    std::shared_ptr<sf::Shape> render();
    void initializeDrawable();

};
