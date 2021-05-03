#include "Asteroid.h"
#include "Additional.h"

Asteroid::Asteroid(sf::String& pathToTexture)
{
	if (!this->texture.loadFromFile(pathToTexture)) {
		std::cout << "Error to load player" << std::endl;
	}

	this->speed = 1;
	this->rotationSpeed = 1;
	this->position.x = 0;
	this->position.y = 0;
	//Texture to sprite
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->position);
}
Asteroid::Asteroid(sf::String& pathToTexture, float speed, float rotationSpeed, sf::Vector2f position)
{
	if (!this->texture.loadFromFile(pathToTexture)) {
		std::cout << "Error to load player" << std::endl;
	}

	this->speed = speed;
	this->rotationSpeed = rotationSpeed;
	this->position = position;
	//Texture to sprite
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->position);
}
Asteroid::Asteroid(sf::String& pathToTexture, float speed, float rotationSpeed, float windowSizeX, float windowSizeY) {
	if (!this->texture.loadFromFile(pathToTexture)) {
		std::cout << "Error to load player" << std::endl;
	}

	this->speed = speed;
	this->rotationSpeed = rotationSpeed;
	this->position.x = windowSizeX;
	this->position.y = windowSizeY;
	//Texture to sprite
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->position);
}
void SpaceObject::flight(float speed, float rotationSpeed) {
	//Rotation
	this->sprite.rotate(rotationSpeed);
	//Position
	this->position.x -= speed;
	this->sprite.setPosition(this->position);
}
void SpaceObject::collision() {}
void SpaceObject::setPosition(sf::Vector2f& position) { this->position = position; }
SpaceObject SpaceObject::spawn(SpaceObject asteroid, float windowSizeX, float windowSizeY) {
	asteroid.speed = FloatRand(0.5f, 2.0f);
	asteroid.rotationSpeed = FloatRand(0.1f, 0.5f);
	asteroid.position.x = windowSizeX;
	asteroid.position.y = FloatRand(1, windowSizeY);
	asteroid.sprite.setPosition(asteroid.position.x, asteroid.position.y);
	return asteroid;
}
sf::Vector2f& SpaceObject::getPosition() { return this->position; }
sf::Sprite& SpaceObject::getSprite() { return this->sprite; }
float SpaceObject::getSpeed() { return this->speed; }
float SpaceObject::getRotationSpeed() { return this->rotationSpeed; }

SpaceObject::~SpaceObject() {}


