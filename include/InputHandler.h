#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <SFML/Graphics.hpp>
#include "Directions.h"

class InputHandler {
    public:
    Direction getDirection();
    bool isShooting();
    std::vector<sf::Keyboard::Key> getInputs();
};


#endif