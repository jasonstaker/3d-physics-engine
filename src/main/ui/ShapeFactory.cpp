// ShapeFactory.cpp
#include "ShapeFactory.hpp"
#include <memory>
#include "Entity.hpp"
#include "Ball.hpp"

using namespace std;

ShapeFactory::ShapeFactory() {}

unique_ptr<sf::Shape> ShapeFactory::createShape(const shared_ptr<Entity>& entity) const {
    auto circle = make_unique<sf::CircleShape>(50.0f);
    circle->setFillColor({102, 102, 255});
    circle->setPosition({entity->getPosition().x, entity->getPosition().y});
    circle->setOutlineColor(sf::Color::Black);
    circle->setOutlineThickness(3.f);

    return circle;
}