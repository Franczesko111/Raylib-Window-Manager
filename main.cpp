#include "Window.h"
#include <vector>

int main()
{
    InitWindow(1280, 720, "Window Manager");
    SetTargetFPS(60);

    std::vector<Window> windows;
    windows.push_back(Window(100, 100, 200, 200, "Test"));
    windows.push_back(Window(400, 400, 200, 200, "Another test"));

    std::vector<Window>::iterator window_iterator;

    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        for(window_iterator = windows.begin(); window_iterator != windows.end(); ++window_iterator) {
            window_iterator->Update();
            if(window_iterator->held) {
                Window temp = *window_iterator;
                windows.erase(window_iterator);
                windows.push_back(temp);
            }
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