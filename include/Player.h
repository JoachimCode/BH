#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Bullet.h"
#include <vector>

class Player : public Entity {
    public:
    Player(sf::Vector2f position_, double speed_, std::string imagepath, int health);
    void shoot(std::vector<Bullet*>& bulletBuffer, sf::Vector2f targetPosition);
    private:
};


#endif