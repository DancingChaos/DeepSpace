#pragma once
#include <SFML/Graphics.hpp>
class Entity {
protected:
	float speed;
	float damage;
	float range;

	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	virtual void flight();
	virtual void hit();
	void setPosition(float x, float y) { 
		this->position.x = x; 
		this->position.y = y;
	}

	virtual float getSpeed();
	virtual sf::Vector2f& getPosition();
	virtual sf::Sprite& getSprite();
};
