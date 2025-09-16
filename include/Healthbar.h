#ifndef HEALTHBAR_H
#define HEALTHBAR_H
#include "SFML/Graphics.hpp"

class Healthbar {
    public:
    sf::RectangleShape healthBar;
    sf::RectangleShape currentHealthbar;
    void setHealthbar(float healthPercentage, sf::Vector2f bottomLeftCorner, sf::Vector2f topRightCorner);


    private:

};

#endif