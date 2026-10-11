#include "game/BurgerGame.hpp"

#include <algorithm>

namespace redro {

void BurgerGame::addIngredient(int index) {
    if (index < 0 || index > 3 || ingredient_count_ >= 3) {
        return;
    }
    ingredients_[static_cast<std::size_t>(ingredient_count_++)] = index;
}

void BurgerGame::serveOrder() {
    if (orderComplete()) {
        money_ += 25;
        patience_ = std::min(100, patience_ + 5);
        resetOrder();
    }
}

void BurgerGame::resetOrder() {
    ingredients_.fill(0);
    ingredient_count_ = 0;
}

}
