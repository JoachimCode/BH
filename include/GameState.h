#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <SFML/Graphics.hpp>
#include "GameContext.h"
#include <chrono>



class GameState {
    public:
    virtual void update(float deltatime);
    GameState(GameContext& context_); 
    
    protected: 
    GameContext& context;
};

#endif //GAMESTATE_H