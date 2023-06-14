#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Character.hpp"
#include "../utils/headers/CollisionElement.hpp"
#include "../utils/headers/DrawnImage.hpp"
#include "../utils/headers/Enemy.hpp"
#include "../utils/headers/AnimatedObject.hpp"
#include "../utils/headers/DrawnText.hpp"
#include "../utils/headers/FontLoader.hpp"
#include "../utils/headers/MusicPlayer.hpp"

class Game {
public:
    Game(sf::RenderWindow& window, sf::Event& event);
    void start();
    void update();
    void render();

private:
    sf::RenderWindow& window;
    sf::Event& event;
    float deltaTime;
    DrawnImage map;
    DrawnImage background;
    std::vector<Enemy> enemies;
    std::vector<AnimatedObject> animatedObjects;
};

#endif // GAME_HPP
