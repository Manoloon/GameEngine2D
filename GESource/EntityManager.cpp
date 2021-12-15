//
// Created by Manoloon on 13/12/2021.
//

#include "EntityManager.h"

EntityManager::EntityManager()
{

}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag)
{
    // We declare it this way because Entity have a private constructor.
    auto newEntity = std::shared_ptr<Entity>(new Entity(m_totalEntities++,tag));
    // store it in the queue for beeing store on the next frame.
    m_toAdd.push_back(newEntity);
    // return the entity obj
    return newEntity;
}

void EntityManager::Update()
{
    for(auto e:m_toAdd)
    {
        m_entities.push_back(e);
        // store it in the map of tag->entityVector
        m_entitiesMap[e->GetTag()].push_back(e);
    }
    // remove those who are marked for dead
    for(auto e: m_entities)
    {
        if(!e->GetIsAlive())
        {
            // remove it from entities
            // remove it from entitiesMap
        }
    }
    // end of frame -> clear the vector.
    m_toAdd.clear();
}

