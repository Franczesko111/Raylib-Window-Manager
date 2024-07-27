#pragma once

#include <stdint.h>
#define RAYLIB "C:\\raylib\\raylib\\src\\raylib.h"
#include RAYLIB

namespace utils
{
    bool IsMouseHovered(const int16_t x, const int16_t y, const uint16_t width, const uint16_t height);
};