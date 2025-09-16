#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H
#include "Entity.h"


inline bool detectCollision(Entity* firstEntity, Entity* secondEntity) {
    sf::FloatRect firstBoundingBox = firstEntity->getGlobalBounds();
    sf::FloatRect secondBoundingBox = secondEntity->getGlobalBounds();

    return firstBoundingBox.intersects(secondBoundingBox);
};

#endif