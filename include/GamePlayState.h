#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H
#include "GameState.h"
#include <iostream>
#include <memory>
#include <Entity.h>

struct GameplayContext {
    std::vector<std::unique_ptr<Entity>> enemyBuffer;
};

class GamePlayState : GameState {
    public:
    GamePlayState(GameContext& context);
    void update(float tick);
    GameplayContext ctx;
};

#endif //GAMEPLAYSTATE_H