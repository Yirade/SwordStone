#ifndef DYNAMICTILE_HPP
#define DYNAMICTILE_HPP

#include "Tile.hpp"
#include <SFML/Graphics.hpp>

class DynamicTile : public Tile
{
public:
    DynamicTile(float posX, float posY, float size = 50.0f, bool collide = false, int index = -1);

    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;

    void addTexture(const sf::Texture& texture);

private:
    std::vector<sf::Texture> textures;
    int currentTextureIndex;
};

#endif // DYNAMICTILE_HPP
