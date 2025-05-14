#include "Vec.hpp"
#include "World.hpp"
#include "Ball.hpp"
#include <chrono>
#include <thread>

using namespace std::chrono;

void runSimulationLoop(World& world, float duration = 10.0f) {
    using clock = std::chrono::steady_clock;
    const float dtTarget = 1.0f / 60.0f;
    const auto frameDuration = std::chrono::duration<float>(dtTarget);

    auto startTime = clock::now();
    int totalFrames = static_cast<int>(duration / dtTarget);

    for (int i = 0; i < totalFrames; ++i) {
        auto frameStart = clock::now();

        world.update(dtTarget);

        auto frameEnd = clock::now();
        std::chrono::duration<float> elapsed = frameEnd - frameStart;

        if (elapsed < frameDuration) {
            std::this_thread::sleep_for(frameDuration - elapsed);
        }
    }
}

int main() {
    World world(960, 540);

    world.addEntity(make_shared<Ball>(Vec(480,270)));

    runSimulationLoop(world);

    return 0;
}