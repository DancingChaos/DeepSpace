#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Player
{
private:
	sf::Vector2f position;
	sf::Texture player_texture;
public:
	sf::Sprite player_sprite;
	//Constructor
	Player(float x, float y, sf::String path_to_texture) {
		//Texture load
		if (!player_texture.loadFromFile(path_to_texture)) {
			std::cout << "Error to load player" << std::endl;
		}
		//Texture to sprite
		this->player_sprite.setTexture(player_texture);

		//Start position
		this->position.x = x;
		this->position.y = y;
	}
	sf::Vector2f GetPosition() { return this->position; };
	void SetPosition(float x, float y) { this->position.x = x, this->position.y = y; }
	void Move(const int TOP_BORDER, const int BOT_BORDER);
	void Shoot();
};

