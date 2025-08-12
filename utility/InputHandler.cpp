#include "InputHandler.h"

Direction InputHandler::getDirection() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
    return Direction::UP_LEFT;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
    return Direction::UP_RIGHT;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
    return Direction::DOWN_LEFT;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
    return Direction::DOWN_RIGHT;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
    return Direction::LEFT;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    return Direction::RIGHT;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    return Direction::DOWN;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    return Direction::UP;
    else 
    return Direction::NONE;
}

bool InputHandler::isShooting() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}