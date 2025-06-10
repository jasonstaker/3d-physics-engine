# 2D Physics Engine

A simple 2D physics engine built in C++ using SFML. This project simulates basic rigid body dynamics and real-time rendering of circular entities, serving as a foundation for future physics and rendering work.

## 🔧 Features

- Circular entities with:
  - Position, velocity, acceleration
  - Mass and restitution
- Collision detection and resolution between circles
- Spatial partitioning with a Quadtree for broad-phase collision detection
- Simple Euler integration
- Real-time rendering using SFML
- Object-oriented architecture with modular classes

## 📁 Project Structure

.  
├─ assets/  
├─ include/  
│  ├─ model/  
│  │  ├─ AABB.hpp  
│  │  ├─ CircleEntity.hpp  
│  │  ├─ Collision.hpp  
│  │  ├─ Entity.hpp  
│  │  ├─ Physics.hpp  
│  │  ├─ Quadtree.hpp  
│  │  ├─ Vec.hpp  
│  │  └─ World.hpp  
│  ├─ ui/  
│  │  ├─ Renderer.hpp  
│  │  ├─ ShapeFactory.hpp  
│  │  └─ Simulation.hpp  
│  └─ Config.hpp  
├─ lib/  
├─ src/  
│  └─ main/  
│     ├─ model/  
│     │  ├─ AABB.cpp  
│     │  ├─ CircleEntity.cpp  
│     │  ├─ Collision.cpp  
│     │  ├─ Entity.cpp  
│     │  ├─ Physics.cpp  
│     │  ├─ Quadtree.cpp  
│     │  ├─ Vec.cpp  
│     │  └─ World.cpp  
│     └─ ui/  
│        ├─ Main.cpp  
│        ├─ Renderer.cpp  
│        ├─ ShapeFactory.cpp  
│        └─ Simulation.cpp  
├─ CMakeLists.txt  
├─ LICENSE  
└─ README.md  


## ⚙️ Build Instructions

### Prerequisites

- C++17 compatible compiler
- [SFML 2.5+](https://www.sfml-dev.org/)
- CMake 3.15+

### Build (Linux/macOS/WSL)
git clone https://github.com/your-username/2d-physics-engine.git
cd 2d-physics-engine
mkdir build && cd build
cmake ..
make
./PhysicsEngine

### Build (Windows)
* Install SFML and CMake
* Configure the project using CMake GUI or Visual Studio

## 🧠 Components

* `Vec` – 2D vector math helper class
* `Entity` – Base class for all physical objects
* `CircleEntity` – Implements physics for circular shapes
* `World` – Manages and updates entities
* `Quadtree` – Optimizes collision detection
* `Renderer` – Uses SFML to draw the simulation

## 🚧 Future Work

* Add FPS overlay and performance stats
* Implement color coding by velocity
* Add toggles for rendering quadtree and bounding boxes
* Support additional shape types (e.g., rectangles)
* Export and load scenes from file
* More Physics features

## 👤 Author

Jason Staker  
Computer Science @ UBC  
Summer 2025  