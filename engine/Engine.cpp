#include "Engine.h"
#include <iostream>
#include "GamePlayState.h"
#include <memory>

Engine::Engine() : window(sf::VideoMode(1000, 1000), "Bullet Hell Extreme!") {
    running = true;
    GameContext context {window};
    auto gamePlayState = std::make_unique<GamePlayState>(context);
    stateStack.push(std::move(gamePlayState));
    
}

void Engine::run() {
    while(running) {
        tickData.now = std::chrono::high_resolution_clock::now();
        tickData.deltaTime = time_to_float(tickData.now) - time_to_float(tickData.lastTimePulled);
        if(tickData.deltaTime > tickData.MAXFRAME); tickData.deltaTime = tickData.MAXFRAME;


        while(tickData.deltaTime > tickData.TICK) {

            stateStack.top().get()->update(tickData.TICK);
            tickData.deltaTime - tickData.TICK;
        }
    }
}

float Engine::time_to_float(std::chrono::system_clock::time_point time) {
    return std::chrono::duration<float, std::milli>(time.time_since_epoch()).count();
};


