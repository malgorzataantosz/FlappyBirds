
#ifndef FLAPPYBIRDS_GAMESTATE_H
#define FLAPPYBIRDS_GAMESTATE_H


#include "Game.h"
#include "Pipe.h"
#include "Ground.h"
#include "Bird.h"
#include "Collision.h"
#include "HeadupDisplay.h"

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

    sf::Clock clock;

    Pipe *pipe;

    Ground *ground;

    Bird *bird;
    Collision collision;
    HeadupDisplay *hud;

    int gameState;
    int score;

};


#endif //FLAPPYBIRDS_GAMESTATE_H
