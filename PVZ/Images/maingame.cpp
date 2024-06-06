#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;
using namespace std;

//Drawing the background
void createBack(RenderWindow& window) 
{
	//Drawing the background
	Image map_image;
	map_image.loadFromFile("Images/gamelevel1.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);
}

void createScorebox(RenderWindow& window)
{
	Image box;
	box.loadFromFile("Images/scorebox2.png");
	Texture boxtext;
	boxtext.loadFromImage(box);
	Sprite boxsprite;
	boxsprite.setTexture(boxtext);
	boxsprite.setPosition(100, -30);
	boxsprite.setColor(Color(255, 255, 255, 255));
	window.draw(boxsprite);
}

void createSunicon(RenderWindow& window)
{
	Image sun;
	sun.loadFromFile("Images/sunicon.png");
	Texture suntexture;
	suntexture.loadFromImage(sun);
	Sprite sunsprite;
	sunsprite.setTexture(suntexture);
	sunsprite.setPosition(120, 15);
	window.draw(sunsprite);
}

void displayscore(RenderWindow& window, int score, Font& font)
{
	// Create the score text
	Text scoreText("Score: " + std::to_string(score), font, 20);
	scoreText.setFillColor(Color::Black);
	scoreText.setPosition(157, 15);

	// Draw the score text to the window
	window.draw(scoreText);
}
int main()
{
	RenderWindow window(VideoMode(1100, 700), "Plants Vs Zombies");
	//Game icon
	Image icon;
	if (!icon.loadFromFile("Images/icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());
	const int ROWS = 5;
	const int COLS = 9;

	bool FIELD_GAME_STATUS[ROWS][COLS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			FIELD_GAME_STATUS[i][j] = true;
		}
	}

	Clock timeMoney;
	Clock sunclock;


	Clock clock;

	int score = 25;
	srand(time(0));
	Texture sunTexture;
	if (!sunTexture.loadFromFile("Images/sun.png")) 
	{
	   return 1;
	}
	Font font;
	if (!font.loadFromFile("SAN ANDREAS.otf"))
	{
		return EXIT_FAILURE;
	}

	const int maxsun = 10;
	Sprite sunsprite[maxsun];
	float sunx[maxsun];
	float suny[maxsun];
	bool alive[maxsun] = { false }; 
	Clock sunSpawnClock;
	//float timer = 5.0f;
	for (int i = 0; i < maxsun; ++i)
	{
		sunsprite[i].setTexture(sunTexture);
		sunx[i] = static_cast<float>((rand() % 1200)+400);
		suny[i] = -static_cast<float>(sunTexture.getSize().y);
		sunsprite[i].setPosition(sunx[i], suny[i]);
	}

	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		//timer += deltaTime;
		float time = clock.getElapsedTime().asMicroseconds();
		float moneyTime = timeMoney.getElapsedTime().asSeconds();

		clock.restart();
		time = time / 800;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					int mouseX = event.mouseButton.x;
					int mouseY = event.mouseButton.y;
					for (int i = 0; i < maxsun; ++i)
					{
						int sunLeft = static_cast<int>(sunx[i]);
						int sunRight = sunLeft + 45;
						int sunTop = static_cast<int>(suny[i]);
						int sunBottom = sunTop+45;

						if (alive[i] && mouseX >= sunLeft && mouseX <= sunRight + sunLeft && mouseY >= sunTop && mouseY <= sunBottom+sunTop)
						{
							alive[i] = false; 
							score += 25; 
							break; 
						}
					}
				}
			}
		}

		if (sunclock.getElapsedTime().asSeconds() >= 7.0f)
		{
			// Spawn a new sun
			for (int i = 0; i < maxsun; ++i)
			{
				if (!alive[i])
				{
					sunx[i] = static_cast<float>((rand() % 1200) + 400);
					suny[i] = -static_cast<float>(sunTexture.getSize().y);
					sunsprite[i].setTexture(sunTexture);
					sunsprite[i].setPosition(sunx[i], suny[i]);
					alive[i] = true;
					break;
				}
			}
			// Restart the sun spawn clock
			sunclock.restart();
		}
		window.clear();
		//Create a background
		createBack(window);
		createScorebox(window);
		createSunicon(window);
		displayscore(window,score,font);
		for (int i = 0; i < maxsun; ++i)
		{
			if (alive[i])
			{
				suny[i] += 30 * deltaTime;
				sunsprite[i].setPosition(sunx[i], suny[i]);
				window.draw(sunsprite[i]);
			}
		}
		//window.setSize(sf::Vector2u(1000, 800));
		window.setSize(sf::Vector2u(1200, 700));
		window.setPosition(sf::Vector2i(0, 0));
		window.display();
	}
	return 0;
}

