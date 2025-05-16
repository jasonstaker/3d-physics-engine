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
    const float TIME_SCALE = 6.0f;
    Vec gravity = Vec(0, 9.81f);
    constexpr static float dragCoefficient = 0.01f;
    constexpr static float restitution = 0.8f;
    constexpr static float groundFriction = 0.05f;

    // functions
    void update(const vector<shared_ptr<Entity>>& entities, float dt);
    void updateEntity(shared_ptr<Entity> entity, float dt);
    Vec getLinearDragVec(const shared_ptr<Entity>& entity);

};

#endif