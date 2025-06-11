#include "Config.hpp"

namespace Config {
    const double frameDuration = 1000.0 / targetFPS;
    const float fixedTimeStep = 1.0f / (targetFPS * renderFrequencyMultiplier);

    bool renderQT = false;
    bool showAABBs = false;
    bool paused = false;
    bool stepOnceRequested = false;
    bool running = true;
    bool showFPS = false;
    bool showHelpOverlay = false;
    bool showVelocityColors = false;
    float timeScaleMultiplier = 1.0f;
}