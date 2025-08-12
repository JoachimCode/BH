#include "Entity.h"
#include <iostream>

Entity::Entity(sf::Vector2f position_, double speed_, std::string imagepath) : speed(speed_) {
    setPosition(position_);
    setEntityTexture(imagepath);
    setEntityOrigin();
}


void Entity::setEntityTexture(std::string imagepath) {
    if(!texture.loadFromFile(imagepath)) {
        std::cerr << "Failed to load entity texture/n";
        std::exit(EXIT_FAILURE);
    }
    setTexture(texture);
}

//Sets the origin of the entity to its center, instead of top left corner. 
//This is so all rotation and movement comes from the center of the entity.
void Entity::setEntityOrigin() {
    sf::FloatRect bounds = getLocalBounds();
    setOrigin(bounds.width/2.f, bounds.height/2.f);
}

int Entity::getHealth() {
    return health;
}

void Entity::setHealth(int health_) {
    health = health_;
} 

void Entity::drawEntity(sf::RenderWindow& window) const {
    window.draw(*this);
}

void Entity::moveEntity(float x, float y) {
    sf::Vector2f currentPosition = getPosition();
    sf::Vector2f newPosition(currentPosition.x + x, currentPosition.y + y);
    setPosition(newPosition);
}

double Entity::getSpeed() const {
    return speed;
}

double Entity::getVerticalSpeed() const {
    return speed/std::sqrt(2);
}