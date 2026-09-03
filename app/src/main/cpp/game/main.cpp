#include "raylib.h"
#include "heist/Heist.hpp"

extern "C" {
    int GameMain();
}

typedef enum { MODE_NONE, MODE_SURVIVAL, MODE_HEIST } GameMode;

/**
 * A simple launcher to select the game mode at runtime.
 */
GameMode ShowLauncher() {
    GameMode selected = MODE_NONE;

    while (selected == MODE_NONE && !WindowShouldClose()) {
        Vector2 mouse = GetMousePosition();
        bool pressed = false;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || GetTouchPointCount() > 0) {
            if (GetTouchPointCount() > 0) mouse = GetTouchPosition(0);
            pressed = true;
        }

        // Survival Button
        Rectangle survivalBtn = { 100, 150, 600, 100 };
        bool hoverS = CheckCollisionPointRec(mouse, survivalBtn);

        // Heist Button
        Rectangle heistBtn = { 100, 280, 600, 100 };
        bool hoverH = CheckCollisionPointRec(mouse, heistBtn);

        if (pressed) {
            if (hoverS) selected = MODE_SURVIVAL;
            if (hoverH) selected = MODE_HEIST;
        }

        BeginDrawing();
            ClearBackground((Color){ 15, 15, 25, 255 });

            DrawText("PODNIK", 280, 40, 60, RAYWHITE);
            DrawText("SELECT GAME MODE", 285, 100, 20, (Color){ 0, 255, 255, 255 });

            // Draw Survival
            DrawRectangleRec(survivalBtn, hoverS ? (Color){ 40, 150, 80, 255 } : (Color){ 30, 100, 60, 255 });
            DrawRectangleLinesEx(survivalBtn, 3, hoverS ? (Color){ 0, 255, 0, 255 } : (Color){ 0, 200, 0, 255 });
            DrawText("SURVIVAL MODE (2D)", 230, 185, 30, WHITE);

            // Draw Heist
            DrawRectangleRec(heistBtn, hoverH ? (Color){ 150, 40, 120, 255 } : (Color){ 100, 30, 80, 255 });
            DrawRectangleLinesEx(heistBtn, 3, hoverH ? (Color){ 255, 0, 255, 255 } : (Color){ 200, 0, 200, 255 });
            DrawText("HEIST MODE (2.5D CPP)", 215, 315, 30, WHITE);

            DrawText("Build: 2026.09.03-V3", 10, 420, 15, DARKGRAY);
        EndDrawing();
    }

    return selected;
}

int main() {
    // Init window once for the launcher.
    InitWindow(800, 450, "Podnik");
    SetTargetFPS(60);

    GameMode mode = ShowLauncher();

    // After selection, we do NOT close the window.
    // We let the game mode handle its own InitAudioDevice()
    // and potentially call InitWindow() again (which Raylib will ignore).

    if (mode == MODE_SURVIVAL) {
        return GameMain();
    } else if (mode == MODE_HEIST) {
        return Heist::HeistMain();
    }

    CloseWindow();
    return 0;
}
