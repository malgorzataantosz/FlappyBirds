
#ifndef FLAPPYBIRDS_GAMESTATE_H
#define FLAPPYBIRDS_GAMESTATE_H


#include "Game.h"

class GameState : public State {
public:
    explicit GameState(GameDataRef data);

    void init();

    void handleInput();

    void update(float dt);

    void draw(float dt);

private:
    GameDataRef data;

    sf::Sprite background;

};


#endif //FLAPPYBIRDS_GAMESTATE_H
