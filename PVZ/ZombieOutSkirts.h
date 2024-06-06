#pragma once
#include <SFML/Graphics.hpp>
#include"LevelManager.h"
#include"PeaShooter.h"
Window window;
class ZombieOutSkirts :public LevelManager {
protected:
	int a;
	bool isPeashooterSelected = false;
	bool isSunFlowerSelected = false;
	bool isCherrySelected = false;
	bool isWallNutSelected = false;
public:
	ZombieOutSkirts()
		:LevelManager("Images/backGroundFinal.jpg", "ZombieOutSkirts")
	{
		isPeashooterSelected = false;
		isSunFlowerSelected = false;
		isCherrySelected = false;
		isWallNutSelected = false;
	}
	LevelManager* makeLevel() {
		return new ZombieOutSkirts();
	}
	void ShowAvailablePlants(RenderWindow& window)
	{
		//cout << "Available Plants called " << endl;
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
	}
	
	
	

	

void handleEvent(Event event, RenderWindow& window, LevelManager*& level1, int& score, int& totalScore)
{
	//cout << "Level 2 display called " << endl;
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
				//cout << "SunFlower is selected " << endl;
				isSunFlowerSelected = true;
				a = 2;
			}
			else if (!isCherrySelected && mouseX >= 0 && mouseX <= 64 && mouseY > 180 && mouseY <= 270)
			{
				//cout << "Cherry is Selected " << endl;
				isCherrySelected = true;
				a = 3;
			}
			else if (!isWallNutSelected && mouseX >= 0 && mouseX <= 64 &&
				mouseY > 270 && mouseY <= 360)
			{
				//cout << "WallNut is Selected " << endl;
				isWallNutSelected = true;
				a = 4;
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
				if (score >= 100)
				{
					if (level1->getPlantFactory()->isPlantPossible(mouseX, mouseY, level1->getLevelName(), 2)) {

						score -= 100;
						isSunFlowerSelected = false;
						totalScore += 10;
					}
				}
			}
			else if (isCherrySelected)
			{
				if (score >= 150)
				{
					//Set a PeaShooter Here 
					if (level1->getPlantFactory()->isPlantPossible(mouseX, mouseY, level1->getLevelName(), 3)) {

						score -= 100;
						isCherrySelected = false;
						totalScore += 10;
					}
				}

			}
			else if (isWallNutSelected)
			{
				if (score >= 50)
				{
					//Set a PeaShooter Here 
					if (level1->getPlantFactory()->isPlantPossible(mouseX, mouseY, level1->getLevelName(), 4)) {
						score -= 50;
						isWallNutSelected = false;
						totalScore += 10;
					}
				}

			}
		}


	}
	
}
	
	void collisionWithLawnMower() {

		for (int j = 0; j < 3; j++) {
			if (lm[j].getMove()) {
				lm[j].moveLawnMower();
			}
			for (int i = 0; i < zf->getMaxNumOfZombies(); i++) {
				if (zf->getZombies(i)->isZombieRip()) {
					int lawnMowerX = lm[j].getSprite().getPosition().x;
					int lawnMowerY = lm[j].getSprite().getPosition().y;
					int ZombieX = zf->getZombies(i)->getSprite().getPosition().x;
					int ZombieY = zf->getZombies(i)->getSprite().getPosition().y;
					if (lm[j].getAlive() && ZombieX <= lawnMowerX && lawnMowerY - ZombieY <= 50 && lawnMowerY - ZombieY >= 0) {//}&& ZombieY <= 340 && ZombieY >= 460) {
						zf->getZombies(i)->setZombieRip(0);
						lm[j].setMove(1);
					}
				}
			}
		}
	}

	void playLevel(RenderWindow& window, int& score, LevelManager* level,int &lives) {
		//cout << "PLAY LEVEL FOR LEVEL 1 CALLED " << endl;
		window.draw(level->getBackgroud());
		level->ShowAvailablePlants(window);
		level->drawPlants(window);
		level->drawZombies(window);
		level->drawBullets(window);
		level->drawLawnMowersLevel2(window);
		level->checkCollision();
		level->wallNutCollision();
		level->checkCherryBoom();
		level->ifZombieReachesHome(lives);
		level->collisionWithLawnMower();
		level->callPartners();
	}
	
};
