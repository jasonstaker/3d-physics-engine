#pragma once

#include "Vec.hpp"
#include "Config.hpp"
#include <vector>
#include "Entity.hpp"
#include "CircleEntity.hpp"
#include <memory>

using namespace std;

class Physics {
public:

    // functions
    void update(const vector<shared_ptr<Entity>>& entities, float dt);
    void updateEntity(const shared_ptr<Entity>& entity, float dt);
    Vec getLinearDragVec(const shared_ptr<Entity>& entity);

};