#include "Window.h"
#include <vector>

int main()
{
    InitWindow(1280, 720, "Window Manager");
    SetTargetFPS(60);

    std::vector<Window> windows;
    windows.push_back(Window(100, 100, 200, 200, "Test"));
    windows.push_back(Window(400, 400, 200, 200, "Another test"));

    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        for(Window& window: windows) {
            window.Update();
        }

        ClearBackground(RED);

        for(Window& window: windows) {
            window.Draw();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}