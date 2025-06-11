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
    if(!font.openFromFile("../assets/fonts/arial.ttf")) {
        return;
    }  
}

void Renderer::render(const vector<shared_ptr<Entity>>& entities) {
    float dt = fpsClock.restart().asSeconds();
    float fps = dt > 0.f ? 1.f / dt : 0.f;

    if (window->isOpen()) {
        window->clear();

        for (shared_ptr<Entity> entity : entities) {
            renderEntity(entity);
        }
        
        if (Config::showOverlay) {
            drawOverlay(static_cast<int>(entities.size()), fps);
        }
        
        if (debugQuadtree && Config::renderQT) {
            drawQuadtree(*debugQuadtree);
        }

        if (Config::showHelpOverlay) {
            drawHelpOverlay();
        }

        window->display();
    } else {
        Config::running = false;
    }
}


void Renderer::renderEntity(const shared_ptr<Entity>& entity) {
    auto drawnEntity = entity->render();
    window->draw(*drawnEntity);
}

void Renderer::drawOverlay(int entityCount, float fps) {
    sf::Text fpsText(font, "FPS: " + std::to_string(static_cast<int>(fps)));
    fpsText.setCharacterSize(28);
    fpsText.setFillColor(sf::Color::White);
    fpsText.setOutlineColor(sf::Color::Black);
    fpsText.setOutlineThickness(1.f);
    fpsText.setPosition({8.f, 4.f});

    sf::Text entityCountText(font, "Entities: " + std::to_string(entityCount));
    entityCountText.setCharacterSize(30);
    entityCountText.setFillColor(sf::Color::White);
    entityCountText.setOutlineColor(sf::Color::Black);
    entityCountText.setOutlineThickness(1.f);
    entityCountText.setPosition({8.f, 36.f});

    window->draw(fpsText);
    window->draw(entityCountText);
}

void Renderer::drawQuadtree(const Quadtree& qt) {
    AABB box = qt.getBoundary();
    float width = box.bottomRight.x - box.topLeft.x;
    float height = box.bottomRight.y - box.topLeft.y;
    sf::FloatRect bounds = sf::FloatRect(sf::Vector2f(box.topLeft.x, box.topLeft.y), sf::Vector2f(width, height));

    sf::RectangleShape rect;
    rect.setPosition({bounds.position.x, bounds.position.y});
    rect.setSize({bounds.size.x, bounds.size.y});
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color(0, 255, 0, 128));
    rect.setOutlineThickness(1.f);
    window->draw(rect);

    for (const shared_ptr<Quadtree> child : qt.getChildren()) {
        drawQuadtree(*child);
    }
}

void Renderer::setQuadtree(const shared_ptr<Quadtree>& qt) {
    debugQuadtree = move(qt);
}

std::vector<sf::Event> Renderer::pollEvents() {
    std::vector<sf::Event> events;
    
    while (const auto event = window->pollEvent()) {
        events.push_back(*event);
    }
    return events;
}

void Renderer::drawHelpOverlay() {
    sf::RectangleShape backdrop({ float(width), float(height) });
    backdrop.setFillColor(sf::Color(0, 0, 0, 150));
    window->draw(backdrop);

    struct { const char* key; const char* desc; } items[] = {
        { "P",         "Pause / Resume Simulation"         },
        { "Space",     "Step One Frame"                    },
        { "C",         "Spawn Ball Without Clash"          },
        { "Backspace","Clear All Entities"                },
        { "T",         "Toggle Time Scale"                 },
        { "V",         "Toggle Velocity Colors"            },
        { "F",         "Toggle FPS/Entities Overlay"       },
        { "Q",         "Toggle Quadtree Debug"             },
        { "H",         "Toggle Help Overlay"               },
        { "Escape",    "Exit Simulation"                   },
    };

    const float startX = 10.f;
    const float startY = 16.f;
    const float lineHeight = 45.f;

    for (size_t i = 0; i < std::size(items); ++i) {
        sf::Text line(font, std::string(items[i].key) + " : " + items[i].desc);
        line.setCharacterSize(35);
        line.setFillColor(sf::Color::White);
        line.setOutlineColor(sf::Color::Black);
        line.setOutlineThickness(1.f);
        line.setPosition({ startX, startY + i * lineHeight });
        window->draw(line);
    }
}