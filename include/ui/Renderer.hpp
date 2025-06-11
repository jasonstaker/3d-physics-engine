#pragma once

#include "SFML/Graphics.hpp"
#include "Entity.hpp"
#include "ShapeFactory.hpp"
#include "Quadtree.hpp"
#include "Config.hpp"
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
    void drawQuadtree(const Quadtree& qt);
    void setQuadtree(const shared_ptr<Quadtree>& qt);
    void drawHelpOverlay();
    vector<sf::Event> pollEvents();

private:

    // fields
    unsigned int width; 
    unsigned int height;
    sf::RenderWindow* window;
    ShapeFactory shapeFactory;
    sf::Clock fpsClock;
    sf::Font font;
    shared_ptr<Quadtree> debugQuadtree = nullptr;
};