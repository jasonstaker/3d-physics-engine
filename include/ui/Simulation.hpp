#pragma once

#include "World.hpp"
#include "Renderer.hpp"
#include "Config.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <random>

using namespace std::chrono;

class Simulation {
public:

    // constructors
    Simulation();

    // functions
    void run();

private:

    // fields
    World world;
    Renderer renderer;

};