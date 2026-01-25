#ifndef BULLET_H
#define BULLET_H
#include "Entity.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>

class Enemy;

class Bullet : public Entity {
    public:
    Bullet(sf::Vector2f position, double speed, std::string imagepath, sf::Vector2f trajectory_);
    sf::Vector2f getTrajectory();
    std::vector<Entity*> entitiesHit;
    bool hasHitEnemy(const Entity* enemy);

    private:
    sf::Vector2f trajectory;


};
#endif 