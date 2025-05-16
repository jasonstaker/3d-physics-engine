#include "Simulation.hpp"
#include "World.hpp"
#include <algorithm>

Simulation::Simulation() : world(WINDOW_WIDTH, WINDOW_HEIGHT, {}) {
    // temporary
    world.addEntity(make_shared<Ball>(Vec(WINDOW_WIDTH/4, WINDOW_HEIGHT/2), Vec(120.0f, 0.0f)));
    world.addEntity(make_shared<Ball>(Vec(WINDOW_WIDTH/4, WINDOW_HEIGHT/4), Vec(120.0f, -100.0f), Vec(), 1.0f, 50.0f));
    world.addEntity(make_shared<Ball>(Vec(WINDOW_WIDTH/8, WINDOW_HEIGHT/2), Vec(-120.0f, 0.0f)));
    world.addEntity(make_shared<Ball>(Vec(WINDOW_WIDTH/2, WINDOW_HEIGHT/2), Vec(-300.0f, 100.0f), Vec(), 1.0f, 50.0f));
    renderer = Renderer(WINDOW_WIDTH, WINDOW_HEIGHT);
    //
}

void Simulation::run() {
    // temporary
    float cap = 16.0f;
    float total = 0.0f;
    //

    const int targetFPS = 60;
    const double frameDuration = 1000.0 / targetFPS;
    const float fixedTimeStep = 1.0f / ((float)targetFPS);

    auto lastRenderTime = high_resolution_clock::now();
    auto lastTime = lastRenderTime;

    float accumulator = 0.0f;

    bool running = true;
    while (running) {
        // temporary
            if (total >= cap) {
                running = false;
                break;
            }
        //
        
        auto currentTime = high_resolution_clock::now();
        float frameTime = duration<float>(currentTime - lastTime).count();
        lastTime = currentTime;

        frameTime = std::min(frameTime, 0.25f);

        accumulator += frameTime;

        while (accumulator >= fixedTimeStep) {
            world.update(fixedTimeStep);
            accumulator -= fixedTimeStep;
            total += fixedTimeStep;
        }

        if (duration<double, std::milli>(currentTime - lastRenderTime).count() >= frameDuration) {
            lastRenderTime = currentTime;
            renderer.render(world.getEntities());
        }
    }

}