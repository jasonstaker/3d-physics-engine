// Config.hpp
#pragma once

#include <string>

namespace Config {
    // Window dimensions
    extern unsigned int windowWidth;
    extern unsigned int windowHeight;

    // Physics parameters
    extern float timeScale;
    extern float dragCoefficient;
    extern float restitution;
    extern float frictionCoefficient;

    // Simulation variables
    extern float simulationRunTime;
    extern float renderFrequencyMultiplier;
    extern float targetFPS;
    extern double frameDuration;
    extern float fixedTimeStep;
    extern int numBalls;
    extern float radius;
    extern float spawnMargin;
    extern int maxAttempts;
    extern int qtSplitThreshold;

    // Mutable simulation flags
    extern bool renderQT;
    extern bool showAABBs;
    extern bool paused;
    extern bool stepOnceRequested;
    extern bool running;
    extern bool showOverlay;
    extern bool showHelpOverlay;
    extern bool showVelocityColors;
    extern float timeScaleMultiplier;

    void loadFromFile(const std::string &path);
}
