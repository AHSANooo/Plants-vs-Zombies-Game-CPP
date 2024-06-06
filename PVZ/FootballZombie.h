#pragma once
#include <SFML/Graphics.hpp>
#include"Zombie.h"

class FootballZombie :public Zombie
{
public:
	bool UP;
	bool DOWN;
	Clock moveLeft;
	Clock moveRight;
	Clock moveStraight;
	

public:
	FootballZombie() :Zombie(11, 0.25, 10,0.25,7, 0.3571428571428571,0.1, "FootballZombie",6)
	{
		//cout << "FootballZombie created" << endl;
		UP = true;
		DOWN = false;
	}
	void moveZombie(int a) {
		if (move && !eat && !boom && alive && !drop) {
			
			
			
			 if (a == 2)//MoveMent for Level 2
			{

				static int y = zombieSprite.getPosition().y;
		//		cout << "Y IS " << y << endl;

				if (UP && !DOWN) {
					zombieSprite.setPosition(zombieSprite.getPosition().x - speed, zombieSprite.getPosition().y - speed);
				}
				if (DOWN && !UP) {
					zombieSprite.setPosition(zombieSprite.getPosition().x - speed, zombieSprite.getPosition().y + speed);
				}
				if (static_cast<int>(zombieSprite.getPosition().y) == y - 120 || static_cast<int>(zombieSprite.getPosition().y) <= 170) {
			//		cout << "SET TO DOWN " << endl;
					UP = false;
					DOWN = true;
				}

				if (static_cast<int>(zombieSprite.getPosition().y) == y + 120 || static_cast<int>(zombieSprite.getPosition().y) >= 410) {
				//	cout << "SET TO UP " << endl;
					UP = true;
					DOWN = false;
				}
			}
			 else if (a == 3) {
				 static int y = zombieSprite.getPosition().y;
				// cout << "Y IS " << y << endl;

				 if (UP && !DOWN) {
					 zombieSprite.setPosition(zombieSprite.getPosition().x - speed, zombieSprite.getPosition().y - speed);
				 }
				 if (DOWN && !UP) {
					 zombieSprite.setPosition(zombieSprite.getPosition().x - speed, zombieSprite.getPosition().y + speed);
				 }
				 if (static_cast<int>(zombieSprite.getPosition().y) == y - 120 || static_cast<int>(zombieSprite.getPosition().y) <= 50) {
					// cout << "SET TO DOWN " << endl;
					 UP = false;
					 DOWN = true;
				 }

				 if (static_cast<int>(zombieSprite.getPosition().y) == y + 120 || static_cast<int>(zombieSprite.getPosition().y) >= 530) {
					// cout << "SET TO UP " << endl;
					 UP = true;
					 DOWN = false;
				 }
			 }

		}
	}
};
