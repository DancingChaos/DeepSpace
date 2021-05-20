#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Environment.h"
#include "WindowParams.h"
#include "AsteroidFactory.h"



#pragma region 1200x600
#define pathToPlayerCfg "../Config/Player/player.txt"
#define pathToPlayerTexture "../Images/1200x600/kasatka.png"
#define pathToBulletTexture "../Images/1200x600/bullet.png"
#define pathToAsteroidTexture "../Images/1200x600/asteroid.png"
#define pathToGlassAsteroidTexture "../Images/1200x600/asteroidglass.png"
#define pathToUranAsteroidTexture "../Images/1200x600/asteroiduran.png"
#define pathToBackground "../Images/1200x600/background.jpg"
#define pathToStarsTexture "../Images/1200x600/stars.png"
#pragma endregion

#pragma region Sounds
#define pathToShootSound "../Music/shoot.wav"
#pragma endregion


int main()
{
	//Rendering window
	sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "DeepSpace", sf::Style::Close);

	//Creating Environment
	Environment env(pathToBackground, pathToStarsTexture, window.getSize());

	//Creating Asteroid Factory
	AsteroidFactory astFact;

	//Creating player
	Player player(pathToPlayerCfg, pathToPlayerTexture, pathToShootSound);

	//Creating bullet vector
	std::vector<std::unique_ptr<Entity>> bulletVec;
	bulletVec.reserve(10);

	std::vector< std::unique_ptr<SpaceObject>> SpaceObjVec;
	SpaceObjVec.reserve(10);
	//Game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (player.isAlive) {
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
				if (player.isShootReady) {
					//std::cout << "fire_delay:" << player.getFireDelay() << " isReady:" << player.isShootReady << std::endl;
					player.shoot(player.getCooldown());

					bulletVec.push_back(std::make_unique<Bullet>(player.getPosition(), pathToBulletTexture, 2.0f));
				}
			}
			player.reloading(player.getReloadSpeed());
		}

		player.update();
		//Timing actions
		env.movement(env.getStarsSpeed(), window.getSize().x);
		if (bulletVec.size()) {
			env.collCheck(bulletVec, SpaceObjVec);
		}
		//Clearing window
		window.clear();

		//Draw Environment`
		window.draw(env.getBgSprite());
		window.draw(env.getStarsSprite());

		//Draw Bullets
		if (bulletVec.size()) {
			for (auto it = bulletVec.begin(); it != bulletVec.end(); it++)
			{
				if ((*it)->isActive) {
					(*it)->update();
					window.draw((*it)->getSprite());
				}
				else {
					it->reset();
					bulletVec.erase(it);
					break;
				}
			}
		}
		
		//Draw Player
		window.draw(player.getSprite());

		//Draw Space Objects
		if (env.isSpawnReady()) {
			switch (rand() % 3 + 1)
			{
			case 1:
				SpaceObjVec.emplace_back(astFact.makeAsteroid(pathToAsteroidTexture));
				break;
			case 2:
				SpaceObjVec.emplace_back(astFact.makeAsteroid(pathToGlassAsteroidTexture));
				break;
			case 3:
				SpaceObjVec.emplace_back(astFact.makeAsteroid(pathToUranAsteroidTexture));
				break;
			}
		}
		if (SpaceObjVec.size()) {
			for (auto it = SpaceObjVec.begin(); it != SpaceObjVec.end(); it++)
			{
				if ((*it)->isActive) {
					(*it)->update((*it)->getSpeed(),(*it)->getRotationSpeed());
					window.draw((*it)->getSprite());
				}
				else {
					it->reset();
					SpaceObjVec.erase(it);
					break;
				}
			}
		}
		//Display texture
		window.display();
	}

	return 0;
}