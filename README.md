# Podnik (VampyReloaded)

**Podnik** is a high-performance Android game built using **Raylib** and the **Android NDK**. It leverages a custom C-based game engine integrated with Android's `NativeActivity` and `GameActivity` for a seamless mobile gaming experience.

## 🚀 Tech Stack

*   **Game Engine:** [Raylib](https://www.raylib.com/) (Custom C implementation)
*   **Languages:** C, C++, Kotlin (Android Glue)
*   **Graphics:** OpenGL ES 2.0
*   **Audio:** OpenSLES
*   **Framework:** Android Game SDK (`GameActivity`), NDK (`native_app_glue`)
*   **Build System:** CMake + Gradle

## 📂 Project Structure

```text
Podnik/
├── app/
│   ├── src/main/cpp/          # Native source code
│   │   ├── game/              # Core game logic (C/C++)
│   │   │   ├── game_loop.c    # Main engine & state management
│   │   │   ├── map.c          # Procedural/Tile-based map system
│   │   │   ├── enemy.c        # AI and flocking (Boids) logic
│   │   │   └── ...            # Physics, Projectiles, NPCs, etc.
│   │   ├── external/          # Third-party libraries (Raylib)
│   │   └── CMakeLists.txt     # Native build configuration
│   ├── src/main/java/         # Android wrapper
│   │   └── com/jaycefr/podnik/
│   │       └── MainActivity.kt # Entry point (GameActivity)
│   ├── src/main/assets/       # Game resources
│   │   ├── shaders/           # GLSL Shaders
│   │   ├── music/             # Background tracks & SFX
│   │   ├── tiles/             # World tilemaps
│   │   └── entities/          # Player, Enemy, and Item sprites
│   └── AndroidManifest.xml    # NativeActivity configuration
└── build.gradle.kts           # Project build settings
```

## ✨ Key Features

*   **Native Performance:** Core logic runs directly in C for maximum efficiency.
*   **Custom Game Engine:** Features a dedicated game loop, AABB physics, and a modular entity system.
*   **Advanced AI:** Implementation of flocking behaviors (Boids) for environmental birds and complex enemy patterns.
*   **Mobile-First Input:** Dual-virtual joystick controls designed specifically for touchscreens.
*   **Procedural Systems:** Room-based map management and dynamic entity spawning.
*   **Asset Management:** Custom loaders for textures, music, and entity definitions.

## 🛠️ Build & Development

### Prerequisites
*   Android Studio (Ladybug or newer recommended)
*   Android NDK (Side-by-side)
*   CMake 3.22.1+

### Setup
1.  Clone the repository.
2.  Open the project in **Android Studio**.
3.  Ensure the NDK and CMake are installed via the SDK Manager.
4.  Sync Gradle and run the `app` module on a landscape-oriented device/emulator.

## 🎮 Controls
*   **Left Joystick:** Movement.
*   **Right Joystick:** Aiming and Shooting.
*   **Landscape Mode:** Optimized for wide-screen mobile play.

---
*Note: This project is continuation of the archived **VampyReloaded** It has been moved to AndroidStudio from vanilla Makefiles and WSL because of the evergrowing vision of Podnik*
The old history can be found here : https://github.com/JayceFR/VampyReloaded

