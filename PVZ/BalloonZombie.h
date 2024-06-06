#pragma once
#include <SFML/Graphics.hpp>
#include"Zombie.h"
class BalloonZombie :public Zombie {
public:
	BalloonZombie() : Zombie(41,0.04,24,0.04,28,0.09,0.07,"BalloonZombie",12)
	{
		//cout << "BalloonZombieCreated" << endl;
	}
	void moveZombie(int a) {
		if (move && !eat && !boom && alive && !drop)
		zombieSprite.setPosition(zombieSprite.getPosition().x - speed, zombieSprite.getPosition().y);
	}
};
