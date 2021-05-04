#include "Bullet.h"

//Functions
Bullet::Bullet(sf::Vector2f& playerPosition, sf::String& pathToTexture,
    float speed){
    if (!this->texture.loadFromFile(pathToTexture)) {
        std::cout << "Error to load player" << std::endl;
    }
    this->speed = speed;
    //Texture to sprite
    this->sprite.setTexture(this->texture);

    this->position.x = playerPosition.x;
    this->position.y = playerPosition.y;

    this->sprite.setPosition(position);
}
//Bullet movement
void Entity::flight() {   
    this->sprite.setPosition(this->position.x += this->speed, this->position.y);
}
void Entity::hit() {

}

//Getters
float Entity::getSpeed() { return this->speed; }
sf::Vector2f& Entity::getPosition() { return this->position; }
sf::Sprite& Entity::getSprite() { return this->sprite; }
