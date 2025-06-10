#pragma once

#include "SFML/Graphics.hpp"
#include "Entity.hpp"
#include "ShapeFactory.hpp"
#include <vector>
#include <memory>

using namespace std;

class Renderer {
public:

    // constructors
    Renderer();
    Renderer(unsigned int width, unsigned int height);
    
    // functions
    void render(const vector<shared_ptr<Entity>>& entities);
    void renderEntity(const shared_ptr<Entity>& entity);
    void drawOverlay(int entityCount, float fps);

private:

    // fields
    unsigned int width; 
    unsigned int height;
    sf::RenderWindow* window;
    ShapeFactory shapeFactory;
    sf::Clock fpsClock;
    sf::Font fpsFont;
};