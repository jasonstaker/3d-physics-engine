#pragma once

#include "Vec.hpp"

namespace Config {

    // Window dimensions
    constexpr unsigned int windowWidth = 1500;
    constexpr unsigned int windowHeight = 1100;

    // Physics parameters
    constexpr float timeScale = 6.0f;
    extern Vec gravity;
    constexpr float dragCoefficient = 0.01f;
    constexpr float restitution = .8f;
    constexpr float frictionCoefficient = 1.0f;

    // Simulation variables
    constexpr float simulationRunTime = 6.0f;
    constexpr float renderFrequencyMultiplier = 3.0f;
    constexpr float targetFPS = 60.0f;
    extern const double frameDuration;
    extern const float fixedTimeStep;
    constexpr int numBalls = 500;
    constexpr float radius = 20.0f;
    constexpr float spawnMargin = radius;
    constexpr int maxAttempts = 5000;
    constexpr int qtSplitThreshold = 4;
    
    // Mutable simulation variables
    extern bool renderQT;
    extern bool showAABBs;
    extern bool paused;
    extern bool stepOnceRequested;
    extern bool running;
}