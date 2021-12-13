//
// Created by Manoloon on 13/12/2021.
//

#ifndef GAMEENGINE2D_SMOVEMENT_H
#define GAMEENGINE2D_SMOVEMENT_H
#include "../CommonHeaders.h"
#include "../Entity.h"

struct SMovement
{
    void sMovement(std::vector<Entity> & entities)
    {
        for(auto & e : entities)
        {
            e.cTransform->pos += e.cTransform->velocity;
        }
    }
};


#endif //GAMEENGINE2D_SMOVEMENT_H
