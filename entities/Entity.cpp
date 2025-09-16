#include "Entity.h"
#include <iostream>

Entity::Entity(sf::Vector2f position_, double speed_, std::string imagepath, int health) : speed(speed_), maxHealth(health) {
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
    window.draw(healthbar.healthBar);
    window.draw(healthbar.currentHealthbar);
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

void Entity::setHealthBar() {
    sf::Vector2f bottomleft = sf::Vector2f(getPosition().x, getPosition().y + 30);
    sf::Vector2f topRight = sf::Vector2f(bottomleft.x + getLocalBounds().getSize().x, bottomleft.y + 30);
    healthbar.setHealthbar(health/maxHealth, bottomleft, topRight);
};


