#pragma once
//#include <SFML/Graphics.hpp>
//#include"Zombie.h"

//class DancingZombie :public Zombie
//{
//public:
//	DancingZombie() :Zombie(10, 0.25, 10,0.5,10, 1.0,0.3, "DancingZombie",6)
//	{
//		cout << "Dancing Zombie Created" << endl;
//	}
//};

#pragma once
#include <SFML/Graphics.hpp>
#include"Zombie.h"
//#include"Partner.h"

class DancingZombie :public Zombie
{
	//protected:
	
	//	PartnerZombie partner[4];
public:
	DancingZombie() :Zombie(22, 0.25, 11, 0.25, 12, 0.25, 0.1, "DancingZombie", 6)
	{
	//	cout << "Dancing Zombie Created" << endl;
	}
	//void drawpartners(RenderWindow& window)
	//{
	//	//cout << "dancing zombie position is" << getZombiePositionX()<< endl;
	//	partner[0].setPosition(getZombiePositionX() + 80, getZombiePositionY());
	//	partner[0].update();
	//	//partner[0].setPosition(100, 100);
	//	partner[0].drawzombies(window);
	//	partner[1].setPosition(getZombiePositionX() - 80, getZombiePositionY());
	//	//partner[1].setPosition(50,50);
	//	partner[1].drawzombies(window);
	//	partner[2].setPosition(getZombiePositionX(), getZombiePositionY() + 120);
	//	partner[2].drawzombies(window);
	//	partner[3].setPosition(getZombiePositionX(), getZombiePositionY() - 120);
	//	partner[3].drawzombies(window);
	//}
	//void update()
	//{}
	void moveZombie(int a) {
		if (move && !eat && !boom && alive && !drop) {

		
		zombieSprite.setPosition(zombieSprite.getPosition().x - speed, zombieSprite.getPosition().y);
		}
		
	}
};
