//
// Created by malgorzata on 23.05.18.
//

#include "MainMenuState.h"
#include "DEFINITIONS.h"
#include <sstream>
#include <iostream>

MainMenuState::MainMenuState(GameDataRef data) : data(data) {


}

void MainMenuState::init() {
    data->assetManager.loadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
    data->assetManager.loadTexture("Game Title", GAME_TITLE_FILEPATH);
    data->assetManager.loadTexture("Play Button", PLAY_BUTTON_FILEPATH);
    background.setTexture(this->data->assetManager.getTexture("Main Menu Background"));
    title.setTexture(this->data->assetManager.getTexture("Game Title"));
    playButton.setTexture(this->data->assetManager.getTexture("Play Button"));
    title.setPosition((SCREEN_WIDTH/2) - (title.getGlobalBounds().width/2), (title.getGlobalBounds().height/2));
    playButton.setPosition((SCREEN_WIDTH/2) - (playButton.getGlobalBounds().width/2), (SCREEN_HEIGHT/2) -(playButton.getGlobalBounds().height/2));

}

void MainMenuState::handleInput() {
    sf::Event event;
    while (data->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            data->window.close();
        }
    }
    if(data->inputManager.isSpriteClicked(playButton,  sf::Mouse::Left, data->window)){
        std::cout << "Go to Game Screen" << std::endl; // i'll implement game screen later
    }
}

void MainMenuState::update(float dt) {

}

void MainMenuState::draw(float dt) {
    data->window.clear();
    data->window.draw(background);
    data->window.draw(title);
    data->window.draw(playButton);
    data->window.display();
}
