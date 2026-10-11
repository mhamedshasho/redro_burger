#pragma once

#include <array>
#include <string>

namespace redro {

class BurgerGame {
public:
    void addIngredient(int index);
    void serveOrder();
    void resetOrder();

    int money() const { return money_; }
    int patience() const { return patience_; }
    int ingredientCount() const { return ingredient_count_; }
    bool orderComplete() const { return ingredient_count_ >= 3; }
    const std::array<int, 3>& ingredients() const { return ingredients_; }

private:
    std::array<int, 3> ingredients_{};
    int ingredient_count_ = 0;
    int money_ = 0;
    int patience_ = 100;
};

}
