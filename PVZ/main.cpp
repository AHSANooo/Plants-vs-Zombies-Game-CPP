#include <SFML/Graphics.hpp>
#include <ctime>
#include "menus.h"
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
#include"Game.h"

using namespace sf;
using namespace std;


struct coordinats {
	int x;
	int y;
};

int main()
{
	//Create a window, n*n
	RenderWindow window(VideoMode(1100, 700), "Plants Vs Zombies");
	//Game icon
	Image icon;
	if (!icon.loadFromFile("Images/icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	bool b = false;
	Game g;
	Font font;
	if (!font.loadFromFile("SAN ANDREAS.otf"))
	{
		return EXIT_FAILURE;
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else
			{
				g.check(event, window, font);
			}
		}
		window.clear();
		g.run(window, font,b);
		window.display();

	}
	return 0;
}
