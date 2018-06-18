
#ifndef FLAPPYBIRDS_HEADUPDISPLAY_H
#define FLAPPYBIRDS_HEADUPDISPLAY_H


#include "Game.h"

class HeadupDisplay {

public:
    explicit HeadupDisplay(GameDataRef  data);

    void draw();

    void updateScore(int score);

private:
    GameDataRef data;
    sf::Text scoreText;

};


#endif //FLAPPYBIRDS_HEADUPDISPLAY_H
