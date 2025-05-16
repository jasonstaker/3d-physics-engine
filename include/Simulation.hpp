#pragma once

#include "World.hpp"
#include "Renderer.hpp"
#include "World.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <random>

using namespace std::chrono;

class Simulation {
public:

    // fields
    const static unsigned int WINDOW_WIDTH = 1920/2;
    const static unsigned int WINDOW_HEIGHT = 1080/2;
    
    // constructors
    Simulation();

    // functions
    void run();

private:

    // fields
    World world;
    Renderer renderer;

};