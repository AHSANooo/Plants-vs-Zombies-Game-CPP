#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include"Plant.h"

class WallNut :public Plant
{
protected:
    const int numOfTextures;
    Clock moveTimer;
    Texture moveTexture[4];
    int current;
    float textureChangeInterval;
    Sprite  moveWallnutSprite;
    int positionX;
    int positionY;
    bool moveRight;
    bool moveLeft;
public:
    WallNut() :Plant("Images/wall1.png", "WallNut", 50, 10, 150, 10, 1.0f, 1), numOfTextures(4)
    {
        textureChangeInterval = 1.0f;
        current = 0;
       // cout << "WallNut created" << endl;
        moveRight = 0;
        moveLeft = 0;
        for (int i = 0; i < 4; ++i)
        {
            if (!moveTexture[i].loadFromFile("Images/wallnut" + std::to_string(i + 1) + ".png"))
            {
                cout << "Error loading image" << endl;
            }
        }
        moveWallnutSprite.setTexture(moveTexture[0]); // Set initial texture
        //moveWallnutSprite.setPosition(250, 250);
    }
    void setWallnut(int x, int y) {
        moveWallnutSprite.setPosition(x, y);
    }
    void moveBullets(RenderWindow& window) override{
        if (!moveLeft && !moveRight)
        {
            moveWallnutSprite.move(0.2, 0);
            if (moveWallnutSprite.getPosition().x >= 1015) {
                alive = false;
            }
        }
        else {
            if (moveRight)
                moveWallnutSprite.move(0.2, 0.2);
            if(moveLeft)
                moveWallnutSprite.move(0.2, -0.2);
            if (moveWallnutSprite.getPosition().x >= 1015) {
                alive = false;
            }
        }
            //    cout << "UPDATE CALLED " << endl;
        if (moveTimer.getElapsedTime().asSeconds() >= 0.5)
        {
            current = (current + 1) % 4;
            moveWallnutSprite.setTexture(moveTexture[current]);
            //moveWallnutSprite.setPosition(x, y);
            //moveSprite.setPosition(moveSprite.getPosition().x + 0.3f, moveSprite.getPosition().y);
            //moveSprite.setPosition(x, y);
            moveTimer.restart();
        }
        //moveSprite.setPosition(x, y);
        //moveSprite.setPosition(moveSprite.getPosition().x + 0.3f, moveSprite.getPosition().y);


        window.draw(moveWallnutSprite);
        // moveSprite.setPosition(moveSprite.getPosition().x + 0.3f, moveSprite.getPosition().y);
       // drawBullets(window);
    }
    /*void drawBullets(RenderWindow& window) override
    {
        cout << "Draw Bullets Called " << endl;
        window.draw(moveWallnutSprite);
    }*/
    Sprite& getBullet(int a) {
       return  moveWallnutSprite;
    }
    void dieBullet(int a) {
        //cout << "Hello" << endl;
    }
    bool isBulletAlive(int a) {
        return  1;
    }
    void ifPlantDies(bool a) {
        //cout << "NO " << endl;
    }
    int getBulletXPosition(int a) {
        return positionX;
    }
    int getBulletYPosition(int b) {
        return positionY;
    }
    void SetAllBullets(int x, int y) {
        //cout << "No Bullets For WallNut" << endl;
    }
    Clock getPlantBulletClock() {
        return moveTimer;
    }
    void setWallNutDirection(bool a) {
        if (a == 0) {
            moveRight = true;
            moveLeft = false;
        }
        if (a == 1) {
            moveLeft = true;
            moveRight = false;
        }
    }
    bool getMoveLeft() {
        return moveLeft;
    }
    bool getMoveRight() {
        return moveRight;
    }

   
};
