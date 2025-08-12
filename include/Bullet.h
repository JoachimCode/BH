#ifndef BULLET_H
#define BULLET_H
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Bullet : public Entity {
    public:
    Bullet(sf::Vector2f position, double speed, std::string imagepath, sf::Vector2f trajectory_);
    sf::Vector2f getTrajectory();

    private:
    sf::Vector2f trajectory;

};
#endif 