#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>

class Character {
public:
    Character();

    void handleInput(sf::Event& event, float deltaTime);
    void update(float deltaTime);
    void render(sf::RenderWindow& window);

private:
    std::vector<sf::Texture> animationFrames;
    unsigned int currentFrame;
    sf::Sprite sprite;
    sf::Vector2f position;
    float movementSpeed;

    void moveUp(float deltaTime);
    void moveDown(float deltaTime);
    void moveLeft(float deltaTime);
    void moveRight(float deltaTime);
};

#endif // CHARACTER_HPP
