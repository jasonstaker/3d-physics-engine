#ifndef WORLD_HPP
#define WORLD_HPP

#include "Entity.hpp"
#include <vector>
#include <memory>
#include <utility>

using namespace std;

class World {
public:

    // constructors
    World(int width, int height, vector<shared_ptr<Entity>> entities = {});

    // functions
    void addEntity(shared_ptr<Entity> entity);
    void update(float dt);
    int getWidth();
    int getHeight();
    
private:

    // fields
    int width, height;
    vector<shared_ptr<Entity>> entities;
    
};

#endif