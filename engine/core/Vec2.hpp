#pragma once
namespace redro {
struct Vec2 {
    float x = 0.0F;
    float y = 0.0F;
    Vec2 operator+(const Vec2& rhs) const { return {x + rhs.x, y + rhs.y}; }
    Vec2 operator-(const Vec2& rhs) const { return {x - rhs.x, y - rhs.y}; }
    Vec2 operator*(float scale) const { return {x * scale, y * scale}; }
};
}