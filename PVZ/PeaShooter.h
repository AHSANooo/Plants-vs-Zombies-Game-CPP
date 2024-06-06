#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include"Plant.h"
class Peashooter : public Plant {
protected:
    Clock bulletTime;
    Texture bulletTexture;
    Sprite bulletSprite[100];
    bool bulletLive[100];
    int totalBullets;
    int bullet;
    int positionX;
    int positionY;
    //  Weapon pea;
public:

    //Sprite fireSprite;
    Peashooter()
        : Plant("Images/Peashooter.png", "Peashooter", 100, 10, 10000, 10, 1.0f, 1){
    //  cout << "PeasShooter Created " << endl;
        if (!bulletTexture.loadFromFile("Images/pea.png")) {
            std::cout << "Failed to load texture from file: " << std::endl;
        }
        totalBullets = 100;
        bullet = 0;
        positionX = 0;
        positionY = 0;
        for (int i = 0; i < totalBullets; i++) {
            bulletLive[i] = 0;
        }
    }
    void moveBullets(RenderWindow& window) {
     //   cout << "MOVE BULLET CALLED for peashooter" << endl;
        if (bulletTime.getElapsedTime().asSeconds() >= 10) {
            if(!bulletLive[bullet]){
                if (bullet < totalBullets) {
                    // if(bulletLive[bullet] && initialBulletLive[bullet]){
//                    cout << "Al set " << endl;
                    bulletLive[bullet] = 1;
                    bulletSprite[bullet].setTexture(bulletTexture);
                    bullet++;
                    bulletTime.restart();
                }
            }
        }
        for (int i = 0; i < bullet; i++) {
            if(bulletLive[i]){
                if (bulletSprite[i].getPosition().x >= 1000) {
                    dieBullet(i);
                }
            bulletSprite[i].setPosition(bulletSprite[i].getPosition().x+1.0f, bulletSprite[i].getPosition().y);
            window.draw(bulletSprite[i]);
            }
        }
    }
    
    Sprite& getBullet(int a) {
       // cout << "GET BULLETS CALLED " << endl;
        return bulletSprite[a];
    }
    void dieBullet(int a) {
  //      cout << "DIE BULLET CALLED FOR A "<<a << endl;
        if(bulletLive[a]){
    //    cout << "BULLET " << a << "FALSED " << endl;
        bulletLive[a] = false;
        }
    }
    bool isBulletAlive(int a) {
        return bulletLive[a];
    }
    
    void ifPlantDies(bool a) {
    //    cout << "All BULLETS FALSE " << endl;
        if (!a) {
            for (int i = 0; i < 10; i++) {
                bulletLive[i] = 0;
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
      //  cout << "PEASHOOTER SETBULLET CALLED FOR (" << x << "," << y << ")" << endl;
        for (int i = 0; i < totalBullets; i++) {
            bulletSprite[i].setPosition(x+20, y);
        //    cout << "REPEATER SETBULLET CALLED FOR (" << bulletSprite[i].getPosition().x << "," << bulletSprite[i].getPosition().y << ")" << endl;
        }
    }
    Clock getPlantBulletClock() {
        return bulletTime;
    }
};

