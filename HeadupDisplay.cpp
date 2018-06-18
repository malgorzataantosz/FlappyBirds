#include "HeadupDisplay.h"

HeadupDisplay::HeadupDisplay(GameDataRef data) : data(data) {
    scoreText.setFont(data->assetManager.getFont("Font"));
    scoreText.setString("0");
    scoreText.setCharacterSize(100);
    scoreText.setColor(sf::Color::White);
    scoreText.setOrigin(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2 + 150.0f);
    scoreText.setPosition(data->window.getSize().x / 2, data->window.getSize().y / 5);
}


void HeadupDisplay::draw() {
    data->window.draw(scoreText);
}

void HeadupDisplay::updateScore(int score) {
    scoreText.setString(std::to_string(score));

}

