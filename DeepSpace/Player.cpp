#include "Player.h"



#pragma region Constructors
Player::Player(std::string pathToCfg, sf::String pathToSprite) {
    if (!this->texture.loadFromFile(pathToSprite)) {
        std::cout << "Error to load player" << std::endl;
    }
    loadConfig(pathToCfg);

    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(this->position.x, this->position.y);
}
Player::Player(sf::Vector2f position, sf::String pathToTexture, sf::Vector2f speed, float health)
        : position(position), speed(speed), health(health), isShootReady(true) {
   
    //Loading texture       
    if (!this->texture.loadFromFile(pathToTexture)) {
        std::cout << "Error to load player" << std::endl;
    }

    //Default init
    this->cooldown = 100.0f;
    this->fireDelay = 0.0f;
    this->reloadSpeed = 1.0f;

    //Texture to sprite
    this->sprite.setTexture(this->texture);

    //Width/Height of ship
    this->width = 100.0f;
    this->height = 50.0f;

    this->sprite.setPosition(position);
}
Player::Player(float x, float y, sf::String pathToTexture, sf::Vector2f speed, float health)
    : speed(speed), health(health), isShootReady(true){

    //Texture load
    if (!this->texture.loadFromFile(pathToTexture)) {
        std::cout << "Error to load player" << std::endl;
    }

    //Default init
    this->cooldown = 100.0f;
    this->fireDelay = 0.0f;
    this->reloadSpeed = 1.0f;

    //Texture to sprite
    this->sprite.setTexture(this->texture);

    //Start position
    this->position.x = x;
    this->position.y = y;
    
    //Width/Height of ship
    this->width = 100.0f;
    this->height = 50.0f;

    //Set sprite position
    this->sprite.setPosition(position);
}
#pragma endregion


#pragma region Functions\
//Config
void Player::loadConfig(std::string pathToCfg) {
    std::ifstream fin(pathToCfg);
    std::string line;
    while (getline(fin, line)) {
        std::istringstream sin(line.substr(line.find("=") + 1));
        if (line.find("positionX") != -1)
            sin >> this->position.x;
        else if (line.find("positionY") != -1)
            sin >> this->position.y;
        else if (line.find("width") != -1)
            sin >> this->width;
        else if (line.find("height") != -1)
            sin >> this->height;
        else if (line.find("fireDelay ") != -1)
            sin >> this->fireDelay;
        else if (line.find("cooldown") != -1)
            sin >> this->cooldown;
        else if (line.find("reloadSpeed") != -1)
            sin >> this->reloadSpeed;
        else if (line.find("speedX") != -1)
            sin >> this->speed.x;
        else if (line.find("speedY") != -1)
            sin >> this->speed.y;
        else if (line.find("isShootReady") != -1)
            sin >> this->isShootReady;
    }
}
//Movement
void Player::move(float xSpeed, float ySpeed) {
    //Movement(Changing position)
    this->setPosition(this->position.x + xSpeed, this->position.y + ySpeed);
    //Applying position to sprite
    this->sprite.setPosition(this->position);
}
//Collision with window borders
void Player::borderCheck(sf::Vector2u windowSize) {
    //X check (100.0f width of ship)
    if (this->position.x < 0) {
        this->position.x = 0;
    }
    else if (this->position.x > windowSize.x - 100.0f) {
        this->position.x = windowSize.x - 100.0f;
    }
    //Y check (50.0f height of ship)
    if (this->position.y < 0) {
        this->position.y = windowSize.y - 50.0f;
    }
    else if(this->position.y > windowSize.y - 50.0f) {
        this->position.y = 0;
    }
}
//Shooting
void Player::shoot(float cooldown) {
        this->fireDelay = this->cooldown;
        this->isShootReady = false;
}
//Time before next bullet
void Player::reloading(float reloadSpeed) {
    if (this->fireDelay <= NULL) {
        isShootReady = true;
    }
    else {
        isShootReady = false;
        this->fireDelay -= reloadSpeed;
    }
}
#pragma endregion


