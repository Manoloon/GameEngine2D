//
// Created by Manoloon on 09/01/2022.
//

#include "Action.h"

void Action::update()
{

}

bool Action::hasEnded()
{
    return false;
}

const std::string &Action::getName() const
{
    return m_name;
}

const Vec2 &Action::getSize() const
{
    return m_size;
}

const sf::Sprite &Action::getSprite() const
{
    return m_sprite;
}

const std::string & Action::getType() const
{
    return m_type;
}
