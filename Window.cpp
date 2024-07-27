#include "Window.h"

Window::Window(const int16_t x, const int16_t y, const uint16_t width, const uint16_t height, const char* title)
{
    held = false;
    offset_x = 0;
    offset_y = 0;

    data.x = x;
    data.y = y;
    data.width = width;
    data.height = height;
    data.title = title;
}

void Window::Draw()
{
    DrawRectangle(data.x, data.y, data.width, data.height, LIGHTGRAY);
    DrawRectangle(data.x, data.y, data.width, 30, WHITE);
    DrawText(data.title, data.x + 5, data.y + 7, 20, BLACK);
}

void Window::Update()
{
    if(utils::IsMouseHovered(data.x, data.y, data.width, 30))
    {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            held = true;
            offset_x = GetMouseX() - data.x;
            offset_y = GetMouseY() - data.y;
        }
    }

    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) held = false;

    if(held) {
        data.x = GetMouseX() - offset_x;
        data.y = GetMouseY() - offset_y;
    }
}