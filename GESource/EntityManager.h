//
// Created by Manoloon on 13/12/2021.
//

#ifndef GAMEENGINE2D_ENTITYMANAGER_H
#define GAMEENGINE2D_ENTITYMANAGER_H
#include <map>
#include <vector>
#include <memory>
#include <cstddef>

#include "Entity.h"

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<std::string,EntityVec> EntityMap;
class EntityManager
{
    // generate id
    size_t m_totalEntities =0;
    EntityVec m_entities;
    EntityMap m_entitiesMap;
    EntityVec m_toAdd;
public:
    EntityManager();
    void Update();
    std::shared_ptr<Entity> addEntity(const std::string& tag);
    EntityVec& GetEntity();
    EntityVec& GetEntity(const std::string& tag);

};


#endif //GAMEENGINE2D_ENTITYMANAGER_H
