#ifndef TRAJECTORY_CALCULATOR_H
#define TRAJECTORY_CALCULATOR_H
#include <SFML/Graphics.hpp>
#include "TrajectoryData.h"

class TrajectoryCalculator {
    public:
    static TrajectoryData getBulletTrajectory(sf::Vector2f source, sf::Vector2f target, double speed);
};

#endif