#include "core/Rect.hpp"
#include <cassert>
int main() {
    const redro::Rect a{{0, 0}, {10, 10}};
    const redro::Rect b{{5, 5}, {10, 10}};
    const redro::Rect c{{20, 20}, {2, 2}};
    assert(a.intersects(b));
    assert(!a.intersects(c));
    assert(a.contains({5, 5}));
    assert(!a.contains({15, 15}));
    return 0;
}