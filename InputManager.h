#ifndef FLAPPYBIRDS_INPUTMANAGER_H
#define FLAPPYBIRDS_INPUTMANAGER_H

#include <SFML/Graphics.hpp>

class InputManager {
public:
    InputManager(){};
    ~InputManager() {}

    bool isSpriteClicked(sf::Sprite sprite, sf::Mouse::Button button, sf::RenderWindow &window);

    sf::Vector2i getMousePosition(sf::RenderWindow &window);

};


#endif //FLAPPYBIRDS_INPUTMANAGER_H
