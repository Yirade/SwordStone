#ifndef PARALLAX_BACKGROUND_HPP
#define PARALLAX_BACKGROUND_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class ParallaxBackground
{
public:
    ParallaxBackground(const std::string& layerFilePath);
    void update(sf::RenderWindow& window, const sf::Vector2f& mousePosition);

private:
    std::vector<std::string> layerPaths;
    std::vector<sf::Texture> textures;
    std::vector<sf::Sprite> sprites;
};

#endif // PARALLAX_BACKGROUND_HPP
