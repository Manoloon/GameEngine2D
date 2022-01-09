//
// Created by Manoloon on 09/01/2022.
//

#include "Assets.h"

Assets::Assets()
{

}

void Assets::addTexture(const std::string &textureName, const std::string &path, bool smooth)
{
    m_textureMap[textureName] = sf::Texture();
    if(!m_textureMap[textureName].loadFromFile(path))
    {
        std::cerr << "Could not load texture file" << path << std::endl;
    }
    else
    {
        m_textureMap[textureName].setSmooth(smooth);
    }
}

void Assets::addAnimation(const std::string &animName, const std::string &textureName, size_t frameCount, size_t speed)
{
    m_animationMap[animName] = Animation(animName, getTexture(textureName), frameCount,speed);

}

void Assets::addFont(const std::string &fontName, const std::string &path)
{
    m_fontMap[fontName] = sf::Font();
    if(!m_fontMap[fontName].loadFromFile(path))
    {
        std::cerr << "Could not load Font file" << path << std::endl;
    }
}

void Assets::LoadFromFile(const std::string &path)
{
  std::ifstream file(path);
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

const sf::Texture &Assets::getTexture(const std::string &textureName) const
{
    assert(m_textureMap.find(textureName) != m_textureMap.end());
    return m_textureMap.at(textureName);
}

const Animation &Assets::getAnimation(const std::string &animName) const
{
    assert(m_animationMap.find(animName) != m_animationMap.end());
    return m_animationMap.at(animName);
}

const sf::Font &Assets::getFont(const std::string &fontName) const
{
    assert(m_fontMap.find(fontName) != m_fontMap.end());
    return m_fontMap.at(fontName);
}

