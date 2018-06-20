#include "GameOverState.h"
#include "DEFINITIONS.h"
#include "GameState.h"

GameOverState::GameOverState(GameDataRef data) : data(data) {

}

void GameOverState::init() {

    data->assetManager.loadTexture("Game Over",GAME_OVER_FILEPATH);

    gameOver.setTexture(this->data->assetManager.getTexture("Game Over"));
    //same button as play button
    restartButton.setTexture(this->data->assetManager.getTexture("Play Button"));
    restartButton.setPosition((data->window.getSize().x/2) -( restartButton.getGlobalBounds().width/2 ), 300 );

}

void GameOverState::handleInput() {
    sf::Event event;
    while (data->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            data->window.close();
        }
        if(data->inputManager.isSpriteClicked(restartButton, sf::Mouse::Left, data->window)){
            data->stateMachine.addState(StateRef(new GameState(data)), true);
        }
    }
}

void GameOverState::update(float dt) {
}

void GameOverState::draw(float dt) {
    data->window.clear();
    data->window.draw(background);
    data->window.draw(gameOver);
    data->window.draw(restartButton);
    data->window.display();
}
