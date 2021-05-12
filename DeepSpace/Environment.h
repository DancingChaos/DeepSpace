#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Environment
{
private:
	sf::Texture bgTexture;
	sf::Sprite bgSprite;

	sf::Texture starsTexture;
	sf::Sprite starsSprite;

	float starsSpeed;
public:

	//Constructors
	Environment(const char* pathToBackground,const char* pathToStars, sf::Vector2u windowSize);
	
	//Functions
	void movement(float starsSpeed,int windowWidth);

	//Getters
	sf::Sprite& getBgSprite();
	sf::Sprite& getStarsSprite();

	float getStarsSpeed() { return this->starsSpeed; }

	
};

