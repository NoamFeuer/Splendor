#include "raylib.h"

int main() {
    // Initialize the window
    InitWindow(800, 600, "raylib C++ Example");

    // Set the target FPS
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // Start drawing
        BeginDrawing();

        // Clear the background
        ClearBackground(RAYWHITE);

        // Draw some text
        DrawText("Hello, raylib!", 350, 280, 20, DARKGRAY);

        // Finish drawing
        EndDrawing();
    }

    // Close the window
    CloseWindow();

    return 0;
}
