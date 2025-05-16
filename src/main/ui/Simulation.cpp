// Simulation.cpp
#include "Simulation.hpp"

Simulation::Simulation() : world(WINDOW_WIDTH, WINDOW_HEIGHT, {}) {
    const int   NUM_BALLS    = 400;
    const float RADIUS       = 20.0f;
    const float SPAWN_MARGIN = RADIUS;
    const int   MAX_ATTEMPTS = 5000;

    std::mt19937 rng{std::random_device{}()};
    std::uniform_real_distribution<float> distX(SPAWN_MARGIN, WINDOW_WIDTH  - SPAWN_MARGIN);
    std::uniform_real_distribution<float> distY(SPAWN_MARGIN, WINDOW_HEIGHT - SPAWN_MARGIN);
    std::uniform_real_distribution<float> distV(-150.0f, 150.0f);

    std::vector<Vec> placed;
    placed.reserve(NUM_BALLS);

    for (int i = 0; i < NUM_BALLS; ++i) {
        bool ok = false;
        for (int att = 0; att < MAX_ATTEMPTS; ++att) {
            Vec p{ distX(rng), distY(rng) };
            bool clash = false;
            for (auto& q : placed) {
                if ((p - q).norm() < RADIUS * 2.0f) {
                    clash = true;
                    break;
                }
            }
            if (!clash) {
                placed.push_back(p);
                Vec v{ distV(rng), distV(rng) };
                world.addEntity(std::make_shared<Ball>(p, v, Vec(), 1.0f, RADIUS));
                ok = true;
                break;
            }
        }
        if (!ok) {
            // couldn't place the i-th ball after many attempts
            break;
        }
    }

    renderer = Renderer(WINDOW_WIDTH, WINDOW_HEIGHT);
}

/*
Simulation::Simulation() : world(WINDOW_WIDTH, WINDOW_HEIGHT, {}) {
    // temporary
    world.addEntity(make_shared<Ball>(Vec(200.0f, 300.0f), Vec(150.0f, 0.0f)));
    world.addEntity(make_shared<Ball>(Vec(600.0f, 300.0f), Vec(-150.0f, 0.0f)));
    world.addEntity(make_shared<Ball>(Vec(400.0f, 100.0f), Vec(-100.0f, 100.0f)));
    world.addEntity(make_shared<Ball>(Vec(300.0f, 200.0f), Vec(50.0f, -80.0f)));
    world.addEntity(make_shared<Ball>(Vec(WINDOW_WIDTH - 60.0f, WINDOW_HEIGHT - 60.0f), Vec(-100.0f, -80.0f)));
    renderer = Renderer(WINDOW_WIDTH, WINDOW_HEIGHT);
    //
}
*/

void Simulation::run() {
    // temporary
    float cap = 8.0f;
    float total = 0.0f;
    //

    const int targetFPS = 60;
    const double frameDuration = 1000.0 / targetFPS;
    const float fixedTimeStep = 1.0f / ((float)targetFPS*2);

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