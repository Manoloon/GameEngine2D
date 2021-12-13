//
// Created by Manoloon on 13/12/2021.
//

#include "Entity.h"

Entity::Entity(size_t m_id,const std::string& m_tag){}

size_t Entity::GetId() const
{
    return m_id;
}

std::string Entity::GetTag() const
{
    return m_tag;
}

bool Entity::GetIsAlive() const
{
    return m_alive;
}

: m_id(m_id),m_tag(m_tag);
