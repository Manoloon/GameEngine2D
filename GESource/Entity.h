//
// Created by Manoloon on 13/12/2021.
//

#ifndef GAMEENGINE2D_ENTITY_H
#define GAMEENGINE2D_ENTITY_H
#include <cstddef>
#include <string>
#include "CommonHeaders.h"
#include "Components.h"

class Entity
{
    //we declare EntityManager our friend, ergo he is the only one who can
    // create an instance of this class.
    friend class EntityManager;

    const size_t m_id =0;
    const std::string m_tag = "default";
    bool m_alive =true;

    // crear componentes...
    ptr<CShape>     cShape;
    ptr<CTransform> cTransform;
    ptr<CCollision> cCollision;
    ptr<CInput>     cInput;
    ptr<CScore>     cScore;
    ptr<CLifespan>  cLifespan;

    size_t GetId()const;
    const std::string &  GetTag()const;
    bool isActive()const;
    void destroy();

    explicit Entity(size_t m_id,const std::string& m_tag);

};


#endif //GAMEENGINE2D_ENTITY_H
