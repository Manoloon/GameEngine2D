//
// Created by Manoloon on 18/12/2021.
//

#ifndef GAMEENGINE2D_SYSTEMS_H
#define GAMEENGINE2D_SYSTEMS_H
#include "Entity.h"
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

struct SRender
{
    void sRender(std::vector<Entity> & entities)
    {
        for(auto & e : entities)
        {
            if(e.cShape && e.cTransform)
            {
                e.cShape->shape.setPosition(e.cShape,cTransform->pos);
                window.draw(e.cShape->shape);
            }
        }
    }
};
#endif //GAMEENGINE2D_SYSTEMS_H
