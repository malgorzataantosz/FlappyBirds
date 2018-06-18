
#include <iostream>
#include "GameState.h"
#include "DEFINITIONS.h"


GameState::GameState(GameDataRef data) : data(data) {
}

void GameState::init() {

    data->assetManager.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
    data->assetManager.loadTexture("Pipe Up", PIPE_UP_FILEPATH);
    data->assetManager.loadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
    data->assetManager.loadTexture("Ground", GROUND_FILEPATH);
    data->assetManager.loadTexture("Bird 1", BIRD_FRAME_1_FILEPATH);
    data->assetManager.loadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);
    data->assetManager.loadFont("Font", FONT_FILEPATH);


    pipe = new Pipe(data);
    ground = new Ground(data);
    bird = new Bird(data);
    hud = new HeadupDisplay(data);

    background.setTexture(this->data->assetManager.getTexture("Game Background"));
    score = 0;
    hud->updateScore(score);
    gameState = GameStates::READY;
}

void GameState::handleInput() {
    sf::Event event;
    while (data->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            data->window.close();
        }

        if (data->inputManager.isSpriteClicked(this->background, sf::Mouse::Left, data->window)) {
            //testing
            if (GameStates::GAMEOVER != gameState) {
                gameState = GameStates::PLAY;
                bird->tap();
            }


        }
    }
}

void GameState::update(float dt) {
    if (GameStates::GAMEOVER != gameState) {
        ground->moveGround(dt);
    }
    if (GameStates::PLAY == gameState) {
        pipe->movePipes(dt);
        if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
            pipe->randomisePipeOffset();
            pipe->spawnInvisiblePipe();
            pipe->spawnBottomPipe();
            pipe->spawnTopSpawn();
            pipe->spawnScoringPipe();

            clock.restart();
        }
        bird->update(dt);
        std::vector<sf::Sprite> groundSprite = ground->getSprite();
        for (size_t i = 0; i < groundSprite.size(); ++i) {
            if (collision.checkSpriteCollision(bird->getSprite(), 0.7f, groundSprite.at(i), 1.0f)) {
                gameState = GameStates::GAMEOVER;
            }
        }

        std::vector<sf::Sprite> pipes = pipe->getSprites();
        for (size_t i = 0; i < pipes.size(); ++i) {
            if (collision.checkSpriteCollision(bird->getSprite(), 0.525f, pipes.at(i), 1.0f)) {
                gameState = GameStates::GAMEOVER;
                clock.restart();
            }
        }
        if (GameStates::PLAY == gameState) {
            std::vector<sf::Sprite> &scoringSprites = pipe->getScoringSprites();
            for (size_t i = 0; i < scoringSprites.size(); ++i) {
                if (collision.checkSpriteCollision(bird->getSprite(), 0.525f, scoringSprites.at(i), 1.0f)) {
                    score++;
                    hud->updateScore(score);
                    scoringSprites.erase(scoringSprites.begin() + i);

                }
            }
        }
    }
}

void GameState::draw(float dt) {
    data->window.clear();
    data->window.draw(background);
    pipe->drawPipes();
    ground->drawGround();
    bird->draw();
    hud->draw();
    data->window.display();
}

