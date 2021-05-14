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

    this->spawnDelay = 1.0f;
    this->spawnCD = 0.0f;
    this->defaultSpawnCD = 500.0f;

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
void Environment::collCheck(std::vector<std::unique_ptr<Entity>>& bulletVec, std::vector<std::unique_ptr<SpaceObject>>& SpaceObjVec) {
    if (bulletVec.size()) {
        for (auto bulletIt = bulletVec.begin(); bulletIt != bulletVec.end(); bulletIt++)
        {
            if (SpaceObjVec.size()) {
                for (auto objIt = SpaceObjVec.begin(); objIt != SpaceObjVec.end(); objIt++)
                {
                    if ((*bulletIt)->isActive) {
                        if ((*bulletIt)->getSprite().getGlobalBounds().intersects((*objIt)->getSprite().getGlobalBounds())) {
                            (*bulletIt)->isActive = false;
                            (*objIt)->setHealth((*objIt)->getHealth() - 1);
                        }
                    }
                }
            }
        }
    }
}

bool Environment::isSpawnReady() {
    if (this->spawnCD <= 0.0f) {
        spawnCD = defaultSpawnCD;
        return true;
    }
    this->spawnCD -= this->spawnDelay;
    return false;
}
//Getters
sf::Sprite& Environment::getBgSprite() {
    return this->bgSprite;
}
sf::Sprite& Environment::getStarsSprite() {
    return this->starsSprite;
}

