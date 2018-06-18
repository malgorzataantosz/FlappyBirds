#ifndef FLAPPYBIRDS_GAMEOVERSTATE_H
#define FLAPPYBIRDS_GAMEOVERSTATE_H


#include "State.h"
#include "Game.h"

class GameOverState : public State {
public:
    explicit GameOverState(GameDataRef data);

    void init();

    void handleInput();

    void update();

    void draw();

private:
    GameDataRef data;
    sf::Sprite background;

};


#endif //FLAPPYBIRDS_GAMEOVERSTATE_H
