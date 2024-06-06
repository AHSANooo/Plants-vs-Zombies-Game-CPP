#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;



class Zombie {
protected:
    int NoOfFrames; // Adjust the number of frames as needed
    Texture* animationFrames; // Array to store animation frames
    int currentFrameIndex; // Index of the current animation frame
    float speed;
    Clock frameTimer; // Timer to control the timing of frame changes
    float frameChangeInterval; // Interval between frame changes (in seconds)
    Sprite zombieSprite;
    
    //sf::Texture texture;

    //For eating Prpose
    Texture* eatingFrames;
    int currentEatFrameIndex;
    float eatFrameChangeInterval;
    int noOfEatingFrames;
    Clock eatTimer;


    //For Dying Purpose
    Texture* dieFrames;
    int currentDieIndex;
    float dieFrameChangeInterval;
    int noOfDieFrames;
    Clock dieTimer1;
    Clock dieTimer2;

    //For CherryExplosion Purpose
    Texture* explosionFrames;
    int currentExplosionFrames;
    int noOfExplosionFrames;
    float explosionFramChangeInterval;
    Clock explosionTimer1;
    Clock explosionTimer2;

    //Especial for Dropping Zombie
    Texture* dropTexture;
    int currentDropFrameIndex;
    int noOfDropFrames;
    float dropFrameChangeInterval;
    Clock dropClock1;
    Clock dropClock2;


    //Especial for Flying Texture for Flying Zombie
    Texture* flyTextur;
    int currentFlyFrameIndex;
    int noOfFLyFrameIndex;
    float flyFrameChangeInterval;
    Clock flyClock1;
    Clock flyClock2;


    std::string name;
    int damage;
    bool alive;
    int totalHits;
    int hits;
    bool move;
    bool eat;
    bool deadZombie;
    bool boom;
    int positionX;
    int positionY;
    bool getAwayFromEating;
    bool drop;//Only For Balloon Zombie
    bool fly;
public:
    
    Zombie(int noOfFrame, float fci,int noOfEatFrames,float efci,int noOfDieFrames,float dfci, float s, const string& name,int th)
        :NoOfFrames(noOfFrame),frameChangeInterval(fci),noOfEatingFrames(noOfEatFrames),eatFrameChangeInterval(efci),
        noOfDieFrames(noOfDieFrames),dieFrameChangeInterval(dfci), speed(s),name(name),totalHits(th)
    {
        animationFrames = new Texture[noOfFrame];
        eatingFrames = new Texture[noOfEatingFrames];
        dieFrames = new Texture[noOfDieFrames];
        move = true;
        eat = false;
        alive = true;
        deadZombie = false;
        currentFrameIndex = 0;
        currentEatFrameIndex = 0;
        currentDieIndex = 0;
        positionX = 0;
        positionY = 0;
        hits = 0;
        getAwayFromEating = 0;
        //Temporarily here

        currentExplosionFrames=0;
        noOfExplosionFrames = 20;
        explosionFramChangeInterval = 0.25;
        explosionFrames = new Texture[noOfExplosionFrames];
        boom = false;


        //Especial For Ballon Zombie

        currentDropFrameIndex = 0;
        noOfDropFrames = 29;
        dropFrameChangeInterval =0.04;
        Clock dropClock1;
        Clock dropClock2;

        dropTexture =new Texture[noOfDropFrames];

        drop = false;

        currentFlyFrameIndex = 0;
        noOfFLyFrameIndex = 4;
        flyFrameChangeInterval = 0.25;
        flyTextur = new Texture[noOfFLyFrameIndex];
        fly = true;
        Clock flyClock1;
        Clock flyClock2;



        zombieSprite.setPosition(positionX, positionY);
        for (int i = 0; i < NoOfFrames; ++i) {
            
            if (name == "FootballZombie" && !animationFrames[i].loadFromFile("Images/football ("+to_string(i+1)+").gif"))
            {
                cout << "Failed to load animation frame" << i << endl;
            }
            else if (name == "SimpleZombie" && !animationFrames[i].loadFromFile("Images/simple (" + to_string(i + 1) + ").gif"))
            {
                cout << "Failed to load animation frame" << i << endl;
            }
            else if (name == "DancingZombie" && !animationFrames[i].loadFromFile("Images/dance/dance (" + to_string(i+1) + ").gif"))
            {
                cout << "Failed to load animation frame" << i << endl;
            }
            else if (name == "BalloonZombie" && !animationFrames[i].loadFromFile("Images/BalloonWalking/BalloonWalking" + to_string(i+1) + ".png"))
            {
                cout << "Failed to load animation frame in walking " << i << endl;
            }
            else if (name == "PartnerZombie" && !animationFrames[i].loadFromFile("Images/summondance/summondance (" + to_string(i + 1) + ").gif"))
            {
                cout << "Failed to load animation frame" << i << endl;
            }
        }
        //Eating Sprite Texture loading
        
        for (int j = 0; j < noOfEatingFrames; j++) {
            if (name == "SimpleZombie" && !eatingFrames[j].loadFromFile("Images/simple_eat (" + to_string(j + 1) + ").gif"))
            {
                cout << "Failed to load animation frame" << j << endl;
            }
            else if (name == "FootballZombie" && !eatingFrames[j].loadFromFile("Images/football_eat (" + to_string(j + 1) + ").gif"))
            {
                cout << "Failed to load animation frame" << j << endl;
            }
            else if (name == "DancingZombie" && !eatingFrames[j].loadFromFile("Images/dancing_eat/dancing (" + to_string(j+1) + ").gif"))
            {
                cout << "Failed to load animation frame in Eating" << j << endl;
            }
            else if (name == "BalloonZombie" && !eatingFrames[j].loadFromFile("Images/BalloonEating/BalloonEating" + to_string(j + 1) + ".png"))
            {
                cout << "Failed to load animation frame in Eating " << j << endl;
            }
            else if (name == "PartnerZombie" && !eatingFrames[j].loadFromFile("Images/summon_eat/summon_eat (" + to_string(j + 1) + ").gif"))
            {
                cout << "Failed to load animation frame" << j << endl;
            }
            
        }
        //Die Sprite texture Loading

        

        for (int k = 0; k < noOfDieFrames; k++) {
            if (name == "SimpleZombie" && !dieFrames[k].loadFromFile("Images/simple_die (" + to_string(k + 1) + ").gif"))
            {
                cout << "Failed to load animation frame" << k << endl;
            }
            else if (name == "FootballZombie" && !dieFrames[k].loadFromFile("Images/football_die (" + to_string(k + 1) + ").gif"))
            {
                cout << "Failed to load animation frame" << k << endl;
            }
            else if (name == "BalloonZombie" && !dieFrames[k].loadFromFile("Images/BalloonDying/BalloonDying" + to_string(k) + ".png"))
            {
                cout << "Failed to load animation frame in Dying" << k << endl;
            }
            else if (name == "DancingZombie" && !dieFrames[k].loadFromFile("Images/dancing_die/die (" + to_string(k+1) + ").gif"))
            {
                cout << "Failed to load animation frame" << k << endl;
            }
            else if (name == "PartnerZombie" && !dieFrames[k].loadFromFile("Images/summon_die/summon_die ("+ to_string(k+1)+").gif"))
            {
                cout << "Failed to load animation frame" << k << endl;
            }
        }
        //boom_die (1)
        for (int l = 0; l < noOfExplosionFrames; l++) {
            if (!explosionFrames[l].loadFromFile("Images/boom_die (" + to_string(l + 1) + ").gif"))
            {
                cout << "Failed to load animation frame in Explosion " << l << endl;
            }
        }
        //Balloon Zombie Loading 
        for (int i = 0; i < noOfDropFrames; i++) {
            if (name == "BalloonZombie" && !dropTexture[i].loadFromFile("Images/BalloonDropping/BalloonDropping" + to_string(i + 1) + ".png"))
            {
                cout << "Failed to load animation frame in Droping" << i << endl;
            }
        }
        for (int i = 0; i < noOfFLyFrameIndex; i++) {
            if (name == "BalloonZombie" && !flyTextur[i].loadFromFile("Images/BalloonFlying/baloon" + to_string(i + 1) + ".png"))
            {
                cout << "Failed to load animation frame in Droping" << i << endl;
            }
        }
        zombieSprite.setTexture(animationFrames[currentFrameIndex]);

    }
    void drawZombie(sf::RenderWindow& window) {
        if(!deadZombie)
        window.draw(zombieSprite);
    }
    Sprite& getSprite() {
        return zombieSprite;
    }
    
    
    
    string getname()
    {
        return name;
    }
    //}
    /*static int getdieTime() {
        return dieTimer.getElapsedTime().asSeconds();
    }*/
    void update(RenderWindow& window) {

//        if (zombieSprite.getPosition().x >= 200) {

        
            if (fly && name == "BalloonZombie") {
        //  zombieSprite.move(-0.05, 0);
          //cout << "Flying time " << endl;
          if (flyClock1.getElapsedTime().asSeconds() >= flyFrameChangeInterval) {
              currentFlyFrameIndex = (currentFlyFrameIndex + 1) % noOfFLyFrameIndex;
              zombieSprite.setTexture(flyTextur[currentFlyFrameIndex]);
              flyClock1.restart();
          }
      }
      else if(move && !eat && !boom && alive && !drop)
        { 
      //   cout << "WALKING" << endl;
          //  zombieSprite.move(-speed, 0);
           // zombieSprite.setPosition(zombieSprite.getPosition().x - speed, zombieSprite.getPosition().y);
            if (frameTimer.getElapsedTime().asSeconds() >= frameChangeInterval) {
                currentFrameIndex = (currentFrameIndex + 1) % NoOfFrames;
                zombieSprite.setTexture(animationFrames[currentFrameIndex]);
                frameTimer.restart();
            }
        }
        else if (!move && eat && alive && !boom && !drop) {
        //  cout << "EATNG" << endl;
            if (frameTimer.getElapsedTime().asSeconds() >= eatFrameChangeInterval) {
                currentEatFrameIndex = (currentEatFrameIndex + 1) % noOfEatingFrames;
                zombieSprite.setTexture(eatingFrames[currentEatFrameIndex]);
                frameTimer.restart();
            }
            
        }//!move && eat && alive
        else if ( boom && !drop) {
          //cout << "BOOM ELIF CALLED " << endl;
          if(explosionTimer2.getElapsedTime().asSeconds()<5){
         // cout << "EXPLOSION" << endl;
             if (explosionTimer1.getElapsedTime().asSeconds() >= explosionFramChangeInterval) {
                  currentExplosionFrames = (currentExplosionFrames + 1) % noOfExplosionFrames;
                zombieSprite.setTexture(explosionFrames[currentExplosionFrames]);
                explosionTimer1.restart();
             }
          }
          else {
              deadZombie = true;
          }
        }//
        else if ( !alive && !drop ) {
             if(dieTimer2.getElapsedTime().asSeconds() < 2.5){
         // cout << "DYING " << endl;
                 if (dieTimer1.getElapsedTime().asSeconds() >= dieFrameChangeInterval) {
                 currentDieIndex = (currentDieIndex + 1) % noOfDieFrames;
                 zombieSprite.setTexture(dieFrames[currentDieIndex]);
                 dieTimer1.restart();
                }
             }
             else {
                 deadZombie=true;
             }

        }//SPecially for Balloon ZOmbie
        else if (drop && name=="BalloonZombie") {
         
          if (dropClock2.getElapsedTime().asSeconds() < 1.16) {
            // cout << "DROPPING " << endl;
              if (dropClock1.getElapsedTime().asSeconds() >= dropFrameChangeInterval) {
                  currentDropFrameIndex = (currentDropFrameIndex + 1) % noOfDropFrames;
                  zombieSprite.setTexture(dropTexture[currentDropFrameIndex]);
                  dropClock1.restart();
              }
          }
          else {
              drop = false;
          }
        }
            if(!deadZombie)
        drawZombie(window);
      //  }
    }
    void draw(RenderWindow& window) {
        window.draw(zombieSprite);
    }
    bool isZombieRip() {
        return alive;
        dieTimer1.restart();
        dieTimer2.restart();
    }
    bool getMove() {
        return move;
    }
    void setMove(bool b) {
        move = b;
    }
    void setEat(bool a) {
        eat = a;
    }
    bool getEat() {
        return eat;
    }
    void setZombieRip(bool b) {
        alive = b;
        dieTimer1.restart();
        dieTimer2.restart();
    }
    void setDrop() {
        if (name == "BalloonZombie" && !drop) {
            cout << "Set Drop Called " << endl;
           // if (hits == 1 && !drop) {
                drop = true;
                fly = false;
                dropClock1.restart();
                 dropClock2.restart();
            //}
        }
    }
    void decreaseHealthZombie() {
        if(hits<totalHits){
        hits++;
    //    cout << "HITS " << hits << endl;
        if (hits == 1) {
            setDrop();
        }
        if (hits == totalHits) {
            //deadZombie = true;
                alive = false;
                dieTimer2.restart();
                dieTimer1.restart();
               
             }
        }
    }
    
    void setZombiePosition(int x, int y) {
        positionX = x;
        positionY = y;
        zombieSprite.setPosition(x, y);
    }
    void setZombieBoom() {
        if (!boom) {
            boom = 1;
            alive = false;
            explosionTimer2.restart();
            explosionTimer1.restart();
           // dropClock1.restart();
           // dropClock2.restart();
        }
    }
    int getZombiePositionX()
    {
        return positionX;
    }
    int getZombiePositionY()
    {
        return positionY;
    }
    void dieZombie() {
        deadZombie = true;
    }
    void setDeadFalse() {
        deadZombie = false;
    }
    void setZombieAlive(bool a) {
        alive = a;
    }
    virtual void moveZombie(int a) = 0;
    
};
