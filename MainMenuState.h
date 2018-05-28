//
// Created by malgorzata on 23.05.18.
//

#ifndef FLAPPYBIRDS_MAINMENUSTATE_H
#define FLAPPYBIRDS_MAINMENUSTATE_H


#include "State.h"
#include "Game.h"

class MainMenuState : public State {

public:
    explicit MainMenuState(GameDataRef data);

    void init();

    void handleInput();

    void update(float dt);

    void draw(float dt);

private:
    GameDataRef data;
    sf::Sprite background;
    sf::Sprite title;
    sf::Sprite playButton;
};


#endif //FLAPPYBIRDS_MAINMENUSTATE_H
