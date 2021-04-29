#include "Player.h"
void Player::Move(const int TOP_BORDER, const int BOT_BORDER) {
    //Movement(Changing position)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->SetPosition(this->GetPosition().x, this->GetPosition().y - 0.5);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->SetPosition(this->GetPosition().x, this->GetPosition().y + 0.5);
    }
    //Borders Teleporting
    if (this->GetPosition().y >= BOT_BORDER - 50) {
        this->SetPosition(this->GetPosition().x, 0);
    }
    else if (this->GetPosition().y <= TOP_BORDER) {
        this->SetPosition(this->GetPosition().x, BOT_BORDER - 50);
    }
    //Applying position to sprite
    this->player_sprite.setPosition(this->position);
}