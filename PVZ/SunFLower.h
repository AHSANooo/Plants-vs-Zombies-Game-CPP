#pragma once
#include <SFML/Graphics.hpp>
#include"Plant.h"

class SunFlower : public Plant {
protected:
    Clock sunclock;
    Texture sunTexture;
    Sprite sunSprite[100];
    int totalSuns;
    int suns;
    bool aliveSun[100];
    int positionX;
    int positionY;

public:
    SunFlower() : Plant("Images/SunFlower2.gif", "SunFlower", 50, 10, 10000, 10, 1.0f, 1) {
        cout << "Sunflower created " << endl;
        if (!sunTexture.loadFromFile("Images/sun.png")) {
            std::cout << "Failed to load texture from file: " << std::endl;
        }
        totalSuns = 100;
        suns = 0;
        for (int i = 0; i < totalSuns; i++) {
            aliveSun[i] = 0;
        }
    }

    void moveBullets(RenderWindow& window) {
        //cout << "UPDATE CALLED for SunFlower" << endl;
        if (sunclock.getElapsedTime().asSeconds() >= 10)
        {
            if (suns < totalSuns)
            {
                sunSprite[suns].setTexture(sunTexture);
                aliveSun[suns] = 1;
                suns++;
                sunclock.restart();

            }
        }
        drawBullets(window);
    }

    void drawBullets(RenderWindow& window)
    {
        //cout << "Draw Bullets Called for Sun" << endl;
        for (int i = 0; i < suns; i++)
        {
            if(aliveSun[i])
            window.draw(sunSprite[i]);
        }
    }

    void setSunSpritePosition(int x, int y) {
       // cout << "SET SUN CALLED " << endl;
        for (int i = 0; i < totalSuns; i++) {
            sunSprite[i].setPosition(x, y);
        }
    }
    Sprite& getSprite(int x) {
        return sunSprite[x];
    }
    bool getSunAlive(int x) {
        return aliveSun[x];
    }
    void setSunAlive(int x,bool b) {
        //cout << "Sun Dead" << endl;
        aliveSun[x] = b;
    }
    Sprite& getBullet(int a) {
        return  sunSprite[a];
    }
    void dieBullet(int a) {
        aliveSun[a] = 0;
    }
    bool isBulletAlive(int a) {
        return aliveSun[a];
    }
    void ifPlantDies(bool a) {
       // cout << "All BULLETS FALSE " << endl;
        if (!a) {
            for (int i = 0; i < totalSuns; i++) {
                aliveSun[i] = 0;
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
      //  cout << "Set Bullet called for SunFlower " << endl;
        positionX = x;
        positionY = y;
        for (int i = 0; i < totalSuns; i++) {
            sunSprite[i].setPosition(x , y);
        }
    }
    Clock getPlantBulletClock() {
        return sunclock;
    }
};

