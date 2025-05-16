#include "Simulation.hpp"
#include "World.hpp"

const unsigned int WINDOW_WIDTH = 1920/2;
const unsigned int WINDOW_HEIGHT = 1080/2;


Simulation::Simulation() : world(WINDOW_WIDTH, WINDOW_HEIGHT, {}) {
    // temporary
    world.addEntity(make_shared<Ball>(Vec(WINDOW_WIDTH/2, WINDOW_HEIGHT/2), Vec(0.0f, -39.6f)));
    renderer = Renderer(WINDOW_WIDTH, WINDOW_HEIGHT);
    //
}

void Simulation::run() {
    // temporary
    float cap = 8.0f;
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