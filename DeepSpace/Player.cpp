#include "Player.h"
#pragma region Constructors
Player::Player(std::string pathToCfg, const char* pathToTexture, const char* pathToSound) {
    if (!this->texture.loadFromFile(pathToTexture)) {
        std::cout << "Error to load player" << std::endl;
    }
    if (!this->soundBuffer.loadFromFile(pathToSound)) {
        std::cout << "Error to load sound" << std::endl;
    }

    soundBuffer.loadFromFile(pathToSound);
    shootSound.setBuffer(soundBuffer);

    loadConfig(pathToCfg);
    //Sound Buffer to Sound
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(this->position.x, this->position.y);
}
#pragma endregion


#pragma region Functions
//Updating
void Player::update() {
    if (this->health <= 0) {
        this->isAlive = false;
    }
}
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
        else if (line.find("isAlive") != -1)
            sin >> this->isAlive;
        else if (line.find("health") != -1)
            sin >> this->health;
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
    this->shootSound.play();
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


