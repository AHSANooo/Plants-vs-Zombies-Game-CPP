#pragma once
#include <SFML/Graphics.hpp>
#include"Zombie.h"
class SimpleZombie :public Zombie {
public:
	SimpleZombie() : Zombie(18, 0.25,20,0.25,10,0.25, 0.02,"SimpleZombie",4)
	{
//		cout << "SimpleZOmbieCreated" << endl;
	}
	void moveZombie(int a) {
		if (move && !eat && !boom && alive && !drop) 
		zombieSprite.setPosition(zombieSprite.getPosition().x - speed, zombieSprite.getPosition().y);
	}
};
