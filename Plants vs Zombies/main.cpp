#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;


const int resolutionX = 1280;
const int resolutionY = 960;
const int boxPixelsX = 32;
const int boxPixelsY = 32;
const int gameRows = resolutionY / boxPixelsX; // Total rows on grid --> org resX
const int gameCols = resolutionX / boxPixelsY; // Total columns on grid --> org resY

// Initializing GameGrid.
int gameGrid[gameRows][gameCols] = {};



int main()
{


	// Declaring RenderWindow.
	RenderWindow window(VideoMode(resolutionX, resolutionY), "Plants VS Zombies", Style::Close | Style::Titlebar);

	window.setSize(Vector2u(1440, 960)); // According to the size of my display.

	//to start out from 0,0 --> orignally 100,0
	window.setPosition(Vector2i(0, 0));


	// Initializing Background.
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	backgroundTexture.loadFromFile("Textures/background3.png");//changed the BG image
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setColor(sf::Color(255, 255, 255, 255 * 0.45)); // Reduces Opacity to 45% --> orignally 25% //(redness, greenness, blue ness , opc.)




	//setting uo the font style to show 
	sf::Font font;
	font.loadFromFile("Fonts/arial.ttf");

	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(24);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(10, 10);

	

	

	// Display Starting window
	sf::Text gameOverText;
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(36);
	gameOverText.setFillColor(sf::Color::White);
	gameOverText.setPosition(300, 400);
	gameOverText.setString("Plants vs Zombies \n by Ahsan & Ashehal");

	window.clear();
	window.draw(gameOverText);
	window.display();

	sf::sleep(sf::seconds(1));



	while (window.isOpen()) {








		window.draw(backgroundSprite);



		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {

				return 0;
			}
		}
		window.display();
		window.clear();
	}
}
