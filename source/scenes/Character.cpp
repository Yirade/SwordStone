#include "headers/Character.hpp"
#include <iostream>

Character::Character()
{
    // Inizializza le proprietà del personaggio
    position = sf::Vector2f(0.0f, 0.0f);
    movementSpeed = 100.0f;

    // Carica le texture degli sprite per l'animazione
    for (int i = 1; i <= 4; ++i) {
        std::string filename = "source/resources/sprites/Asset/Character_animation/priests_idle/priest1/priest1_v1_" + std::to_string(i) + ".png";
        sf::Texture texture;
        std::cout << "Loading file: " << filename << std::endl;
        if (!texture.loadFromFile(filename)) {
            // Errore nel caricamento della texture
            // Gestisci l'errore come preferisci
        }
        animationFrames.push_back(texture);
    }

    // Imposta il personaggio iniziale
    currentFrame = 0;
    sprite.setTexture(animationFrames[currentFrame]);
    sprite.setPosition(position);
}

void Character::handleInput(sf::Event& event, float deltaTime)
{
    // Gestisci l'input per il movimento del personaggio
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) {
            moveUp(deltaTime); // Aggiungi il parametro deltaTime
        } else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) {
            moveDown(deltaTime); // Aggiungi il parametro deltaTime
        } else if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) {
            moveLeft(deltaTime); // Aggiungi il parametro deltaTime
        } else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) {
            moveRight(deltaTime); // Aggiungi il parametro deltaTime
        }
    }
}


void Character::update(float deltaTime)
{
    // Aggiorna l'animazione del personaggio
    // ...

    // Avanza al frame successivo dell'animazione
    currentFrame = (currentFrame + 1) % animationFrames.size();
    sprite.setTexture(animationFrames[currentFrame]);

    // Aggiorna la posizione del personaggio in base al tempo trascorso e alla velocità
    sf::Vector2f movement(0.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        movement.y -= movementSpeed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        movement.y += movementSpeed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= movementSpeed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += movementSpeed * deltaTime;
    }

    position += movement;
    sprite.setPosition(position);
}

void Character::render(sf::RenderWindow& window)
{
    // Effettua il rendering del personaggio
    window.draw(sprite);
}

void Character::moveUp(float deltaTime)
{
    // Sposta il personaggio verso l'alto
    position.y -= movementSpeed * deltaTime;
    sprite.setPosition(position);
}

void Character::moveDown(float deltaTime)
{
    // Sposta il personaggio verso il basso
    position.y += movementSpeed * deltaTime;
    sprite.setPosition(position);
}

void Character::moveLeft(float deltaTime)
{
    // Sposta il personaggio verso sinistra
    position.x -= movementSpeed * deltaTime;
    sprite.setPosition(position);
}

void Character::moveRight(float deltaTime)
{
    // Sposta il personaggio verso destra
    position.x += movementSpeed * deltaTime;
    sprite.setPosition(position);
}
