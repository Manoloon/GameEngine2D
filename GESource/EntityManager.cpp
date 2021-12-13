//
// Created by Manoloon on 13/12/2021.
//

#include "EntityManager.h"

std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag)
{
    // create a new entity obj
    auto newEntity = std::make_shared<Entity>(m_totalEntities++,tag);
    // store it in the vector of all entities
    m_entities.push_back(newEntity);
    // store it in the map of tag->entityVector
    m_entitiesMap[tag];
    // return the entity obj
    return newEntity;
}
