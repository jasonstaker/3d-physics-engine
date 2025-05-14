#include "Vec.hpp"
#include "World.hpp"
#include "Ball.hpp"
#include <chrono>

using namespace std::chrono;

void runSimulationLoop(World& world, float duration = 5.0f) {
    using clock = std::chrono::steady_clock;
    auto startTime = clock::now();
    auto lastTime = startTime;
    float dtTarget = 1.0f / 60.0f;

    while (true) {
        auto currentTime = clock::now();
        std::chrono::duration<float> elapsed = currentTime - lastTime;
        std::chrono::duration<float> totalElapsed = currentTime - startTime;

        float dt = elapsed.count();
        lastTime = currentTime;

        if (totalElapsed.count() >= duration) break;

        world.update(dt);
    }
}

int main() {
    World world(960, 540);

    world.addEntity(make_shared<Ball>(Vec(480,270)));

    runSimulationLoop(world);

    return 0;
}