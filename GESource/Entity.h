//
// Created by Manoloon on 13/12/2021.
//

#ifndef GAMEENGINE2D_ENTITY_H
#define GAMEENGINE2D_ENTITY_H
#include <cstddef>
#include <string>
#include "CommonHeaders.h"
#include "Components.h"

// TODO: esto porque?
class EntityManager;

using ComponentTuple =
        std::tuple<
        CTransform,
        CLifespan,
        CInput,
        CAnimation,
        CGravity,
        CBBCollision,
        CState
        >;

class Entity
{
    //we declare EntityManager our friend, ergo he is the only one who can
    // create an instance of this class.
    friend class EntityManager;

    const size_t m_id =0;
    const std::string m_tag = "default";
    bool m_alive =true;
    ComponentTuple m_components;

    Entity(const size_t & m_id, const std::string & m_tag);
public:
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

    template<typename T>
    bool hasComponent() const
    {
        return getComponent<T>().has;
    }

    template<typename T,typename... TArgs>
    T & addComponent(TArgs&&... mArgs)
    {
        auto & component = getComponent<T>();
        component = T(std::forward<TArgs>(mArgs)...);
        return component;
    }

    template<typename T>
    T & getComponent()
    {
        return std::get<T>(m_components);
    }
    template<typename T>
    T & getComponent() const
    {
        return std::get<T>(m_components);
    }

    // TODO : implementar el removeComponent template
    template<typename T>
    void RemoveComponent(T)
    {
       if(std::get<T>(m_components))
       {

       }
    }

};


#endif //GAMEENGINE2D_ENTITY_H
