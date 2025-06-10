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
    void spawnRandomBall();
    bool spawnBallWithoutClash(std::vector<Vec>& placed);
    void processEvents();

private:

    // fields
    World world;
    Renderer renderer;
    std::vector<Vec> placedPositions;
    std::mt19937 rng;

    Vec getRandomPosition();
    Vec getRandomVelocity();

};