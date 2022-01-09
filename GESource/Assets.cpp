//
// Created by Manoloon on 09/01/2022.
//

#include "Assets.h"

Assets::Assets()
{

}

void Assets::addTexture(const std::string &textureName, const std::string &path, bool smooth)
{

}

void Assets::addAnimation(const std::string &animName, const std::string &textureName, size_t frameCount, size_t speed)
{

}

void Assets::addFont(const std::string &fontName, const std::string &path)
{

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
    return m_textureMap[textureName];
}

const Animation &Assets::getAnimation(const std::string &animName) const
{
    return m_animationMap[animName];
}

const sf::Font &Assets::getFont(const std::string &fontName) const
{
    return <#initializer#>;
}

