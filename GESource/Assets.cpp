//
// Created by Manoloon on 09/01/2022.
//

#include "Assets.h"

void Assets::LoadFromFile(const std::string &NewPath)
{
  std::ifstream file(NewPath);
  std::string str;
    while (file.good())
    {
        file >> str;
        if(str == "Texture")
        {
            std::string name, path;
            file >> name >> path;
            addTexture(name,path);
        }
        else if (str == "Animation")
        {
            std::string name,texture;
            size_t frames, speed;
            file >> name >> texture >> frames >> speed;
            addAnimation(name,texture,frames,speed);
        }
        else if (str == "font")
        {
            std::string name,path;
            file >> name >> path;
            addFont(name,path);
        }
        else
        {
            std::cerr << " Unknown Asset Type "<< str << std::endl;
        }
    }
}

const sf::Texture &Assets::getTexture(const std::string &textureName)
{
    return m_textureMap[textureName];
}

const Animation &Assets::getAnimation(const std::string &animName)
{
    return m_animationMap[animName];
}

const sf::Font &Assets::getFont(const std::string &fontName)
{
    return m_fontMap[fontName];
}

const sf::Sound &Assets::getSound(const std::string &soundName)
{
    return m_soundMap[soundName];
}

void Assets::addTexture(const std::string &textureName, const std::string &path, bool smooth)
{
        m_textureMap[textureName].loadFromFile(path);
        m_textureMap[textureName].setSmooth(smooth);
}

void Assets::addAnimation(const std::string &animName, const std::string &textureName, size_t frameCount, size_t speed)
{

}

void Assets::addFont(const std::string &fontName, const std::string &path)
{
    m_fontMap[fontName].loadFromFile(path);
}

void Assets::addSound(const std::string &soundName, const std::string &path)
{
    //TODO : add sound to the map.
}


