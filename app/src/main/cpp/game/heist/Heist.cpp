#include "Heist.hpp"
#include "raylib.h"
#include "raymath.h"

namespace Heist {

int HeistMain() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Raylib initialization
    InitWindow(screenWidth, screenHeight, "Podnik - Heist Mode");
    InitAudioDevice();
    SetTargetFPS(60);

    // Camera setup for 2.5D Isometric look
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 20.0f, 20.0f, 20.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 10.0f;
    camera.projection = CAMERA_ORTHOGRAPHIC;

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        // TODO: Add player movement and networking here

        // Draw
        BeginDrawing();
            ClearBackground(BLACK);

            BeginMode3D(camera);
                DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 50.0f, 50.0f }, DARKGRAY);
                DrawGrid(20, 1.0f);

                // Placeholder for heist objective or player
                DrawCube((Vector3){ 0.0f, 0.5f, 0.0f }, 1.0f, 1.0f, 1.0f, RED);
                DrawCubeWires((Vector3){ 0.0f, 0.5f, 0.0f }, 1.0f, 1.0f, 1.0f, MAROON);
            EndMode3D();

            DrawText("HEIST MODE: C++ BASE", 10, 10, 20, RAYWHITE);
            DrawText("Procedural 2.5D Heist in development...", 10, 40, 10, SKYBLUE);
            DrawFPS(10, screenHeight - 20);
        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}

} // namespace Heist
