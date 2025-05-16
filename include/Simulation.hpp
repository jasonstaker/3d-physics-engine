#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "World.hpp"
#include "Renderer.hpp"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono;

class Simulation {
public:

    // constructors
    Simulation();

    // functions
    void run();

    // fields
    const static unsigned int WINDOW_WIDTH = 1920/2;
    const static unsigned int WINDOW_HEIGHT = 1080/2;

private:

    // fields
    World world;
    Renderer renderer;
    //InputHandler input;

};

#endif