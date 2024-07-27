#pragma once

//Raylib and stdint.h inside
#include "Utils.h"

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
        void Draw();
        void Update();

        _window::Data data;
        bool held;
    
    private:
        uint16_t offset_x;
        uint16_t offset_y;
};