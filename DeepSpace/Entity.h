#pragma once
#include <SFML/Graphics.hpp>
#include "WindowParams.h"
#include <iostream>
class Entity {
protected:
	float speed;
	float damage;
	float range;

	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	bool isActive;

	virtual void update();
	virtual void hit();
	void setPosition(float x, float y) { 
		this->position.x = x; 
		this->position.y = y;
	}

	virtual float getSpeed();
	virtual sf::Vector2f& getPosition();
	virtual sf::Sprite& getSprite();
	virtual ~Entity() { std::cout << "Deleted bullet" << std::endl; };
};
