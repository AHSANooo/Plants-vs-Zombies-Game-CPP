#pragma once
#include"menus.h"
#include<iostream>
#include"sun.h"
#include"ZombieOutSkirts.h"
#include"SunFlowerFields.h"
#include <SFML/Graphics.hpp>
#include"Beginner'sGarden.h"
#include"LevelManager.h"
#include"PeaShooter.h"
#include"Plant.h"
#include"PlantFactory.h"
#include"Zombie.h"
#include"SimpleZombie.h"
#include"SnowPea.h"
#include"SunFLower.h"
#include"Wallnut.h"
#include<fstream>
#include<sstream>
using namespace sf;
using namespace std;

struct Highscore
{
	string name;
	int score;
};

class Game {
public:
//	static int x;
	int lives;
	int totalscore;
	sf::Text inputname;
	string name;
	int score;
	/*LevelManager* level1;
	LevelManager* level2;
	LevelManager* level3;*/
	LevelManager* level;
	MenuScreen menu;
	Button playButton;
	Button instructionButton;
	Button tickButton;
	Button popupButton;
	Button pauseButton;
	Button level1Button;
	Button level2Button;
	Button level3Button;
	Button startbutton;
	Button highscore;
	Button highscoretick;
	badge gold;
	badge silver;
	badge bronze;
	Sun s;
	bool inmenu = true;
	bool inlevel1 = false;
	bool inlevel2 = false;
	bool inlevel3 = false;
	bool ininstructions = false;
	bool inlevel1instructions = false;
	bool inlevel2instructions = false;
	bool inlevel3instructions = false;
	bool inpopup = false;
	bool inlevel = false;
	bool inpause = false;
	bool inhighscore = false;
	bool click;
	popupwindow p;
	Level l;
public:
	Game() : playButton("Images/playbutton.png", 440, 105),
		instructionButton("Images/instructionbutton.png", 440, 185),
		tickButton("Images/tickbutton.png", 900, 430),
		popupButton("Images/tickbutton.png", 950, 450),
		pauseButton("Images/pausebutton.png", 1030, 10),
		level1Button("Images/level1.png", 575, 0),
		level2Button("Images/level2.png", 575, 100),
		level3Button("Images/level3.png", 575, 200),
		startbutton("Images/start.png", 550, 350),
		highscore("Images/highscore.png", 440, 265),
		highscoretick("Images/tickbutton.png", 900, 430),
		gold("Images/gold.png", 700, 210),
		silver("Images/silver.png", 700, 300),
		bronze("Images/bronze.png", 700, 400)
	{
		click = false;
		score = 100;
		totalscore = 0;
		level = nullptr;
		//level3 = new SunFlowerField;
		lives = 3;
	//	x = 0;

	//	cout << "In game" << endl;
		//loadNameFromFile();

	}


	void filesave(const string& name, int score)
	{
		const string filename = "final.txt";

		ifstream file(filename);
		ofstream tempfile("temp.txt");

		bool found = false;
		bool add = false;

		if (file.is_open())
		{
			string read;
			while (getline(file, read))
			{
				string playerName;
				int playerScore;

				istringstream s(read);
				s >> playerName >> playerScore;

				if (playerName == name)
				{
					found = true;
					playerScore += score;
					tempfile << playerName << " " << playerScore << endl;
					add = true;
				}
				else
				{
					tempfile << read << endl;
				}
			}
			if (!found)
			{
				tempfile << name << " " << score << endl;
				add = true;
			}

			file.close();
		}
		if (add)
		{
			tempfile.close();

			ifstream tempfile2("temp.txt");
			ofstream output(filename);

			if (tempfile2.is_open())
			{
				const int size = 100;
				string names[size];
				int scores[size];
				int count = 0;

				while (count < size && tempfile2 >> names[count] >> scores[count])
				{
					count++;
				}

				tempfile2.close();

				for (int i = 0; i < count - 1; ++i)
				{
					for (int j = 0; j < count - i - 1; ++j)
					{
						if (scores[j] < scores[j + 1])
						{
							swap(scores[j], scores[j + 1]);
							swap(names[j], names[j + 1]);
						}
					}
				}

				for (int i = 0; i < count; ++i)
				{
					output << names[i] << " " << scores[i] << endl;
				}

				output.close();
			}
			else
			{
				cout << "Error opening temp file." << endl;
			}
		}
		else
		{
			cout << "Error adding score." << endl;
		}
	}




	void displayfile(RenderWindow& window, Font font)
	{
		const int max = 100;
		Highscore highscore[max];
		int count = 0;

		ifstream file("final.txt");
		if (file.is_open())
		{
			while (count < max && file >> highscore[count].name >> highscore[count].score)
			{
				count++;
			}
			for (int i = 0; i < count - 1; i++)
			{
				for (int j = 0; j < count - i - 1; j++)
				{
					if (highscore[j].score < highscore[j + 1].score)
					{
						swap(highscore[j], highscore[j + 1]);
					}
				}
			}
			file.close();

			Text heading;
			heading.setFont(font);
			heading.setString("Highscores:");
			heading.setCharacterSize(40);
			heading.setFillColor(Color::White);
			heading.setPosition(300, 100);
			window.draw(heading);

			int posY = 200;
			for (int i = 0; i < 3; i++)
			{
				Text nametext;
				nametext.setFont(font);
				nametext.setString(highscore[i].name + ": " + to_string(highscore[i].score));
				nametext.setCharacterSize(35);
				nametext.setFillColor(Color::White);
				nametext.setPosition(300, posY);
				window.draw(nametext);
				posY += 100;
			}
		}
		else
		{
			cout << "Error loading highscores" << endl;
		}
	}

	void check(Event event, RenderWindow& window, Font font)
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				int mouseX = event.mouseButton.x;
				int mouseY = event.mouseButton.y;

				if (inmenu)
				{
					if (playButton.isclickedplay(mouseX, mouseY))
					{
						inmenu = false;
						inlevel1 = false;
						ininstructions = false;
						inpopup = true;
					}
					else if (instructionButton.isclickedinstruction(mouseX, mouseY))
					{
						inmenu = false;
						inlevel1 = false;
						inpopup = false;
						ininstructions = true;
					}
					else if (highscore.isclickedhighscore(mouseX, mouseY))
					{
						inmenu = false;
						inlevel1 = false;
						inpopup = false;
						ininstructions = false;
						inhighscore = true;
					}
				}

				else if (inpopup && !inmenu)
				{
					click = true;
					if (p.isclickedpopup(mouseX, mouseY))
					{
						inlevel1 = false;
						ininstructions = false;
						inmenu = false;
						inpopup = false;
						inlevel = true;
					}
				}
				else if (!inlevel1 && !inmenu && !ininstructions && inlevel)
				{
					if (l.isClickedLevel1(mouseX, mouseY))
					{
						inlevel1 = false;
						inlevel1instructions = true;
						inlevel2 = false;
						inlevel3 = false;
						ininstructions = false;
						inmenu = false;
						inpopup = false;
						inlevel = false;
					}
					else if (l.isClickedLevel2(mouseX, mouseY))
					{
						inlevel2 = false;
						inlevel2instructions = true;
						inlevel1 = false;
						inlevel3 = false;
						ininstructions = false;
						inmenu = false;
						inpopup = false;
						inlevel = false;
					}
					else if (l.isClickedLevel3(mouseX, mouseY))
					{
						inlevel3instructions = true;
						inlevel3 = false;
						inlevel2 = false;
						inlevel1 = false;
						ininstructions = false;
						inmenu = false;
						inpopup = false;
						inlevel = false;
					}
	//				cout << "In level" << endl;
				}
				else if (inlevel1 && !inmenu && !ininstructions && !inlevel2 && !inlevel3 && !inlevel1instructions)
				{
					if (pauseButton.isclickedpause(mouseX, mouseY))
					{
						inpause = true;
						inlevel1 = false;
						inlevel3instructions = false;
						inlevel3 = false;
						inlevel2 = false;
						ininstructions = false;
						inmenu = false;
						inpopup = false;
						inlevel = false;

					}
					s.clicked(mouseX, mouseY, score, totalscore);
	//				cout << "calling PlayLevel1 for level 1" << endl;
				
					level->handleEvent(event, window, level, score, totalscore);
					level->sunflowerSunCollection(event, window, score);
					filesave(name, totalscore);
				}
				else if (inlevel2 && !inmenu && !ininstructions && !inlevel1 && !inlevel3 && !inlevel2instructions && !inlevel3instructions)
				{
		//			cout << "calling PlayLevel1 for level 2" << endl;
					if (pauseButton.isclickedpause(mouseX, mouseY))
					{
						inpause = true;
						inlevel1 = false;
						inlevel3instructions = false;
						inlevel3 = false;
						inlevel2 = false;
						ininstructions = false;
						inmenu = false;
						inpopup = false;
						inlevel = false;

					}
					s.clicked(mouseX, mouseY, score, totalscore);
				//	level = new ZombieOutSkirts;
					level->handleEvent(event, window, level, score, totalscore);
					level->sunflowerSunCollection(event, window, score);
					filesave(name, totalscore);
				}
				else if (inlevel3 && !inmenu && !ininstructions && !inlevel2 && !inlevel1 && !inlevel2instructions && !inlevel3instructions)
				{
					if (pauseButton.isclickedpause(mouseX, mouseY))
					{
						inpause = true;
						inlevel1 = false;
						inlevel3instructions = false;
						inlevel3 = false;
						inlevel2 = false;
						ininstructions = false;
						inmenu = false;
						inpopup = false;
						inlevel = false;

					}
					s.clicked(mouseX, mouseY, score, totalscore);
		//			cout << "calling PlayLevel1 for level 3" << endl;
					//level = new SunFlowerField;
					level->handleEvent(event, window, level, score, totalscore);
					level->sunflowerSunCollection(event, window, score);
					filesave(name, totalscore);
				}
				else if (inlevel1instructions && !inlevel1 && !inlevel2 && !inlevel3 && !inmenu && !ininstructions)
				{
					if (startbutton.isclickedstartbutton(mouseX, mouseY))
					{
						inlevel1 = true;
						inlevel2 = false;
						inlevel3 = false;
						inlevel1instructions = false;
						inmenu = false;
						inpopup = false;
					}
				}
				else if (inlevel2instructions && !inlevel1 && !inlevel2 && !inlevel3 && !inmenu && !ininstructions)
				{
					if (startbutton.isclickedstartbutton(mouseX, mouseY))
					{
						inlevel1 = false;
						inlevel2 = true;
						inlevel3 = false;
						inlevel1instructions = false;
						inlevel2instructions = false;
						inlevel3instructions = false;
						inmenu = false;
						inpopup = false;
					}
				}
				else if (inlevel3instructions && !inlevel2instructions && !inlevel1 && !inlevel2 && !inlevel3 && !inmenu && !ininstructions && !inlevel1instructions)
				{
					if (startbutton.isclickedstartbutton(mouseX, mouseY))
					{
						inlevel1 = false;
						inlevel2 = false;
						inlevel3 = true;
						inlevel1instructions = false;
						inlevel2instructions = false;
						inlevel3instructions = false;
						inmenu = false;
						inpopup = false;
					}
				}
				else if (inpause)
				{
					if (quitbuttonclicked(mouseX, mouseY))
					{
						window.close();
					}
					else if (restartbuttonclicked(mouseX, mouseY))
					{
						inmenu = true;
						ininstructions = false;
						inlevel1 = false;
						inlevel2 = false;
						inlevel3 = false;
						inpopup = false;
						inlevel = false;
						inpause = false;

					}
					else if (resumebuttonclicked(mouseX, mouseY))
					{
						inmenu = false;
						ininstructions = false;
						inlevel1 = true;
						inpopup = false;
						inlevel = false;
						inpause = false;
					}
				}
				else if (inhighscore && !inmenu && !inpopup)
				{
					if (highscoretick.isclickedhighscoretick(mouseX, mouseY))
					{
						inmenu = true;
						inhighscore = false;
						inpopup = false;
					}
				}
				else if (!inmenu && !inlevel1 && ininstructions)
				{
					if (tickButton.isclickedtick(mouseX, mouseY))
					{
						inmenu = true;
						ininstructions = false;
						inlevel1 = false;
					}
				}
			}
		}
		if (click)
		{
			if (event.type == Event::TextEntered)
			{
				//cout << "entering text" << endl;
				if (event.text.unicode < 128 && event.text.unicode != '\b')
				{
					name += static_cast<char>(event.text.unicode);
					inputname.setString(name);
				}
				else if (event.text.unicode == '\b' && !name.empty())
				{
					name.pop_back();
				}
				inputname.setString(name);

			}
			//saveNameToFile();
		}

	}

	void run(RenderWindow& window, Font font,bool b)
	{
		if (inmenu && !inlevel1 && !ininstructions && !inpopup && !inlevel)
		{
			menu.draw(window);
			playButton.draw(window);
			instructionButton.draw(window);
			highscore.draw(window);
		}
		else if (inhighscore && !inlevel1 && !inmenu && !ininstructions && !inpopup && !inlevel)
		{
			createprofilescreen(window);
			displayfile(window, font);
			gold.draw(window);
			silver.draw(window);
			bronze.draw(window);
			highscoretick.draw(window);
		}
		else if (!inlevel1 && !inmenu && !ininstructions && inpopup && !inlevel)
		{

			//cout << "draw function called" << endl;
			p.draw(window);
			inputname.setString(name);
			inputname.setFillColor(Color::Black);
			inputname.setPosition(330, 320);
			inputname.setCharacterSize(34);
			inputname.setFont(font);
			window.draw(inputname);
			//cout << name;
			popupButton.draw(window);
		}
		else if (!inlevel1 && !inmenu && !ininstructions && !inpopup && inlevel)
		{

			l.draw(window);
			level1Button.draw(window);
			level2Button.draw(window);
			level3Button.draw(window);
		}
		else if (inlevel1instructions && !inlevel2 && !inlevel1 && !inlevel3 && !inmenu && !ininstructions && !inpopup && !inlevel)
		{
			createLevel1Instruction(window, font);
			startbutton.draw(window);
		}
		else if (inlevel2instructions && !inlevel1instructions && !inlevel2 && !inlevel1 && !inlevel3 && !inmenu && !ininstructions && !inpopup && !inlevel)
		{
			createLevel2Instruction(window, font);
			startbutton.draw(window);
		}
		else if (inlevel3instructions && !inlevel1instructions && !inlevel2 && !inlevel1 && !inlevel3 && !inmenu && !ininstructions && !inpopup && !inlevel)
		{
			createLevel3Instruction(window, font);
			startbutton.draw(window);
		}
		else if (inlevel1 && !inmenu && !ininstructions && !inpopup && !inlevel && !inlevel1instructions)
		{
			static int x = 0;
			if (x==0) {
				level = new BeginnerGarden;
				b = true;
				x++;
			}
			//level = new BeginnerGarden;
			level->playLevel(window, score, level, lives);
			
			if (lives == 0) {
				window.close();
			}
			createlevelbox(window, lives, font);
			createScorebox(window);
			createSunicon(window);
			displayscore(window, score, font);
			pauseButton.draw(window);
			s.spawnSun();
			s.draw(window);
			//cout << "total score is: " << totalscore << endl;
		}
		else if (inlevel2 && !inlevel3 && !inmenu && !ininstructions && !inpopup && !inlevel)
		{
			static int y = 0;
			if (y == 0) {
				level = new ZombieOutSkirts;
			//	b = true;
				y++;
			}
		//	level = new ZombieOutSkirts;
			level->playLevel(window, score, level, lives);
			if (lives == 0) {
				window.close();
			}
			createScorebox(window);
			displayscore(window, score, font);
			createlevelbox(window, lives, font);
			createSunicon(window);
			pauseButton.draw(window);
			s.spawnSun();
			s.draw(window);
		}
		else if (inlevel3 && !inlevel1 && !inlevel2 && !inmenu && !ininstructions && !inpopup && !inlevel)
		{
			static int z = 0;
			if (z == 0) {
				level = new SunFlowerField;
				b = true;
				z++;
			}
			
		
			level->playLevel(window, score, level, lives);
			if (lives == 0) {
				window.close();
			}
			createScorebox(window);
			createSunicon(window);
			displayscore(window, score, font);
			createlevelbox(window, lives, font);
			pauseButton.draw(window);
			s.spawnSun();
			s.draw(window);
		}
		else if (inpause && !inmenu && !ininstructions && !inpopup && !inlevel && !inlevel1 && !inlevel2 && !inlevel3)
		{
			createPausescreen(window);
		}
		else if (!inmenu && !inlevel1 && ininstructions && !inlevel2 && !inlevel3)
		{
			createInstruction(window, font);
			tickButton.draw(window);
		}

	}
};
