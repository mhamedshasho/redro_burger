#pragma once
#include "core/Vec2.hpp"
namespace redro {
struct InputState {
    Vec2 pointer{};
    bool pointer_pressed = false;
    bool quit_requested = false;
};
}