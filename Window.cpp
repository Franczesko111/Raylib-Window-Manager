#include "Window.h"

Window::Window(const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const char* title)
{
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
    
}