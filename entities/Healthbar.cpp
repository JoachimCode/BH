#include "Healthbar.h"

void Healthbar::setHealthbar(float healthPercentage, sf::Vector2f bottomLeftCorner, sf::Vector2f topRightCorner) {
    float height = topRightCorner.y - bottomLeftCorner.y;
    float width = topRightCorner.x - bottomLeftCorner.x;

    healthBar.setSize(sf::Vector2f(width, height));
    healthBar.setFillColor(sf::Color(150, 50, 250));
    healthBar.setOrigin(0, bottomLeftCorner.y);
    healthBar.setPosition(bottomLeftCorner);

    currentHealthbar.setSize(sf::Vector2f(width - (width*0.1) - (width * healthPercentage), height - (height*0.1)));
    currentHealthbar.setFillColor(sf::Color(250, 50, 250));
    currentHealthbar.setOrigin(0, bottomLeftCorner.y);
    healthBar.setPosition(sf::Vector2f(bottomLeftCorner.x + (width * 0.1), bottomLeftCorner.y + (height * 0.1)));
    
}