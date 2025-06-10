# Contributing to 2D Physics Engine

Thanks for your interest in this project! Even though this is currently a solo project, a consistent development process helps keep the code clean and understandable.

## Commit Style

Please follow the **Conventional Commits** format:

```

<type>: <short summary in sentence case>

```

### Common Types:
- `feat`: New feature
- `fix`: Bug fix
- `refactor`: Code change that doesn't alter behavior
- `perf`: Performance improvement
- `style`: Formatting only (no logic change)
- `test`: Add or update tests
- `chore`: Miscellaneous tasks

### Examples:
```

feat: add friction system to simulation
refactor: restructure collision logic into separate class
fix: correct edge case in boundary reflection

````

## Branching (Currently Simplified)

This project is currently maintained on a single branch (`main`) for simplicity. Feature branches may be used later during larger overhauls.

## Formatting

Run clang-format on all C++ files before committing.

## Build

To build the project:
```bash
cd .\build\
cmake --build .
.\PhysicsEngine.exe
````

## Questions?

Open an issue or contact me directly (See README).
