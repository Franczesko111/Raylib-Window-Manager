#include "Window.h"
#include <vector>

void WindowLayering(std::vector<Window>& windows, std::vector<Window>::reverse_iterator& it);

class Player
{
    public:
        Player(const int16_t x, const int16_t y, const uint16_t width, const uint16_t height)
        {
            this->x = x;
            this->y = y;
            this->width = width;
            this->height = height;
        }
        void Draw(const int16_t window_x = 0, const int16_t window_y = 0)
        {
            DrawRectangle(x + window_x, y + window_y, width, height, GREEN);
        }
        void Update()
        {
            x += (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * 5;
            y += (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * 5;
        }
    
    private:
        int16_t x;
        int16_t y;
        uint16_t width;
        uint16_t height;
};

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

    Player player(50, 50, 50, 50);

    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        player.Update();

        WindowLayering(windows, window_iterator);

        ClearBackground(RED);

        for(Window& window: windows) {
            window.Draw([&]() {
                DrawRectangle(200, 200, 200, 200, YELLOW);
                DrawRectangle(500, 500, 200, 200, YELLOW);
            });
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