#pragma once

#include "Entity.hpp"
#include "AABB.hpp"
#include <vector>
#include <memory>

using namespace std;


class Quadtree {

    // fields
    AABB boundary;
    int capacity;
    vector<shared_ptr<Entity>> objects;
    bool divided;
    unique_ptr<Quadtree> northeast, northwest, southeast, southwest;

public:

    // constructors
    Quadtree(AABB boundary, int capacity);

    // functions
    bool insert(shared_ptr<Entity> entity);
    vector<shared_ptr<Entity>> query(const AABB& range);
    void subdivide();
    void clear();
    
};
