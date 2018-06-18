#ifndef FLAPPYBIRDS_BIRD_H
#define FLAPPYBIRDS_BIRD_H


#include "Game.h"

class Bird {

public:
    Bird(GameDataRef data);

    void draw();

    void update(float dt);

    void tap();

    const sf::Sprite &getSprite() const;

private:
    GameDataRef data;
    sf::Sprite birdSprite;
    sf::Clock movementClock;
    int birdState;
};


#endif //FLAPPYBIRDS_BIRD_H
