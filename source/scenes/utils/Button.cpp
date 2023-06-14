#include "headers/Button.hpp"

Button::Button(sf::RenderWindow& window, const std::string& text, const std::string& fontPath, unsigned int fontSize, const sf::Color& idleColor, const sf::Color& hoverColor, const sf::Color& clickColor, const std::string& position, float positionX, float positionY, const std::function<void()>& onClick, const std::string& texturePath)
    : window(window), text(text), fontPath(fontPath), fontSize(fontSize), idleColor(idleColor), hoverColor(hoverColor), clickColor(clickColor), position(position), positionX(positionX), positionY(positionY), onClick(onClick), texturePath(texturePath), hasTexture(false) {

    if (!font.loadFromFile(fontPath)) {
        std::cout << "Error loading font: " << fontPath << std::endl;
    }

    shape.setPosition(positionX, positionY);
    shape.setSize(sf::Vector2f(100.f, 50.f));
    shape.setFillColor(idleColor);

    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(fontSize);
    label.setFillColor(sf::Color::White);

    sf::FloatRect textBounds = label.getGlobalBounds();

    if (position == "CENTER") {
        positionX = (window.getSize().x - textBounds.width) / 2.f;
        positionY = (window.getSize().y - textBounds.height) / 2.f;
    }
    else if (position == "LEFT") {
        positionX = 0.f;
        positionY = (window.getSize().y - textBounds.height) / 2.f;
    }
    else if (position == "RIGHT") {
        positionX = window.getSize().x - textBounds.width;
        positionY = (window.getSize().y - textBounds.height) / 2.f;
    }

    label.setPosition(positionX, positionY);

    if (!texturePath.empty()) {
        if (texture.loadFromFile(texturePath)) {
            shape.setTexture(&texture);
            hasTexture = true;
        }
    }
}

void Button::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                        if (shape.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                shape.setFillColor(clickColor);
                isPressed = true;
            }
        }
    } else if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (isPressed) {
                shape.setFillColor(hoverColor);
                isPressed = false;
                onClick();
            }
        }
    } else if (event.type == sf::Event::MouseMoved) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        if (shape.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
            if (!isPressed) {
                shape.setFillColor(hoverColor);
            }
        } else {
            shape.setFillColor(idleColor);
            isPressed = false;
        }
    }
}

void Button::draw() const {
    window.draw(shape);
    window.draw(label);
}

