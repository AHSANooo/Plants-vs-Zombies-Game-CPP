#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include"Plant.h"



class CherryBomb : public Plant {
private:
    Clock blastTime;
    Texture blastTexture;
    Sprite blastSprite;
    bool exploded;
    int positionX;
    int positionY;
    Clock blastLastingTexture;
    bool vanished = false;
public:
    CherryBomb() : Plant("Images/cherry.png", "CherryBomb", 200, 10, 150, 10, 1.0f, 1), exploded(false) {
      //  cout << "Cherry Bomb created" << endl;
        if (!blastTexture.loadFromFile("Images/cherrybombblast.png")) {
            std::cout << "Failed to load texture from file" << std::endl;
        }
        blastSprite.setTexture(blastTexture);
    }

    void moveBullets(RenderWindow& window) {
        if (!exploded && blastTime.getElapsedTime().asSeconds() >= 3.5 ) {
           // cout << "Time for Explosion" << endl;
            // Set the position of the explosion relative to the CherryBomb's position
            blastSprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - 20);
            exploded = true;
            blastLastingTexture.restart();
            //cout << "Explosion set to " << exploded << endl;
            //cout << "CHERRY AT (" << positionX << "," << positionY<<")" << endl;
        //    blastTime.restart();
           // sprite.setPosition(-500, -500);
        }
        if (exploded && !vanished) {
            window.draw(blastSprite);
        }
        else {
            window.draw(sprite);
        }
        if (exploded && !vanished) {
            if (blastLastingTexture.getElapsedTime().asSeconds() > 3) {
                vanished = true;
                alive = false;
          //      cout << "VANISHED " << endl;
            }
        }
        //drawBullets(window);
    }

    /*void drawBullets(RenderWindow& window) {
        if (exploded) {
            window.draw(blastSprite);
        }
        else {
            window.draw(sprite);
        }
    }*/
    Sprite& getBullet(int a) {
        return blastSprite;
    }
    void dieBullet(int a) {
        //cout << "Hello " << endl;
    }
    bool isBulletAlive(int a) {
        return 1;
    }
    void ifPlantDies(bool a) {
      //  cout << "NO" << endl;
    }
    int getBulletXPosition(int a) {
        return positionX;
    }
    int getBulletYPosition(int b) {
        return positionY;
    }
    void SetAllBullets(int x, int y) {
        positionX = x;
        positionY = y;
    }
    Clock getPlantBulletClock() {
        return blastTime;
    }
    bool isCherryExploded() {
        return exploded;
    }
    bool isCherryVanished() {
        return vanished;
    }
    
};

