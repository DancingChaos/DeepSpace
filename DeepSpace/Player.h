#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Bullet.h"
class Player
{
private:
	sf::Vector2f position;
	sf::Vector2f speed;

	sf::Texture texture;
	sf::Sprite sprite;

	sf::SoundBuffer soundBuffer;
	sf::Sound shootSound;

	int health;
	float fireDelay;
	float cooldown;
	float reloadSpeed;
	float width, height;

public:
	bool isAlive;
	bool isShootReady;
	//Constructor
	Player(std::string pathToCfg, const char* pathToTexture, const char* pathToSound);

	//Functions
	void update();
	void loadConfig(std::string pathToCfg);
	void move(float xSpeed, float ySpeed);
	void borderCheck(sf::Vector2u windowSize);
	void shoot(float cooldown);
	void reloading(float reloadSpeed);

	//Getters
	sf::Sprite& getSprite() { return this->sprite; }
	sf::Vector2f& getSpeed() { return this->speed; }
	sf::Vector2f& getPosition() { return this->position; };
	int getHealth() { return this->health; }

	float getFireDelay() { return this->fireDelay; }
	float getReloadSpeed() { return this->reloadSpeed; }
	float getCooldown() { return this->cooldown; }

	//Setters
	void setHealth(int health) { this->health = health; }
	void setReloadSpeed(float newReloadSpeed) { this->reloadSpeed = newReloadSpeed; }
	void setCooldown(float newCooldown) { this->reloadSpeed = newCooldown; }
	void setPosition(float x, float y) { this->position.x = x, this->position.y = y; }
};

