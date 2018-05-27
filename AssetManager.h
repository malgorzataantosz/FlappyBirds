
#ifndef FLAPPYBIRDS_ASSETMANAGER_H
#define FLAPPYBIRDS_ASSETMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>


class AssetManager {
public:
    AssetManager() {}

    ~AssetManager() {};

    //name that you assign to a texture, and actual file itself including the path
    void loadTexture(std::string name, std::string filename);

    sf::Texture &getTexture(std::string name);

    void loadFont(std::string name, std::string filename);

    sf::Font &getFont(std::string name);

private:
    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Font> fonts;

};


#endif //FLAPPYBIRDS_ASSETMANAGER_H
