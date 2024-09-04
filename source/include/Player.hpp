#pragma once
#include "common/PCH.hpp"

class Player
{
    public:
        Player(const int16_t x, const int16_t y, const uint16_t width, const uint16_t height);
        void Draw(const int16_t window_x = 0, const int16_t window_y = 0);
        void Update();
        
    private:
        int16_t x;
        int16_t y;
        uint16_t width;
        uint16_t height;
};