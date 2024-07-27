#include "Window.h"
#include <vector>

int main()
{
    InitWindow(1280, 720, "Window Manager");
    SetTargetFPS(60);

    std::vector<Window> windows;
    windows.push_back(Window(100, 100, 200, 200, "Test"));
    windows.push_back(Window(350, 300, 200, 200, "Another test"));
    windows.push_back(Window(600, 500, 200, 200, "Yet another test"));
    windows.push_back(Window(850, 300, 200, 200, "What am I doing"));

    std::vector<Window>::reverse_iterator window_iterator;

    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        for(window_iterator = windows.rbegin(); window_iterator != windows.rend(); ++window_iterator) {
            window_iterator->Update();
            if(window_iterator->held) {
                Window temp = *window_iterator;
                windows.erase((window_iterator + 1).base());
                windows.push_back(temp);
                break;
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