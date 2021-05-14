#include "AsteroidFactory.h"

std::unique_ptr<SpaceObject> AsteroidFactory::makeAsteroid(const char* pathToTexture) {
	return std::make_unique<Asteroid>(pathToTexture, true);
}