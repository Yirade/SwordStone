#ifndef ANIMATED_OBJECT_HPP
#define ANIMATED_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class AnimatedObject
{
public:
    AnimatedObject(const std::string& texturePath);
    virtual ~AnimatedObject();

    void update();
    void render(sf::RenderWindow& window) const;
    void setPosition(float x, float y);
    void setPosition(const sf::Vector2f& position);
    void setScale(float scaleX, float scaleY);
    void setScale(const sf::Vector2f& scale);

protected:
    std::vector<sf::Texture*> animationFrames;
    sf::Sprite sprite;
    int currentFrame;
    int frameCount;
    sf::Clock frameClock;
};

#endif // ANIMATED_OBJECT_HPP
