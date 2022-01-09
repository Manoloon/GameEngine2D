//
// Created by Manoloon on 09/01/2022.
//

#ifndef GAMEENGINE2D_ANIMATION_H
#define GAMEENGINE2D_ANIMATION_H
#include "CommonHeaders.h"
#include <math.h>

class Animation
{
    sf::Sprite m_sprite;
    size_t m_frameCount =1;
    size_t m_currentFrame =0;
    size_t m_speed = 0;
    Vec2 m_size={1,1};
    std::string  m_name = "none";

public:
    Animation();
    explicit Animation(const std::string & name, const sf::Texture & t);
    explicit Animation(const std::string & name, const sf::Texture & t, size_t frameCount,size_t speed);
    void update();
    bool hasEnded() const;
    const std::string & getName() const;
    const Vec2 & getSize() const;
    sf::Sprite & getSprite();
};


#endif //GAMEENGINE2D_ANIMATION_H
