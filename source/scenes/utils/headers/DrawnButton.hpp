#ifndef DRAWN_BUTTON_HPP
#define DRAWN_BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <functional>

class DrawnButton
{
public:
    DrawnButton(sf::RenderWindow& window);

    void setPosition(float x, float y);
    void setSize(float width, float height);
    void setIdleTexture(const sf::Texture& texture);
    void setHoveredTexture(const sf::Texture& texture);
    void setClickedTexture(const sf::Texture& texture);
    void setOnClickAction(std::function<void()> onClick);
    void update(const sf::Vector2f& mousePosition, bool isPressed);
    void draw();

private:
    sf::RenderWindow& m_window;
    sf::Sprite m_sprite;
    sf::Texture m_idleTexture;
    sf::Texture m_hoveredTexture;
    sf::Texture m_clickedTexture;
    bool m_isHovered;
    bool m_isPressed;
    std::function<void()> m_onClickAction;
};

#endif  // DRAWN_BUTTON_HPP
