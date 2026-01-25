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

std::vector<sf::Keyboard::Key> InputHandler::getInputs() {
    std::vector<sf::Keyboard::Key> inputs;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) inputs.push_back(sf::Keyboard::A);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) inputs.push_back(sf::Keyboard::D);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) inputs.push_back(sf::Keyboard::W);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) inputs.push_back(sf::Keyboard::S);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) inputs.push_back(sf::Keyboard::Space);
    return inputs;
}