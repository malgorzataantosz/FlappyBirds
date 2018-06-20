#ifndef FLAPPYBIRDS_GAME_H
#define FLAPPYBIRDS_GAME_H

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"



struct GameData{
    StateMachine stateMachine;
    sf::RenderWindow window;
    AssetManager assetManager;
    InputManager inputManager;

};

typedef std::shared_ptr<GameData> GameDataRef;


class Game {
public:
    Game(int width, int height, std::string title);
private:
    //update per second
    const float dt = 1.0f / 60.0f;
    sf::Clock clock;
    GameDataRef data = std::make_shared<GameData>();
    void run();
};


#endif //FLAPPYBIRDS_GAME_H
