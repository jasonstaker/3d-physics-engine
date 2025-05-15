#include "Simulation.hpp"
#include "World.hpp"

Simulation::Simulation() : world(1920/2, 1080/2, {}) {
    // temporary
    world.addEntity(make_shared<Ball>(Vec(1920/4, 1080/4)));
    //
}

void Simulation::run() {
    // temporary
    float cap = 5.0f;
    float total = 0.0f;
    //

    const int targetFPS = 60;
    const double frameDuration = 1000.0 / targetFPS;

    auto lastRenderTime = high_resolution_clock::now();
    auto lastTime = lastRenderTime;

    bool running = true;
    while (running) {
        // temporary
            if (total >= cap) {
                break;
            }
        //
        
        auto currentTime = high_resolution_clock::now();
        float elapsed = duration<double, std::milli>(currentTime - lastTime).count();
        lastTime = currentTime;

        world.update(elapsed/1000);
        total += elapsed/1000;
        cout << total << endl;

        if (duration<double, std::milli>(currentTime - lastRenderTime).count() >= frameDuration) {
            lastRenderTime = currentTime;

            renderer.render(world.getEntities());
        }

    }
}