//
// Created by Manoloon on 13/12/2021.
//

#ifndef GAMEENGINE2D_ENTITY_H
#define GAMEENGINE2D_ENTITY_H
#include <cstddef>
#include <string>


class Entity
{
    const size_t m_id =0;
    const std::string m_tag = "default";
    bool m_alive =true;

public:
    // crear componentes...

    explicit Entity(size_t m_id,const std::string& m_tag);
    [[nodiscard]] size_t GetId()const;
    std::string GetTag()const;
    bool GetIsAlive()const;
};


#endif //GAMEENGINE2D_ENTITY_H
