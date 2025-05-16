#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include "Entity.hpp"
#include "Ball.hpp"
#include <memory>

using namespace std;

class ShapeFactory {
public:

    // constructors
    ShapeFactory();

    // functions
    unique_ptr<sf::Shape> createShape(const shared_ptr<Entity>& entity) const;

};