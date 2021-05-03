#include "Environment.h"

Environment::Environment(sf::String pathToBackground,sf::String pathToStars, sf::Vector2u windowSize) {
    if (!this->bgTexture.loadFromFile(pathToBackground)) {
        std::cout << "Error to load background" << std::endl;
    }
    if (!this->starsTexture.loadFromFile(pathToStars)) {
        std::cout << "Error to load stars" << std::endl;
    }
    this->starsTexture.setRepeated(true);
    this->bgSprite.setTexture(this->bgTexture);
    this->starsSprite.setTexture(this->starsTexture);

}
sf::Sprite Environment::getBgSprite() {
    return this->bgSprite;
}
sf::Sprite Environment::getStarsSprite() {
    return this->starsSprite;
}
void Environment::movement(float starsSpeed,int windowWidth) {
    //std::cout << this->stars_sprite.getPosition().x << std::endl;
    if (this->starsSprite.getPosition().x < -windowWidth) {
        this->starsSprite.setPosition(0,this->starsSprite.getPosition().y);
    }
    else {
        this->starsSprite.setPosition(
            this->starsSprite.getPosition().x - starsSpeed,
            this->starsSprite.getPosition().y);
    }
}
