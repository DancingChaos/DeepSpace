#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class SpaceObject {
protected:
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;
	
	int health;
	int spawn_delay;
	float speed;
	float rotationSpeed;
	float width, height;
public:
	//Functions
	virtual void flight(float speed, float rotationSpeed);
	virtual void collision();
	virtual SpaceObject& spawn(SpaceObject asteroid, float windowSizeX, float windowSizeY);

	//Setters
	virtual void setPosition(sf::Vector2f& position);

	//Getters
	virtual sf::Vector2f& getPosition();
	virtual sf::Sprite& getSprite();
	virtual float getSpeed();
	virtual float getRotationSpeed();

	virtual ~SpaceObject();
};
