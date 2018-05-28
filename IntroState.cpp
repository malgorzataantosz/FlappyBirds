//
// Created by malgorzata on 22.05.18.
//

#include "IntroState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include <sstream>
#include <iostream>

IntroState::IntroState(GameDataRef data) : data(data) {

}

void IntroState::init() {
    data->assetManager.loadTexture("Intro State Background", INTRO_SCENE_BACKGROUND_FILEPATH);
    background.setTexture(this->data->assetManager.getTexture("Intro State Background"));
}

void IntroState::handleInput() {
    sf::Event event;
    while (data->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            data->window.close();
        }
    }
}

void IntroState::update(float dt) {
    if (clock.getElapsedTime().asSeconds() > INTRO_STATE_SHOW_TIME) {
        data->stateMachine.addState(StateRef(new MainMenuState(data)), true);
    }
}

void IntroState::draw(float dt) {
    data->window.clear();
    data->window.draw(background);
    data->window.display();
}

