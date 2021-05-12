#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Asteroid.h"
#include "Environment.h"

#define pathToPlayerCfg "../Config/Player/player.txt"
#define pathToPlayerTexture "../Images/1200x600/kasatka.png"
#define pathToBulletTexture "../Images/1200x600/bullet.png"
#define pathToAsteroidTexture "../Images/1200x600/asteroid.png"
#define pathToBackground "../Images/1200x600/background.jpg"
#define pathToStarsTexture "../Images/1200x600/stars.png"

int main()
{
	//Rendering window
	sf::RenderWindow window(sf::VideoMode(1200, 600), "DeepSpace", sf::Style::Close);
	
	//Creating Environment
	Environment env(pathToBackground, pathToStarsTexture, window.getSize());
	
	//Creating player
	Player player(pathToPlayerCfg, pathToPlayerTexture);
	
	//Creating bullet
	Bullet bullet(player.getPosition(), pathToBulletTexture, 2);
	std::vector<Bullet> bulletVec;
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
		
		//Timing actions
		player.reloading(player.getReloadSpeed());
		env.movement(env.getStarsSpeed(), window.getSize().x);

		//Clearing window
		window.clear();

		//Draw Environment
		window.draw(env.getBgSprite());
		window.draw(env.getStarsSprite());

		//Draw Bullets 
		for (int i = 0; i < bulletVec.size(); i++)
		{
			bulletVec[i].flight();
			window.draw(bulletVec[i].getSprite());
		}

		//Draw Player
		window.draw(player.getSprite());

		//Display texture
		window.display();
	}

	return 0;
}