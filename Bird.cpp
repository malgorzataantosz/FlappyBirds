#include "Bird.h"
#include "DEFINITIONS.h"

Bird::Bird(GameDataRef data) : data(data) {
    birdSprite.setTexture(data->assetManager.getTexture("Bird 1"));
    birdSprite.setPosition((data->window.getSize().x / 4) - (birdSprite.getGlobalBounds().width / 2),
                           (data->window.getSize().y / 2) - (birdSprite.getGlobalBounds().height / 2));
    birdState = BIRD_STATE_STILL;
}

void Bird::draw() {
    data->window.draw(birdSprite);
}

void Bird::update(float dt) {
    if (BIRD_STATE_FALLING == birdState) {
        birdSprite.move(0, GRAVITY * dt);
    } else if (BIRD_STATE_FLYING == birdState) {
        birdSprite.move(0, -FLYING_SPEED*dt);
    }
    if (movementClock.getElapsedTime().asSeconds() > FLYING_DURATUIN) {
        movementClock.restart();
        birdState = BIRD_STATE_FALLING;
    }
}

void Bird::tap() {
    movementClock.restart();
    birdState = BIRD_STATE_FLYING;

}

const sf::Sprite &Bird::getSprite() const {
    return birdSprite;
}
