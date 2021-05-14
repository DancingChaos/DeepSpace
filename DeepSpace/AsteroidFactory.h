#pragma once
#include "SpaceObject.h"
#include "Asteroid.h"
class AsteroidFactory : public SpaceObject
{
public:
	std::unique_ptr<SpaceObject> makeAsteroid(const char* pathToTexture);
};

