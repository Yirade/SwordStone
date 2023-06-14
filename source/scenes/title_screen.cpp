#include "headers/title_screen.hpp"
#include "utils/headers/DrawnText.hpp"
#include "utils/headers/ParallaxBackground.hpp"
#include "utils/headers/Button.hpp"
#include "utils/headers/FontLoader.hpp"
#include "utils/headers/DrawnImage.hpp"
#include "utils/headers/DrawnButton.hpp"
#include "headers/Game.hpp"

void title_screen(sf::RenderWindow& window, sf::Event& event)
{
    sf::Vector2i mousePosition; // Posizione del mouse

    ParallaxBackground parallaxBackground("./source/configurations/title_screen_parallax.conf");

    if (sf::Mouse::getPosition(window).x >= 0 && sf::Mouse::getPosition(window).y >= 0 &&
        sf::Mouse::getPosition(window).x < window.getSize().x && sf::Mouse::getPosition(window).y < window.getSize().y)
    {
        mousePosition = sf::Mouse::getPosition(window);
    }

    sf::Vector2f mousePositionF = window.mapPixelToCoords(mousePosition); // Conversione in sf::Vector2f

    window.clear();

    parallaxBackground.update(window, mousePositionF);

    const std::vector<sf::Font>& fonts = FontLoader::getFonts();

    DrawnText test(window);
    test.setText("SwordStone");
    test.setFont(fonts[1]);
    test.setFontSize(50);
    test.setColor(sf::Color(50, 168, 82, 255));
    //test.setPosition("XCENTER");
    test.setPositionY(50.0f);
    test.setPositionX(220.0f);
    test.draw();

    DrawnButton start(window);
    sf::Texture idleTexture;
    sf::Texture hoveredTexture;
    sf::Texture clickedTexture;
    if (idleTexture.loadFromFile("source/resources/sprites/buttons/start/Idle.png") &&
        hoveredTexture.loadFromFile("source/resources/sprites/buttons/start/Hovered.png") &&
        clickedTexture.loadFromFile("source/resources/sprites/buttons/start/Clicked.png"))
    {
        start.setIdleTexture(idleTexture);
        start.setHoveredTexture(hoveredTexture);
        start.setClickedTexture(clickedTexture);
        start.setPosition(263.0f, 180.0f);
        start.setSize(114.0f, 50.0f);
        start.setOnClickAction([&window, &event]() {
            std::cout << "Start!" << std::endl;
            Game game(window, event);
            game.start();
        });
        start.update(mousePositionF, sf::Mouse::isButtonPressed(sf::Mouse::Left));
        start.draw();
    }

    DrawnButton menu(window);
    sf::Texture idlemenu;
    sf::Texture hoveredmenu;
    sf::Texture clickedmenu;
    if (idlemenu.loadFromFile("source/resources/sprites/buttons/menu/Hovered.png") &&
        hoveredmenu.loadFromFile("source/resources/sprites/buttons/menu/Idle.png") &&
        clickedmenu.loadFromFile("source/resources/sprites/buttons/menu/Clicked.png"))
    {
        menu.setIdleTexture(idlemenu);
        menu.setHoveredTexture(hoveredmenu);
        menu.setClickedTexture(clickedmenu);
        menu.setPosition(263.0f, 240.0f);
        menu.setSize(114.0f, 50.0f);
        menu.setOnClickAction([&window, &event]() {
            std::cout << "Menu!" << std::endl;
        });
        menu.update(mousePositionF, sf::Mouse::isButtonPressed(sf::Mouse::Left));
        menu.draw();
    }

    DrawnButton quit(window);
    sf::Texture idlequit;
    sf::Texture hoveredquit;
    sf::Texture clickedquit;
    if (idlequit.loadFromFile("source/resources/sprites/buttons/quit/Hovered.png") &&
        hoveredquit.loadFromFile("source/resources/sprites/buttons/quit/Idle.png") &&
        clickedquit.loadFromFile("source/resources/sprites/buttons/quit/Clicked.png"))
    {
        quit.setIdleTexture(idlequit);
        quit.setHoveredTexture(hoveredquit);
        quit.setClickedTexture(clickedquit);
        quit.setPosition(263.0f, 300.0f);
        quit.setSize(114.0f, 50.0f);
        quit.setOnClickAction([&window, &event]() {
            std::cout << "Quit!" << std::endl;
            window.close();
        });
        quit.update(mousePositionF, sf::Mouse::isButtonPressed(sf::Mouse::Left));
        quit.draw();
    }


    window.display();
}
