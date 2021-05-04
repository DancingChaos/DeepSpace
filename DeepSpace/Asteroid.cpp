#include "Asteroid.h"
#include "Additional.h"

Asteroid::Asteroid(sf::String& pathToTexture)
{
	if (!this->texture.loadFromFile(pathToTexture)) {
		std::cout << "Error to load player" << std::endl;
	}

	//Default init
	this->speed = 1;
	this->rotationSpeed = 1;
	this->position.x = 0;
	this->position.y = 0;
	this->health = 20;
	this->height = 50.0f;
	this->width = 50.0f;
	this->spawn_delay = 2.0f;

	//Texture to sprite
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->position);
}
Asteroid::Asteroid(sf::String& pathToTexture, float speed, float rotationSpeed, sf::Vector2f position)
{
	if (!this->texture.loadFromFile(pathToTexture)) {
		std::cout << "Error to load player" << std::endl;
	}

	//Default init
	this->speed = speed;
	this->rotationSpeed = rotationSpeed;
	this->position = position;
	this->health = 20;
	this->height = 50.0f;
	this->width = 50.0f;
	this->spawn_delay = 2.0f;

	//Texture to sprite
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->position);
}
Asteroid::Asteroid(sf::String& pathToTexture, float speed, float rotationSpeed, float positionX, float positionY) {
	if (!this->texture.loadFromFile(pathToTexture)) {
		std::cout << "Error to load player" << std::endl;
	}

	//Default init
	this->speed = speed;
	this->rotationSpeed = rotationSpeed;
	this->position.x = positionX;
	this->position.y = positionY;
	this->health = 20;
	this->height = 50.0f;
	this->width = 50.0f;
	this->spawn_delay = 2.0f;

	//Texture to sprite
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->position);
}
//Functions
void SpaceObject::collision() {}
void SpaceObject::flight(float speed, float rotationSpeed) {
	//Rotation
	this->sprite.rotate(rotationSpeed);
	//Position
	this->position.x -= speed;
	this->sprite.setPosition(this->position);
}

SpaceObject& SpaceObject::spawn(SpaceObject asteroid, float windowSizeX, float windowSizeY) {
	asteroid.speed = FloatRand(0.5f, 2.0f);
	asteroid.rotationSpeed = FloatRand(0.1f, 0.5f);
	asteroid.position.x = FloatRand(1, windowSizeX);
	asteroid.position.y = FloatRand(1, windowSizeY);
	asteroid.sprite.setPosition(asteroid.position.x, asteroid.position.y);
	return asteroid;
}

//Setters
void SpaceObject::setPosition(sf::Vector2f& position) { this->position = position; }

//Getters
float SpaceObject::getSpeed() { return this->speed; }
float SpaceObject::getRotationSpeed() { return this->rotationSpeed; }
sf::Sprite& SpaceObject::getSprite() { return this->sprite; }
sf::Vector2f& SpaceObject::getPosition() { return this->position; }

SpaceObject::~SpaceObject() {}


