#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

int main()
{
    //Rendering window
    sf::RenderWindow window(sf::VideoMode(1200, 600), "SFML works!");
    //Window borders constant
    const int TOP_BORDER = 0;
    const int BOT_BORDER = window.getSize().y;
    //Creating player
    Player player(0, window.getSize().y/2 ,"../Images/1.png");
    //Game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //Get player position to console
        std::cout << player.GetPosition().y << std::endl;
        //Player movement check
        if (sf::Keyboard::isKeyPressed) {
            player.Move(TOP_BORDER, BOT_BORDER);
        }
        //Clearing window
        window.clear();
        //Draw textures
        window.draw(player.player_sprite);
        //Display texture
        window.display();
    }

    return 0;
}