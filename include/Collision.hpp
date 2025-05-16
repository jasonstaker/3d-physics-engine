#pragma once

#include "Entity.hpp"
#include "Quadtree.hpp"
#include "Simulation.hpp"
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

class Collision {
public:

    // constructors
    Collision();

    // functions
    void update(vector<shared_ptr<Entity>>& entities);
    bool checkCollisionBetween(const shared_ptr<Entity>& entityOne, const shared_ptr<Entity>& entityTwo);
    bool checkCollisionBorder(const shared_ptr<Entity>& entity);
    float distance(const shared_ptr<Entity>& entityOne, const shared_ptr<Entity>& entityTwo) const;
    void resolveCollisionBetween(shared_ptr<Entity>& entityOne, shared_ptr<Entity>& entityTwo);
    void resolveCollisionBorder(shared_ptr<Entity>& entity);
    
};