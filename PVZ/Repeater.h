#pragma once
#include <SFML/Graphics.hpp>
#include"Plant.h"
class Repeater : public Plant
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
    Repeater() : Plant("Images/repeater.png", "Repeater", 200, 10, 10000, 100, 1.0f, 1)
    {
//        cout << "Repeater Created " << endl;
        if (!bulletTexture.loadFromFile("Images/pear.png")) {
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

    void moveBullets(RenderWindow& window)
    {
      //  cout << "UPDATE CALLED FOE REPEATER" << endl;
        if (bulletTime.getElapsedTime().asSeconds() >= 3) {
          
            if (!bulletlive[bullet]) {
                if (bullet < totalBullets) {
                    bulletSprite[bullet].setTexture(bulletTexture);
                    //   bulletSprite[bullet].setPosition(x + 20, y);
                    bulletlive[bullet] = 1;
                    bullet++;
                    bulletTime.restart();
                }
            }

        }
        for (int i = 0; i < totalBullets; i++) {
            if (bulletlive[i]) {
                if (bulletSprite[i].getPosition().x >= 1000) {
                    //bulletLive[i] = false;
                    dieBullet(i);
                }
                bulletSprite[i].setPosition(bulletSprite[i].getPosition().x + 1.0f, bulletSprite[i].getPosition().y);
                window.draw(bulletSprite[i]);
            }
        }
            //drawBullets(window);
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
       /// cout << "REPEATER SETBULLET CALLED FOR (" << x << "," << y << ")" << endl;
        positionX = x;
        positionY = y;
        for (int i = 0; i < totalBullets; i++) {
            bulletSprite[i].setPosition(x + 20, y);
     //       cout << "REPEATER SETBULLET CALLED FOR (" << bulletSprite[i].getPosition().x << "," << bulletSprite[i].getPosition().y << ")" << endl;
        }
    }
    Clock getPlantBulletClock() {
        return bulletTime;
    }
};
