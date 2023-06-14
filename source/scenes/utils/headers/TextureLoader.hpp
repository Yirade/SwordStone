#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class TextureLoader
{
public:
    static void loadTexturesFromDirectory(const std::string& directoryPath);
    static const std::vector<sf::Texture>& getTextures();

private:
    static std::vector<sf::Texture> textures;
};

#endif // TEXTURELOADER_HPP
