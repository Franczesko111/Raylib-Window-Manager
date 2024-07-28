# RAYLIB WINDOW MANAGER
An in-game window that you can add to your game (supports multiple windows).


$~$


## HOW TO USE
To use this tool you have to download [raylib](https://www.raylib.com/) (what a surprise!)

You can do whatever you want with this tool, just make sure to credit me if you use it! (please :D)


$~$


Here is a simple template:
```cpp
#include <raylib.h>

int main()
{
    InitWindow(1280, 720, "Template");
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
```


$~$


## WHAT CAN IT DO?
 - You can drag it across the screen
 - You can draw things into it (you can either make the contents follow the window or stay at one place)
 - Create multiple windows with an ease! No need to hardcode anything!

## SYNTAX
**SINGLE WINDOW**
```cpp
//Make a window object
Window window(0, 0, 1280, 720, "Window");


//Update
window.Update();


//Draw
window.Draw([&]() {

    //this will move with the window
    DrawRectangle(50 + window.data.x, 50 + window.data.y, 50, 50);

    //this won't
    DrawRectangle(50, 50, 50, 50);

});
```


**MULTIPLE WINDOWS**
```cpp
//Make a window vector and push back data
std::vector<Window> windows;
windows.push_back(Window(100, 100, 200, 200, "Test"));
windows.push_back(Window(350, 300, 200, 200, "Another test"));


//Update
for(Window& window: windows) {
    window.Update();
}


//Draw
for(Window &window: windows) {
    window.Draw([&]() {

        //this will move with the window
        DrawRectangle(50 + window.data.x, 50 + window.data.y, 50, 50);

        //this won't
        DrawRectangle(50, 50, 50, 50);

    });
}
```


$~$


## EXTRA
Here is a snippet of code for layering the windows:
```cpp
//add this after you make your window vector
std::vector<Window>::reverse_iterator window_iterator;

//replace it with the window.Update()
for(it = vec.rbegin(); it != vec.rend(); ++it) {
    it->Update();
    if(it->held) {
        Window temp = *it;
        vec.erase((it + 1).base());
        vec.push_back(temp);
        break;
    }
}
```

All those things together come with a template and a simple player script!
```cpp
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
                player.Draw(window.data.x, window.data.y);
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
```


$~$


## QUESTIONS
1. How to make each window draw something different if I make it in a vector?

You can make a simple for loop like this:

```cpp
//the simple way
for(int i = 0; i < windows.size(); i++) {
    windows[i].Draw([&]() {
        switch(i)
        {
            case 0:
                DrawRectangle(0 + window.data.x, 0 + window.data.y, 50, 50, GREEN);
                break;
            
            case 1:
                //other stuff
                break;
        }
    });
}
```


$~$


## DISCLAIMER
If you find any bugs in the source code or the README.md file or have a feature idea, please submit an issue (or help me fix it/implement it)!