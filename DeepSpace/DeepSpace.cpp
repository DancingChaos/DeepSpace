#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Asteroid.h"
#include "Environment.h"

int main()
{
//1200x600
#pragma region Resources
	sf::String player_texture_path = "../Images/1200x600/kasatka.png";
	sf::String bullet_texture_path = "../Images/1200x600/bullet.png";
	sf::String asteroid_texture_path = "../Images/1200x600/asteroid.png";
	sf::String background_texture_path = "../Images/1200x600/background.jpg";
	sf::String stars_texture_path = "../Images/1200x600/stars.png";
#pragma endregion

	//Rendering window
	sf::RenderWindow window(sf::VideoMode(1200, 600), "DeepSpace", sf::Style::Close);
	
	//Creating Environment
	Environment env(background_texture_path,stars_texture_path, window.getSize());
	
	//Creating player
	Player player(0, window.getSize().y / 2.0f,player_texture_path, sf::Vector2f{ 0.5f,0.5f }, 3);
	
	//Creating bullet
	Bullet bullet(player.getPosition(), bullet_texture_path, 2);
	std::vector<Bullet> bulletVec;
	bulletVec.reserve(10);

	//Creating asteroid
	Asteroid asteroid(asteroid_texture_path, 1, 0.1f, 0.0f, 0.0f);
	std::vector<SpaceObject> asteroidVec;
	bulletVec.reserve(10);

	//Game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Player movement
		/*std::cout << player.GetPosition().y << std::endl;*/
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			player.move(NULL, -player.getSpeed().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			player.move(-player.getSpeed().x, NULL);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			player.move(NULL, player.getSpeed().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			player.move(player.getSpeed().x, NULL);
		}
		player.borderCheck(window.getSize());

		//Player shooting
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if(player.isShootReady){
				//std::cout << "fire_delay:" << player.getFireDelay() << " isReady:" << player.isShootReady << std::endl;
				player.shoot(player.getCooldown());
				//Update bullet position(from spaceship gun)
				bullet.setPosition(
					player.getPosition().x + 40.0f,
					player.getPosition().y + 40.0f);

				bulletVec.push_back(bullet);
			}
		}
		player.reloading(player.getReloadSpeed());

		//Clearing window
		window.clear();

		//Draw Environment
		window.draw(env.getBgSprite());
		window.draw(env.getStarsSprite());
		env.movement(0.2f, window.getSize().x);

		//Draw Bullets 
		for (int i = 0; i < bulletVec.size(); i++)
		{
			bulletVec[i].flight();
			window.draw(bulletVec[i].getSprite());
		}

		//Draw Asteroids
		//asteroidVec.push_back(asteroid.spawn(asteroid, window.getSize().x, window.getSize().y));
		for (int i = 0; i < asteroidVec.size(); i++)
		{
			asteroidVec[i].flight(asteroidVec[i].getSpeed(), asteroidVec[i].getRotationSpeed());
			window.draw(asteroidVec[i].getSprite());
		}

		//Draw Player
		window.draw(player.getSprite());

		//Display texture
		window.display();
	}

	return 0;
}