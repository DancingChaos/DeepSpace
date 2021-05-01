#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"

int main()
{
#pragma region Resources
	sf::String player_texture_path = "../Images/kasatka.png";
	sf::String bullet_texture_path = "../Images/1.png";
#pragma endregion

	//Rendering window
	sf::RenderWindow window(sf::VideoMode(1200, 600), "DeepSpace");
	//Creating player & entities
	Player player(0, window.getSize().y / 2.0f,
		player_texture_path, sf::Vector2f{ 0.5f,0.5f }, 3, 2, 10);
	Bullet bullet(player.getPosition(), bullet_texture_path, 2);
	std::vector<Bullet> bulletVec;
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
				player.shoot();
				//Update bullet position(from spaceship gun)
				bullet.position.x = player.getPosition().x + 40;
				bullet.position.y = player.getPosition().y + 40;

				bulletVec.push_back(bullet);
			}
		}
		player.reloading();
		//Clearing window
		window.clear();
		//Draw texture
		for (int i = 0; i < bulletVec.size(); i++)
		{
			bulletVec[i].flight();
			window.draw(bulletVec[i].sprite);
		}
		window.draw(player.getSprite());
		//Display texture
		window.display();
	}

	return 0;
}