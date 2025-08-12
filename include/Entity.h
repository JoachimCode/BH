#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Sprite {
    public:
    Entity(sf::Vector2f position_, double speed_, std::string imagepath);
    void drawEntity(sf::RenderWindow& window) const; 
    void moveEntity(float xpos, float ypos);    
    double getSpeed() const;
    double getVerticalSpeed() const;
    int getHealth();
    void setHealth(int health);
    //void move(sf::Vector2f movement_vector);
    //void setPosition(sf::Vector2f coordinates);
       // sf::Vector2f getPosition();
       //  double getSpeed();
   // void setSpeed(double speed_);

    private:
    sf::Texture texture;
    double speed;
    int health;
    void setEntityTexture(std::string imagepath);
    void setEntityOrigin();

};


#endif //ENTITY_H