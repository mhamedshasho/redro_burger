#include "core/Clock.hpp"
#include "core/Rect.hpp"
#include "game/BurgerGame.hpp"

#include <cassert>
#include <thread>
#include <chrono>

int main() {
    const redro::Rect a{{0, 0}, {10, 10}};
    const redro::Rect b{{5, 5}, {10, 10}};
    const redro::Rect c{{20, 20}, {2, 2}};
    assert(a.intersects(b));
    assert(!a.intersects(c));
    assert(a.contains({5, 5}));
    assert(!a.contains({15, 15}));

    redro::BurgerGame game;
    assert(game.money() == 0);
    assert(game.ingredientCount() == 0);
    assert(!game.orderComplete());

    game.addIngredient(-1);
    game.addIngredient(4);
    assert(game.ingredientCount() == 0);

    game.addIngredient(0);
    game.addIngredient(1);
    game.addIngredient(3);
    assert(game.orderComplete());
    assert(game.ingredientCount() == 3);
    game.addIngredient(2);
    assert(game.ingredientCount() == 3);

    game.serveOrder();
    assert(game.money() == 25);
    assert(game.ingredientCount() == 0);
    assert(!game.orderComplete());

    game.serveOrder();
    assert(game.money() == 25);

    game.resetOrder();
    assert(game.ingredientCount() == 0);
    return 0;
}
