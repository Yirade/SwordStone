#include "headers/AnimatedObject.hpp"

AnimatedObject::AnimatedObject(const std::string& texturePath)
{
    // Carica le texture separate dell'oggetto animato
    for (int i = 1; i <= 4; i++)
    {
        sf::Texture* texture = new sf::Texture();
        if (!texture->loadFromFile(texturePath + std::to_string(i) + ".png"))
        {
            // Gestisci l'errore in caso di problemi nel caricamento della texture
        }
        animationFrames.push_back(texture);
    }

    sprite.setTexture(*animationFrames[0]);

    // Altri inizializzazioni
    currentFrame = 0;
    frameCount = 4;
}

AnimatedObject::~AnimatedObject()
{
    // Dealloca le texture caricate
    // for (sf::Texture* texture : animationFrames)
    // {
    //     delete texture;
    // }
    // animationFrames.clear(); // Rimuovi i puntatori deallocati dal vettore
}

void AnimatedObject::update()
{
    // Calcola il tempo trascorso dall'ultimo frame
    sf::Time elapsed = frameClock.getElapsedTime();

    // Se è passato abbastanza tempo (200 millisecondi), passa al prossimo frame
    if (elapsed.asMilliseconds() >= 200)
    {
        currentFrame = (currentFrame + 1) % frameCount;
        sprite.setTexture(*animationFrames[currentFrame]);

        // Resetta il timer del frame
        frameClock.restart();
    }
}

void AnimatedObject::render(sf::RenderWindow& window) const
{
    window.draw(sprite);
}

void AnimatedObject::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

void AnimatedObject::setPosition(const sf::Vector2f& position)
{
    sprite.setPosition(position);
}

void AnimatedObject::setScale(float scaleX, float scaleY)
{
    sprite.setScale(scaleX, scaleY);
}

void AnimatedObject::setScale(const sf::Vector2f& scale)
{
    sprite.setScale(scale);
}
