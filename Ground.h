
#ifndef FLAPPYBIRDS_GROUND_H
#define FLAPPYBIRDS_GROUND_H


#include "Game.h"

class Ground {
public:
    Ground(GameDataRef data);

    void moveGround(float dt);

    void drawGround();

    const std::vector<sf::Sprite> &getSprite() const;

private:
    GameDataRef data;

    std::vector<sf::Sprite> groundSprites;

};


#endif //FLAPPYBIRDS_GROUND_H
