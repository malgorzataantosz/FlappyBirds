#include "Game.h"
#include "IntroState.h"

Game::Game(int width, int height, std::string title) {
    data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    data->stateMachine.addState(StateRef(new IntroState(this->data)));
    this->run();
}

void Game::run() {
    float newTime, frameTime, interpolation;
    float currentTime = this->clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;

    while (this->data->window.isOpen()) {
        this->data->stateMachine.processStateChanges();
        newTime = this->clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;
        if (frameTime > 0.25f) {
            frameTime = 0.25f;
        }
        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= dt) {
            this->data->stateMachine.getActiveState()->handleInput();
            this->data->stateMachine.getActiveState()->update(dt);
            accumulator -= dt;
        }
        interpolation = accumulator / dt;
        this->data->stateMachine.getActiveState()->draw(interpolation);
    }
}
