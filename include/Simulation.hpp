#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "World.hpp"
#include "Renderer.hpp"
#include "InputHandler.hpp"
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

private:

    // fields
    World world;
    Renderer renderer = Renderer(1920/2, 1080/2);
    //InputHandler input;

};

#endif