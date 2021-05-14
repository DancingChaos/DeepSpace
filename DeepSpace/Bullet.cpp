#include "Bullet.h"

//Functions
Bullet::Bullet(sf::Vector2f& playerPosition, const char* pathToTexture,
    float speed){
    if (!this->texture.loadFromFile(pathToTexture)) {
        std::cout << "Error to load bullet" << std::endl;
    }

    this->speed = speed;
    this->isActive = true;

    //Texture to sprite
    this->sprite.setTexture(this->texture);

    this->position.x = playerPosition.x + 40.0f;
    this->position.y = playerPosition.y + 40.0f;

    this->sprite.setPosition(position);
}
//Bullet movement
void Entity::update() {   
    if (this->position.x > WINDOW_X) {
        this->isActive = false;
    }
    this->sprite.setPosition(this->position.x += this->speed, this->position.y);
}
void Entity::hit() {

}

//Getters
float Entity::getSpeed() { return this->speed; }
sf::Vector2f& Entity::getPosition() { return this->position; }
sf::Sprite& Entity::getSprite() { return this->sprite; }
