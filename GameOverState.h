#ifndef FLAPPYBIRDS_GAMEOVERSTATE_H
#define FLAPPYBIRDS_GAMEOVERSTATE_H


#include "State.h"
#include "Game.h"

class GameOverState : public State {
public:
    explicit GameOverState(GameDataRef data);

    void init() override ;

    void handleInput() override ;

    void update(float dt) override ;

    void draw(float dt) ;

private:
    GameDataRef data;
    sf::Sprite background;
    sf::Sprite gameOver;
    sf::Sprite restartButton;

};


#endif //FLAPPYBIRDS_GAMEOVERSTATE_H
