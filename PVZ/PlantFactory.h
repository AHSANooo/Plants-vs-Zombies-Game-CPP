#pragma once
#include <SFML/Graphics.hpp>
#include"Plant.h"
#include"PeaShooter.h"
#include"Repeater.h"
#include"SunFLower.h"
#include"Wallnut.h"
#include"SnowPea.h"
#include"CherryBomb.h"

#include"Repeater.h"
class PlantFactory {
	int numOfPlants;
	int maxNumOfPlants;
	//Plant* peaShooters[5];
	//Making Plant Dynamic
	Plant** Plants;
public:
	//virtual Plant* makePlant() = 0;
	/*Peashooter* makePeaShooter() {
		return new Peashooter;
	}*/
	PlantFactory(int a) {
		//cout << "TOTAL PLANTS : " << a << endl;
		numOfPlants = 0;
		maxNumOfPlants = a;
		Plants = new Plant * [a];
		for (int i = 0; i < a; i++) {
			Plants[i] = nullptr;
		}
		
	}
	/*Plant* makePeaShooter() {
		return new Peashooter;
	}*/
	~PlantFactory() {
		for (int i = 0; i < 5; i++) {
			delete Plants[i];
		}
		delete[]Plants;
	}
	
	
	int getNumberOfPlants() {
		return numOfPlants;
	}
	Plant* getPlants(int x) {
		return Plants[x];
	}
	SunFlower* getSun() {
		for (int i = 0; i < 5; i++) {
			if (Plants[i]->getName() == "SunFlower") {
				return (SunFlower*)Plants[i];
			}
		}
	}
	
	bool isPlantPossible(int mouseX, int mouseY, String levelName, int a)
	{
	//	cout << "AVA <<" << mouseX << ",,," << mouseY << endl;
		if (levelName == "BeginnerGarden")
		{
		//	cout << "level 1" << endl;
			if (mouseX <= 250 || mouseX >= 1015 || mouseY <= 310 || mouseY >= 430)
			{
				return false;
			}
		}
		else if (levelName == "ZombieOutSkirts")
		{
			if (mouseX <= 250 || mouseX >= 1015 || mouseY <= 190 || mouseY >= 550)
			{
				return false;
			}
		}
		else if (levelName == "SunFLowerField")
		{
			if (mouseX <= 250 || mouseX >= 1015 || mouseY <= 70 || mouseY >= 670)
			{
				return false;
			}
		}
		//cout << "X " << mouseX << endl;
		mouseX -= 250;
		int count = 0;
		while (mouseX >= 85)
		{
			mouseX -= 85;
			count++;
		}
		mouseX = 250 + count * 85;
		//cout << "X: " << mouseX << endl;
		mouseY -= 70;
		count = 0;
		while (mouseY >= 120)
		{
			mouseY -= 120;
			count++;
		}
		mouseY = 70 + count * 120;
		for (int i = 0; i < numOfPlants; i++)
		{
		//	cout << "I: " << i << endl;
			if (Plants[i]->isAlive() && Plants[i]->getPlantX() == mouseX && Plants[i]->getPlantY() - 20 == mouseY)
			{
				return false;
			}
		}

		if (numOfPlants < maxNumOfPlants) {
			if (a == 1)
			{
				Plants[numOfPlants] = new Peashooter;
				
				
			}
			if (a == 2)
				Plants[numOfPlants] = new SunFlower;
			if (a == 3)
				Plants[numOfPlants] = new CherryBomb;
			if (a == 4)
			{
				Plants[numOfPlants] = new WallNut;
				WallNut* temp = (WallNut*)Plants[numOfPlants];
				temp->setWallnut(mouseX, mouseY);
			}
			if (a == 5)
				Plants[numOfPlants] = new Repeater;
			if (a == 6)

				Plants[numOfPlants] = new SnowPea;
			//	Plants[numOfPlants]->getSprite().setPosition(x, y);
			Plants[numOfPlants]->setPlant(mouseX, mouseY + 20);
			Plants[numOfPlants]->SetAllBullets(mouseX,mouseY+20);
			//Peashooter* temp = (Peashooter*)peaShooters[numOfPlants];
			numOfPlants++;
		}
		return true;
	}
	

};
