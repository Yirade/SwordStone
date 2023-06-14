#include "headers/TextureLoader.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>

namespace fs = std::filesystem;

std::vector<sf::Texture> TextureLoader::textures;

void TextureLoader::loadTexturesFromDirectory(const std::string& directoryPath)
{
    std::ofstream outputFile(directoryPath + "/texture_list.txt");
    if (!outputFile.is_open())
    {
        std::cout << "Failed to create texture_list.txt file" << std::endl;
        return;
    }

    int index = 0;

    for (const auto& file : fs::directory_iterator(directoryPath))
    {
        if (file.path().extension() == ".png" || file.path().extension() == ".jpg" || file.path().extension() == ".bmp")
        {
            sf::Texture texture;
            if (texture.loadFromFile(file.path().string()))
            {
                textures.push_back(texture);
                outputFile << index << ": " << file.path().filename().string() << std::endl;
                std::cout << "Loaded texture: " << file.path().filename() << std::endl;
                index++;
            }
            else
            {
                std::cout << "Failed to load texture: " << file.path().filename() << std::endl;
            }
        }
    }

    outputFile.close();
}

const std::vector<sf::Texture>& TextureLoader::getTextures()
{
    return textures;
}
