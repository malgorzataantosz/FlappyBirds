#include <iostream>
#include "Pipe.h"

Pipe::Pipe(GameDataRef data) : data(data) {
    groundHeight = data->assetManager.getTexture("Ground").getSize().y;
    pipeSpawnYOffset = 0;
}

void Pipe::drawPipes() {
    for (size_t i = 0; i < pipes.size(); ++i) {
        data->window.draw(pipes.at(i));
    }
}

void Pipe::spawnBottomPipe() {
    sf::Sprite sprite(data->assetManager.getTexture("Pipe Up"));
    sprite.setPosition(data->window.getSize().x,
                       data->window.getSize().y - sprite.getGlobalBounds().height - pipeSpawnYOffset);
    pipes.push_back(sprite);
}

void Pipe::spawnTopSpawn() {
    sf::Sprite sprite(data->assetManager.getTexture("Pipe Down"));
    sprite.setPosition(data->window.getSize().x, -pipeSpawnYOffset);
    pipes.push_back(sprite);
}

void Pipe::spawnInvisiblePipe() {
    sf::Sprite sprite(data->assetManager.getTexture("Pipe Down"));
    sprite.setPosition(data->window.getSize().x, data->window.getSize().y - sprite.getGlobalBounds().height);
    sprite.setColor(sf::Color(0, 0, 0, 0));
    pipes.push_back(sprite);
}

void Pipe::movePipes(float dt) {
    for (size_t i = 0; i < pipes.size(); ++i) {
        if (pipes.at(i).getPosition().x < 0 - pipes.at(i).getGlobalBounds().width) {
            pipes.erase(pipes.begin() + i);
        } else {
            float movement = dt * PIPE_MOVEMENT_SPEED;
            pipes.at(i).move(-movement, 0);
        }
    }
    for (size_t i = 0; i < scoringPipes.size(); ++i) {
        if (scoringPipes.at(i).getPosition().x < 0 - scoringPipes.at(i).getGlobalBounds().width) {
            scoringPipes.erase(scoringPipes.begin() + i);
        } else {
            float movement = dt * PIPE_MOVEMENT_SPEED;
            scoringPipes.at(i).move(-movement, 0);
        }
    }
}

void Pipe::randomisePipeOffset() {
    pipeSpawnYOffset = rand() % (groundHeight + 1);
}

const std::vector<sf::Sprite> &Pipe::getSprites() const {
    return pipes;
}


std::vector<sf::Sprite> &Pipe::getScoringSprites() {
    return scoringPipes;
}

void Pipe::spawnScoringPipe() {
    sf::Sprite sprite(data->assetManager.getTexture("Scoring Pipe"));
    sprite.setPosition(data->window.getSize().x, 0);
    scoringPipes.push_back(sprite);
}

