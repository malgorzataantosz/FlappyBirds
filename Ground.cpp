
#include "Ground.h"
#include "DEFINITIONS.h"

Ground::Ground(GameDataRef data) : data(data) {
    sf::Sprite sprite(data->assetManager.getTexture("Ground"));
    sf::Sprite sprite2(data->assetManager.getTexture("Ground"));

    sprite.setPosition(0, data->window.getSize().y - sprite.getGlobalBounds().height);
    sprite2.setPosition(sprite.getGlobalBounds().width, data->window.getSize().y - sprite.getGlobalBounds().height);
    groundSprites.push_back(sprite);
    groundSprites.push_back(sprite2);
}

void Ground::moveGround(float dt) {
    for (size_t i = 0; i < groundSprites.size(); ++i) {
        float movement = PIPE_MOVEMENT_SPEED * dt;
        groundSprites.at(i).move(-movement, 0.0f);
        if (groundSprites.at(i).getPosition().x < 0 - groundSprites.at(i).getGlobalBounds().width) {
            sf::Vector2f position(data->window.getSize().x, groundSprites.at(i).getPosition().y);
            groundSprites.at(i).setPosition(position);
        }
    }
}

void Ground::drawGround( ) {
    for (size_t i = 0; i < groundSprites.size(); ++i) {
        data->window.draw(groundSprites.at(i));
    }
}

const std::vector<sf::Sprite> &Ground::getSprite() const {
    return groundSprites;
}
