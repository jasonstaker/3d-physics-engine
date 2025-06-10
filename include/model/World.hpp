#pragma once

#include "Entity.hpp"
#include "Physics.hpp"
#include "Collision.hpp"
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
    void clearEntities();
    int getWidth();
    int getHeight();
    const vector<shared_ptr<Entity>>& getEntities() const;
    shared_ptr<Quadtree> getQuadtree() const;

    
private:

    // fields
    int width, height;
    vector<shared_ptr<Entity>> entities;
    Physics physics;
    Collision collision;
    
};