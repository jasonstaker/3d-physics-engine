# 2D Physics Engine & Renderer Demo (C++ / SFML)

## Overview

A real-time 2D physics engine implemented in C++17, using SFML for rendering and user input. Features:

* **2D Rigid-Body Simulation**: Circles with mass, gravity, friction, and elastic collisions.
* **Spatial Partitioning**: Quadtree broad-phase culling for efficient collision detection (O(n log n)).
* **JSON Configuration**: Simulation parameters (gravity, friction, entity spawn rates) loaded from `assets/config/config.json`.
* **High Entity Count**: Can handle ~1000 entities at 60 FPS.
* **User Controls**:

  * **P**: Pause/Resume simulation
  * **T**: Slow motion toggle
  * **Backspace**: Clear all entities
  * **C**: Spawn random circle entity
  * **Q**: Toggle quadtree visualization overlay
  * **F**: Toggle FPS and entity-count overlay
  * **H**: Show help overlay with keybindings
* **Dynamic Visuals**:

  * Velocity-based coloring and random entity colors
  * Help overlay with semi-transparent background
  * FPS and entity count display

## Demo
![2D Physics Engine Demo](assets/2d-physics-demo.gif)

## Building & Running

1. Install SFML (>= 3.0) and ensure headers/libs are accessible (may have to copy the SFML lib folder contents into build)
2. Clone this repo.
3. Copy `assets/config/config.json` to the build directory (handled automatically by CMake).
4. Build with CMake:

   ```bash
   mkdir build && cd build
   cmake ..
   cmake --build .
   ```
5. Run:

   ```bash
   ./PhysicsEngine
   ```

## Project Structure

```
physics-engine/
├── assets/              # JSON config, fonts
│   └── config/config.json
├── include/             # Public headers
│   ├── Config.hpp       # Global constants
│   ├── model/           # Vec, Entity, Physics, Quadtree, Collision, World
│   └── ui/              # Renderer, Simulation, ShapeFactory
├── src/
│   ├── main/model       # Model implementations
│   └── main/ui          # UI implementations
├── CONTRIBUTING.md      # Repo commit style
└── CMakeLists.txt       # Build setup
```

## Possible future improvements

* **Resource Manager**: Centralize loading of fonts and textures to avoid duplicate loads and manage lifetimes.
* **Error Handling**: Add robust checks (e.g., fail-safe on font load) and user feedback for missing assets.
* **Code Organization**: Introduce namespaces (e.g., `engine::model`, `engine::ui`) to prevent symbol collisions.

## Next Steps

1. Finalize Pause/Help overlay polish and consider animated fades.
2. Implement Resource Manager for assets (fonts, textures) in `ResourceManager.hpp`.
3. Possible improvement to the UI

## Reflection

The sole purpose of this project is to act as a stepping stone into 3D collision physics and rendering. I have learned so much about rendering, physics, and just generally how to solve issues in C++ with tools I have never even heard of before. While I certainly could have implement more, I really hope to venture out into the 3D world, and believe I have gained the knowledge to at least try. I am excited to extend my knowledge to 3D spaces, and I hope you enjoy this demo.
