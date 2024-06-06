#pragma once
#include <SFML/Graphics.hpp>
#include"Zombie.h"
#include"SimpleZombie.h"
#include"DancingZombies.h"
#include"FootballZombie.h"
#include"BalloonZombie.h"
#include<cstdlib>
#include<time.h>
#include"PartnerZombie.h"
class ZombieFactory
{
protected:
	int numOfZombies;
	int maxNumOfZombies;
	Zombie** zombies;
public:
	ZombieFactory(int a)
	{
		numOfZombies = 0;
		maxNumOfZombies = a;
		zombies = new Zombie * [a];
		for (int i = 0; i < a; i++) {
			zombies[i] = nullptr;
		}
	}
	~ZombieFactory()
	{
		for (int i = 0; i < 10; ++i)
		{
			delete zombies[i];
		}
		delete[] zombies;
	}

	int getMaxNumOfZombies()
	{
		return maxNumOfZombies;
	}
	Zombie*& getZombies(int x)
	{
		return zombies[x];
	}

	void setLevel1Zombies() {
		//cout << "SET ZOMBIES CALLED "<< maxNumOfZombies << endl;
		for (int i = 0; i < maxNumOfZombies; i++) {
			//cout << "IN SET LEVEL " << maxNumOfZombies << endl;
			if(i<6){
				zombies[i] = new SimpleZombie;
				zombies[i]->setZombiePosition(1015+i*400, 290);
			}
			else {
				zombies[i] = new SimpleZombie;
				zombies[i]->setZombiePosition(1500 + i * 200, 290);
			}
		}
	}



	void setLevel2Zombies() {
		//Original Coordinates of ZOmbuies 0of level2  
		//0-6 : Simple
		//6-14 : Football
		//15-19 : Balloon
	//	cout << "Level 2 Zombies called " << endl;
	//	cout << "NUMBER OF ZOMBIES : " << maxNumOfZombies << endl;
		for (int i = 0; i < maxNumOfZombies; i++) {
			if (i < 5) {
				zombies[i] = new SimpleZombie;
			}
			else if (i >= 5 && i < 12) {
				zombies[i] = new FootballZombie;
			}
			else if (i >= 12 && i <= 14) {
				zombies[i] = new BalloonZombie;
			}
			else if (i == 15) {
				zombies[i] = new DancingZombie;
			}
			else {
				zombies[i] = new PartnerZombie;
			}
		}
		//HardCoding the Values of Coordinates of Zombies
		//Simple
		zombies[0]->setZombiePosition(1100, 170);
		zombies[1]->setZombiePosition(1400, 290);
		zombies[2]->setZombiePosition(1700, 410);
		zombies[3]->setZombiePosition(1300, 170);
		zombies[4]->setZombiePosition(1900, 410);

		//Football
		zombies[5]->setZombiePosition(1500, 290);
		zombies[6]->setZombiePosition(2200, 290);
		zombies[7]->setZombiePosition(1215, 290);
		zombies[8]->setZombiePosition(1215, 410);
		zombies[9]->setZombiePosition(1215, 290);
		zombies[10]->setZombiePosition(1650, 290);
		zombies[11]->setZombiePosition(2000, 290);

		//Balloon
		zombies[12]->setZombiePosition(2200, 170);
		zombies[13]->setZombiePosition(2200, 410);
		zombies[14]->setZombiePosition(2300, 170);

		//Dancers 
		zombies[15]->setZombiePosition(1000, 290);

		//Dancing
		zombies[16]->dieZombie();
		zombies[16]->setZombieAlive(0);
		zombies[17]->dieZombie();
		zombies[17]->setZombieAlive(0);
		zombies[18]->dieZombie();
		zombies[18]->setZombieAlive(0);
		zombies[19]->dieZombie();
		zombies[19]->setZombieAlive(0);
		//cout << "Level 2 Zombies called " << endl;
		//cout << "NUMBER OF ZOMBIES : " << maxNumOfZombies << endl;
		//for (int i = 0; i < maxNumOfZombies; i++) {
		//	if (i < 5) {
		//		zombies[i] = new SimpleZombie;
		//	}
		//	if (i >= 5 && i < 12) {
		//		zombies[i] = new FootballZombie;
		//	}
		//	if (i >= 12 && i <= 14) {
		//		zombies[i] = new BalloonZombie;
		//	}
		//	if (i > 14 && i < 19) {
		//		zombies[i] = new PartnerZombie;
		//	}
		//	if (i == 19) {
		//		zombies[i] = new DancingZombie;
		//	}
		//}
		////HardCoding the Values of Coordinates of Zombies
		////Simple
		//zombies[0]->setZombiePosition(300, 170);
		//zombies[1]->setZombiePosition(300, 290);
		//zombies[2]->setZombiePosition(300, 410);
		//zombies[3]->setZombiePosition(1450, 170);
		//zombies[4]->setZombiePosition(1450, 410);

		////Football
		//zombies[5]->setZombiePosition(1500, 290);
		//zombies[6]->setZombiePosition(2200, 290);
		//zombies[7]->setZombiePosition(1215, 290);
		//zombies[8]->setZombiePosition(1215, 410);
		//zombies[9]->setZombiePosition(1215, 290);
		//zombies[10]->setZombiePosition(1650, 290);
		//zombies[11]->setZombiePosition(2000, 290);

		////Balloon
		//zombies[12]->setZombiePosition(2200, 170);
		//zombies[13]->setZombiePosition(2200, 410);
		//zombies[14]->setZombiePosition(2300, 170);

		////Partners 
		//zombies[15]->setZombiePosition(1450, 290);
		//zombies[16]->setZombiePosition(1650, 170);
		//zombies[17]->setZombiePosition(2000, 170);
		//zombies[18]->setZombiePosition(2000, 410);
		////Dancing
		//zombies[19]->setZombiePosition(2200, 290);
	}

	void setLevel3Zombies() {
			//cout << "SET ZOMBIES CALLED " << endl;
			
			zombies[0] = new SimpleZombie;
			zombies[0]->setZombiePosition(1150, 290);
			zombies[1] = new SimpleZombie;
			zombies[1]->setZombiePosition(1250, 530);
			zombies[2] = new SimpleZombie;
			zombies[2]->setZombiePosition(1300, 530);
			zombies[3] = new SimpleZombie;
			zombies[3]->setZombiePosition(1200, 50);
			zombies[4] = new SimpleZombie;
			zombies[4]->setZombiePosition(1350, 170);
			zombies[5] = new SimpleZombie;
			zombies[5]->setZombiePosition(1400, 530);
			zombies[6] = new SimpleZombie;
			zombies[6]->setZombiePosition(1450, 290);
			zombies[7] = new SimpleZombie;
			zombies[7]->setZombiePosition(1600, 50);
			zombies[8] = new SimpleZombie;
			zombies[8]->setZombiePosition(1700, 530);
			zombies[9] = new FootballZombie;
			zombies[9]->setZombiePosition(1800, 170);
			zombies[10] = new FootballZombie;
			zombies[10]->setZombiePosition(2000, 410);
			zombies[11] = new FootballZombie;
			zombies[11]->setZombiePosition(1850, 290);
			zombies[12] = new FootballZombie;
			zombies[12]->setZombiePosition(1900, 50);
			zombies[13] = new FootballZombie;
			zombies[13]->setZombiePosition(2100, 530);
			zombies[14] = new FootballZombie;
			zombies[14]->setZombiePosition(1600, 170);
			zombies[15] = new FootballZombie;
			zombies[15]->setZombiePosition(2200, 290);
			zombies[16] = new BalloonZombie;
			zombies[16]->setZombiePosition(1950, 410);
			zombies[17] = new BalloonZombie;
			zombies[17]->setZombiePosition(2200, 530);
			zombies[18] = new BalloonZombie;
			zombies[18]->setZombiePosition(2300, 50);
			zombies[19] = new BalloonZombie;
			zombies[19]->setZombiePosition(2450, 290);
			zombies[20] = new BalloonZombie;
			zombies[20]->setZombiePosition(2150, 170);
			zombies[21] = new DancingZombie;
			zombies[21]->setZombiePosition(1015, 410);//(2400, 410);
			zombies[22] = new PartnerZombie;
			zombies[23] = new PartnerZombie;
			zombies[24] = new PartnerZombie;
			zombies[25] = new PartnerZombie;
			zombies[22]->setZombiePosition(750, 410);
			zombies[22]->dieZombie();
			zombies[22]->setZombieAlive(0);
			zombies[23]->setZombiePosition(550, 410);
			zombies[23]->dieZombie();
			zombies[23]->setZombieAlive(0);
			zombies[24]->setZombiePosition(650, 530);
			zombies[24]->dieZombie();
			zombies[24]->setZombieAlive(0);
			zombies[25]->setZombiePosition(650, 290);
			zombies[25]->dieZombie();
			zombies[25]->setZombieAlive(0);
			zombies[26] = new SimpleZombie;
			zombies[26]->setZombiePosition(2350, 170);
			zombies[27] = new FootballZombie;
			zombies[27]->setZombiePosition(2350, 290);
			zombies[28] = new FootballZombie;
			zombies[28]->setZombiePosition(2350, 4100);
			zombies[29] = new SimpleZombie;
			zombies[29]->setZombiePosition(2350, 530);
		}


};
