#include "Engine.h"
#include <iostream>

struct TickData {
    const float TICK = 1.f / 60.f;
    const float MAXFRAME = 0.25f;
    float deltaTime = 0.f;
    std::chrono::_V2::system_clock::time_point lastTimePulled = std::chrono::high_resolution_clock::now();
    std::chrono::_V2::system_clock::time_point now = std::chrono::high_resolution_clock::now();
};

Engine::Engine() {
    running = true;
}

void Engine::run() {
    while(running) {
        std::cout << "RUNNING";
    }
}