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
    shared_ptr<Quadtree> northeast, northwest, southeast, southwest;

public:

    // constructors
    Quadtree(AABB boundary, int capacity);

    // functions
    bool insert(shared_ptr<Entity> entity);
    void query(const AABB& range, vector<shared_ptr<Entity>>& out);
    void subdivide();
    void clear();
    AABB getBoundary() const;
    vector<shared_ptr<Quadtree>> getChildren() const;
    
};
