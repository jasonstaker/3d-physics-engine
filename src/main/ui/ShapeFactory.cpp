// ShapeFactory.cpp
#include "ShapeFactory.hpp"
#include <memory>
#include "Entity.hpp"
#include "CircleEntity.hpp"

using namespace std;

ShapeFactory::ShapeFactory() {}

unique_ptr<sf::Shape> ShapeFactory::createShape(const shared_ptr<Entity>& entity) {
    auto ball = dynamic_pointer_cast<CircleEntity>(entity);
    float radius = ball->getRadius();
    auto circle = make_unique<sf::CircleShape>(radius);
    circle->setFillColor({102, 102, 255});
    circle->setOrigin({radius, radius});
    circle->setPosition({ball->getPosition().x, ball->getPosition().y});

    return circle;
}