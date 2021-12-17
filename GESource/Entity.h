//
// Created by Manoloon on 13/12/2021.
//

#ifndef GAMEENGINE2D_ENTITY_H
#define GAMEENGINE2D_ENTITY_H
#include <cstddef>
#include <string>
#include <memory>
#include "Components/CTransform.h"
#include "Components/CShape.h"
#include "Components/CCollision.h"

class Entity
{
    const size_t m_id =0;
    const std::string m_tag = "default";
    bool m_alive =true;

    // crear componentes...
    std::shared_ptr<CShape>     cShape;
    std::shared_ptr<CTransform> cTransform;
    std::shared_ptr<CCollision> cCollision;

    //we declare EntityManager our friend, ergo he is the only one who can
    // create an instance of this class.
    friend class EntityManager;
    explicit Entity(size_t m_id,const std::string& m_tag);
public:
    size_t GetId()const;
    std::string GetTag()const;
    bool GetIsAlive()const;
};


#endif //GAMEENGINE2D_ENTITY_H
