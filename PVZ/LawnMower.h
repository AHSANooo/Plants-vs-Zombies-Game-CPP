#pragma once
#include <SFML/Graphics.hpp>
class LawnMower
{
	Sprite lawnMowerSprite;
	Texture lawnMowerTexture;
	int noOfLawnMowers;
	float speed;
	bool present;
	int positionX;
	int positionY;
	bool move;
	bool alive;
public:
	LawnMower() :speed(0.2f), present(true), positionX(195), positionY(285)
	{
		if (!lawnMowerTexture.loadFromFile("Images/car.png"))
		{
			cout << "Error loading image" << endl;
		}
		lawnMowerSprite.setTexture(lawnMowerTexture);
		noOfLawnMowers = 0;
		positionX = 0;
		positionY = 0;
		speed = 0;
		alive = true;
		move = false;
	}
	void setLawnMower(int x,int y) {
	//	cout << "St lwnmwer " << endl;
		positionX = x;
		positionY = y;
		noOfLawnMowers++;
		lawnMowerSprite.setPosition(x, y);
	}
	
	
	void draw(sf::RenderWindow& window)
	{
		if(alive)
			window.draw(lawnMowerSprite);
	
	}
	int getSize() {
		cout << noOfLawnMowers << endl;
		return noOfLawnMowers;
	}
	void setSize(int a) {
		noOfLawnMowers = a;
	}
	Sprite& getSprite()
	{
		return lawnMowerSprite;
	}
	void setMove(bool a) {
		move = a;
	}
	bool getMove() {
		return move;
	}
	void moveLawnMower() {
		if (lawnMowerSprite.getPosition().x <= 1000) {
			lawnMowerSprite.setPosition(lawnMowerSprite.getPosition().x + 0.5, lawnMowerSprite.getPosition().y);
			lawnMowerSprite.move(1, 0);
		}
		else {
			alive = false;
		}
	}
	void setAlive(bool a) {
		alive = a;
	}
	bool getAlive() {
		return alive;
	}
};
