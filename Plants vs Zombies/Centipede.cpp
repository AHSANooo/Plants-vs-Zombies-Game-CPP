#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

// Initializing Dimensions.
// resolutionX and resolutionY determine the rendering resolution.
// Don't edit unless required. i'm increasing the resolutionY to fill up the screen and look good to 1280 from 960.
const int resolutionX = 1280;
const int resolutionY = 960;
const int boxPixelsX = 32;
const int boxPixelsY = 32;
const int gameRows = resolutionY / boxPixelsX; // Total rows on grid --> org resX
const int gameCols = resolutionX / boxPixelsY; // Total columns on grid --> org resY

// Initializing GameGrid.
int gameGrid[gameRows][gameCols] = {};

//we can use the constants in the code but using these makes it easier to understand the complex code.
const int x = 0;
const int y = 1;
const int exists = 2;

/////////////////////////////////////////////
//                                         //
// Writing my functions declarations here. //
//                                         //
/////////////////////////////////////////////


void movePlayer(float player[]);
void drawPlayer(sf::RenderWindow& window, float player[], sf::Sprite& playerSprite);
void firebullet(float bullet[],float player[], sf::Sound& bulletFireSound);
void moveBullet(float bullet[], sf::Clock& bulletClock);
void drawBullet(sf::RenderWindow& window, float bullet[], sf::Sprite& bulletSprite);
void moveCentipede(float **centripede,float centipedeSpeed, float **mushroom, int numMushrooms);
void drawCentipede(sf::RenderWindow& window, sf::Texture& centipedeBodyTexture, sf::Texture& centipedeHeadTexture,float** centipede);
void drawMushroom(sf::RenderWindow& window, float **mushroom,int i, sf::Sprite& mushroomSprite,sf::Sprite& pmushroomSprite,sf::Sprite& mushroomfSprite, sf::Sprite& pmushroomfSprite);
void movespider(float spider[]);
void drawspider(sf::RenderWindow& window, float spider[], sf::Sprite& spiderSprite);
bool checkCollision(float bullet[], float **target,int i);
bool checkCollision(float **centipede,int i, float **mushroom,int j);
bool checkCollision(float bullet[], float target[]);
bool checkGameOver(float player[], float **centipede,int times);


int main()
{
	srand(time(0));

	// Declaring RenderWindow.
	sf::RenderWindow window(sf::VideoMode(resolutionX, resolutionY), "Centipede by Ahsan", sf::Style::Close | sf::Style::Titlebar);
	
	window.setSize(sf::Vector2u(1920, 1015)); // According to the size of my display.
	
	//to start out from 0,0 --> orignally 100,0
	window.setPosition(sf::Vector2i(0, 0));

	// Initializing Background Music.
	sf::Music bgMusic;
	bgMusic.openFromFile("Music/gametune.ogg");// changed as i likes this one more 
	bgMusic.play();
	bgMusic.setVolume(100);
	
	
	
	// Initializing kill & fire sound.
	sf::SoundBuffer bulletFireBuffer;
	sf::SoundBuffer bulletHitBuffer;

	sf::Sound bulletFireSound;
	sf::Sound bulletHitSound;
	
	bulletFireBuffer.loadFromFile("Sounds/fire1.wav");
	bulletHitBuffer.loadFromFile("Sounds/kill.wav");
	
	bulletFireSound.setBuffer(bulletFireBuffer);
	bulletHitSound.setBuffer(bulletHitBuffer);
	
	
	
	
	// Initializing Background.
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	backgroundTexture.loadFromFile("Textures/backg.png");//changed the BG image
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setColor(sf::Color(255, 255, 255, 255 * 0.45)); // Reduces Opacity to 45% --> orignally 25% //(redness, greenness, blue ness , opc.)

	// Initializing Player and Player Sprites.
	float player[2] = {};
	player[x] = (gameCols / 2) * boxPixelsX;
	player[y] = resolutionY- boxPixelsY*6;// changed to 6 --> orignally the condition used gamecols which was tatally wrong
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	playerTexture.loadFromFile("Textures/player.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));

	
	// Initializing spider and spider Sprites.
	float spider[3] = {};
	spider[x] = 0; // Fixed the assignment here
	spider[y] = resolutionY - boxPixelsY*2;
	sf::Texture spiderTexture;
	sf::Sprite spiderSprite;	
	spiderTexture.loadFromFile("Textures/spider.png");
	spiderSprite.setTexture(spiderTexture);
	spiderSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	spider[exists] = false;


	// Initializing Bullet and Bullet Sprites.
	float bullet[3] = {};
	bullet[x] = player[x];
	bullet[y] = player[y] - boxPixelsY;
	bullet[exists] = false;//-->org true
	sf::Clock bulletClock;
	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;
	bulletTexture.loadFromFile("Textures/bullet.png");
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setTextureRect(sf::IntRect(0, 0, 6, boxPixelsY)); //-->(x,y,w.h)


	//setting uo the font style to show 
	sf::Font font;
	font.loadFromFile("Fonts/arial.ttf");

	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(24);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(10, 10);

	int level=1;
	int score=0;//initializing the score 
	
	//initializing the centipede
	
	float **centipede= new float*[13];//12 segments , each having x y and exist ,1 extra to skip segmentation fault
	for (int i=0;i<13;i++)
	centipede[i]= new float[4];
	float centipedeSpeed = 0.18;
	
	sf::Texture centipedeBodyTexture;
	centipedeBodyTexture.loadFromFile("Textures/segment.png");

	sf::Texture centipedeHeadTexture;
	centipedeHeadTexture.loadFromFile("Textures/head.png");
	
	
	
	int rcinaitialy = rand()% 16, rcinaitialx=rand()%18;//only random for upper half
	if(rcinaitialy%2!=0)
	rcinaitialy++;
	    
	for (int i = 0; i <13; ++i) 
	{
		centipede[i][x] = (rcinaitialx+i) * boxPixelsX;
		centipede[i][y] = rcinaitialy * boxPixelsY; //for random placement of the centipede
		centipede[i][exists] = true;
		if(i==0)
		centipede[i][3]=true;
		else
		centipede[i][3]=false;
		if(i==12)
		centipede[i][exists]=false;
	}
	
		//initialize the mushrooms 
		int numMushrooms = rand() % 10 + 20;int maxmushrooms=numMushrooms+12+100;int tempindexm=numMushrooms;//extra 100 for levels
		float **mushroom= new float*[maxmushrooms];//generating random number of mushrooms + 12 extra
		for (int i=0;i<maxmushrooms;i++)
		mushroom[i]= new float[5];
		
		sf::Texture mushroomTexture;
		sf::Sprite mushroomSprite;
		mushroomTexture.loadFromFile("Textures/mushroom.png");
		mushroomSprite.setTexture(mushroomTexture);
		mushroomSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
		
		sf::Texture pmushroomTexture;
		sf::Sprite pmushroomSprite;
		pmushroomTexture.loadFromFile("Textures/mushroom.png");
		pmushroomSprite.setTexture(pmushroomTexture);
		pmushroomSprite.setTextureRect(sf::IntRect(0,32 , boxPixelsX, boxPixelsY));
		
		
		sf::Texture mushroomfTexture;
		sf::Sprite mushroomfSprite;
		mushroomfTexture.loadFromFile("Textures/mushroom.png");
		mushroomfSprite.setTexture(mushroomfTexture);
		mushroomfSprite.setTextureRect(sf::IntRect(64, 0, boxPixelsX, boxPixelsY));
		
		sf::Texture pmushroomfTexture;
		sf::Sprite pmushroomfSprite;
		pmushroomfTexture.loadFromFile("Textures/mushroom.png");
		pmushroomfSprite.setTexture(pmushroomfTexture);
		pmushroomfSprite.setTextureRect(sf::IntRect(64,32 , boxPixelsX, boxPixelsY));
		
		
		for (int i = 0; i < maxmushrooms; i++) 
		{	
			if(i<numMushrooms)
			{
			mushroom[i][exists]=true;mushroom[i][3]=false;mushroom[i][4]=2;
			mushroom[i][x] = rand() % (gameCols - 2) * boxPixelsX + boxPixelsX;  // Avoid placing mushrooms on border columns
			mushroom[i][y] = rand() % (gameRows - 6) * boxPixelsY;  // Start from the second row
			}
			else
			{
			mushroom[i][exists]=false;
			mushroom[i][3]=false;//for poisonous mushrooms
			mushroom[i][4]=2;//for half mushroom
			}
		}
	
	// Display Starting window
			sf::Text gameOverText;
			gameOverText.setFont(font);
			gameOverText.setCharacterSize(36);
			gameOverText.setFillColor(sf::Color::White);
			gameOverText.setPosition(300, 400);
			gameOverText.setString("Centipide by Ahsan \nStarting... ");

			window.clear();
			window.draw(gameOverText);
			window.display();

			sf::sleep(sf::seconds(1)); 
	
		
	
	while(window.isOpen()) {

		///////////////////////////////
		//                           //
		// Calling my Functions Here.//
		//                           //
		///////////////////////////////



		



		window.draw(backgroundSprite);
		
		movePlayer(player);
		drawPlayer(window, player, playerSprite);
		
		// Draw mushrooms
		for (int i = 0; i < tempindexm; i++)
		    drawMushroom(window, mushroom,i, mushroomSprite,pmushroomSprite,mushroomfSprite,pmushroomfSprite);
		
		firebullet(bullet,player,bulletFireSound);
		if (bullet[exists] == true) 
		{
			moveBullet(bullet, bulletClock);
			drawBullet(window, bullet, bulletSprite);
		}
		
		moveCentipede(centipede,centipedeSpeed,mushroom,tempindexm); 
		drawCentipede(window, centipedeBodyTexture, centipedeHeadTexture,centipede);
		
		
		//case used for spider(part of bonus)
		if(level > 1)
		{
			movespider(spider);
   		 	drawspider(window, spider, spiderSprite);
   		 	
   		 	
   		 	// to check collision between bullet and spider
			if (checkCollision(bullet, spider) && bullet[exists] && spider[exists]) 
			{
				bullet[exists]=false;
				score += 300;
				spider[exists] = false;
			}

		}
		
		 // Check collision with centipede
		for (int i = 0; i <12; i++) 
		{
			if (centipede[i][exists] && checkCollision(bullet, centipede,i) && bullet[exists] == true && centipede[i][y] < resolutionY- boxPixelsY*6) 
			{
			
				bulletHitSound.play();
			
				 //Bullet hit centipede segment
				if (centipede[i][3]==true) 
				{
		                score += 20;
		                }
		                else if(centipede[i][3]==false)
		                score += 10;
		                
		                 bullet[exists] = false;
		                // Create a mushroom at the hit position
		                mushroom[tempindexm][exists]=true;
		                mushroom[tempindexm][x] = centipede[i][x];
		                mushroom[tempindexm][y] = centipede[i][y];
		                tempindexm++;

		           	//Destroy the hit segment
		            	 centipede[i][exists] = false;
		           	
		           	if(centipede[i+1][exists])
		           	 centipede[i+1][3]=true;

		            // it is to break out of the loop to ensure only one segment is destroyed
		        
		            break;
		        }
		        
		        else if (centipede[i][exists] && checkCollision(bullet, centipede,i) && bullet[exists] == true && centipede[i][y] >= resolutionY- boxPixelsY*6) 
			{
				bulletHitSound.play();
				
				 //Bullet hit centipede segment
				if (centipede[i][3]==true) 
				{
		                score += 20;
		                }
		                else if(centipede[i][3]==false)
		                score += 10;
		                
		                bullet[exists] = false;
		                
		                // Create a mushroom at the hit position
		                mushroom[tempindexm][exists]=true;
		                mushroom[tempindexm][x] = centipede[i][x];
		                mushroom[tempindexm][y] = centipede[i][y];
		                mushroom[tempindexm][3] = true;
		                tempindexm++;

		           	//Destroy the hit segment
		            	centipede[i][exists] = false;
		           	 
		           	if(centipede[i+1][exists])
		           	centipede[i+1][3]=true;

		            // it is to break out of the loop to ensure only one segment is destroyed
		        
		            break;
		        }
		  
		}
		
		//to check the collision between bullet and the mushroom
		for ( int i=0; i<tempindexm ; i++ )
		{
			if(mushroom[i][exists] && checkCollision(bullet,mushroom,i) && bullet[exists])
			{
				if(mushroom[i][4]==2)
				{	
					bulletHitSound.play();
					bullet[exists]=false;
					mushroom[i][4] -= 1;
					break;
				}
				
				else
				{	
					bulletHitSound.play();
					bullet[exists]=false;
					mushroom[i][exists]=false;
					score += 1;
					break;
				}

			}	
		} 
		    
		
		//condition to check for collision & game over
		for(int i=0;i<12;i++)
		if ( (checkGameOver(player,centipede,i)&&(centipede[i][exists])) || (checkCollision(player,mushroom,i+numMushrooms)) || (checkCollision(player, spider) && spider[exists]) )
		{
			sf::sleep(sf::seconds(1));  // display feels stuck for 1 sec to show that the play collided with the centipede... moye moye

			// Display final score
			sf::Text gameOverText;
			gameOverText.setFont(font);
			gameOverText.setCharacterSize(36);
			gameOverText.setFillColor(sf::Color::White);
			gameOverText.setPosition(300, 400);
			gameOverText.setString("Game Over\nFinal Score: " + std::to_string(score));

			window.clear();
			window.draw(gameOverText);
			window.display();

			sf::sleep(sf::seconds(3));  // Display final score for 3 seconds
			
			
			for (int i=0;i<13;i++)
			delete[] centipede[i];
			delete[] centipede;
			
			for (int i=0;i<maxmushrooms;i++)
			delete [] mushroom[i];
			delete [] mushroom;
				return 0;
			
		}

		// Display the score
		scoreText.setString("Score: " + std::to_string(score));
		window.draw(scoreText);
	
	
		bool win = true;
		for(int i=0;i<12;i++)
		if (centipede[i][exists]) 
		win = false;
		
		if (win)
		{
		sf::sleep(sf::seconds(1)); 
		
		// Display winning window 
			sf::Text gameOverText;
			gameOverText.setFont(font);
			gameOverText.setCharacterSize(36);
			gameOverText.setFillColor(sf::Color::White);
			gameOverText.setPosition(300, 400);
			gameOverText.setString("Level completed \nNext level...");

			window.clear();
			window.draw(gameOverText);
			window.display();

			sf::sleep(sf::seconds(3)); 
			
			
			// Resetting the game 
			
			
			level++;
			int extra=level*2;
			spider[exists]=true;
			
			//Reinitialization  
			
			centipedeSpeed += (level/4);
			
			if(level==2)
			{
			centipedeBodyTexture.loadFromFile("Textures/segment2.png");
			centipedeHeadTexture.loadFromFile("Textures/head2.png");
			}
			else
			{
			centipedeBodyTexture.loadFromFile("Textures/segment3.png");
			centipedeHeadTexture.loadFromFile("Textures/head3.png");
			}
			
			
			for (int i = 0; i <13; ++i) 
			{
				centipede[i][x] = (rcinaitialx+i) * boxPixelsX;
				centipede[i][y] = 0 ; //for random placement of the centipede
				centipede[i][exists] = true;
				if(i==0)
				centipede[i][3]=true;
				else
				centipede[i][3]=false;
				if(i==12)
				centipede[i][exists]=false;
			}
			
			numMushrooms += extra;
			
			for (int i = 0; i < maxmushrooms; i++) 
			{	
				if(i<numMushrooms)
				{
					mushroom[i][exists]=true;mushroom[i][3]=false;mushroom[i][4]=2;
					mushroom[i][x] = rand() % (gameCols - 2) * boxPixelsX + boxPixelsX;  // Avoid placing mushrooms on border columns
					mushroom[i][y] = rand() % (gameRows - 6) * boxPixelsY;  // Start from the second row
				}
				else
				{
					mushroom[i][exists]=false;
					mushroom[i][3]=false;//for poisonous mushrooms
					mushroom[i][4]=2;//for half mushroom
				}
			}
			
			
		
		
		}
		
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
			
			for (int i=0;i<13;i++)
			delete[] centipede[i];
			delete[] centipede;
			
			for (int i=0;i<maxmushrooms;i++)
			delete [] mushroom[i];
			delete [] mushroom;
				return 0;
			}
		}		
		window.display();
		window.clear();
	}
}

///////////////////////////////////////////
//                                       //
// Writing my functions definitions here.//
//                                       //
///////////////////////////////////////////


void movePlayer(float player[])//used to move the player & solved the problem of player moment (used the limit of 6 rows)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player[x] > 0)
	{
		player[x] -= 0.3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player[y] > resolutionY- boxPixelsY*6)// --> here  (768)  could also be used
	{
		player[y] -= 0.3;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player[y] < resolutionY - boxPixelsY) 
	{
		player[y] += 0.3;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player[x] < resolutionX - boxPixelsX) 
	{
		player[x] += 0.3;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player[y] > resolutionY- boxPixelsY*6) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player[x] > 0)) 
	{
		player[y] -= 0.2;
		player[x] -= 0.2;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&player[x]<resolutionX-boxPixelsX)&&(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&player[y]<resolutionY-boxPixelsY)) 
	{
		player[x] += 0.2;
		player[y] += 0.2;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player[y] > resolutionY- boxPixelsY*6) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player[x] < resolutionX - boxPixelsX)) 
	{
		player[y] -= 0.2;
		player[x] += 0.2;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player[x] > 0)&&(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&player[y]<resolutionY-boxPixelsY)) 
	{
		player[x] -= 0.2;
		player[y] += 0.2;
	}

}

void drawPlayer(sf::RenderWindow& window, float player[], sf::Sprite& playerSprite) // it is used to draw the player 
{
	playerSprite.setPosition(player[x], player[y]);
	window.draw(playerSprite);
}

void firebullet(float bullet[], float player[], sf::Sound& bulletFireSound)// Fire a bullet when the 'F' key is pressed and there's no existing bullet
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && !bullet[exists]) {
        bullet[x] = player[x] + 12; // Adjust bullet position
        bullet[y] = player[y] - boxPixelsY;
        bullet[exists] = true;
        bulletFireSound.play();
       
    }
}


void moveBullet(float bullet[], sf::Clock& bulletClock) //part of the skeliton & it is used to move bullet
{
	if (bulletClock.getElapsedTime().asMilliseconds() < 2)
		return;

	bulletClock.restart();
	bullet[y] -= 3;	
	if (bullet[y] < -32)
		bullet[exists] = false;

}
void drawBullet(sf::RenderWindow& window, float bullet[], sf::Sprite& bulletSprite) // part of the skeliton & is used to draw bullet
{
	bulletSprite.setPosition(bullet[x], bullet[y]);
	window.draw(bulletSprite);
}
void moveCentipede(float** centipede, float centipedeSpeed, float **mushroom, int M)//this function is used to move centipede... if it hits the mushroom then it goes to next line and changes its direction 
{
	for (int i = 0; i < 12; i++) 
	{
	        // Check for collision with mushrooms
	        bool hit = false;
	        for (int j = 0; j < M; j++) 
	        {
			if (checkCollision(centipede, i, mushroom, j) && mushroom[j][exists]) 
			{
        		        hit = true;
        		        break;
			}
        
		}

		// Move segments separately if a mushroom was hit
        	if (hit) 
        	{
				if (int(centipede[i][y]) % 64 != 0) 
				{
        		        	centipede[i][y] += 32;
        		        	centipede[i][x] -= centipedeSpeed;
				}
				else 
				{
	        	        	centipede[i][y] += 32;
	        	        	centipede[i][x] += centipedeSpeed;
        		    	}
       		}
				
		else 
        	{
			if (centipede[i][x] < 0 || centipede[i][x] >= resolutionX - boxPixelsX) 
            		{
            		
            			if(centipede[i][y] > resolutionY - 64)
            			centipede[i][y] -= boxPixelsY*6;
            		
        		        centipede[i][y] += 32;
			}
            
            		if (int(centipede[i][y]) % 64 != 0) 
            		{
       			    	centipede[i][x] += centipedeSpeed;
      			} 
       			else 
       			{
                			centipede[i][x] -= centipedeSpeed;
				}
			} 
	}
}


void drawCentipede(sf::RenderWindow& window, sf::Texture& centipedeBodyTexture, sf::Texture& centipedeHeadTexture,float** centipede) //the function is used to draw the centipede & solved the provlem of drawing it
{
	for (int i = 0; i < 12; ++i) 
	{
		if (centipede[i][exists]) 
		{
			sf::Sprite segmentSprite;
			segmentSprite.setTexture(centipedeBodyTexture);
			segmentSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
			segmentSprite.setPosition(centipede[i][x], centipede[i][y]);

		// it is to use head texture for the first segment
		if (centipede[i][3]) //conditions for head 
		{
		        segmentSprite.setTexture(centipedeHeadTexture);
		}
			window.draw(segmentSprite);
		}
	}
}


void drawMushroom(sf::RenderWindow& window, float **mushroom, int i, sf::Sprite& mushroomSprite, sf::Sprite& pmushroomSprite,sf::Sprite& mushroomfSprite, sf::Sprite& pmushroomfSprite)//it draw all the types of mushroom 
{
	if (mushroom[i][exists]) 
	{
		if (!mushroom[i][3] && mushroom[i][4]==2) // Normal mushroom (non hurt)
		{
			mushroomSprite.setPosition(mushroom[i][x], mushroom[i][y]);
			window.draw(mushroomSprite);
		} 
		else if (mushroom[i][3] && mushroom[i][4]==2) // Poison mushroom (non hurt)
		{
			pmushroomSprite.setPosition(mushroom[i][x], mushroom[i][y]);
			window.draw(pmushroomSprite);
		}
		
		else if (!mushroom[i][3] && mushroom[i][4]==1) // Normal mushroom (hurt)
		{
			mushroomfSprite.setPosition(mushroom[i][x], mushroom[i][y]);
			window.draw(mushroomfSprite);
		} 
		else // Poison mushroom (hurt)
		{
			pmushroomfSprite.setPosition(mushroom[i][x], mushroom[i][y]);
			window.draw(pmushroomfSprite);
		}
	}
}

void movespider(float spider[]) 
{
    static int direction = 1;

    spider[x] += 0.2 * direction;

	if (spider[x] < 0) 
	{
	        direction = 1;
	        spider[x] = 0;
	} 
	else if (spider[x] > resolutionX - boxPixelsX) 
	{
		direction = -1;
		spider[x] = resolutionX - boxPixelsX;
	}
}


void drawspider(sf::RenderWindow& window, float spider[], sf::Sprite& spiderSprite) 
{	
	if(spider[exists])
	{
		spiderSprite.setPosition(spider[x], spider[y]);
		window.draw(spiderSprite);
	}
}

bool checkCollision(float bullet[], float **target,int i) // finds out the collision between bullet & centipede || centipede
{

	return (bullet[x] < target[i][x] + (boxPixelsX/2+5) && bullet[x] + (boxPixelsX/2+5) > target[i][x] && bullet[y] < target[i][y] + (boxPixelsY/2) && bullet[y] + (boxPixelsY/2+5) > target[i][y]);

}

bool checkCollision(float **centipede,int i, float **mushroom,int j)// to check the collision between the mushroom and centipede
{
	return (centipede[i][x] < mushroom[j][x] + (boxPixelsX/2-2) && centipede[i][x] + (boxPixelsX/2-2) > mushroom[j][x] && centipede[i][y] < mushroom[j][y] + (boxPixelsY/2-2) && centipede[i][y] + 		(boxPixelsY/2-2) > mushroom[j][y]);

}

bool checkCollision(float bullet[], float target[])//it is used to check the collision between bullet and spider and also for player & spider 
{
return (bullet[x] < target[x] + (boxPixelsX/2+5) && bullet[x] + (boxPixelsX/2+5) > target[x] && bullet[y] < target[y] + (boxPixelsY/2) && bullet[y] + (boxPixelsY/2+5) > target[y]);
}

bool checkGameOver(float player[], float **centipede,int i)// it is used to check game over
{
	return checkCollision(player, centipede,i);
}



