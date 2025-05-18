#pragma once

#include "Vec.hpp"

namespace Config {

    // Window dimensions
    static constexpr unsigned int windowWidth = 600;
    static constexpr unsigned int windowHeight = 600;

    // Physics parameters
    constexpr static float timeScale = 6.0f;
    static Vec gravity = Vec(0, 9.81f);
    constexpr static float dragCoefficient = 0.01f;
    constexpr static float restitution = .8f;
    constexpr static float groundFriction = .05f;

    // Simulation variables
    static constexpr float simulationRunTime = 6.0f;
    static constexpr float renderFrequencyMultiplier = 2.0f;
    static constexpr float targetFPS = 60.0f;
    static const int numBalls = 500;
    static const float radius = 5.0f;
    static const float spawnMargin = radius;
    static const int maxAttempts = 5000;
}