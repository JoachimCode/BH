#ifndef ENGINE_H
#define ENGINE_H
#include <chrono>
#include <stack>
#include "GameState.h"
#include "TickData.h"
#include "InputHandler.h"
#include "GameContext.h"
#include <memory>

class Engine {
    public:
    void run();
    Engine();


    private:
    sf::RenderWindow window;
    sf::View getLetterBoxView(sf::View view, int windowWidth, int windowHeight);
    InputHandler inputHandler;
    std::stack<std::unique_ptr<GameState>> stateStack;
    bool running;
    TickData tickData;
    float time_to_float(std::chrono::system_clock::time_point time);
};

#endif //ENGINE_H