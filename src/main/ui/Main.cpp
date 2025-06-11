// Main.cpp
#include "Config.hpp"
#include "Simulation.hpp"
#include <iostream>

int main(int argc, char** argv) {
    std::string cfgPath = (argc > 1 ? argv[1] : "config.json");
    try {
        Config::loadFromFile(cfgPath);
    } catch (const std::exception &e) {
        std::cerr << "Error loading config: " << e.what() << "\n";
        return EXIT_FAILURE;
    }

    Simulation simulation;
    simulation.run();

    return 0;
}