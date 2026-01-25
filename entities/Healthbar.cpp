#include "Healthbar.h"
#include <iostream>
void Healthbar::setHealthbar(float healthPercentage, sf::Vector2f bottomLeftCorner, sf::Vector2f topRightCorner) {
    float height = topRightCorner.y - bottomLeftCorner.y;
    float width = topRightCorner.x - bottomLeftCorner.x;
    healthBar.setSize(sf::Vector2f(width, height));
    healthBar.setFillColor(sf::Color(70, 50, 250));
    //healthBar.setOrigin(bottomLeftCorner.x, bottomLeftCorner.y);
    healthBar.setPosition(bottomLeftCorner.x, bottomLeftCorner.y);

    currentHealthbar.setSize(sf::Vector2f(width - (width*0.1) - (width * (1.f - healthPercentage)), height - (height*0.1)));
    currentHealthbar.setFillColor(sf::Color(250, 50, 250));
    //currentHealthbar.setOrigin(0, bottomLeftCorner.y);
    currentHealthbar.setPosition(sf::Vector2f(bottomLeftCorner.x + (width * 0.05), bottomLeftCorner.y + (height * 0.05)));
}