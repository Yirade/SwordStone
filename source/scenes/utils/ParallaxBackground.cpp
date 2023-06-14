#include "headers/ParallaxBackground.hpp"
#include <fstream>

ParallaxBackground::ParallaxBackground(const std::string& layerFilePath)
{
    // Legge il file dei percorsi dei layer
    std::ifstream file(layerFilePath);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            layerPaths.push_back(line);
        }
        file.close();
    }
    else
    {
        // Errore nell'apertura del file
        return;
    }

    textures.resize(layerPaths.size());
    sprites.resize(layerPaths.size());

    // Carica le texture dei livelli
    for (size_t i = 0; i < layerPaths.size(); ++i)
    {
        if (!textures[i].loadFromFile(layerPaths[i]))
        {
            // Errore nel caricamento della texture
            return;
        }
    }
}

void ParallaxBackground::update(sf::RenderWindow& window, const sf::Vector2f& mousePosition)
{
    // Imposta le posizioni dei livelli basate sul movimento del mouse
    for (size_t i = 0; i < sprites.size(); ++i)
    {
        sf::Vector2f layerPosition = -mousePosition * static_cast<float>(i + 1) * 0.02f; // Modifica il fattore di parallasse come preferisci
        sprites[i].setTexture(textures[i]);
        sprites[i].setPosition(layerPosition);
    }

    // Disegna i livelli sulla finestra
    for (size_t i = 0; i < sprites.size(); ++i)
    {
        window.draw(sprites[i]);
    }
}
