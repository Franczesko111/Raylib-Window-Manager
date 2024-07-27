#include "Window.h"

Window::Window(const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const char* title)
{
    position.x = x;
    position.y = y;
    position.width = width;
    position.height = height;
    this->title = title;
}

void Window::Draw()
{
    DrawRectangle(position.x, position.y, position.width, position.height, LIGHTGRAY);
    DrawRectangle(position.x, position.y, position.width, 30, WHITE);
    DrawText(title, position.x + 5, position.y + 7, 20, BLACK);
}

void Window::Update()
{

}