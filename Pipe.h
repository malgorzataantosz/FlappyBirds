#ifndef FLAPPYBIRDS_PIPE_H
#define FLAPPYBIRDS_PIPE_H

#include <vector>
#include "Game.h"
#include "DEFINITIONS.h"
class Pipe {

public:
    explicit Pipe(GameDataRef data);

    void drawPipes();

    void spawnBottomPipe();

    void spawnTopSpawn();

    void spawnInvisiblePipe();

    void movePipes(float dt);

    void spawnScoringPipe();

    void randomisePipeOffset();

    const std::vector<sf::Sprite> &getSprites() const;
    std::vector<sf::Sprite> &getScoringSprites();

private:
    GameDataRef data;

    std::vector<sf::Sprite> pipes;
    std::vector<sf::Sprite> scoringPipes;

    int groundHeight;
    int pipeSpawnYOffset;


};


#endif //FLAPPYBIRDS_PIPE_H
