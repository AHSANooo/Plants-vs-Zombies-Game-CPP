#pragma once
//#ifndef PLANTSVSZOMBIES_H
//#define PLANTSVSZOMBIES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include<cstring>
#include <ctime>

using namespace std;
using namespace sf;

//class badge

class badge
{
    sf::Texture badgeTexture;
    sf::Sprite badgeSprite;
public:
    badge();
    badge(const string& Texturepath, int posX, int posY);
    void draw(RenderWindow& window);
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//POPUP CLASS
class popupwindow
{
private:
    sf::Texture popupTexture;
    sf::Sprite popupSprite;
public:
    popupwindow();
    void draw(sf::RenderWindow& window);
    bool isclickedpopup(int mouseX, int mouseY);
};
//
//CLASS BUTTON
class Button
{
    sf::Text buttonText;
    sf::Texture buttonTexture;
    sf::Sprite buttonSprite;

public:
    Button();
    Button(const string& Texturepath, int posX, int posY);
    void draw(sf::RenderWindow& window);
    bool isclickedplay(int mouseX, int mouseY);
    bool isclickedinstruction(int mouseX, int mouseY);
    bool isclickedtick(int mouseX, int mouseY);
    bool isclickedpause(int mouseX, int mouseY);
    bool isclickedstartbutton(int mouseX, int mouseY);
    bool isclickedhighscore(int mouseX, int mouseY);
    bool isclickedhighscoretick(int mouseX, int mouseY);
};

//CLASS MENUSCREEN
class MenuScreen
{
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

public:
    MenuScreen();
    void draw(sf::RenderWindow& window);
};

//CLASS LEVEL
class Level
{
    sf::Texture levelTexture;
    sf::Sprite levelSprite;
public:
    Level();
    void draw(sf::RenderWindow& window);
    bool isClickedLevel1(int mouseX, int mouseY);
    bool isClickedLevel2(int mouseX, int mouseY);
    bool isClickedLevel3(int mouseX, int mouseY);
};


// Function declarations
void createBack(sf::RenderWindow& window);
void createScorebox(sf::RenderWindow& window);
void createSunicon(sf::RenderWindow& window);
void displayscore(sf::RenderWindow& window, int score, sf::Font& font);
void createPopup2(RenderWindow& window);
void createPausescreen(RenderWindow& window);
bool quitbuttonclicked(int mouseX, int mouseY);
bool restartbuttonclicked(int mouseX, int mouseY);
bool resumebuttonclicked(int mouseX, int mouseY);
void createInstruction(sf::RenderWindow& window, sf::Font& font);
void createLevel1Instruction(RenderWindow& window, Font font);
void createLevel2Instruction(RenderWindow& window, Font font);
void createLevel3Instruction(RenderWindow& window, Font font);
void createprofilescreen(RenderWindow& window);
void createlevelbox(RenderWindow& window, int lives, Font font);
//#endif // PLANTSVSZOMBIES_H


//#include "menus.h"
//#include"Game.h"
//#include<iostream>
//#include<cstring>
//#include <SFML/Graphics.hpp>
//#include <ctime>
//#include<fstream>
//using namespace sf;
//using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Button Class Definitions
Button::Button()
{
    buttonSprite.setPosition(0, 0);
}

Button::Button(const string& Texturepath, int posX, int posY)
{
    if (!buttonTexture.loadFromFile(Texturepath)) {
        cout << "Failed to load button image from " << Texturepath << endl;
        return;
    }
    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setPosition(posX, posY);
    buttonSprite.setColor(sf::Color(255, 255, 255, 240));
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(buttonSprite);
}

bool Button::isclickedplay(int mouseX, int mouseY)
{
    return (mouseX >= 440 && mouseX <= 440 + 210 && mouseY >= 105 && mouseY <= 105 + 150);
}

bool Button::isclickedinstruction(int mouseX, int mouseY)
{
    return (mouseX >= 440 && mouseX <= 440 + 210 && mouseY >= 185 && mouseY <= 185 + 150);
}

bool Button::isclickedtick(int mouseX, int mouseY)
{
    return (mouseX >= 900 && mouseX <= 900 + 130 && mouseY >= 430 && mouseY <= 430 + 140);
}

bool Button::isclickedpause(int mouseX, int mouseY)
{
   // cout << "Mouse x is " << mouseX << " mouse y is " << mouseY << endl;
    return(mouseX >= 1030 && mouseX <= 1100 && mouseY >= 10 && mouseY <= 75);
}

bool Button::isclickedstartbutton(int mouseX, int mouseY)
{

    return (mouseX >= 550 && mouseX <= 800 && mouseY >= 350 && mouseY <= 600);
}

bool Button::isclickedhighscore(int mouseX, int mouseY)
{
    return(mouseX >= 440 && mouseX <= 650 && mouseY >= 265 << mouseY <= 265 + 150);
}

bool Button::isclickedhighscoretick(int mouseX, int mouseY)
{
    return (mouseX >= 900 && mouseX <= 900 + 130 && mouseY >= 430 && mouseY <= 430 + 140);
}
//////////////////////////////////////////////////////////////////////////////////
// MenuScreen Class Definitions
MenuScreen::MenuScreen() {
    cout << "Drawing background" << endl;
    if (!backgroundTexture.loadFromFile("Images/background.png"))
    {
        cout << "Failed to load background image!" << std::endl;
        return;
    }

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);
}

void MenuScreen::draw(sf::RenderWindow& window)
{
    window.draw(backgroundSprite);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Badge class definition
badge::badge()
{
    badgeSprite.setPosition(0, 0);
}
badge::badge(const string& Texturepath, int posX, int posY)
{
    if (!badgeTexture.loadFromFile(Texturepath))
    {
        cout << "failed to load image" << endl;
        return;
    }
    badgeSprite.setTexture(badgeTexture);
    badgeSprite.setPosition(posX, posY);
}

void badge::draw(sf::RenderWindow& window)
{
    window.draw(badgeSprite);
}
///////////////////////////////////////////////////////////////////////////////
//Popupwindow class definitions
popupwindow::popupwindow()
{
    if (!popupTexture.loadFromFile("Images/popupwindow.png"))
    {
        cout << "Failed to load background image!" << std::endl;
        return;
    }
    popupSprite.setTexture(popupTexture);
}



void popupwindow::draw(RenderWindow& window)
{
    window.draw(popupSprite);
}

bool popupwindow::isclickedpopup(int mouseX, int mouseY)
{
    return  (mouseX >= 950 && mouseX <= 950 + 130 && mouseY >= 450 && mouseY <= 690);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Level::Level()
{
    if (!levelTexture.loadFromFile("Images/levels.png"))
    {
        cout << "Failed to load background image!" << std::endl;
        return;
    }
    levelSprite.setTexture(levelTexture);
}

void Level::draw(RenderWindow& window)
{
    window.draw(levelSprite);
}

bool Level::isClickedLevel1(int mouseX, int mouseY)
{
    return (mouseX >= 600 && mouseX <= 915 && mouseY >= 100 && mouseY <= 205);
}

bool Level::isClickedLevel2(int mouseX, int mouseY)
{
    return (mouseX >= 600 && mouseX <= 915 && mouseY >= 210 && mouseY <= 310);
}

bool Level::isClickedLevel3(int mouseX, int mouseY)
{
    return (mouseX >= 600 && mouseX <= 915 && mouseY >= 320 && mouseY <= 410);
}
///////////////////////////////////////////////////////////////////////////////////
// Function Definitions
void createBack(sf::RenderWindow& window)
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

void createScorebox(sf::RenderWindow& window)
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

void createSunicon(sf::RenderWindow& window)
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

void displayscore(sf::RenderWindow& window, int score, sf::Font& font)
{
    // Create the score text
    Text scoreText("Score: " + std::to_string(score), font, 20);
    scoreText.setFillColor(Color::Black);
    scoreText.setPosition(150, 15);

    // Draw the score text to the window
    window.draw(scoreText);
}

void createPopup2(sf::RenderWindow& window)
{
    Image popup2;
    popup2.loadFromFile("Images/popupwindow2.png");
    Texture popup2Texture;
    popup2Texture.loadFromImage(popup2);
    Sprite popup2Sprite;
    popup2Sprite.setTexture(popup2Texture);
    popup2Sprite.setPosition(0, 0);
    window.draw(popup2Sprite);
}

void createInstruction(sf::RenderWindow& window, sf::Font& font)
{
    Image instruction;
    instruction.loadFromFile("Images/instructionpage.jpg");
    Texture instructiontexture;
    instructiontexture.loadFromImage(instruction);
    Sprite instructionsprite;
    instructionsprite.setTexture(instructiontexture);
    instructionsprite.setPosition(0, 0);
    instructionsprite.setColor(Color(255, 255, 255, 120));
    window.draw(instructionsprite);
    Text instructionText;
    instructionText.setFont(font);
    instructionText.setCharacterSize(25);
    instructionText.setFillColor(Color::White);
    instructionText.setPosition(50, 50); // Adjust position as needed

    // Set the instruction text content
    string instructions = "Welcome to Plants vs. Zombies!\n\n"
        "Your home has been attacked by zombies. Follow the instructions to stop the zombies\n from eating your brain.\n\n"
        "- Plant different types of plants to defend your house from incoming zombies.\n"
        "- Collect suns to plant more plants.\n"
        "- Click on sun icons to collect them.\n"
        "- Defeat all zombies and move to the next level.\n"
        "- Enjoy playing!\n"
        "-Press tick to go back and start the game.\n";
    instructionText.setString(instructions);
    // Draw the instruction text to the window
    window.draw(instructionText);
}

void createPausescreen(RenderWindow& window)
{
    Image pausescreen;
    pausescreen.loadFromFile("Images/pausescreen.png");
    Texture pausescreenTexture;
    pausescreenTexture.loadFromImage(pausescreen);
    Sprite pausescreenSprite;
    pausescreenSprite.setTexture(pausescreenTexture);
    pausescreenSprite.setPosition(0, 0);
    window.draw(pausescreenSprite);
}

bool quitbuttonclicked(int mouseX, int mouseY)
{
    cout << "mousex is " << mouseX << " and mouseY is " << mouseY << endl;
    return(mouseX >= 340 && mouseX <= 700 && mouseY >= 485 && mouseY <= 560);
}

bool restartbuttonclicked(int mouseX, int mouseY)
{
    return(mouseX >= 340 && mouseX <= 700 && mouseY >= 300 && mouseY <= 480);
}

bool resumebuttonclicked(int mouseX, int mouseY)
{
    return(mouseX >= 340 && mouseX <= 700 && mouseY >= 155 && mouseY <= 315);
}

void createLevel1Instruction(RenderWindow& window, Font font)
{
    Image instruction;
    instruction.loadFromFile("Images/instructionpage.jpg");
    Texture instructiontexture;
    instructiontexture.loadFromImage(instruction);
    Sprite instructionsprite;
    instructionsprite.setTexture(instructiontexture);
    instructionsprite.setPosition(0, 0);
    instructionsprite.setColor(Color(255, 255, 255, 110));
    window.draw(instructionsprite);
    Text instructionText;
    instructionText.setFont(font);
    instructionText.setCharacterSize(25);
    instructionText.setFillColor(Color::White);
    instructionText.setPosition(50, 50);
    string instructions = "Objectives of this level:\n\n"
        "-Plant sunflowers to generate sunlight.\n"
        "- Defend against incoming zombies using pea shooters.\n"
        "- Strategically use lawnmowers as a last line\E1of\E1defense.\n"
        "- You Will Encounter 10 Zombies and can plant 10 Plants to kill them.\n"
        "- You have 3 lives: \n"
        "- If One Zombie Reaches Your Home One Life Will be deducted.\n"
        "- Kill all zombies to go to next level.\n"
        "- Enjoy playing!\n"
        "-Press start to start the level.\n";
    instructionText.setString(instructions);
    window.draw(instructionText);
}

void createLevel2Instruction(RenderWindow& window, Font font)
{
    Image instruction;
    instruction.loadFromFile("Images/instructionpage.jpg");
    Texture instructiontexture;
    instructiontexture.loadFromImage(instruction);
    Sprite instructionsprite;
    instructionsprite.setTexture(instructiontexture);
    instructionsprite.setPosition(0, 0);
    instructionsprite.setColor(Color(255, 255, 255, 110));
    window.draw(instructionsprite);
    Text instructionText;
    instructionText.setFont(font);
    instructionText.setCharacterSize(25);
    instructionText.setFillColor(Color::White);
    instructionText.setPosition(50, 50);
    string instructions = "Objectives of this level:\n\n"
        "- New zombie types are introduced : Simple zombies, Football\nZombies, Flying Zombies, Dancing Zombies, and Dolphin Rider zombies.\n"
        "- Use wall-nuts for additional defense against stronger zombies.\n"
        "- Learn to use cherry bombs to clear out groups of\E1zombies.\n"
        "- You Will Encounter 20 Zombies and can plant 20 Plants to kill them.\n"
        "- You have 3 lives: \n"
        "- If One Zombie Reaches Your Home One Life Will be deducted.\n"
        "- Kill all zombies to go to next level.\n"
        "- Enjoy playing!\n"
        "- Press start to start the level.\n";
    instructionText.setString(instructions);
    window.draw(instructionText);
}

void createLevel3Instruction(RenderWindow& window, Font font)
{
    Image instruction;
    instruction.loadFromFile("Images/instructionpage.jpg");
    Texture instructiontexture;
    instructiontexture.loadFromImage(instruction);
    Sprite instructionsprite;
    instructionsprite.setTexture(instructiontexture);
    instructionsprite.setPosition(0, 0);
    instructionsprite.setColor(Color(255, 255, 255, 110));
    window.draw(instructionsprite);
    Text instructionText;
    instructionText.setFont(font);
    instructionText.setCharacterSize(25);
    instructionText.setFillColor(Color::White);
    instructionText.setPosition(50, 50);
    string instructions = "Objectives of this level:\n\n"
        "- Focus on sunflower placement for optimal sunlight production.\n"
        "- Introduce offensive plants like snow peas and repeaters to counter stronger zombie waves.\n"
        "- Kill all zombies to go to next level.\n"
        "- You Will Encounter 30 Zombies and can plant 45 Plants to kill them.\n"
        "- You have 3 lives: \n"
        "- If One Zombie Reaches Your Home One Life Will be deducted.\n"
        "- Enjoy playing!\n"
        "- Press start to start the level.\n";
    instructionText.setString(instructions);
    window.draw(instructionText);
}

void createprofilescreen(RenderWindow& window)
{
    Image profilescreen;
    profilescreen.loadFromFile("Images/background.jpg");
    Texture profilescreenTexture;
    profilescreenTexture.loadFromImage(profilescreen);
    Sprite profilescreenSprite;
    profilescreenSprite.setTexture(profilescreenTexture);
    profilescreenSprite.setPosition(0, 0);
    profilescreenSprite.setColor(Color(255, 255, 255, 100));
    window.draw(profilescreenSprite);
}

void  createlevelbox(RenderWindow& window, int lives, Font font)
{
    Image box;
    box.loadFromFile("Images/scorebox2.png");
    Texture boxtext;
    boxtext.loadFromImage(box);
    Sprite boxsprite;
    boxsprite.setTexture(boxtext);
    boxsprite.setPosition(300, -30);
    boxsprite.setColor(Color(255, 255, 255, 255));
    window.draw(boxsprite);
    Text livesText("Lives: " + std::to_string(lives), font, 22);
    livesText.setFillColor(Color::Black);
    livesText.setPosition(350, 16);
    window.draw(livesText);
}
