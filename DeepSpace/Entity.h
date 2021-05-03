#pragma once
#include <SFML/Graphics.hpp>
class Entity {
public:
	float speed;
	float damage;
	float range;

	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;

	virtual void flight();
	virtual void hit();
	sf::Vector2f getPosition() { return this->position; }
	void setPosition(float x, float y) { 
		this->position.x = x; 
		this->position.y = y;
	}
};
