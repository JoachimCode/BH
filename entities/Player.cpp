#include "Player.h"
#include "TrajectoryCalculator.h"
Player::Player(sf::Vector2f position_, double speed_, std::string imagepath) : Entity(position_, speed_,  imagepath) {};

void Player::shoot(std::vector<Bullet*>& bulletBuffer, sf::Vector2f targetPosition) {
    TrajectoryData bulletTrajectory = TrajectoryCalculator::getBulletTrajectory(getPosition(), targetPosition, getSpeed());
    Bullet* bullet = new Bullet(getPosition(), 3, "resources/sprites/fire.png", bulletTrajectory.trajectoryVector);
    bullet->rotate(bulletTrajectory.angle);
    bulletBuffer.push_back(bullet);
};