#pragma once
#include "SpaceObject.h"
class Asteroid : public SpaceObject
{
public:
	//Constructors
	Asteroid(sf::String& pathToTexture);
	Asteroid(sf::String& pathToTexture, float speed, float rotationSpeed,sf::Vector2f position);
	Asteroid(sf::String& pathToTexture, float speed, float rotationSpeed, float positionX, float positionY);
};

