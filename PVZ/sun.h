#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include "menus.h"
#include<iostream>
using namespace sf;
using namespace std;
class Sun
{
	int maxSun;
	Sprite sunSprite[20];
	//Sprite sunSprite;
	Texture sunTexture;
	int sunCount;
	Clock sunClock;
	float sunx[20];
	float suny[20];
	bool alive[20] = { false };
	float speed;
public:
	Sun()
	{
		maxSun = 20;
		sunCount = 0;
		speed = 0.5;
		if (!sunTexture.loadFromFile("Images/sun.png"))
		{
		//	cout << "error loading text" << endl;
			return;
		}
		
	//	cout << "sun texture loaded" << endl;

		//sunSprite.setPosition(100, 100);*/
	}


	void spawnSun()
	{
		//cout << "spawning sun" << endl;
		if (sunClock.getElapsedTime().asSeconds() >= 10)
		{
			if (sunCount < 20)
			{
				if (!alive[sunCount])
				{
					sunSprite[sunCount].setTexture(sunTexture);
					//cout << "setting to true" << endl;
					sunx[sunCount] = static_cast<float>((rand() % 1100));
					if (sunx[sunCount] < 250) {
						sunx[sunCount] + 250;
					}
					suny[sunCount] = -static_cast<float>(sunTexture.getSize().y);
					//suny[sunCount] = 0;
					sunSprite[sunCount].setPosition(sunx[sunCount], suny[sunCount]);
					alive[sunCount] = true;
					sunCount++;
					// break;
				}
			}
			sunClock.restart();
		}
		for (int i = 0; i < maxSun; ++i)
		{
			sunx[i] = sunSprite[i].getPosition().x;
			suny[i] += 0.1f;
			sunSprite[i].setPosition(sunx[i], suny[i]);
		}
	}

	void clicked(int mouseX, int mouseY, int& score,int &totalScore)
	{
		for (int i = 0; i < maxSun; ++i)
		{
			int sunLeft = static_cast<int>(sunx[i]);
			int sunRight = sunLeft + 45;
			int sunTop = static_cast<int>(suny[i]);
			int sunBottom = sunTop + 45;

			if (alive[i] && mouseX >= sunLeft && mouseX <= sunRight && mouseY >= sunTop && mouseY <= sunBottom)
			{
				alive[i] = false;
				score += 150;
				totalScore += 100;
				break;
			}
		}
	}

	void draw(RenderWindow& window)
	{
		for (int i = 0; i < maxSun; ++i)
		{
			if (alive[i])
			{
				/*cout << "inside if to draw" << endl;
				sunSprite[i].setPosition(sunx[i], suny[i]);*/
				window.draw(sunSprite[i]);
			}
			//cout << "drawing suns" << endl;
			//window.draw(sunSprite[i]);
		}
		//window.draw(sunSprite);
		//cout << "sun drawn" << endl;
	}
};
