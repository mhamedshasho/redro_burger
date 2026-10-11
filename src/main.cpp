#include "game/BurgerGame.hpp"

#include <SDL3/SDL.h>

#include <array>

namespace {
constexpr int kWidth = 960;
constexpr int kHeight = 540;

void fill(SDL_Renderer* renderer, float x, float y, float w, float h,
          Uint8 r, Uint8 g, Uint8 b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    const SDL_FRect rect{x, y, w, h};
    SDL_RenderFillRect(renderer, &rect);
}

void drawScene(SDL_Renderer* renderer, const redro::BurgerGame& game) {
    SDL_SetRenderDrawColor(renderer, 24, 20, 22, 255);
    SDL_RenderClear(renderer);
    fill(renderer, 0, 0, 960, 82, 143, 24, 35);
    fill(renderer, 30, 105, 900, 255, 48, 38, 34);
    fill(renderer, 60, 140, 840, 190, 91, 57, 39);
    fill(renderer, 80, 355, 800, 115, 36, 33, 33);
    fill(renderer, 105, 175, 150, 95, 232, 164, 55);
    fill(renderer, 115, 185, 130, 75, 250, 210, 125);

    const auto& ingredients = game.ingredients();
    const std::array<std::array<Uint8, 3>, 4> colors{{
        {{240, 184, 69}}, {{117, 65, 36}}, {{65, 164, 74}}, {{230, 57, 54}}
    }};
    fill(renderer, 340, 200, 230, 32, 228, 166, 73);
    for (int i = 0; i < game.ingredientCount(); ++i) {
        const auto& c = colors[static_cast<std::size_t>(ingredients[static_cast<std::size_t>(i)])];
        fill(renderer, 350, 190.0F - static_cast<float>(i) * 27.0F, 210, 28, c[0], c[1], c[2]);
    }
    fill(renderer, 700, 145, 150, 110, 211, 173, 135);
    fill(renderer, 720, 165, 110, 75, 235, 210, 183);

    fill(renderer, 35, 400, 190, 78, 222, 157, 66);
    fill(renderer, 255, 400, 190, 78, 121, 70, 43);
    fill(renderer, 475, 400, 190, 78, 62, 153, 69);
    fill(renderer, 695, 400, 190, 78, 202, 54, 50);
    fill(renderer, 740, 20, 180, 42, 242, 188, 55);
    for (int i = 0; i < game.money() / 5 && i < 30; ++i) {
        fill(renderer, 755.0F + static_cast<float>(i % 10) * 15.0F,
             30.0F + static_cast<float>(i / 10) * 9.0F, 8, 5, 88, 55, 28);
    }
    SDL_RenderPresent(renderer);
}
}

int main(int, char**) {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("Redro Burger Engine - Prototype",
                                          kWidth, kHeight, SDL_WINDOW_RESIZABLE);
    if (!window) {
        SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    redro::BurgerGame game;
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            } else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
                const float x = event.button.x;
                if (event.button.y >= 390.0F) {
                    if (x < 235.0F) game.addIngredient(0);
                    else if (x < 455.0F) game.addIngredient(1);
                    else if (x < 675.0F) game.addIngredient(2);
                    else if (x < 900.0F) game.addIngredient(3);
                    if (game.orderComplete()) game.serveOrder();
                }
            } else if (event.type == SDL_EVENT_FINGER_DOWN) {
                const float x = event.tfinger.x * kWidth;
                const float y = event.tfinger.y * kHeight;
                if (y >= 390.0F) {
                    if (x < 235.0F) game.addIngredient(0);
                    else if (x < 455.0F) game.addIngredient(1);
                    else if (x < 675.0F) game.addIngredient(2);
                    else if (x < 900.0F) game.addIngredient(3);
                    if (game.orderComplete()) game.serveOrder();
                }
            }
        }
        drawScene(renderer, game);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
