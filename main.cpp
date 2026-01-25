#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"
#include "InputHandler.h"
#include <vector>
#include "Bullet.h"
#include "Player.h"
#include <chrono>
#include <ctime>
#include "Enemy.h"
#include "CollisionDetector.h"
#include <bits/stdc++.h>

bool debug = true;

void drawDebugText(Entity* entity, sf::RenderWindow& window) {
    sf::Text t;
    t.setCharacterSize(24);
    t.setPosition(10.f, 10.f);

    sf::Font font;
    //path to font
    font.loadFromFile("C:\\Windows\\Fonts\\lucon.ttf");
    t.setFont(font);
    t.setFillColor(sf::Color::Red);

    std::ostringstream ss;
 //   ss << "DEBUG" << "\n" << 
    ss = entity->getDebugInfo();

    t.setString(ss.str());
    window.draw(t);
}


//https://github.com/SFML/SFML/wiki/Source%3A-Letterbox-effect-using-a-view
sf::View getLetterboxView(sf::View view, int windowWidth, int windowHeight) {

    // Compares the aspect ratio of the window to the aspect ratio of the view,
    // and sets the view's viewport accordingly in order to achieve a letterbox effect.
    // A new view (with a new viewport set) is returned.

    float windowRatio = (float) windowWidth / (float) windowHeight;
    float viewRatio = view.getSize().x / (float) view.getSize().y;
    float sizeX = 1;
    float sizeY = 1;
    float posX = 0;
    float posY = 0;

    bool horizontalSpacing = true;
    if (windowRatio < viewRatio)
        horizontalSpacing = false;

    // If horizontalSpacing is true, the black bars will appear on the left and right side.
    // Otherwise, the black bars will appear on the top and bottom.

    if (horizontalSpacing) {
        sizeX = viewRatio / windowRatio;
        posX = (1 - sizeX) / 2.f;
    }

    else {
        sizeY = windowRatio / viewRatio;
        posY = (1 - sizeY) / 2.f;
    }

    view.setViewport( sf::FloatRect(posX, posY, sizeX, sizeY) );

    return view;
}


int main() {
    auto lastShot = std::chrono::high_resolution_clock::now();
    bool isCooldown = false;
    std::vector<Entity*> enemyBuffer;

    Enemy* enemy = new Enemy(sf::Vector2f(500,500), 2, "resources/sprites/player.png", 20);
    enemy->lastHit = std::chrono::high_resolution_clock::now();
    enemyBuffer.push_back(enemy);

    Player player(sf::Vector2f(100,100), 8, "resources/sprites/player.png", 100);
    std::vector<Bullet*> bulletBuffer;
    sf::Sprite wallpaper;
    sf::Texture wallpaper_texture;
    wallpaper_texture.loadFromFile("resources/sprites/wallpaper.jpg");
    wallpaper.setTexture(wallpaper_texture);
    

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Shooter");
    window.setFramerateLimit(60);
    sf::View view(sf::FloatRect(0,0, 1000, 1000));
    view = getLetterboxView(view, 1000,1000);
    window.setView(view);
    InputHandler inputHandler;
    while(window.isOpen()) {

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Resized){
                view = getLetterboxView(view, event.size.width, event.size.height);
            }

            if(event.type == sf::Event::Closed)
            window.close();
        }
        
        Direction direction = inputHandler.getDirection();
        switch(direction) {
        case Direction::UP_LEFT:
        player.move(-player.getVerticalSpeed(), - player.getVerticalSpeed());
        break;
        case Direction::UP_RIGHT:
        player.move(player.getVerticalSpeed(), -player.getVerticalSpeed());
        break;
        case Direction::DOWN_LEFT:
        player.move(-player.getVerticalSpeed(), player.getVerticalSpeed());
        break;
        case Direction::DOWN_RIGHT:
        player.move(player.getVerticalSpeed(), player.getVerticalSpeed());
        break;
        case Direction::UP:
        player.move(0, player.getSpeed());
        break;
        case Direction::DOWN:
        player.move(0,-player.getSpeed());
        break;
        case Direction::LEFT:
        player.move(-player.getSpeed(), 0);
        break;
        case Direction::RIGHT:
        player.move(player.getSpeed(), 0);
        break;
        case Direction::NONE:
        break;
        }


        window.clear();
        window.draw(wallpaper);


        auto timeNow = std::chrono::high_resolution_clock::now();
        if((timeNow - lastShot) > std::chrono::milliseconds(200)) {
            isCooldown = false;
        }


        if(inputHandler.isShooting() && !isCooldown) {

        
        player.shoot(bulletBuffer, enemy->getPosition());
        
        
        lastShot = std::chrono::high_resolution_clock::now();
        isCooldown = true;
        }


        for(Entity* enemy: enemyBuffer)
        {
            if(!enemyBuffer.empty()) {
                enemy->setPosition(500,500);
                enemy->setHealthBar();
                enemy->drawEntity(window);
            }
        }

        for(Bullet* bullet : bulletBuffer)
        {
            if(bullet->getGlobalBounds().getPosition().x > 1000 || bullet->getGlobalBounds().getPosition().y > 1000)
            {
                bulletBuffer.erase(std::remove(bulletBuffer.begin(), bulletBuffer.end(), bullet), bulletBuffer.end());
                delete bullet;
            }
            else 
            {
            double speed = bullet->getSpeed();
            bullet->move(bullet->getTrajectory());
            bullet->drawEntity(window);
            
            if(!enemyBuffer.empty()) {
                if(detectCollision(bullet, enemy) && !bullet->hasHitEnemy(enemy)) {
                    enemy->setHealth(enemy->getHealth() - 2);
                    if(enemy->getHealth() <= 0) {
                        enemyBuffer.erase(std::find(enemyBuffer.begin(), enemyBuffer.end(), enemy));
                        delete enemy;
                    }
                    bullet->entitiesHit.push_back(enemy);
                }
            }
        }
    }
        window.setView(view);
        player.setHealthBar();
        player.drawEntity(window);
        drawDebugText(enemy, window);
        //ndow.draw(player);
        window.display();
    }
    return 0;
}

