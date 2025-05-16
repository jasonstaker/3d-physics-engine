#ifndef RENDERER_HPP
#define RENDERER_HPP

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

private:
    unsigned int width; 
    unsigned int height;
    sf::RenderWindow* window;
    ShapeFactory shapeFactory;
};

#endif