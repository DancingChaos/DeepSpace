#include "Environment.h"

//Constructors
Environment::Environment(const char* pathToBackground,const char* pathToStars, sf::Vector2u windowSize) {
    if (!this->bgTexture.loadFromFile(pathToBackground)) {
        std::cout << "Error to load background" << std::endl;
    }
    if (!this->starsTexture.loadFromFile(pathToStars)) {
        std::cout << "Error to load stars" << std::endl;
    }
    
    this->starsSpeed = 0.1f;

    this->bgSprite.setTexture(this->bgTexture);
    this->starsSprite.setTexture(this->starsTexture);
}

//Functions
void Environment::movement(float starsSpeed,int windowWidth) {
    //Changing X position
    if (this->starsSprite.getPosition().x < -windowWidth) {
        this->starsSprite.setPosition(0,this->starsSprite.getPosition().y);
    }
    //Position reset when picture ends
    else {
        this->starsSprite.setPosition(
            this->starsSprite.getPosition().x - starsSpeed,
            this->starsSprite.getPosition().y);
    }
}

//Getters
sf::Sprite& Environment::getBgSprite() {
    return this->bgSprite;
}
sf::Sprite& Environment::getStarsSprite() {
    return this->starsSprite;
}

