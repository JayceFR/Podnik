# Porting VampyReloaded to C++

This plan outlines the refactoring of the VampyReloaded game from C to C++, focusing on modernizing the codebase using the C++ Standard Template Library (STL) and Object-Oriented Programming (OOP) principles.

## User Review Required

> [!IMPORTANT]
> The refactor involves deleting your custom `dynarray`, `hash`, and `minheap` implementations in favor of `std::vector`, `std::unordered_map`, and `std::priority_queue`. If you have highly specific behavior in those custom structures (e.g., custom memory pooling), let me know.

## Proposed Changes

### Core Architecture

- **[NEW] `Game.hpp` / `Game.cpp`**: Create a central `Game` class to manage the lifecycle (Init, Update, Draw) and global state.
- **[MODIFY] `main.cpp`**: Shift game logic from global variables into the `Game` class instance.

### Data Structure Migration (Pruning)

- **[DELETE] `dynarray.h` / `dynarray.cpp`**: Replace all usages with `std::vector`.
- **[DELETE] `hash.h` / `hash.cpp`**: Replace all usages with `std::unordered_map`.
- **[DELETE] `minheap.h` / `minheap.cpp`**: Replace all usages with `std::priority_queue`.

### Entity Management

- **[NEW] `Entity.hpp`**: Define a base class for all game objects (Player, Enemy, NPC).
- **[MODIFY] `player.hpp` / `enemy.hpp`**: Transition from `struct` with helper functions to classes with member functions.

### Code Quality & Maintenance

- **Type Safety**: Replace `void*` pointer usage with typed pointers or templates.
- **Memory Management**: Use `RAII` (Resource Acquisition Is Initialization) to handle Raylib resources (Textures, Shaders) so they unload automatically via destructors.

## Verification Plan

### Automated Tests
- `gradle_build(":app:assembleDebug")`: Verify that the C++ compiler accepts the new STL-based code.

### Manual Verification
- Deploy to device and verify:
    - Splash screen and menu navigation.
    - Player movement and shooting.
    - Enemy AI and spawning logic.
    - Asset loading consistency.
