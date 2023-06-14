#include "headers/FontLoader.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>

namespace fs = std::filesystem;

std::vector<sf::Font> FontLoader::fonts;

void FontLoader::loadFontsFromDirectory(const std::string& directoryPath)
{
    std::ofstream outputFile(directoryPath + "/font_list.txt");
    if (!outputFile.is_open())
    {
        std::cout << "Failed to create font_list.txt file" << std::endl;
        return;
    }

    int index = 0;

    for (const auto& file : fs::directory_iterator(directoryPath))
    {
        if (file.path().extension() == ".ttf" || file.path().extension() == ".otf")
        {
            sf::Font font;
            if (font.loadFromFile(file.path().string()))
            {
                fonts.push_back(font);
                outputFile << index << ": " << file.path().filename().string() << std::endl;
                std::cout << "Loaded font: " << file.path().filename() << std::endl;
                index++;
            }
            else
            {
                std::cout << "Failed to load font: " << file.path().filename() << std::endl;
            }
        }
    }

    outputFile.close();
}

const std::vector<sf::Font>& FontLoader::getFonts()
{
    return fonts;
}