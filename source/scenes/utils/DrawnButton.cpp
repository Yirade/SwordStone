#include "headers/DrawnButton.hpp"

DrawnButton::DrawnButton(sf::RenderWindow& window)
    : m_window(window), m_isHovered(false), m_isPressed(false)
{
}

void DrawnButton::setPosition(float x, float y)
{
    m_sprite.setPosition(x, y);
}

void DrawnButton::setSize(float width, float height)
{
    m_sprite.setScale(width / m_sprite.getLocalBounds().width, height / m_sprite.getLocalBounds().height);
}

void DrawnButton::setIdleTexture(const sf::Texture& texture)
{
    m_idleTexture = texture;
    m_sprite.setTexture(m_idleTexture);
}

void DrawnButton::setHoveredTexture(const sf::Texture& texture)
{
    m_hoveredTexture = texture;
}

void DrawnButton::setClickedTexture(const sf::Texture& texture)
{
    m_clickedTexture = texture;
}

void DrawnButton::setOnClickAction(std::function<void()> onClick)
{
    m_onClickAction = onClick;
}

void DrawnButton::update(const sf::Vector2f& mousePosition, bool isPressed)
{
    bool wasHovered = m_isHovered;
    m_isHovered = m_sprite.getGlobalBounds().contains(mousePosition);

    if (m_isHovered && !wasHovered)
    {
        m_sprite.setTexture(m_hoveredTexture);
    }
    else if (!m_isHovered && wasHovered)
    {
        m_sprite.setTexture(m_idleTexture);
    }

    m_isPressed = m_isHovered && isPressed;

    if (m_isPressed)
    {
        m_sprite.setTexture(m_clickedTexture);
        if (m_onClickAction)
        {
            m_onClickAction();
        }
    }
}

void DrawnButton::draw()
{
    m_window.draw(m_sprite);
}
