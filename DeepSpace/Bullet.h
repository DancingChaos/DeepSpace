#pragma once
#include "Entity.h"
class Bullet : public Entity
{
public:
	//Constructor
	Bullet(sf::Vector2f& playerPosition, const char* pathToTexture, float speed);
};

