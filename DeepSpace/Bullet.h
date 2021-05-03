#pragma once
#include "Entity.h"
#include <iostream>
class Bullet : public Entity
{
public:
	//Constructor
	Bullet(sf::Vector2f& playerPosition, sf::String& pathToTexture,float speed);
};

