#pragma once
#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Plant {
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    std::string name;
    int cost;
    int rechargeTime; 
    int health;
    int damage;
    int range;
    bool alive;
    bool eat;
    int xCoordinate;
    int yCoordinate;



    
public:
    // Default constructor
    Plant() : name(""), cost(0), rechargeTime(0), health(0), damage(0), range(0), alive(false) {}

    // Parameterized constructor
    Plant(const string& texturePath, const string& name, int cost, int rechargeTime, int health, int damage, float r, bool b)
        : name(name), cost(cost), rechargeTime(rechargeTime), health(health), damage(damage), range(r), alive(b) {
        string fullPath = texturePath;
        if (!texture.loadFromFile(fullPath)) {
            cout << "Failed to load texture from file: " << fullPath << std::endl;
        }
        sprite.setTexture(texture);
    //    sprite.setPosition(10000, 10000);
        xCoordinate = 0;
        yCoordinate = 0;
        sprite.setPosition(xCoordinate, yCoordinate);
        eat = false;
        

        //window.draw(sprite);
    }
    bool isEatTrue() {
        return eat;
    }
    Sprite& getSprite() {
        return sprite;
    }

    // Getters
    bool isAlive() {
        return alive;
    }
    virtual bool isBulletAlive(int a) = 0;
   // virtual bool getBulletAlie(int a) = 0;
    void setPlantAlive(bool b) {
        alive = b;
    }
    bool getPlantAlive() {
        return alive;
    }
  //  virtual void drawBullets(RenderWindow& window) = 0;
    virtual Sprite& getBullet(int a) = 0;
    virtual void dieBullet(int a) = 0;

    virtual void moveBullets(RenderWindow& window) = 0;

    std::string getName() const { return name; }
    int getCost() const { return cost; }
    int getRechargeTime() const { return rechargeTime; }
    void setPlant(int a, int b) {
        xCoordinate = a;
        yCoordinate = b;
        sprite.setPosition(xCoordinate, yCoordinate);
    }
    int getPlantY() {
        return yCoordinate;
    }
    int getPlantX() {
        return xCoordinate;
    }

    bool decreaseHealth() {
        health--;
        if (health == 0) {
            alive = false;
            return true;
        }
        else {
            return false;
        }
    }
    virtual void ifPlantDies(bool a) = 0;
    virtual int getBulletXPosition(int a) = 0;
    virtual int getBulletYPosition(int b) = 0;
    virtual void SetAllBullets(int x,int y) = 0;
    virtual Clock getPlantBulletClock() = 0;

};