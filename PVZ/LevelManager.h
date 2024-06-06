#pragma once
#include <SFML/Graphics.hpp>
//#include"PeaShooter.h"
#include"PlantFactory.h"
#include"ZombieFactory.h"
//#include"SimpleZombie.h"
//#include"SunFLower.h"
//#include"Wallnut.h"
#include"LawnMower.h"
class LevelManager
{
protected:
	LawnMower* lm;
	PlantFactory* pf;
	ZombieFactory* zf;
	sf::Texture texture;
	sf::Sprite sprite;
	string name;
public:
	//PlantFactory* pf;
	LevelManager()
	{
		lm = nullptr;
		pf = nullptr;
		name = "";
		zf = nullptr;
	}
	LevelManager(const string& texturePath, const string& name) {
		if (!texture.loadFromFile(texturePath)) {
			std::cout << "Failed to load texture from file: " << texturePath << endl;
		}
		this->name = name;
		if (name == "BeginnerGarden") {
		//	cout << "IF IS TRUE " << endl;
			pf = new PlantFactory(9);
			lm = new LawnMower[1];
			zf = new ZombieFactory(10);
			zf->setLevel1Zombies();
			lm->setSize(1);
			lm[0].setLawnMower(180, 340);
		}
		else if (name == "ZombieOutSkirts") {
			pf = new PlantFactory(20);
			lm = new LawnMower[3];
			zf = new ZombieFactory(20);
			zf->setLevel2Zombies();
			lm->setSize(3);
			lm[0].setLawnMower(180, 220);
			lm[1].setLawnMower(180, 340);
			lm[2].setLawnMower(180, 450);

		}
		else if(name == "SunFLowerField") {
			pf = new PlantFactory(45);
			lm = new LawnMower[5];
			zf = new ZombieFactory(30);
			zf->setLevel3Zombies();
			lm->setSize(5);
			lm[0].setLawnMower(180, 110);
			lm[1].setLawnMower(180, 220);
			lm[2].setLawnMower(180, 340);
			lm[3].setLawnMower(180, 450);
			lm[4].setLawnMower(180, 570);

		}
		sprite.setTexture(texture);
		
	}
	Sprite& getBackgroud() {
		return sprite;
	}
	PlantFactory*& getPlantFactory() {
		return pf;
	}
	ZombieFactory*& getZombieFactory() {
		return zf;
	}
	void drawPlants(RenderWindow& window) {
		for (int i = 0; i < getPlantFactory()->getNumberOfPlants(); i++) {
			if(getPlantFactory()->getPlants(i)->isAlive()){
			if(getPlantFactory()->getPlants(i)->getName()!="WallNut"
				&& getPlantFactory()->getPlants(i)->getName()!="CherryBomb")
			window.draw(getPlantFactory()->getPlants(i)->getSprite());
			}
		}
	}
	void drawZombies(RenderWindow& window)
	{
	//	cout << "Draw Zombies Called " << endl;
		for (int i = 0; i < zf->getMaxNumOfZombies(); i++)
		{
		//	cout << "MAX ZOMBIES " << zf->getMaxNumOfZombies() << endl;
		//	if(zf->getZombies(i)->isZombieRip())
			zf->getZombies(i)->update(window);
			if (name == "BeginnerGarden") {
			zf->getZombies(i)->moveZombie(1);

			}
			if (name == "ZombieOutSkirts") {
				zf->getZombies(i)->moveZombie(2);
			}
			if (name == "SunFLowerField") {
				zf->getZombies(i)->moveZombie(3);
			}
		}
	}

	String getName() {
		return name;
	}
	void drawBullets(RenderWindow& window) {
		for (int i = 0; i < getPlantFactory()->getNumberOfPlants(); i++)
		{
			if(getPlantFactory()->getPlants(i)->getPlantAlive())
			getPlantFactory()->getPlants(i)->moveBullets(window);
		}
	}
	//virtual void handlEvent(Event event, RenderWindow& window, LevelManager*& level1, int& score,int a) = 0;
	virtual void handleEvent(Event event, RenderWindow& window, LevelManager*& level1, int& score,int &totalScore) = 0;
	virtual void ShowAvailablePlants(RenderWindow& window) = 0;
	virtual void playLevel(RenderWindow& window, int& score,LevelManager* level1,int& lives) = 0;
	void drawLawnMowersLevel1(RenderWindow& window) {
		for (int i = 0;i<1; i++) {
			lm[i].draw(window);
		}
	}
	void drawLawnMowersLevel2(RenderWindow& window) {
		for (int i = 0; i < 3; i++) {
			lm[i].draw(window);
		}
	}
	void drawLawnMowersLevel3(RenderWindow& window) {
		for (int i = 0; i < 5; i++) {
			lm[i].draw(window);
		}
	}
	
	void checkCollision() {
		for (int i = 0; i < pf->getNumberOfPlants(); i++) { //i refer to plant
			for (int j = 0; j < 100; j++) {//j refer to bullets
				for (int k = 0; k < zf->getMaxNumOfZombies(); k++) {//K refer to Zombies
					int zombieX = zf->getZombies(k)->getSprite().getPosition().x;
					int zombieY = zf->getZombies(k)->getSprite().getPosition().y;
					int plantX = pf->getPlants(i)->getSprite().getPosition().x;
					int plantY = pf->getPlants(i)->getSprite().getPosition().y;
					
					//Stopping Zombie to eat plant and then letting him Go
					if (pf->getPlants(i)->isAlive()&&
						pf->getPlants(i)->getName()!="CherryBomb"&&
						pf->getPlants(i)->getName() != "WallNut" &&
						//plantX - zombieX < 0 &&
						zombieX+66 - plantX <= 56 &&
						zombieX+66 - plantX > 0 &&
						//plantX-zombieX<0 &&
					
						plantY -  zombieY <= 40&&
						plantY - zombieY >=0)
					{
						zf->getZombies(k)->setMove(0);
						zf->getZombies(k)->setEat(1);
						if (pf->getPlants(i)->decreaseHealth()) {
						//	cout << "Hello " << endl;

							pf->getPlants(i)->ifPlantDies(pf->getPlants(i)->isAlive());
							pf->getPlants(i)->setPlantAlive(0);
							//Set ALl zombies Previous to Move Rather than Eating
							zf->getZombies(k)->setMove(1);
							zf->getZombies(k)->setEat(0);
							/*for (int x = k-1; x > 0; x--) {
								if (zf->getZombies(x)->getSprite().getPosition().x > zf->getZombies(k)->getSprite().getPosition().x) {
									zf->getZombies(x)->setMove(1);
									zf->getZombies(x)->setEat(0);
								}
							}*/
							
							//break;
						}
					
					}
					if (pf->getPlants(i)->isBulletAlive(j)) {
						int bulletX = pf->getPlants(i)->getBullet(j).getPosition().x;
						int bulletY = pf->getPlants(i)->getBullet(j).getPosition().y;
						if (getZombieFactory()->getZombies(k)->isZombieRip() &&
							bulletX >= zombieX+66
							&& bulletX<= zombieX+166
							&& bulletY >= zombieY
							&& bulletY <= zombieY + 100
							&& bulletX<= 1000)
						{
							pf->getPlants(i)->dieBullet(j);
							pf->getPlants(i)->getPlantBulletClock().restart();
							getZombieFactory()->getZombies(k)->decreaseHealthZombie();
						//	break;
						}
					}
					
				}
			}
		}
	}
	void checkCherryBoom() {

		for (int i = 0; i < pf->getNumberOfPlants(); i++) {
			if (pf->getPlants(i)->getName() == "CherryBomb" && pf->getPlants(i)->isAlive()) {
				CherryBomb* temp = (CherryBomb*)pf->getPlants(i);
				if (temp->isCherryExploded() && !temp->isCherryVanished()) {

				//	cout << "Time to killl zombie " << endl;
					for (int j = 0; j < zf->getMaxNumOfZombies(); j++) {
						if (zf->getZombies(j)->isZombieRip())
						{
							int zombieX = zf->getZombies(j)->getSprite().getPosition().x;
							int zombieY = zf->getZombies(j)->getSprite().getPosition().y;
							int cherryX = pf->getPlants(i)->getSprite().getPosition().x;
							int cherryY = pf->getPlants(i)->getSprite().getPosition().y;
							if ( zombieX - cherryX >=-100 && zombieX-cherryX<= 100
								&& zombieY-cherryY >= -100 && zombieY - cherryY <= 100	)
							{
				//				cout << "(ZombieX,CherryX)" << endl;
				//				cout << "(" << zombieX << "," << cherryX << ")" << endl;
								//	cout << "RIP ZOMBIE " << endl;
								zf->getZombies(j)->setZombieBoom();
								break;
							}
						}
					}
				}
			}
		}
	}
	void wallNutCollision() {
		for (int i = 0; i < pf->getNumberOfPlants(); i++) {
			if (pf->getPlants(i)->isAlive() && pf->getPlants(i)->getName() == "WallNut") {
				for (int j = 0; j < zf->getMaxNumOfZombies(); j++) {
					WallNut* temp = (WallNut*)pf->getPlants(i);
					if (zf->getZombies(j)->isZombieRip() && (!temp->getMoveLeft() || !temp->getMoveRight())) {
			//			cout << "ZOMBIE: " << i << " IS ALIVE " << endl;
							int WallNutX = pf->getPlants(i)->getBullet(i).getPosition().x;
							int WallNutY= pf->getPlants(i)->getBullet(i).getPosition().y;
							int ZombieX = zf->getZombies(j)->getSprite().getPosition().x;
							int ZombieY= zf->getZombies(j)->getSprite().getPosition().y;
						//	cout << "(" << WallNutX << "," << WallNutY << ") " << endl;
							if (WallNutX >= ZombieX + 66
								&& WallNutX <= ZombieX + 166
								&& ZombieX<=1015){// && WallNutX <= ZombieX + 166) {
						//		cout << "WALLNUT COLLISON CALLED " << endl;
								if (!temp->getMoveLeft() && !temp->getMoveRight()) {//IF both ae false will ove UP
									temp->setWallNutDirection(1);
								}
								//if (!temp->getMoveRight() && temp->getMoveLeft())//If move Left is True, it will move down
								//{
								//	temp->setWallNutDirection(0);
								//	/*if (WallNutY >= 670) {
								//		temp->setWallNutDirection(1);
								//	}*/
								//}
								//if (temp->getMoveRight() && !temp->getMoveLeft())//If move Left is True, it will move UP
								//{
								//	temp->setWallNutDirection(1);
								//	/*if (WallNutY <= 70) {
								//		temp->setWallNutDirection(0);
								//	}*/
								//}
								if (!temp->getMoveRight() && temp->getMoveLeft() && WallNutY <= 70)
								{
				//					cout << "TOP REACHED " << endl;
									temp->setWallNutDirection(0);
								}
								/*
								if (temp->getMoveRight() && !temp->getMoveLeft() && WallNutY >= 670)
								{
									temp->setWallNutDirection(1);
								}*/
								break;
							}
					}
				}
			}
		}
	}
	virtual void collisionWithLawnMower() = 0;

	
	
	
	string getLevelName() {
		return name;
	}

	void sunflowerSunCollection(Event event, RenderWindow& window, int& score) {

		//	cout << "SUNFLOWER COLLECTION " << endl;
		int bulletX = 0;
		int bulletY = 0;
		for (int i = 0; i < pf->getNumberOfPlants(); i++)
		{
			if (pf->getPlants(i)->getName() == "SunFlower")
			{
				for (int j = 0; j < 10; j++)
				{
					if (pf->getPlants(i)->isBulletAlive(j)) {
						bulletX = pf->getPlants(i)->getBulletXPosition(j);
						bulletY = pf->getPlants(i)->getBulletYPosition(j);
						

						//	}
						if (event.type == sf::Event::MouseButtonPressed)
						{
							//		cout << "inside event" << endl;
							if (event.mouseButton.button == sf::Mouse::Left)
							{
								int mouseX = event.mouseButton.x;
								int mouseY = event.mouseButton.y;
				//				cout << "BulletX " << bulletX << endl;
					//			cout << "Bullet Y " << bulletY << endl;
						//		cout << "MouseX " << mouseX << endl;
							//	cout << "MouseY"<<mouseY << endl;
								if (mouseY >= bulletY && mouseY <= bulletY + 78 &&
									 mouseX>=bulletX && mouseX <= bulletX +78 )
								{
									score += 50;
				//					cout << "Sun Clicked " << endl;
									getPlantFactory()->getPlants(i)->dieBullet(j);
									break;
								}

							}

						}

					}
				}


			}
		}
	}

	
	void ifZombieReachesHome(int &a) {
	//	cout << "ZOMBIE IN HOME CALLED " << endl;
		for (int i = 0; i < zf->getMaxNumOfZombies(); i++) {
			if (zf->getZombies(i)->isZombieRip()) {
				if (zf->getZombies(i)->getSprite().getPosition().x <= 100) {
				 //	cout << "Zombie Reaches Home " << endl;
					zf->getZombies(i)->setZombieRip(0);
					zf->getZombies(i)->dieZombie();
				//	cout << "LIVES BEFORE" << a << endl;
					a--;
				//	cout << "LIVES After" << a << endl;
					//break;
				}
			}
		}
	}
	void callPartners() {
		for (int i = 0; i < zf->getMaxNumOfZombies(); i++) {
			if (zf->getZombies(i)->getname() == "DancingZombie") {
				if (zf->getZombies(i)->getSprite().getPosition().x >= 600 && zf->getZombies(i)->getSprite().getPosition().x <= 700) {
					int zx = zf->getZombies(i)->getSprite().getPosition().x;
					int zy = zf->getZombies(i)->getSprite().getPosition().y;
					zf->getZombies(i + 1)->setZombiePosition(zx-100,zy);
					zf->getZombies(i + 1)->setDeadFalse();
					zf->getZombies(i + 1)->setZombieAlive(1);
					zf->getZombies(i + 2)->setZombiePosition(zx + 100, zy);
					zf->getZombies(i + 2)->setDeadFalse();
					zf->getZombies(i + 2)->setZombieAlive(1);
					zf->getZombies(i + 3)->setZombiePosition(zx, zy+100);
					zf->getZombies(i + 3)->setDeadFalse();
					zf->getZombies(i + 3)->setZombieAlive(1);
					zf->getZombies(i + 4)->setZombiePosition(zx , zy-100);
					zf->getZombies(i + 4)->setDeadFalse();
					zf->getZombies(i + 4)->setZombieAlive(1);
					//break;
				}
			}
		}
		/*if (zombieSprite.getPosition().x <= 800) {
			for (int i = 0; i < )
		}*/
	}
	

		



};
