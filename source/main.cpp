#include <SFML/Graphics.hpp>
#include "scenes/headers/title_screen.hpp"
#include "scenes/utils/headers/FontLoader.hpp"
#include "scenes/utils/headers/TextureLoader.hpp"
#include "scenes/utils/headers/Player.hpp"
#include "scenes/utils/headers/CollisionElement.hpp"
#include "scenes/utils/headers/MusicPlayer.hpp"

std::vector<CollisionElement> collisionElements;

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 360), "Swordstone");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false); // Disabilita la ripetizione dei tasti
    window.setActive();

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.setPosition(sf::Vector2i((desktop.width - window.getSize().x) / 2, (desktop.height - window.getSize().y) / 2));

    // Caricamento delle risorse
    FontLoader::loadFontsFromDirectory("source/resources/fonts");
    const std::vector<sf::Font>& fonts = FontLoader::getFonts();

    // TextureLoader::loadTexturesFromDirectory("source/resources/sprites/tiles");
    // const std::vector<sf::Texture>& textures = TextureLoader::getTextures();

    // Ottieni l'istanza del player
    // Player& player = Player::getInstance(window);

    sf::Clock clock;

    // Inizializza la musica
    MusicPlayer& musicPlayer = MusicPlayer::getInstance();

    // Riproduci una canzone
    musicPlayer.playMusic("source/resources/music/xDeviruchi - Title Theme .wav");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
 
        }

        float deltaTime = clock.restart().asSeconds();

        // Aggiorna il player
        // player.update();

        title_screen(window, event); // Passa l'istanza del giocatore alla funzione title_screen

        // Disegna il player
        // player.draw(window);

        window.display();
    }

    return 0;
}
