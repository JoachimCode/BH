#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Healthbar.h"
#include <chrono>

class Entity : public sf::Sprite {
    public:
    Entity(sf::Vector2f position_, double speed_, std::string imagepath, int health);
    void drawEntity(sf::RenderWindow& window) const; 
    void moveEntity(float xpos, float ypos);    
    double getSpeed() const;
    double getVerticalSpeed() const;
    int getHealth();
    void setHealthBar();
    void setHealth(int health_);
    std::chrono::_V2::system_clock::time_point lastHit;
    


    private:
    Healthbar healthbar;
    sf::Texture texture;
    double speed;
    int maxHealth;
    int health;

    void setEntityTexture(std::string imagepath);
    void setEntityOrigin();

};


#endif //ENTITY_H