#pragma once
#include "SpaceObject.h"
class Asteroid : public SpaceObject
{
public:
	//Constructors
	Asteroid(const char* pathToTexture, bool isRandomValues);
};

