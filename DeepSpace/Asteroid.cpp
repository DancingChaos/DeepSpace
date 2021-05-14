#include "Asteroid.h"
#include "Additional.h"
#include "WindowParams.h"

Asteroid::Asteroid(const char* pathToTexture, bool isRandomValues)
{
	if (!this->texture.loadFromFile(pathToTexture)) {
		std::cout << "Error to load player" << std::endl;
	}

	//Default init
	this->speed = FloatRand(0.5f, 2.0f);
	this->rotationSpeed = FloatRand(0.1f, 0.5f);

	this->position.x = WINDOW_X;
	this->position.y = FloatRand(1, WINDOW_Y);

	this->health = 3;

	this->height = 50.0f;
	this->width = 50.0f;

	//Texture to sprite
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->position);
}
//Functions
void SpaceObject::collision() {}
void SpaceObject::update(float speed, float rotationSpeed) {
	if (this->health <= 0) {
		this->isActive = false;
	}
	if (this->position.x < NULL) {
		this->isActive = false;
	}
	//Rotation
	this->sprite.rotate(rotationSpeed);
	//Position
	this->position.x -= speed;
	this->sprite.setPosition(this->position);
}

SpaceObject* SpaceObject::randomValues(SpaceObject* asteroid, float windowSizeX, float windowSizeY) {
	asteroid->speed = FloatRand(0.5f, 2.0f);
	asteroid->rotationSpeed = FloatRand(0.1f, 0.5f);
	asteroid->position.x = windowSizeX;
	asteroid->position.y = FloatRand(1, windowSizeY);
	asteroid->sprite.setPosition(asteroid->position.x, asteroid->position.y);
	return asteroid;
}

//Setters
void SpaceObject::setPosition(sf::Vector2f& position) { this->position = position; }
void SpaceObject::setHealth(int health) { this->health = health; }
//Getters
int SpaceObject::getHealth() { return this->health; }
float SpaceObject::getSpeed() { return this->speed; }
float SpaceObject::getRotationSpeed() { return this->rotationSpeed; }
sf::Sprite& SpaceObject::getSprite() { return this->sprite; }
sf::Vector2f& SpaceObject::getPosition() { return this->position; }

SpaceObject::~SpaceObject() {}


