#pragma once

#define RAYLIB "C:\\raylib\\raylib\\src\\raylib.h"
#include RAYLIB
#include <stdint.h>

namespace _window
{
    struct Position
    {
        uint16_t x;
        uint16_t y;
        uint16_t width;
        uint16_t height;
    };
};

class Window
{
    public:
        Window(const uint16_t x = 0, const uint16_t y = 0, const uint16_t width = 400, const uint16_t height = 400, const char* title = "Window");
        void Draw();
        void Update();

        _window::Position position;
        const char* title;
};