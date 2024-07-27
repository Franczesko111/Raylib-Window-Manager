#define RAYLIB "C:\\raylib\\raylib\\src\\raylib.h"
#include RAYLIB

int main()
{
    InitWindow(1280, 720, "Window Manager");
    SetTargetFPS(60);

    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}