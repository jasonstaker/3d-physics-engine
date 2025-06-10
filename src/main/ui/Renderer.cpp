// Renderer.cpp
#include "Renderer.hpp"
#include "Entity.hpp"
#include "SFML/Graphics.hpp"
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

Renderer::Renderer() {}

Renderer::Renderer(unsigned int width, unsigned int height) : width(width), height(height) {
    window = new sf::RenderWindow(sf::VideoMode({width, height}), "Physics Engine");
    if(!fpsFont.openFromFile("../assets/fonts/arial.ttf")) {
        return;
    }  
}

void Renderer::render(const vector<shared_ptr<Entity>>& entities) {
    float dt = fpsClock.restart().asSeconds();
    float fps = dt > 0.f ? 1.f / dt : 0.f;

    if (window->isOpen()) {
        if (const std::optional event = window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window->close();
            } else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    window->close();
                }
            }
        }

        window->clear();

        for (shared_ptr<Entity> entity : entities) {
            renderEntity(entity);
        }
        
        drawOverlay(static_cast<int>(entities.size()), fps);

        window->display();
    }
}


void Renderer::renderEntity(const shared_ptr<Entity>& entity) {
    auto drawnEntity = entity->render();
    window->draw(*drawnEntity);
}

void Renderer::drawOverlay(int entityCount, float fps) {
    sf::Text fpsText(fpsFont, "FPS: " + std::to_string(static_cast<int>(fps)));
    fpsText.setCharacterSize(28);
    fpsText.setFillColor(sf::Color::White);
    fpsText.setOutlineColor(sf::Color::Black);
    fpsText.setOutlineThickness(1.f);
    fpsText.setPosition({8.f, 4.f});

    sf::Text entityCountText(fpsFont, "Entities: " + std::to_string(entityCount));
    entityCountText.setCharacterSize(28);
    entityCountText.setFillColor(sf::Color::White);
    entityCountText.setOutlineColor(sf::Color::Black);
    entityCountText.setOutlineThickness(1.f);
    entityCountText.setPosition({8.f, 36.f}); // 4 + 28 + 4 = 36

    window->draw(fpsText);
    window->draw(entityCountText);
}
