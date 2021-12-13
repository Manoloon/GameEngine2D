//
// Created by Manoloon on 13/12/2021.
//

#ifndef GAMEENGINE2D_SRENDER_H
#define GAMEENGINE2D_SRENDER_H
#include "../CommonHeaders.h"
#include "../Entity.h"

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


#endif //GAMEENGINE2D_SRENDER_H
