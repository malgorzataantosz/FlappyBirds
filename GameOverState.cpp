#include "GameOverState.h"
#include "DEFINITIONS.h"

GameOverState::GameOverState(GameDataRef data) : data(data) {

}

void GameOverState::init() {
    data->assetManager.loadTexture("Game Over Background",GAME_OVER_BACKGROUND_FILEPATH);
    background.setTexture(this->data->assetManager.getTexture("Game Over Background"));
}

void GameOverState::handleInput() {
    sf::Event event;
    while (data->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            data->window.close();
        }
    }
}

void GameOverState::update() {
}

void GameOverState::draw() {
    data->window.clear();
    data->window.draw(background);
    data->window.display();
}
