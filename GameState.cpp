
#include <iostream>
#include "GameState.h"
#include "DEFINITIONS.h"


GameState::GameState(GameDataRef data) : data(data) {
}

void GameState::init() {
    std::cout << "Game State" <<std::endl; //temporary cout
    data->assetManager.loadTexture("Game Background",GAME_BACKGROUND_FILEPATH);
    background.setTexture(this->data->assetManager.getTexture("Game Background"));
}

void GameState::handleInput() {
    sf::Event event;
    while (data->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            data->window.close();
        }
    }
}

void GameState::update(float dt) {

}

void GameState::draw(float dt) {
    data->window.clear();
    data->window.draw(background);
    data->window.display();
}

