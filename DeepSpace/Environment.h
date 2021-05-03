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

	float stars_speed;
	sf::Vector2f position;
public:
	Environment(sf::String pathToBackground,sf::String pathToStars, sf::Vector2u windowSize);
	void movement(float stars_speed,int windowWidth);
	sf::Sprite getBgSprite();
	sf::Sprite getStarsSprite();

	
};

