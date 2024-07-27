#include "Window.h"

int main()
{
    InitWindow(1280, 720, "Window Manager");
    SetTargetFPS(60);

    Window window(GetScreenWidth() / 4, GetScreenHeight() / 4, GetScreenWidth() / 2, GetScreenHeight() / 2, "Test");

    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        window.Update();

        ClearBackground(RED);

        window.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}