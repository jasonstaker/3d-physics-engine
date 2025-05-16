#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "Vec.hpp"
#include <vector>
#include "Entity.hpp"
#include "Ball.hpp"
#include <memory>

using namespace std;

class Physics {
public:

    // fields
    const float TIME_SCALE = 4.0f;
    Vec gravity = Vec(0, 9.81f);
    float dragCoefficient = 0.01f;
    float restitution = 0.8f;
    float groundFriction = 0.05f;

    // functions
    void update(const vector<shared_ptr<Entity>>& entities, float dt);
    void updateEntity(shared_ptr<Entity> entity, float dt);
    Vec getLinearDragVec(const shared_ptr<Entity>& entity);

};

#endif