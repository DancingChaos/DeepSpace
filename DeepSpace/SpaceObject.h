#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class SpaceObject {
protected:
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;
	
	int health;

	float speed;
	float rotationSpeed;
	float width, height;
public:
	bool isActive;
	//Functions
	virtual void update(float speed, float rotationSpeed);
	virtual void collision();
	virtual SpaceObject* randomValues(SpaceObject* asteroid, float windowSizeX, float windowSizeY);

	//Setters
	virtual void setPosition(sf::Vector2f& position);
	virtual void setHealth(int health);
	//Getters
	virtual sf::Vector2f& getPosition();
	virtual sf::Sprite& getSprite();
	virtual int getHealth();
	virtual float getSpeed();
	virtual float getRotationSpeed();

	virtual ~SpaceObject();
};
