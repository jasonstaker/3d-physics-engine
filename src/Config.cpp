#include "Config.hpp"

namespace Config {
    Vec gravity = Vec(0, 9.81f);
    const double frameDuration = 1000.0 / targetFPS;
    const float fixedTimeStep = 1.0f / (targetFPS * renderFrequencyMultiplier);

    bool renderQT = false;
    bool showAABBs = false;
    bool paused = false;
    bool stepOnceRequested = false;
    bool running = true;
}