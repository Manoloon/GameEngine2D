//
// Created by Manoloon on 09/01/2022.
//

#include "Animation.h"
#include <math.h>

Animation::Animation(const std::string &name, const sf::Texture &t):m_name(name)
{
    m_sprite.setTexture(t);
    m_size = Vec2((float )t.getSize().x, (float )t.getSize().y);
    m_sprite.setOrigin(m_size.x/2.0f,m_size.y/2.0f);
    m_sprite.setTextureRect(sf::IntRect(0,0,m_size.x,m_size.y));
}

Animation::Animation(const std::string &name, const sf::Texture &t, size_t frameCount, size_t speed):m_name(name),m_frameCount(frameCount),m_speed(speed)
{
    m_sprite.setTexture(t);
    m_size = Vec2((float )t.getSize().x / frameCount, (float )t.getSize().y);
    m_sprite.setOrigin(m_size.x/2.0f,m_size.y/2.0f);
    m_sprite.setTextureRect(sf::IntRect(std::floor(m_currentFrame)* m_size.x,0,m_size.x,m_size.y));
}
void Animation::update()
{
    m_currentFrame++;
    //TODO: calc the correct frame of animation to play based on currentframe and speed
    //set the current texture rectangle properly -> see constructor.
}

bool Animation::hasEnded() const
{
    //TODO : detect when animation has ended and return true
    return false;
}

const std::string &Animation::getName() const
{
    return m_name;
}

const Vec2 &Animation::getSize() const
{
    return m_size;
}

sf::Sprite &Animation::getSprite()
{
    return m_sprite;
}


