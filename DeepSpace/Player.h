#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"
class Player
{
private:
	sf::Vector2f position;
	sf::Vector2f speed;

	sf::Texture texture;
	sf::Sprite sprite;

	float health;
	float fire_delay;
	const float cooldown;

	float width, height;
public:

	bool isShootReady;
	//Constructor
	Player(float x, float y,sf::String path_to_texture,
		sf::Vector2f speed, float health,float fire_delay,float cooldown);
	Player(sf::Vector2f position,sf::String path_to_texture, 
		sf::Vector2f speed, float health,float fire_delay,float cooldown);

	sf::Vector2f getPosition() { return this->position; };
	void setPosition(float x, float y) { this->position.x = x, this->position.y = y; }

	sf::Sprite getSprite() { return this->sprite; }

	sf::Vector2f getSpeed() { return this->speed; }
	float getFireDelay() { return this->fire_delay; }

	void move(float xSpeed,float ySpeed);
	void borderCheck(sf::Vector2u windowSize);

	void shoot();
	void reloading();
};

