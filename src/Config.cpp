// Config.cpp
#include "Config.hpp"
#include "json.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

using json = nlohmann::json;

namespace Config {
    unsigned int windowWidth = 1500;
    unsigned int windowHeight = 1100;

    float timeScale = 6.0f;
    float dragCoefficient = 0.01f;
    float restitution = 0.8f;
    float frictionCoefficient = 1.0f;

    float simulationRunTime = 6.0f;
    float renderFrequencyMultiplier = 3.0f;
    float targetFPS = 60.0f;
    double frameDuration = 1000.0 / 60.0;
    float fixedTimeStep = 1.0f / (60.0f * 3.0f);
    int numBalls = 150;
    float radius = 50.0f;
    float spawnMargin = radius;
    int maxAttempts = 5000;
    int qtSplitThreshold = 4;

    bool renderQT = false;
    bool showAABBs = false;
    bool paused = false;
    bool stepOnceRequested = false;
    bool running = true;
    bool showOverlay = false;
    bool showHelpOverlay = false;
    bool showVelocityColors = false;
    float timeScaleMultiplier = 1.0f;

    void loadFromFile(const std::string& path) {
        std::ifstream in(path);
        if (!in.is_open()) throw std::runtime_error("Cannot open config file: " + path);

        json j;
        in >> j;

        if (j.contains("window")) {
            auto& jw = j["window"];
            windowWidth = jw.value("width", windowWidth);
            windowHeight = jw.value("height", windowHeight);
        }

        if (j.contains("physics")) {
            auto& jp = j["physics"];
            timeScale = jp.value("timeScale", timeScale);
            dragCoefficient = jp.value("dragCoefficient", dragCoefficient);
            restitution = jp.value("restitution", restitution);
            frictionCoefficient = jp.value("frictionCoefficient", frictionCoefficient);
        }

        if (j.contains("simulation")) {
            auto& js = j["simulation"];
            simulationRunTime = js.value("runTime", simulationRunTime);
            renderFrequencyMultiplier = js.value("renderFrequencyMultiplier", renderFrequencyMultiplier);
            targetFPS = js.value("targetFPS", targetFPS);
            numBalls = js.value("numBalls", numBalls);
            radius = js.value("radius", radius);
            spawnMargin = js.value("spawnMargin", spawnMargin);
            maxAttempts = js.value("maxAttempts", maxAttempts);
            qtSplitThreshold = js.value("qtSplitThreshold", qtSplitThreshold);
        }

        if (j.contains("flags")) {
            auto& jf = j["flags"];
            renderQT = jf.value("renderQT", renderQT);
            showAABBs = jf.value("showAABBs", showAABBs);
            paused = jf.value("paused", paused);
            stepOnceRequested = jf.value("stepOnceRequested", stepOnceRequested);
            running = jf.value("running", running);
            showOverlay = jf.value("showOverlay", showOverlay);
            showHelpOverlay = jf.value("showHelpOverlay", showHelpOverlay);
            showVelocityColors = jf.value("showVelocityColors", showVelocityColors);
            timeScaleMultiplier = jf.value("timeScaleMultiplier", timeScaleMultiplier);
        }

        const_cast<double&>(frameDuration) = 1000.0 / targetFPS;
        const_cast<float&>(fixedTimeStep) = 1.0f / (targetFPS * renderFrequencyMultiplier);
    }
}
