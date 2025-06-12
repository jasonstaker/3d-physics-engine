// Simulation.cpp
#include "Simulation.hpp"
#include <random>
#include <chrono>
using namespace std::chrono;

Simulation::Simulation()
    : world(Config::windowWidth, Config::windowHeight, {}),
      renderer(Config::windowWidth, Config::windowHeight),
      rng(std::random_device{}())
{
    placedPositions.reserve(Config::numBalls);
    for (int i = 0; i < Config::numBalls; ++i) {
        if (!spawnBallWithoutClash(placedPositions)) break;
    }
}

// EFFECTS: returns random position within margins
Vec Simulation::getRandomPosition() {
    std::uniform_real_distribution<float> distX(Config::spawnMargin, Config::windowWidth  - Config::spawnMargin);
    std::uniform_real_distribution<float> distY(Config::spawnMargin, Config::windowHeight - Config::spawnMargin);
    return Vec{ distX(rng), distY(rng) };
}

// EFFECTS: returns random velocity vector
Vec Simulation::getRandomVelocity() {
    std::uniform_real_distribution<float> distV(-150.0f, 150.0f);
    return Vec{ distV(rng), distV(rng) };
}

// REQUIRES: placed contains existing positions
// MODIFIES: placed, world.entities
// EFFECTS: tries to spawn non-overlapping ball; returns success
bool Simulation::spawnBallWithoutClash(std::vector<Vec>& placed) {
    for (int att = 0; att < Config::maxAttempts; ++att) {
        Vec p = getRandomPosition();
        bool clash = false;
        for (const Vec& q : placed) {
            if ((p - q).norm() < Config::radius * 2.0f) {
                clash = true;
                break;
            }
        }
        if (!clash) {
            placed.push_back(p);
            world.addEntity(std::make_shared<CircleEntity>(p, getRandomVelocity(), Vec(), 1.0f, Config::radius));
            return true;
        }
    }
    return false;
}

// REQUIRES: world valid
// MODIFIES: world.entities
// EFFECTS: spawns a single random ball
void Simulation::spawnRandomBall() {
    Vec p = getRandomPosition();
    Vec v = getRandomVelocity();
    world.addEntity(std::make_shared<CircleEntity>(p, v, Vec(), 1.0f, Config::radius));
}

// REQUIRES: Config.running controls loop
// MODIFIES: world state, renderer quadtree
// EFFECTS: runs main simulation loop with fixed timestep and rendering
void Simulation::run() {
    auto lastRenderTime = high_resolution_clock::now();
    auto lastTime = lastRenderTime;
    float accumulator = 0.0f;

    while (Config::running) {
        processEvents();

        auto currentTime = high_resolution_clock::now();
        float frameTime = duration<float>(currentTime - lastTime).count();
        lastTime = currentTime;
        frameTime = std::min(frameTime, 0.25f);

        if (!Config::paused || Config::stepOnceRequested) {
            accumulator += frameTime;

            while (accumulator >= Config::fixedTimeStep) {
                world.update(Config::fixedTimeStep);
                accumulator -= Config::fixedTimeStep;

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

// REQUIRES: window created
// MODIFIES: Config flags
// EFFECTS: processes key and close events
void Simulation::processEvents() {
    for (const sf::Event& event : renderer.pollEvents()) {
        if (event.is<sf::Event::Closed>()) {
            Config::running = false;
        } else if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
            switch (keyPressed->scancode) {
                case sf::Keyboard::Scancode::Escape:
                    Config::running = false;
                    break;
                case sf::Keyboard::Scancode::Q:
                    Config::renderQT = !Config::renderQT;
                    break;
                case sf::Keyboard::Scancode::P:
                    Config::paused = !Config::paused;
                    break;
                case sf::Keyboard::Scancode::Space:
                    Config::stepOnceRequested = true;
                    break;
                case sf::Keyboard::Scancode::C:
                    placedPositions = {};

                    for (auto& entity : world.getEntities()) {
                        placedPositions.push_back(entity->getPosition());
                    }
                    spawnBallWithoutClash(placedPositions);
                    break;
                case sf::Keyboard::Scancode::Backspace:
                    world.clearEntities();
                    break;
                case sf::Keyboard::Scancode::T:
                    Config::timeScaleMultiplier =
                        (Config::timeScaleMultiplier == 1.f)
                            ? .5f
                            : 1.f;
                    break;
                case sf::Keyboard::Scancode::V:
                    Config::showVelocityColors = !Config::showVelocityColors;
                    break;
                case sf::Keyboard::Scancode::F:
                    Config::showOverlay = !Config::showOverlay;
                    break;
                case sf::Keyboard::Scancode::H:
                    Config::showHelpOverlay = !Config::showHelpOverlay;
                    break;
                default:
                    break;
            }
        }
    }
}