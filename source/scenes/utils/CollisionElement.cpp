#include "headers/CollisionElement.hpp"

CollisionElement* CollisionElement::instance = nullptr;

CollisionElement& CollisionElement::getInstance()
{
    if (instance == nullptr) {
        instance = new CollisionElement();
    }
    return *instance;
}

CollisionElement::CollisionElement()
{
    // Inizializza il vettore degli elementi di collisione se necessario
}

void CollisionElement::addElement(const sf::FloatRect& rect)
{
    collisionElements.push_back(rect);
}

bool CollisionElement::checkCollision(const sf::FloatRect& otherRect) const
{
    for (const auto& rect : collisionElements) {
        if (rect.intersects(otherRect)) {
            return true;
        }
    }
    return false;
}

void CollisionElement::draw(sf::RenderWindow& window) const
{
    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::Red);

    for (const auto& rect : collisionElements) {
        shape.setSize(sf::Vector2f(rect.width, rect.height));
        shape.setPosition(rect.left, rect.top);
        window.draw(shape);
    }
}

// void CollisionElement::addElement(const sf::FloatRect& rect)
// {
//     collisionElements.emplace_back(rect);
// }

