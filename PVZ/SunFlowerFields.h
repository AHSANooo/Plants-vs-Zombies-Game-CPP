#pragma once
#include <SFML/Graphics.hpp>
#include"LevelManager.h"
class SunFlowerField :public  LevelManager {
protected:
	int a;
	bool isPeashooterSelected = false;
	bool isRepeaterSelected = false;
	bool isSunFlowerSelected = false;
	bool isSnowPeaSelected = false;
	bool isCherrySelected = false;
	bool isWallNutSelected = false;
public:
	SunFlowerField()
		:LevelManager("Images/backGroundFinal.jpg", "SunFLowerField")
	{
		isPeashooterSelected = false;
		isRepeaterSelected = false;
		isSunFlowerSelected = false;
		isSnowPeaSelected = false;
		isCherrySelected = false;
		isWallNutSelected = false;
	}
	LevelManager* makeLevel() {
		return new SunFlowerField();
	}
	void ShowAvailablePlants(RenderWindow& window)
	{
		Image PeaCard;
		PeaCard.loadFromFile("Images/peacard.png");
		Texture PeaCardTexture;
		PeaCardTexture.loadFromImage(PeaCard);
		Sprite PeaCardSprite;
		PeaCardSprite.setTexture(PeaCardTexture);
		PeaCardSprite.setPosition(0, 0);
		window.draw(PeaCardSprite);

		Image SunflowerCard;
		SunflowerCard.loadFromFile("Images/sunflowercard.png");
		Texture SunFlowerCardTexture;
		SunFlowerCardTexture.loadFromImage(SunflowerCard);
		Sprite SunFlowerCardSprite;
		SunFlowerCardSprite.setTexture(SunFlowerCardTexture);
		SunFlowerCardSprite.setPosition(0, 90);
		window.draw(SunFlowerCardSprite);

		Image CherryBombCard;
		CherryBombCard.loadFromFile("Images/cherrycard.png");
		Texture CherryBombTexture;
		CherryBombTexture.loadFromImage(CherryBombCard);
		Sprite cherryBombCardSprite;
		cherryBombCardSprite.setTexture(CherryBombTexture);
		cherryBombCardSprite.setPosition(0, 180);
		window.draw(cherryBombCardSprite);

		Image WallNutCard;
		WallNutCard.loadFromFile("Images/card_wallnut.png");
		Texture WallNutCardTexture;
		WallNutCardTexture.loadFromImage(WallNutCard);
		Sprite WallNutCardSprite;
		WallNutCardSprite.setTexture(WallNutCardTexture);
		WallNutCardSprite.setPosition(0, 270);
		window.draw(WallNutCardSprite);

		Image RepeaterCard;
		RepeaterCard.loadFromFile("Images/repeatercard.png");
		Texture RepeaterCardTexture;
		RepeaterCardTexture.loadFromImage(RepeaterCard);
		Sprite RepeaterCardSprite;
		RepeaterCardSprite.setTexture(RepeaterCardTexture);
		RepeaterCardSprite.setPosition(0, 360);
		window.draw(RepeaterCardSprite);

		Image SnowPeaCard;
		SnowPeaCard.loadFromFile("Images/snowcard.png");
		Texture SnowPeaCardTexture;
		SnowPeaCardTexture.loadFromImage(SnowPeaCard);
		Sprite SnowPeaCardSprite;
		SnowPeaCardSprite.setTexture(SnowPeaCardTexture);
		SnowPeaCardSprite.setPosition(0, 450);
		window.draw(SnowPeaCardSprite);
	}
	
	void drawPlants(RenderWindow& window) {
		for (int i = 0; i < getPlantFactory()->getNumberOfPlants(); i++) {
			if (getPlantFactory()->getPlants(i)->isAlive())
				window.draw(getPlantFactory()->getPlants(i)->getSprite());
		}
	}



void handleEvent(Event event, RenderWindow& window, LevelManager*& level1, int& score, int& totalScore)
{
	//cout << "Level 3 Handle Event called " << endl;
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			int mouseX = event.mouseButton.x;
			int mouseY = event.mouseButton.y;
			if (!isPeashooterSelected && mouseX >= 0 && mouseX <= 65 && mouseY >= 0 && mouseY <= 90)
			{
				isPeashooterSelected = true;
				//cout << "PeasShooter is selected" << endl;
				a = 1;
			}
			else if (!isSunFlowerSelected && mouseX >= 0 && mouseX <= 65 && mouseY > 90 && mouseY <= 180)
			{
			//	cout << "SunFlower is selected " << endl;
				isSunFlowerSelected = true;
				a = 2;
			}
			else if (!isCherrySelected && mouseX >= 0 && mouseX <= 64 &&
				mouseY > 180 && mouseY <= 270)
			{
			//	cout << "Cherry is Selected " << endl;
				isCherrySelected = true;
				a = 3;
			}
			else if (!isWallNutSelected && mouseX >= 0 && mouseX <= 64 &&
				mouseY > 270 && mouseY <= 360)
			{
			//	cout << "WallNut is Selected " << endl;
				isWallNutSelected = true;
				a = 4;
			}
			else if (!isRepeaterSelected && mouseX >= 0 && mouseX <= 65 &&
				mouseY > 360 && mouseY <= 450)
			{
			//	cout << "Repeater is selected" << endl;
				isRepeaterSelected = true;
				a = 5;
			}
			else if (!isSnowPeaSelected && mouseX >= 0 && mouseX <= 64 &&
				mouseY > 450 && mouseY <= 540)
			{
			//	cout << "Snowpea is selected" << endl;
				isSnowPeaSelected = true;
				a = 6;
			}




			else if (isPeashooterSelected)
			{

				if (score >= 100)
				{
					if (level1->getPlantFactory()->isPlantPossible(mouseX, mouseY, level1->getLevelName(), 1))
					{
						score -= 100;
						isPeashooterSelected = false;
						totalScore += 10;
					}
				}

			}


			else if (isSunFlowerSelected)
			{
				if (score >= 50)
				{
					if (level1->getPlantFactory()->isPlantPossible(mouseX, mouseY, level1->getLevelName(), 2))
					{
						score -= 50;
						isSunFlowerSelected = false;
						totalScore += 10;
					}
				}

			}

			else if (isCherrySelected)
			{
				if (score >= 100)
				{
					if (level1->getPlantFactory()->isPlantPossible(mouseX, mouseY, level1->getLevelName(), 3))
					{
						score -= 100;
						isCherrySelected = false;
						totalScore += 10;
					}
				}

			}
			else if (isWallNutSelected)
			{

				if (score >= 100)
				{
					if (level1->getPlantFactory()->isPlantPossible(mouseX, mouseY, level1->getLevelName(), 4))
					{
						score -= 100;
						isWallNutSelected = false;
						totalScore += 10;
					}
				}
			}
			else if (isRepeaterSelected)
			{

				if (score >= 200)
				{
					if (level1->getPlantFactory()->isPlantPossible(mouseX, mouseY, level1->getLevelName(), 5))
					{
						score -= 100;
						isRepeaterSelected = false;
						totalScore += 10;
					}
				}

			}
			else if (isSnowPeaSelected)
			{
				if (score >= 200)
				{
					if (level1->getPlantFactory()->isPlantPossible(mouseX, mouseY, level1->getLevelName(), 6))
					{
						score -= 100;
						isSnowPeaSelected = false;
						totalScore += 10;
					}
				}
			}
		}
	}
	/*bool b = ifZombieReachesHome();*/

}
	void playLevel(RenderWindow& window, int& score, LevelManager* level,int& lives) {
		//cout << "PLAY LEVEL FOR LEVEL 3 CALLED " << endl;
		window.draw(level->getBackgroud());
		level->ShowAvailablePlants(window);
		level->drawPlants(window);
		level->drawZombies(window);
		level->drawBullets(window);
		level->drawLawnMowersLevel3(window);
		level->checkCollision();
		level->wallNutCollision();
		level->checkCherryBoom();
		level->collisionWithLawnMower();
		level->ifZombieReachesHome(lives);
		level->callPartners();
	}
	void collisionWithLawnMower() {

		for (int j = 0; j < 5; j++) {
			if (lm[j].getMove()) {
				lm[j].moveLawnMower();
			}
			for (int i = 0; i < zf->getMaxNumOfZombies(); i++) {
				if (zf->getZombies(i)->isZombieRip()) {
					int lawnMowerX = lm[j].getSprite().getPosition().x;
					int lawnMowerY = lm[j].getSprite().getPosition().y;
					int ZombieX = zf->getZombies(i)->getSprite().getPosition().x;
					int ZombieY = zf->getZombies(i)->getSprite().getPosition().y;
					if (lm[j].getAlive() && ZombieX <= lawnMowerX && lawnMowerY - ZombieY <= 70 && lawnMowerY - ZombieY >= 0) {//}&& ZombieY <= 340 && ZombieY >= 460) {
						zf->getZombies(i)->setZombieRip(0);
						lm[j].setMove(1);
					}
				}
			}
		}
	}
	/*void sunflowerSunCollection(Event event, RenderWindow& window, LevelManager*& level1, int& score) {
		cout << "NINE" << endl;
	}*/
};
