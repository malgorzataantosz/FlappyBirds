#ifndef FLAPPYBIRDS_COLLISION_H
#define FLAPPYBIRDS_COLLISION_H


#include <SFML/Graphics/Sprite.hpp>

class Collision {
public:
    Collision();

    bool checkSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);
    bool checkSpriteCollision(sf::Sprite sprite1,float scale1, sf::Sprite sprite2, float scale2);
};


#endif //FLAPPYBIRDS_COLLISION_H
