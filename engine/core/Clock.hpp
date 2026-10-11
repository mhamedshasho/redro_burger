#pragma once
#include <chrono>
namespace redro {
class Clock {
public:
    using clock_type = std::chrono::steady_clock;
    void reset() { previous_ = clock_type::now(); }
    float tick() {
        const auto now = clock_type::now();
        const std::chrono::duration<float> elapsed = now - previous_;
        previous_ = now;
        return elapsed.count();
    }
private:
    clock_type::time_point previous_ = clock_type::now();
};
}