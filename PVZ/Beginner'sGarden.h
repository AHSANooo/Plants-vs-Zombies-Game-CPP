#pragma once
#include <SFML/Graphics.hpp>
#include"LevelManager.h"

class BeginnerGarden :public LevelManager {
protected:
	int a;
	bool isPeashooterSelected;
	bool isSunFlowerSelected;
public:

	//	sf::Window window;
	BeginnerGarden() : LevelManager("Images/backGroundFinal.jpg", "BeginnerGarden")
	{
//		cout << "LEVEL 1 C called" << endl;
		isPeashooterSelected = false;
		isSunFlowerSelected = false;
		a = 0;
	}
	LevelManager* makeLevel()
	{
		return new BeginnerGarden();
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

	}
	
	
	void handleEvent(Event event, RenderWindow& window, LevelManager*& level1, int& score, int& totalScore) override
	{
	//	cout << "Display called" << endl;
		//sf::Event event;
	//	while (window.pollEvent(event))
		//{
		if (event.type == sf::Event::MouseButtonPressed)
		{
	//		cout << "inside event" << endl;
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				int mouseX = event.mouseButton.x;
				int mouseY = event.mouseButton.y;
				//	cout << "Mouse x is: " << mouseX << " and mouse y is: " << mouseY << endl;
				if (!isPeashooterSelected && mouseX >= 0 && mouseX <= 65 && mouseY >= 0 && mouseY <= 90)
				{
					isPeashooterSelected = true;
//					cout << "PeasShooter is selected" << endl;
					a = 1;
				}
				else if (!isSunFlowerSelected && mouseX >= 0 && mouseX <= 65 && mouseY > 90 && mouseY <= 180)
				{
//					cout << "SunFlower is selected " << endl;
					isSunFlowerSelected = true;
					a = 2;
				}
				else if (isPeashooterSelected)
				{
//					cout << "PEA SHOOTER HAS BEEN SELECTED" << endl;
//
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
						
							if (level1->getPlantFactory()->isPlantPossible(mouseX, mouseY, level1->getLevelName(), 2))
							{
								score -= 100;
								isSunFlowerSelected = false;
								totalScore += 10;
							
							}
						
					}

				}
				
				


			}
		}
		 
		/*if (ifZombieReachesHome()) {
			lives--;
		}*/
	}
	void collisionWithLawnMower() {

		for (int j = 0; j < 1; j++) {
			if (lm[j].getMove()) {
				lm[j].moveLawnMower();
			}
			for (int i = 0; i < zf->getMaxNumOfZombies(); i++) {
				if (zf->getZombies(i)->isZombieRip()) {
					int lawnMowerX = lm[j].getSprite().getPosition().x;
					int lawnMowerY = lm[j].getSprite().getPosition().y;
					int ZombieX = zf->getZombies(i)->getSprite().getPosition().x;
					int ZombieY = zf->getZombies(i)->getSprite().getPosition().y;
					if (lm[j].getAlive() && ZombieX  <= lawnMowerX && lawnMowerY - ZombieY <= 50 && lawnMowerY - ZombieY >= 0) {//}&& ZombieY <= 340 && ZombieY >= 460) {
						zf->getZombies(i)->setZombieRip(0);
						lm[j].setMove(1);
					}
				}
			}
		}

	}
	void playLevel(RenderWindow& window, int& score, LevelManager* level,int& lives) {
		//cout << "PLAY LEVEL FOR LEVEL 1 CALLED " << endl;
		window.draw(level->getBackgroud());
		level->ShowAvailablePlants(window);
		level->drawPlants(window);
		level->drawZombies(window);
		level->drawBullets(window);
		level->drawLawnMowersLevel1(window);
		level->checkCollision();
		level->collisionWithLawnMower();
		level->ifZombieReachesHome(lives);
	}
	
};

