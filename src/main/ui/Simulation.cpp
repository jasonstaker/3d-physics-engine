// Simulation.cpp
#include "Simulation.hpp"

Simulation::Simulation() : world(Config::windowWidth, Config::windowHeight, {}) {
    std::mt19937 rng{std::random_device{}()};
    std::uniform_real_distribution<float> distX(Config::spawnMargin, Config::windowWidth  - Config::spawnMargin);
    std::uniform_real_distribution<float> distY(Config::spawnMargin, Config::windowHeight - Config::spawnMargin);
    std::uniform_real_distribution<float> distV(-150.0f, 150.0f);

    std::vector<Vec> placed;
    placed.reserve(Config::numBalls);

    for (int i = 0; i < Config::numBalls; ++i) {
        bool ok = false;
        for (int att = 0; att < Config::maxAttempts; ++att) {
            Vec p{ distX(rng), distY(rng) };
            bool clash = false;
            for (auto& q : placed) {
                if ((p - q).norm() < Config::radius * 2.0f) {
                    clash = true;
                    break;
                }
            }
            if (!clash) {
                placed.push_back(p);
                Vec v{ distV(rng), distV(rng) };
                world.addEntity(std::make_shared<CircleEntity>(p, v, Vec(), 1.0f, Config::radius));
                ok = true;
                break;
            }
        }
        if (!ok) {
            break;
        }
    }

    renderer = Renderer(Config::windowWidth, Config::windowHeight);
}

void Simulation::run() {
    float total = 0.0f;
    auto lastRenderTime = high_resolution_clock::now();
    auto lastTime = lastRenderTime;
    float accumulator = 0.0f;

    while (Config::running) {
        if (total >= Config::simulationRunTime) {
            Config::running = false;
            break;
        }

        renderer.processEvents();

        auto currentTime = high_resolution_clock::now();
        float frameTime = duration<float>(currentTime - lastTime).count();
        lastTime = currentTime;
        frameTime = std::min(frameTime, 0.25f);

        if (!Config::paused || Config::stepOnceRequested) {
            accumulator += frameTime;

            while (accumulator >= Config::fixedTimeStep) {
                world.update(Config::fixedTimeStep);
                accumulator -= Config::fixedTimeStep;
                total += Config::fixedTimeStep;

                if (Config::paused && Config::stepOnceRequested) {
                    Config::stepOnceRequested = false;
                    break;
                }
            }
        }

        if (duration<double, std::milli>(currentTime - lastRenderTime).count() >= Config::frameDuration) {
            lastRenderTime = currentTime;
            renderer.setQuadtree(world.getQuadtree());
            renderer.render(world.getEntities());
        }
    }
}