#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include"Zombie.h"

using namespace sf;
using namespace std;

//class PartnerZombie
//{
//	Sprite partnerSprite;
//	Texture* partnerTexture;
//	Clock frametime;
//	int currentindex;
//	int posX;
//	int posY;
//public:
//	PartnerZombie()
//	{
//		currentindex = 0;
//		partnerTexture = new Texture[3];
//		for (int i = 0; i < 3; ++i)
//		{
//			if (!partnerTexture[i].loadFromFile("Images/partner"+to_string(i+1)+".png"))
//			{
//				cout << "error loading texture" << endl;
//			}
//			partnerSprite.setTexture(partnerTexture[currentindex]);
//		}
//	}
//	void setPosition(int x, int y)
//	{
//		posX = x;
//		posY = y;
//	}
//	
//	void update()
//	{
//		cout << "moving partner" << endl;
//		partnerSprite.move(-5, 0);
//	}
//
//	void drawzombies(RenderWindow& window)
//	{
//		
//		//cout<<"drawing partner sprites"<<endl;
//		if (frametime.getElapsedTime().asSeconds() >= 1) {
//			currentindex = (currentindex + 1) % 3;
//			partnerSprite.setTexture(partnerTexture[currentindex]);
//			frametime.restart();
//		}
//		partnerSprite.setPosition(posX, posY+40);
//		window.draw(partnerSprite);
//	}
//};

class PartnerZombie :public Zombie
{
public:
	PartnerZombie() :Zombie(22, 0.25,9, 0.25,20,0.08,0.1, "PartnerZombie",6)
	{
//		cout << "Partner zombie created" << endl;
	}
	void moveZombie(int a) {
		if (move && !eat && !boom && alive && !drop)
		zombieSprite.setPosition(zombieSprite.getPosition().x - speed, zombieSprite.getPosition().y);
	}
};
