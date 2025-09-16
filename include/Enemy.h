#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h" 

class Enemy : public Entity{
    public:
    Enemy(sf::Vector2f position, double speed, std::string imagepath, int health);

    private:
};

#endif