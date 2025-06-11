#pragma once

#include "Vec.hpp"
#include <memory>
#include <random>
#include "SFML/Graphics.hpp"
#include "Config.hpp"

class Entity : public std::enable_shared_from_this<Entity> {

    // fields
    Vec position, velocity, acceleration;
    float mass;
    std::shared_ptr<sf::Shape> drawable;
    std::shared_ptr<sf::Color> baseColor;
    
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
