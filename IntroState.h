#ifndef FLAPPYBIRDS_INTROSTATE_H
#define FLAPPYBIRDS_INTROSTATE_H


#include "State.h"
#include "Game.h"

class IntroState : public State {
public:
    IntroState(GameDataRef data);

    void init();

    void handleInput();

    void update(float dt);

    void draw(float dt);

private:
    GameDataRef data;
    sf::Clock clock; //keep track how much time passsed
    sf::Sprite background;


};


#endif //FLAPPYBIRDS_INTROSTATE_H
