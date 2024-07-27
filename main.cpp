#include "Window.h"
#include <vector>

void WindowLayering(std::vector<Window>& windows, std::vector<Window>::reverse_iterator& it);

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

        WindowLayering(windows, window_iterator);

        ClearBackground(RED);

        for(Window& window: windows) {
            window.Draw();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void WindowLayering(std::vector<Window>& vec, std::vector<Window>::reverse_iterator& it)
{
    for(it = vec.rbegin(); it != vec.rend(); ++it) {
        it->Update();
        if(it->held) {
            Window temp = *it;
            vec.erase((it + 1).base());
            vec.push_back(temp);
            break;
        }
    }
}