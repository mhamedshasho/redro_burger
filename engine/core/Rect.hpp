#pragma once
#include "core/Vec2.hpp"
namespace redro {
struct Rect {
    Vec2 position;
    Vec2 size;
    bool contains(Vec2 point) const {
        return point.x >= position.x && point.y >= position.y &&
               point.x <= position.x + size.x && point.y <= position.y + size.y;
    }
    bool intersects(const Rect& other) const {
        return position.x < other.position.x + other.size.x &&
               position.x + size.x > other.position.x &&
               position.y < other.position.y + other.size.y &&
               position.y + size.y > other.position.y;
    }
};
}