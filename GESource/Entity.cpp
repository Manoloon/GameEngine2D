//
// Created by Manoloon on 13/12/2021.
//

#include "Entity.h"

size_t Entity::GetId() const
{
    return m_id;
}

const std::string & Entity::GetTag() const
{
    return m_tag;
}

bool Entity::isActive() const
{
    return m_alive;
}

void Entity::destroy()
{
    m_alive= false;
}
