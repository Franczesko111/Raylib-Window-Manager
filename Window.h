#pragma once

#define RAYLIB "C:\\raylib\\raylib\\src\\raylib.h"
#include RAYLIB
#include <stdint.h>
#include <functional>

namespace _window
{
    struct Data
    {
        int16_t x;
        int16_t y;
        uint16_t width;
        uint16_t height;

        const char* title;
    };
};

class Window
{
    public:
        Window(const int16_t x = 0, const int16_t y = 0, const uint16_t width = 400, const uint16_t height = 400, const char* title = "Window");
        void Draw(const std::function<void()>& DrawEverything);
        void Update();

        _window::Data data;
        bool held;
    
    private:
        bool IsMouseHovered(const int16_t x, const int16_t y, const uint16_t width, const uint16_t height);

        uint16_t offset_x;
        uint16_t offset_y;
};