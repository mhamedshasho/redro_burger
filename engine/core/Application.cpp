#include "core/Application.hpp"

#include <chrono>
#include <thread>

namespace redro {

int Application::run() {
    using clock = std::chrono::steady_clock;
    constexpr auto frame_duration = std::chrono::milliseconds(16);

    bool running = true;
    while (running) {
        const auto frame_start = clock::now();

        // Platform events, game update, and rendering will be implemented here.

        const auto elapsed = clock::now() - frame_start;
        if (elapsed < frame_duration) {
            std::this_thread::sleep_for(frame_duration - elapsed);
        }

        // Temporary bootstrap loop guard until the platform layer is connected.
        running = false;
    }

    return 0;
}

}
