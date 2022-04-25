//
// Created by Manoloon on 09/01/2022.
//

#ifndef GAMEENGINE2D_ASSETS_H
#define GAMEENGINE2D_ASSETS_H
#include "CommonHeaders.h"
#include "Animation.h"

class Assets
{
    std::map<std::string,sf::Texture>   m_textureMap;
    std::map<std::string,Animation>     m_animationMap;
    std::map<std::string,sf::Font>      m_fontMap;
    std::map<std::string,sf::Sound>     m_soundMap;

    void addTexture(const std::string & textureName, const std::string & path, bool smooth = true);
    void addAnimation(const std::string & animName, const std::string & textureName, size_t frameCount, size_t speed);
    void addFont(const std::string & fontName, const std::string & path);
    void addSound(const std::string & soundName, const std::string & path);

public:
    Assets()=default;

    void LoadFromFile(const std::string & NewPath);

    const sf::Texture & getTexture(const std::string & textureName);
    const Animation & getAnimation(const std::string & animName);
    const sf::Font & getFont(const std::string & fontName);
    const sf::Sound & getSound(const std::string & soundName);
};


#endif //GAMEENGINE2D_ASSETS_H
