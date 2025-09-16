#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, double speed, std::string imagepath, sf::Vector2f trajectory_)
 : Entity(position, speed, imagepath, 1), trajectory(trajectory_) {};

sf::Vector2f Bullet::getTrajectory() 
{
    return trajectory;
};