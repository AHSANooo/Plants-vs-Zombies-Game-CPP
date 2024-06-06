#pragma once
#include <SFML/Graphics.hpp>
#include"Plant.h"

class SnowPea :public Plant
{
protected:
    Clock bulletTime;
    Texture bulletTexture;
    Sprite bulletSprite[100];
    int totalBullets;
    int bullet;
    bool bulletlive[100];
    int positionX;
    int positionY;

public:
    SnowPea() 
        :Plant("Images/snow.png", "SnowPea", 175, 10, 10000, 10, 1.0f, 1)
    {
//        cout << "Snowpea Created " << endl;
        if (!bulletTexture.loadFromFile("Images/spea.png")) {
            std::cout << "Failed to load texture from file: " << std::endl;
        }
        totalBullets = 100;
        bullet = 0;
        positionX = 0;
        positionY = 0;
        for (int i = 0; i < totalBullets; i++) {
            bulletlive[i] = 0;
        }
    }
    void moveBullets( RenderWindow& window) {
        if (bulletTime.getElapsedTime().asSeconds() >= 3) {
            if (!bulletlive[bullet]) {
                if (bullet < totalBullets) {
                    // if(bulletLive[bullet] && initialBulletLive[bullet]){
  //                  cout << "Al set " << endl;
                    bulletlive[bullet] = 1;
                    bulletSprite[bullet].setTexture(bulletTexture);
                    bullet++;
                    bulletTime.restart();
                }
            }
        }
        for (int i = 0; i < bullet; i++) {
            if (bulletlive[i]) {
                if (bulletSprite[i].getPosition().x >= 1000) {
                    //bulletLive[i] = false;
                    dieBullet(i);
                }
                bulletSprite[i].setPosition(bulletSprite[i].getPosition().x + 1.0f, bulletSprite[i].getPosition().y);
                window.draw(bulletSprite[i]);
            }
        }
    }
    
    Sprite& getBullet(int a) {
        return bulletSprite[a];
    }
    void dieBullet(int a) {
        bulletlive[a] = 0;
    }
    bool isBulletAlive(int a) {
        return bulletlive[a];
    }
    void ifPlantDies(bool a) {
        if (!a) {
            for (int i = 0; i < 10; i++) {
                bulletlive[i] = 0;
            }
        }
    }
    int getBulletXPosition(int a) {
        return positionX;
    }
    int getBulletYPosition(int b) {
        return positionY;
    }
    void SetAllBullets(int x, int y) {
       /// cout << "SNowPea SETBULLET CALLED FOR (" << x << "," << y << ")" << endl;
        positionX = x;
        positionY = y;
        for (int i = 0; i < totalBullets; i++) {
            bulletSprite[i].setPosition(x + 20, y);
     //       cout << "SNowPea SETBULLET CALLED FOR (" << bulletSprite[i].getPosition().x << "," << bulletSprite[i].getPosition().y << ")" << endl;
        }
    }
   
    Clock getPlantBulletClock() {
        return bulletTime;
    }
};
