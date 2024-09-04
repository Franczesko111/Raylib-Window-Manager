#include "include/Player.hpp"

Player::Player(const int16_t x, const int16_t y, const uint16_t width, const uint16_t height) : x(x), y(y), width(width), height(height) {}

void Player::Draw(const int16_t window_x, const int16_t window_y)
{
    DrawRectangle(x + window_x, y + window_y, width, height, GREEN);
}

void Player::Update()
{
    x += (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * 5;
    y += (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * 5;
}