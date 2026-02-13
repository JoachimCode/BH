#ifndef TICKDATA_H
#define TICKDATA_H
#include <chrono>

struct TickData {
    const float TICK = 1.f / 60.f;
    const float MAXFRAME = 0.25f;
    float deltaTime = 0.f;
    std::chrono::_V2::system_clock::time_point lastTimePulled = std::chrono::high_resolution_clock::now();
    std::chrono::_V2::system_clock::time_point now = std::chrono::high_resolution_clock::now();
};

#endif //TICKDATA_H