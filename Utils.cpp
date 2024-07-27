#include "Utils.h"

bool utils::IsMouseHovered(const int16_t x, const int16_t y, const uint16_t width, const uint16_t height)
{
    return (GetMouseX() > x && GetMouseX() < x + width && GetMouseY() > y && GetMouseY() < y + height);
}