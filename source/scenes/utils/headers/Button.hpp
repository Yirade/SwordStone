#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>

class Button {
public:
    Button(sf::RenderWindow& window, const std::string& text, const std::string& fontPath, unsigned int fontSize, const sf::Color& idleColor, const sf::Color& hoverColor, const sf::Color& clickColor, const std::string& position, float positionX, float positionY, const std::function<void()>& onClick, const std::string& texturePath);

    void handleEvent(const sf::Event& event);
    void draw() const;

private:
    sf::RectangleShape shape;
    sf::Text label;
    sf::Texture texture;
    sf::Font font; // Dichiarazione della variabile font

    sf::RenderWindow& window;
    std::string text;
    std::string fontPath;
    unsigned int fontSize;
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color clickColor;
    std::string position;
    float positionX;
    float positionY;
    std::function<void()> onClick;
    std::string texturePath;
    bool hasTexture;

    bool isPressed = false;
};
