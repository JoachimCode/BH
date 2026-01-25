#ifndef ENGINE_H
#define ENGINE_H
#include <chrono>
#include <stack>
#include "GameState.h"
#include "TickData.h"


class Engine {
    public:
    void run();
    Engine();


    private:
    std::stack<GameState> stateStack;
    bool running;
    TickData tickData;
    float time_to_float(std::chrono::system_clock::time_point time);
};

#endif //ENGINE_H