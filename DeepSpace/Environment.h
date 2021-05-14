#pragma once
#include <SFML/Graphics.hpp>
#include "SpaceObject.h"
#include "Player.h"
#include <iostream>
class Environment
{
private:
	sf::Texture bgTexture;
	sf::Sprite bgSprite;

	sf::Texture starsTexture;
	sf::Sprite starsSprite;

	float starsSpeed;
	sf::Clock gameTime;

	float spawnDelay;
	float spawnCD;
	float defaultSpawnCD;

public:

	//Constructors
	Environment(const char* pathToBackground,const char* pathToStars, sf::Vector2u windowSize);
	
	//Functions
	void movement(float starsSpeed,int windowWidth);
	void collCheck(std::vector<std::unique_ptr<Entity>>& bulletVec, std::vector<std::unique_ptr<SpaceObject>>& SpaceObjVec);
	//Getters
	sf::Sprite& getBgSprite();
	sf::Sprite& getStarsSprite();
	bool isSpawnReady();

	float getStarsSpeed() { return this->starsSpeed; }
	float getTimeAsSec() { return gameTime.getElapsedTime().asSeconds(); }

	
};

