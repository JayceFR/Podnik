cmake_minimum_required(VERSION 3.22.1)
project("VampyReloaded")

# 1. Raylib Configuration for Android
set(PLATFORM "Android" CACHE STRING "Target platform")
set(BUILD_EXAMPLES OFF CACHE BOOL "Build examples")
set(BUILD_GAMES OFF CACHE BOOL "Build games")
set(USE_EXTERNAL_GLFW OFF CACHE BOOL "Use external GLFW")
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build raylib as static library")

# 2. Add Raylib subdirectory (dependency)
add_subdirectory(external/raylib raylib_build)

# 3. Define Game Source Files
# Using relative paths for better maintainability
set(GAME_SOURCES
    game/main.cpp
    game/survival/game_loop.c
    game/survival/camera.c
    game/survival/coin.c
    game/survival/dynarray.c
    game/survival/enemy.c
    game/survival/hash.c
    game/survival/impact.c
    game/survival/map.c
    game/survival/minheap.c
    game/survival/noise.c
    game/survival/npc.c
    game/survival/physics.c
    game/survival/projectile.c
    game/survival/trial.c
    game/survival/utils.c
    game/heist/Heist.cpp
)

# Required Android glue for native activity
set(NATIVE_APP_GLUE_SRC "${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c")

# 4. Create the shared library for Android
add_library(podnik SHARED
    ${GAME_SOURCES}
    ${NATIVE_APP_GLUE_SRC}
)

# 5. Include directories
target_include_directories(podnik PRIVATE
    game
    game/survival
    game/heist
    external/raylib/src
    "${ANDROID_NDK}/sources/android/native_app_glue"
)

# 6. Link required libraries
target_link_libraries(podnik
    raylib
    android
    log
    EGL
    GLESv2
    atomic
    m
    OpenSLES
)

# 7. Ensure ANativeActivity_onCreate is exported for Android
set_target_properties(podnik PROPERTIES LINK_FLAGS "-u ANativeActivity_onCreate")
