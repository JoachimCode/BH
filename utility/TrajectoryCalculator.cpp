#include "TrajectoryCalculator.h"
const int RIGHTANGLE = 90;
const float RADIANCOEF = 57.3;


TrajectoryData TrajectoryCalculator::getBulletTrajectory(sf::Vector2f source, sf::Vector2f target, double speed) {
    TrajectoryData trajectoryData;
    sf::Vector2f deltaPosition(std::abs(source.x - target.x), std::abs(source.y - target.y));
    float angle = atan(deltaPosition.y/deltaPosition.x);
    if(source.x < target.x && source.y < target.y)
    {
        trajectoryData.trajectoryVector = sf::Vector2f(speed*cos(angle), speed*sin(angle));
        trajectoryData.angle = RIGHTANGLE + angle * RADIANCOEF;
    }
    else if(target.x < source.x && target.y < source.y)
    {
        trajectoryData.trajectoryVector = sf::Vector2f(-speed*cos(angle), -speed*sin(angle));
        trajectoryData.angle = - (RIGHTANGLE - angle * RADIANCOEF);
    }
    else if(source.x > target.x && source.y < target.y)
    {
        trajectoryData.trajectoryVector = sf::Vector2f(-speed*cos(angle), speed*sin(angle));
        trajectoryData.angle = - RIGHTANGLE - (angle * RADIANCOEF);
    }
    else if(source.x < target.x && source.y > target.y)
    {
        trajectoryData.trajectoryVector = sf::Vector2f(speed*cos(angle), -speed*sin(angle));
        trajectoryData.angle = RIGHTANGLE - (angle * RADIANCOEF);
    }
    else
    {
        trajectoryData.trajectoryVector = sf::Vector2f(speed*1,0);
    }
    return trajectoryData;
};