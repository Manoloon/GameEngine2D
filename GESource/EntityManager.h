//
// Created by Manoloon on 13/12/2021.
//

#ifndef GAMEENGINE2D_ENTITYMANAGER_H
#define GAMEENGINE2D_ENTITYMANAGER_H
#include "CommonHeaders.h"
#include <cstddef>
#include "Entity.h"

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<std::string,EntityVec> EntityMap;

class EntityManager
{
    // generate id
    size_t m_totalEntities;
    EntityVec m_entities;
    EntityMap m_entitiesMap;
    EntityVec m_toAdd;

    void removeDeadEntities(EntityVec & vec);

public:
    EntityManager();
    void Update();
    ptr<Entity> addEntity(const std::string& tag);
    const EntityVec& getEntities();
    const EntityVec& getEntities(const std::string& tag);
};


#endif //GAMEENGINE2D_ENTITYMANAGER_H
