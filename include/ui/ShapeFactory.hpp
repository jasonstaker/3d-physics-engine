// ShapeFactory.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include <memory>

class ShapeFactory {
public:
    static std::unique_ptr<sf::Shape>
    createShape(const std::shared_ptr<Entity>& entity);
};
